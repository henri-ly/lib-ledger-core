/*
 *
 * CosmosLikeBlockchainExplorerAccountSynchronizer
 *
 * Created by El Khalil Bellakrid on 14/06/2019.
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


#include "CosmosLikeBlockchainExplorerAccountSynchronizer.h"
#include <wallet/cosmos/CosmosLikeAccount.h>

namespace ledger {
    namespace core {
        CosmosLikeBlockchainExplorerAccountSynchronizer::CosmosLikeBlockchainExplorerAccountSynchronizer(
                const std::shared_ptr<WalletPool> &pool,
                const std::shared_ptr<CosmosLikeBlockchainExplorer> &explorer) :
                DedicatedContext(pool->getDispatcher()->getThreadPoolExecutionContext("synchronizers")) {
            _explorer = explorer;
            _database = pool->getDatabaseSessionPool();
        }

        std::shared_ptr<ProgressNotifier<Unit>>
        CosmosLikeBlockchainExplorerAccountSynchronizer::synchronize(const std::shared_ptr<CosmosLikeAccount> &account) {
            auto self = shared_from_this();
            _notifier = std::make_shared<ProgressNotifier<Unit>>();
            _explorer->getCurrentBlock().flatMap<std::list<CosmosLikeBlockchainExplorerTransaction>>(getContext(), [=] (const std::shared_ptr<Block>& block) {
                soci::session session(self->_database->getPool());
                account->putBlock(session, *block);
               return _explorer->getTransactions(account->getKeychain()->getAddress()->toBech32());
            }).onComplete(getContext(), [=] (const Try<std::list<CosmosLikeBlockchainExplorerTransaction>> &txs) {
                std::lock_guard<std::mutex> l(self->_lock);
                if (txs.isFailure()) {
                    self->_notifier->failure(txs.getFailure());
                } else {
                    for (const auto& tx : txs.getValue()) {
                        soci::session session(self->_database->getPool());
                        // TODO COSMOS Use a db transaction here
                        account->putTransaction(session, tx);
                    }
                    self->_notifier->success(unit);
                }
                self->_notifier = nullptr;
            });

            return _notifier;
        }

        bool CosmosLikeBlockchainExplorerAccountSynchronizer::isSynchronizing() const {
            return _notifier != nullptr;
        }

        void CosmosLikeBlockchainExplorerAccountSynchronizer::reset(const std::shared_ptr<CosmosLikeAccount> &account,
                                                                    const std::chrono::system_clock::time_point &toDate) {

        }

    }
}
