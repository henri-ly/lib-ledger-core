// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKEMSGSEND_HPP_JNI_
#define DJINNI_GENERATED_COSMOSLIKEMSGSEND_HPP_JNI_

#include "../../api/CosmosLikeMsgSend.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class CosmosLikeMsgSend final {
public:
    using CppType = ::ledger::core::api::CosmosLikeMsgSend;
    using JniType = jobject;

    using Boxed = CosmosLikeMsgSend;

    ~CosmosLikeMsgSend();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    CosmosLikeMsgSend();
    friend ::djinni::JniClass<CosmosLikeMsgSend>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/CosmosLikeMsgSend") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/ArrayList;)V") };
    const jfieldID field_fromAddress { ::djinni::jniGetFieldID(clazz.get(), "fromAddress", "Ljava/lang/String;") };
    const jfieldID field_toAddress { ::djinni::jniGetFieldID(clazz.get(), "toAddress", "Ljava/lang/String;") };
    const jfieldID field_amount { ::djinni::jniGetFieldID(clazz.get(), "amount", "Ljava/util/ArrayList;") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_COSMOSLIKEMSGSEND_HPP_JNI_
