// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#ifndef DJINNI_GENERATED_BOOLCALLBACK_HPP_JNI_
#define DJINNI_GENERATED_BOOLCALLBACK_HPP_JNI_

#include "../../api/BoolCallback.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class BoolCallback final : ::djinni::JniInterface<::ledger::core::api::BoolCallback, BoolCallback> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::BoolCallback>;
    using CppOptType = std::shared_ptr<::ledger::core::api::BoolCallback>;
    using JniType = jobject;

    using Boxed = BoolCallback;

    ~BoolCallback();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<BoolCallback>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<BoolCallback>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    BoolCallback();
    friend ::djinni::JniClass<BoolCallback>;
    friend ::djinni::JniInterface<::ledger::core::api::BoolCallback, BoolCallback>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::ledger::core::api::BoolCallback
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void onCallback(std::experimental::optional<bool> result, const std::experimental::optional<::ledger::core::api::Error> & error) override;

    private:
        friend ::djinni::JniInterface<::ledger::core::api::BoolCallback, ::djinni_generated::BoolCallback>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("BoolCallback") };
    const jmethodID method_onCallback { ::djinni::jniGetMethodID(clazz.get(), "onCallback", "(Ljava/lang/Boolean;LError;)V") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_BOOLCALLBACK_HPP_JNI_
