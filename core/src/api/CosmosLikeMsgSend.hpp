// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKEMSGSEND_HPP
#define DJINNI_GENERATED_COSMOSLIKEMSGSEND_HPP

#include "CosmosLikeAmount.hpp"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace ledger { namespace core { namespace api {

struct CosmosLikeMsgSend final {
    std::string fromAddress;
    std::string toAddress;
    std::vector<CosmosLikeAmount> amount;

    CosmosLikeMsgSend(std::string fromAddress_,
                      std::string toAddress_,
                      std::vector<CosmosLikeAmount> amount_)
    : fromAddress(std::move(fromAddress_))
    , toAddress(std::move(toAddress_))
    , amount(std::move(amount_))
    {}

    CosmosLikeMsgSend(const CosmosLikeMsgSend& cpy) {
       this->fromAddress = cpy.fromAddress;
       this->toAddress = cpy.toAddress;
       this->amount = cpy.amount;
    }

    CosmosLikeMsgSend() = default;


    CosmosLikeMsgSend& operator=(const CosmosLikeMsgSend& cpy) {
       this->fromAddress = cpy.fromAddress;
       this->toAddress = cpy.toAddress;
       this->amount = cpy.amount;
       return *this;
    }

    template <class Archive>
    void load(Archive& archive) {
        archive(fromAddress, toAddress, amount);
    }

    template <class Archive>
    void save(Archive& archive) const {
        archive(fromAddress, toAddress, amount);
    }
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_COSMOSLIKEMSGSEND_HPP
