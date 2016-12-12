// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#pragma once

#include "../../api/BitcoinLikeNetworkParameters.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class BitcoinLikeNetworkParameters final {
public:
    using CppType = ::ledger::core::api::BitcoinLikeNetworkParameters;
    using JniType = jobject;

    using Boxed = BitcoinLikeNetworkParameters;

    ~BitcoinLikeNetworkParameters();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    BitcoinLikeNetworkParameters();
    friend ::djinni::JniClass<BitcoinLikeNetworkParameters>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/BitcoinLikeNetworkParameters") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;III)V") };
    const jfieldID field_identifier { ::djinni::jniGetFieldID(clazz.get(), "identifier", "Ljava/lang/String;") };
    const jfieldID field_P2PKHVersion { ::djinni::jniGetFieldID(clazz.get(), "P2PKHVersion", "I") };
    const jfieldID field_P2SHVersion { ::djinni::jniGetFieldID(clazz.get(), "P2SHVersion", "I") };
    const jfieldID field_XPUBVersion { ::djinni::jniGetFieldID(clazz.get(), "XPUBVersion", "I") };
};

}  // namespace djinni_generated
