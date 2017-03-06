// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from configuration.djinni

#include "Configuration.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class LGConfiguration;

namespace djinni_generated {

class Configuration
{
public:
    using CppType = std::shared_ptr<::ledger::core::api::Configuration>;
    using CppOptType = std::shared_ptr<::ledger::core::api::Configuration>;
    using ObjcType = LGConfiguration*;

    using Boxed = Configuration;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated
