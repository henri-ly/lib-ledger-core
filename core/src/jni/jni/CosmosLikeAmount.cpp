// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#include "CosmosLikeAmount.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

CosmosLikeAmount::CosmosLikeAmount() = default;

CosmosLikeAmount::~CosmosLikeAmount() = default;

auto CosmosLikeAmount::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<CosmosLikeAmount>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.amount)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.denom)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto CosmosLikeAmount::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<CosmosLikeAmount>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_amount)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_denom))};
}

}  // namespace djinni_generated
