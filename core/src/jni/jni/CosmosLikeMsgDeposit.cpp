// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#include "CosmosLikeMsgDeposit.hpp"  // my header
#include "CosmosLikeAmount.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

CosmosLikeMsgDeposit::CosmosLikeMsgDeposit() = default;

CosmosLikeMsgDeposit::~CosmosLikeMsgDeposit() = default;

auto CosmosLikeMsgDeposit::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<CosmosLikeMsgDeposit>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.depositor)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.proposalId)),
                                                           ::djinni::get(::djinni::List<::djinni_generated::CosmosLikeAmount>::fromCpp(jniEnv, c.amount)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto CosmosLikeMsgDeposit::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 4);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<CosmosLikeMsgDeposit>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_depositor)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_proposalId)),
            ::djinni::List<::djinni_generated::CosmosLikeAmount>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_amount))};
}

}  // namespace djinni_generated
