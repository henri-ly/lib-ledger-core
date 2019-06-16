// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#ifndef DJINNI_GENERATED_COSMOSCURVE_HPP_JNI_
#define DJINNI_GENERATED_COSMOSCURVE_HPP_JNI_

#include "../../api/CosmosCurve.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class CosmosCurve final : ::djinni::JniEnum {
public:
    using CppType = ::ledger::core::api::CosmosCurve;
    using JniType = jobject;

    using Boxed = CosmosCurve;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<CosmosCurve>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<CosmosCurve>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    CosmosCurve() : JniEnum("co/ledger/core/CosmosCurve") {}
    friend ::djinni::JniClass<CosmosCurve>;
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_COSMOSCURVE_HPP_JNI_