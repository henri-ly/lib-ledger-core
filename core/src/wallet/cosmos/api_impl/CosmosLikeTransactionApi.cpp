/*
 *
 * CosmosLikeTransactionApi
 *
 * Created by El Khalil Bellakrid on  14/06/2019.
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


#include "CosmosLikeTransactionApi.h"

#include <fmt/format.h>

#include <wallet/common/Amount.h>
#include <wallet/common/AbstractAccount.hpp>
#include <wallet/common/AbstractWallet.hpp>
#include <cosmos/CosmosLikeAddress.h>
#include <bytes/BytesWriter.h>
#include <bytes/BytesReader.h>
#include <utils/hex.h>
#include <api_impl/BigIntImpl.hpp>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <utils/base64.h>
#include <api/CosmosLikeMsgType.hpp>
#include <wallet/cosmos/CosmosLikeMessage.h>
#include <wallet/cosmos/CosmosLikeConstants.hpp>

using namespace rapidjson;
namespace ledger {
    namespace core {

        CosmosLikeTransactionApi::CosmosLikeTransactionApi(const api::Currency &currency) {
            _currency = currency;
        }

        CosmosLikeTransactionApi::CosmosLikeTransactionApi(const std::shared_ptr<OperationApi> &operation) {
            auto &tx = operation->getBackend().cosmosTransaction.getValue();
            _time = tx.timestamp;
            // TODO COSMOS Retrieve a block (the model only has an optional height)
            _block = nullptr;

            _hash = tx.hash;
            _currency = operation->getAccount()->getWallet()->getCurrency();
            // _fee = tx.fee;
            // _gaz = tx.gas;
            // _accountNumber = tx.accountNumber;
            _memo = tx.memo;
            // _sequence = tx.sequence;

            if (tx.messages.empty()) {
                throw Exception(api::ErrorCode::INVALID_ARGUMENT, "No messages while creating Cosmos transaction");
            } 
            else {
               // TODO manage messages here
            }
        }

        std::string CosmosLikeTransactionApi::getMemo() const {
            return _memo;
        }

        std::vector<std::shared_ptr<api::CosmosLikeMessage>> CosmosLikeTransactionApi::getMessages() const {
            return _messages;
        }

        CosmosLikeTransactionApi & CosmosLikeTransactionApi::setMessages(const std::vector<std::shared_ptr<api::CosmosLikeMessage>> & messages) {
            for (auto& message : messages) {
                if (message->getMessageType() == api::CosmosLikeMsgType::UNKNOWN) {
                    throw Exception(
                        api::ErrorCode::INVALID_ARGUMENT, 
                        fmt::format("Unknown '{}' message", message->getRawMessageType()));
                }
            }
            _messages = messages;
            return *this;
        }

        std::string CosmosLikeTransactionApi::getHash() const {
            return _hash;
        }

        std::shared_ptr<api::Amount> CosmosLikeTransactionApi::getFee() const {
            return std::make_shared<Amount>(_currency, 0, BigInt(_fee->toString()) * BigInt(_gas->toString()));
        }

       std::chrono::system_clock::time_point CosmosLikeTransactionApi::getDate() const {
            return _time;
        }

        std::vector<uint8_t> CosmosLikeTransactionApi::getSigningPubKey() const {
            return _signingPubKey;
        }

        std::shared_ptr<api::Amount> CosmosLikeTransactionApi::getGas() const {
            return _gas;
        }

        void CosmosLikeTransactionApi::setSignature(const std::vector<uint8_t> &rSignature,
                                                    const std::vector<uint8_t> &sSignature) {
            _rSignature = rSignature;
            _sSignature = sSignature;
        }

        void CosmosLikeTransactionApi::setDERSignature(const std::vector<uint8_t> &signature) {
            BytesReader reader(signature);
            //DER prefix
            reader.readNextByte();
            //Total length
            reader.readNextVarInt();
            //Nb of elements for R
            reader.readNextByte();
            //R length
            auto rSize = reader.readNextVarInt();
            if (rSize > 0 && reader.peek() == 0x00) {
                reader.readNextByte();
                _rSignature = reader.read(rSize - 1);
            } else {
                _rSignature = reader.read(rSize);
            }
            //Nb of elements for S
            reader.readNextByte();
            //S length
            auto sSize = reader.readNextVarInt();
            if (sSize > 0 && reader.peek() == 0x00) {
                reader.readNextByte();
                _sSignature = reader.read(sSize - 1);
            } else {
                _sSignature = reader.read(sSize);
            }
        }

        std::string CosmosLikeTransactionApi::serialize() {
            using namespace constants;

            Document document;
            document.SetObject();

            Document::AllocatorType& allocator = document.GetAllocator();

            Value vString(rapidjson::kStringType);
            vString.SetString(_accountNumber.c_str(), static_cast<rapidjson::SizeType>(_accountNumber.length()), allocator);
            document.AddMember(kAccountNumber, vString, allocator);

            auto chainID = _currency.cosmosLikeNetworkParameters.value().ChainId;
            vString.SetString(chainID.c_str(), static_cast<rapidjson::SizeType>(chainID.length()), allocator);
            document.AddMember(kChainId, vString, allocator);

            auto getAmountObject = [&] (const std::string &denom, const std::string &amount) {
                Value amountObject(kObjectType);
                Value vStringLocal(rapidjson::kStringType);
                vStringLocal.SetString(amount.c_str(), static_cast<rapidjson::SizeType>(amount.length()), allocator);
                amountObject.AddMember(kAmount, vStringLocal, allocator);
                vStringLocal.SetString(denom.c_str(), static_cast<rapidjson::SizeType>(denom.length()), allocator);
                amountObject.AddMember(kDenom, vStringLocal, allocator);
                return amountObject;
            };

            // Fee object
            auto fees = std::make_shared<BigInt>(BigInt(_fee->toString()) * BigInt(_gas->toString()));
            auto feeAmountObj = getAmountObject(_fee->getUnit().name, fees->toString());
            Value feeArray(kArrayType);
            feeArray.PushBack(feeAmountObj, allocator);
            Value feeAmountObject(kObjectType);
            feeAmountObject.AddMember(kAmount, feeArray, allocator);
            auto gas = _gas->toString();
            vString.SetString(gas.c_str(), static_cast<rapidjson::SizeType>(gas.length()), allocator);
            feeAmountObject.AddMember(kGas, vString, allocator);
            document.AddMember(kFee, feeAmountObject, allocator);

            vString.SetString(_memo.c_str(), static_cast<rapidjson::SizeType>(_memo.length()), allocator);
            document.AddMember(kMemo, vString, allocator);

            //cosmos-sdk/MsgSend
            Value msgArray(kArrayType);
            for (auto msg: _messages) {
                msgArray.PushBack(std::dynamic_pointer_cast<CosmosLikeMessage>(msg)->toJson(allocator), allocator);
            }
            document.AddMember(kMessages, msgArray, allocator);

            // Add signatures
            if (!_sSignature.empty() && !_rSignature.empty()) {
                Value sigArray(kArrayType);

                Value pubKeyObject(kObjectType);
                // TODO store it somewhere
                std::string pubKeyType = "tendermint/PubKeySecp256k1";
                vString.SetString(pubKeyType.c_str(), static_cast<rapidjson::SizeType>(pubKeyType.length()), allocator);
                pubKeyObject.AddMember(kType, vString, allocator);

                auto pubKeyValue = base64_encode(_signingPubKey.data(), _signingPubKey.size());
                vString.SetString(pubKeyValue.c_str(), static_cast<rapidjson::SizeType>(pubKeyValue.length()), allocator);
                pubKeyObject.AddMember(kValue, vString, allocator);

                auto pad = [] (const std::vector<uint8_t> &input) {
                    auto output = input;
                    while(output.size() < 32) {
                        output.emplace(output.begin(), 0x00);
                    }
                    return output;
                };
                auto signature = vector::concat(pad(_rSignature), pad(_sSignature));
                if (signature.size() != 64) {
                    throw Exception(api::ErrorCode::INVALID_ARGUMENT, "Invalid signature when serializing transaction");
                }

                // Set pub key
                Value sigObject(kObjectType);
                sigObject.AddMember(kPubKey, pubKeyObject, allocator);
                // Set signature
                auto strSignature = base64_encode(signature.data(), signature.size());
                vString.SetString(strSignature.c_str(), static_cast<rapidjson::SizeType>(strSignature.length()), allocator);
                sigObject.AddMember(kSignature, vString, allocator);

                sigArray.PushBack(sigObject, allocator);
                document.AddMember(kSignature, sigArray, allocator);
            }

            vString.SetString(_sequence.c_str(), static_cast<rapidjson::SizeType>(_sequence.length()), allocator);
            document.AddMember(kSequence, vString, allocator);

            StringBuffer buffer;
            Writer<StringBuffer> writer(buffer);
            document.Accept(writer);
            return buffer.GetString();
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setSigningPubKey(const std::vector<uint8_t> &pubKey) {
            _signingPubKey = pubKey;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setHash(const std::string &hash) {
            _hash = hash;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setGas(const std::shared_ptr<BigInt> &gas) {
            if (!gas) {
                throw make_exception(api::ErrorCode::INVALID_ARGUMENT,
                                     "CosmosLikeTransactionApi::setGas: Invalid gas");
            }
            _gas = std::make_shared<Amount>(_currency, 0, *gas);
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setFee(const std::shared_ptr<BigInt> &fee) {
            if (!fee) {
                throw make_exception(api::ErrorCode::INVALID_ARGUMENT,
                                     "CosmosLikeTransactionApi::setGasPrice: Invalid fee");
            }
            _fee = std::make_shared<Amount>(_currency, 0, *fee);
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setSequence(const std::string &sequence) {
            _sequence = sequence;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setMemo(const std::string &memo) {
            _memo = memo;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setAccountNumber(const std::string &accountNumber) {
            _accountNumber = accountNumber;
            return *this;
        }

    }
}
