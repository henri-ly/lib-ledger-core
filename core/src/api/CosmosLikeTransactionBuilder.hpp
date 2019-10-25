// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKETRANSACTIONBUILDER_HPP
#define DJINNI_GENERATED_COSMOSLIKETRANSACTIONBUILDER_HPP

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

class Amount;
class CosmosLikeTransaction;
class CosmosLikeTransactionCallback;
struct Currency;

class LIBCORE_EXPORT CosmosLikeTransactionBuilder {
public:
    virtual ~CosmosLikeTransactionBuilder() {}

    /**
     * Send funds to the given address. This method can be called multiple times to send to multiple addresses.
     * @param amount The value to send
     * @param address Address of the recipient
     * @return A reference on the same builder in order to chain calls.
     */
    virtual std::shared_ptr<CosmosLikeTransactionBuilder> sendToAddress(const std::shared_ptr<Amount> & amount, const std::string & address) = 0;

    /**
     * Send all available funds to the given address.
     * @param address Address of the recipient
     * @return A reference on the same builder in order to chain calls.
     */
    virtual std::shared_ptr<CosmosLikeTransactionBuilder> wipeToAddress(const std::string & address) = 0;

    /**
     * Set gas limit the originator is not willing to exceed.
     * @return A reference on the same builder in order to chain calls.
     */
    virtual std::shared_ptr<CosmosLikeTransactionBuilder> setGasLimit(const std::shared_ptr<Amount> & gasLimit) = 0;

    virtual std::shared_ptr<CosmosLikeTransactionBuilder> setGasPrice(const std::shared_ptr<Amount> & gasPrice) = 0;

    virtual std::shared_ptr<CosmosLikeTransactionBuilder> setGasAdjustment(double gasAdjustment) = 0;

    /** Build a transaction from the given builder parameters. */
    virtual void build(const std::shared_ptr<CosmosLikeTransactionCallback> & callback) = 0;

    /**
     * Creates a clone of this builder.
     * @return A copy of the current builder instance.
     */
    virtual std::shared_ptr<CosmosLikeTransactionBuilder> clone() = 0;

    /** Reset the current instance to its initial state */
    virtual void reset() = 0;

    static std::shared_ptr<CosmosLikeTransaction> parseRawUnsignedTransaction(const Currency & currency, const std::vector<uint8_t> & rawTransaction);

    static std::shared_ptr<CosmosLikeTransaction> parseRawSignedTransaction(const Currency & currency, const std::vector<uint8_t> & rawTransaction);
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_COSMOSLIKETRANSACTIONBUILDER_HPP
