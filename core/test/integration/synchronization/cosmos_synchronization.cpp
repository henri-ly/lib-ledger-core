/*
 *
 * cosmos_synchronization.cpp
 * ledger-core
 *
 * Created by Pierre Pollastri on 15/06/2019.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <gtest/gtest.h>
#include "../BaseFixture.h"
#include <set>
#include <api/KeychainEngines.hpp>
#include <utils/DateUtils.hpp>
#include <wallet/cosmos/explorers/GaiaCosmosLikeBlockchainExplorer.hpp>
#include <wallet/cosmos/cosmosNetworks.h>
#include <collections/DynamicObject.hpp>
#include <iostream>
#include <api/CosmosConfigurationDefaults.hpp>
#include <cosmos/CosmosLikeExtendedPublicKey.h>
#include <wallet/currencies.hpp>
#include <wallet/cosmos/transaction_builders/CosmosLikeTransactionBuilder.h>

using namespace std;
using namespace ledger::core;

api::CosmosLikeNetworkParameters COSMOS = networks::getCosmosLikeNetworkParameters("cosmos");
std::string DEFAULT_ADDRESS = "cosmos1sd4tl9aljmmezzudugs7zlaya7pg2895tyn79r";
std::string DEFAULT_HEX_PUB_KEY = "03d672c1b90c84d9d97522e9a73252a432b77d90a78bf81cdbe35270d9d3dc1c34";

class CosmosLikeWalletSynchronization : public BaseFixture {};

TEST_F(CosmosLikeWalletSynchronization, GetAccountWithExplorer) {

    auto context = this->dispatcher->getSerialExecutionContext("context");
    auto pool = this->newDefaultPool();

    auto explorer = std::make_shared<GaiaCosmosLikeBlockchainExplorer>(
            pool->getDispatcher()->getSerialExecutionContext("explorer"),
            pool->getHttpClient(api::CosmosConfigurationDefaults::COSMOS_DEFAULT_API_ENDPOINT),
            COSMOS,
            std::make_shared<DynamicObject>()
            );

    auto account = ::wait(explorer->getAccount(DEFAULT_ADDRESS));
    ASSERT_EQ(account->address, DEFAULT_ADDRESS);
    ASSERT_EQ(account->accountNumber, "1000");

}


TEST_F(CosmosLikeWalletSynchronization, GetTransactionsWithExplorer) {
    auto context = this->dispatcher->getSerialExecutionContext("context");
    auto pool = this->newDefaultPool();

    auto explorer = std::make_shared<GaiaCosmosLikeBlockchainExplorer>(
            pool->getDispatcher()->getSerialExecutionContext("explorer"),
            pool->getHttpClient(api::CosmosConfigurationDefaults::COSMOS_DEFAULT_API_ENDPOINT),
            COSMOS,
            std::make_shared<DynamicObject>()
    );
    CosmosLikeBlockchainExplorer::TransactionFilter filter {"recipient="};
    auto transactions = ::wait(explorer->getTransactions(DEFAULT_ADDRESS, filter, 1, 10));
    bool foundTx = false;
    for (const auto& tx : transactions) {
        if (tx->hash == "A1E44688B429AF17322EC33CE62876FA415EFC8D9244A2F51454BD025F416594") {
            foundTx = true;
            ASSERT_EQ(tx->block->height, 168801);
            ASSERT_EQ(tx->logs.size(), 1);
            ASSERT_TRUE(tx->logs[0].success);
            ASSERT_EQ(tx->messages[0].type, "cosmos-sdk/MsgSend");
            const cosmos::MsgSend& msg = boost::get<cosmos::MsgSend>(tx->messages[0].content);
            ASSERT_EQ(msg.fromAddress, "cosmos155svs6sgxe55rnvs6ghprtqu0mh69kehrn0dqr");
            ASSERT_EQ(msg.toAddress, "cosmos1sd4tl9aljmmezzudugs7zlaya7pg2895tyn79r");
            ASSERT_EQ(msg.amount[0].amount, "900000");
            ASSERT_EQ(msg.amount[0].denom, "uatom");
            ASSERT_EQ(tx->fee.gas.toInt64(), 30000);
            ASSERT_EQ(tx->fee.amount[0].denom, "uatom");
            ASSERT_EQ(tx->fee.amount[0].amount, "30");
            ASSERT_EQ(tx->gasUsed, Option<std::string>("26826"));
            break;
        }
    }
    ASSERT_TRUE(foundTx);
    ASSERT_TRUE(transactions.size() >= 3);
}


TEST_F(CosmosLikeWalletSynchronization, GetCurrentBlockWithExplorer) {
    std::string address = "cosmos16xkkyj97z7r83sx45xwk9uwq0mj0zszlf6c6mq";
    auto context = this->dispatcher->getSerialExecutionContext("context");
    auto pool = this->newDefaultPool();

    auto explorer = std::make_shared<GaiaCosmosLikeBlockchainExplorer>(
            pool->getDispatcher()->getSerialExecutionContext("explorer"),
            pool->getHttpClient(api::CosmosConfigurationDefaults::COSMOS_DEFAULT_API_ENDPOINT),
            COSMOS,
            std::make_shared<DynamicObject>()
    );

    auto block = ::wait(explorer->getCurrentBlock());
    EXPECT_TRUE(block->hash.size() > 0);
    EXPECT_TRUE(block->height > 0);
}

TEST_F(CosmosLikeWalletSynchronization, MediumXpubSynchronization) {
    auto pool = newDefaultPool();
    {
        auto configuration = DynamicObject::newInstance();
        configuration->putString(api::Configuration::KEYCHAIN_DERIVATION_SCHEME,
                                 "44'/<coin_type>'/<account>'/<node>/<address>");
        auto wallet = wait(pool->createWallet("e847815f-488a-4301-b67c-378a5e9c8a61", "cosmos", configuration));
        std::set<std::string> emittedOperations;
        {
			auto accountInfo = wait(wallet->getNextAccountCreationInfo());
			EXPECT_EQ(accountInfo.index, 0);
			accountInfo.publicKeys.push_back(hex::toByteArray(DEFAULT_HEX_PUB_KEY));
			auto account = createCosmosLikeAccount(wallet, accountInfo.index, accountInfo);

			auto receiver = make_receiver([&](const std::shared_ptr<api::Event> &event) {
			    if (event->getCode() == api::EventCode::NEW_OPERATION) {
					auto uid = event->getPayload()->getString(api::Account::EV_NEW_OP_UID).value();
					EXPECT_EQ(emittedOperations.find(uid), emittedOperations.end());
				}
			});
			auto address = wait(account->getFreshPublicAddresses())[0]->toString();
			EXPECT_EQ(address, DEFAULT_ADDRESS);
			pool->getEventBus()->subscribe(dispatcher->getMainExecutionContext(), receiver);

			receiver.reset();
			receiver = make_receiver([=](const std::shared_ptr<api::Event> &event) {
			    fmt::print("Received event {}\n", api::to_string(event->getCode()));
				if (event->getCode() == api::EventCode::SYNCHRONIZATION_STARTED)
					return;
				EXPECT_NE(event->getCode(), api::EventCode::SYNCHRONIZATION_FAILED);
				EXPECT_EQ(event->getCode(), api::EventCode::SYNCHRONIZATION_SUCCEED);

				auto balance = wait(account->getBalance());
				std::cout << "Balance: " << balance->toString() << std::endl;
				auto txBuilder = std::dynamic_pointer_cast<CosmosLikeTransactionBuilder>(account->buildTransaction());
				dispatcher->stop();
			});

			auto restoreKey = account->getRestoreKey();
			account->synchronize()->subscribe(
				dispatcher->getMainExecutionContext(), receiver);

			dispatcher->waitUntilStopped();

			auto ops = wait(std::dynamic_pointer_cast<OperationQuery>(account->queryOperations()->complete())->execute());
			std::cout << "Ops: " << ops.size() << std::endl;
			auto block = wait(account->getLastBlock());
			auto blockHash = block.blockHash;
        }
    }
}
