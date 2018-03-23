// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

#ifndef DJINNI_GENERATED_NJSDERIVATIONPATH_HPP
#define DJINNI_GENERATED_NJSDERIVATIONPATH_HPP


#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <nan.h>
#include <node.h>
#include "../../../core/src/api/DerivationPath.hpp"

using namespace v8;
using namespace node;
using namespace std;
using namespace ledger::core::api;

class NJSDerivationPath: public Nan::ObjectWrap {
public:

    static void Initialize(Local<Object> target);
    virtual ~NJSDerivationPath() {};
    NJSDerivationPath(const std::shared_ptr<ledger::core::api::DerivationPath> &iDerivationPath):_DerivationPath(iDerivationPath){};

    static Handle<Object> wrap(const std::shared_ptr<ledger::core::api::DerivationPath> &object);
    static Nan::Persistent<ObjectTemplate> DerivationPath_prototype;
    std::shared_ptr<ledger::core::api::DerivationPath> getCppImpl(){return _DerivationPath;};

private:
    /** Get the number of element in this path. */
    static NAN_METHOD(getDepth);

    /** Get the child num at the given index in the path. */
    static NAN_METHOD(getChildNum);

    /**
     * Get the child num at the given index in the path. If the child num is hardened, returns it
     * without the hardened marker bit.
     */
    static NAN_METHOD(getUnhardenedChildNum);

    /** Return true if the given index in the path is an hardened child num. */
    static NAN_METHOD(isHardened);

    /** Serialize the given path to a human readable string like "44'/0'/0'/0/0" */
    static NAN_METHOD(toString);

    /**
     * Return a derivation path without the last element, e.g. the parent of "44'/0'/0'/0/0" is
     * "44'/0'/0'/0"
     */
    static NAN_METHOD(getParent);

    /** Return an array where which item is a child num of the path. */
    static NAN_METHOD(toArray);

    static NAN_METHOD(parse);

    static NAN_METHOD(New);

    std::shared_ptr<ledger::core::api::DerivationPath> _DerivationPath;
};
#endif //DJINNI_GENERATED_NJSDERIVATIONPATH_HPP
