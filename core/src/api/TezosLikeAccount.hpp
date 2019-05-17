// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from tezos_like_wallet.djinni

#ifndef DJINNI_GENERATED_TEZOSLIKEACCOUNT_HPP
#define DJINNI_GENERATED_TEZOSLIKEACCOUNT_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class BigIntCallback;
class StringCallback;
class TezosLikeOriginatedAccount;
class TezosLikeTransaction;
class TezosLikeTransactionBuilder;

/**Class representing a Tezos account */
class LIBCORE_EXPORT TezosLikeAccount {
public:
    virtual ~TezosLikeAccount() {}

    virtual void broadcastRawTransaction(const std::vector<uint8_t> & transaction, const std::shared_ptr<StringCallback> & callback) = 0;

    virtual void broadcastTransaction(const std::shared_ptr<TezosLikeTransaction> & transaction, const std::shared_ptr<StringCallback> & callback) = 0;

    virtual std::shared_ptr<TezosLikeTransactionBuilder> buildTransaction() = 0;

    /**
     * Get needed storage to proceed a tx
     * @param address to which we want to send tx
     * @return needed storage to interact with address/contract
     * Note: same note as for getGasPrice method on EthereumLikeAccount
     */
    virtual void getStorage(const std::string & address, const std::shared_ptr<BigIntCallback> & callback) = 0;

    /**
     * Get estimated gas limit to set so the transaction will succeed
     * The passed address could be implicit address or contract
     * This estimation is based on X last incoming txs (to address) that succeeded
     * Note: same note as for getFees method on BitcoinLikeAccount
     */
    virtual void getEstimatedGasLimit(const std::string & address, const std::shared_ptr<BigIntCallback> & callback) = 0;

    /** Get originated accounts by current account */
    virtual std::vector<std::shared_ptr<TezosLikeOriginatedAccount>> getOriginatedAccounts() = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_TEZOSLIKEACCOUNT_HPP
