// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from crypto.djinni

package com.ledger.reactnative;

import HashAlgorithmHelperImpl;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import java.util.UUID;;

/** Helper class for commonly used crypto algorithms */
public class RCTCoreHashAlgorithmHelper extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;
    private Map<String, HashAlgorithmHelperImpl> javaObjects;

    public RNLedgerCoreModule(ReactApplicationContext reactContext)
    {
        super(reactContext);
        this.reactContext = reactContext;
        this.javaObjects = new HashMap<String, HashAlgorithmHelperImpl>();
    }

    @Override
    public String getName()
    {
        return "RCTCoreHashAlgorithmHelper";
    }

    /**
     *RACE Integrity Primitives Evaluation Message Digest (used in Bitcoin)
     *@param data in bytes, message to hash
     *@return 160 bits hashed message
     */
    @ReactMethod
    public void ripemd160(Map<String, String> currentInstance, byte[] data, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            HashAlgorithmHelperImpl currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreHashAlgorithmHelper instance passed to ripemd160 method");
            }

            byte[] javaResult = currentInstanceObj.ripemd160(data);
            Map<String, byte[]> result = new HashMap<String, byte[]>();
            result.put("value", javaResult);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCoreHashAlgorithmHelper::ripemd160 : Failed to return byte[] from ripemd160 method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     *Secure Hash Algorithm (used in Bitcoin)
     *@param data in bytes, message to hash
     *@return 256 bits hashed message
     */
    @ReactMethod
    public void sha256(Map<String, String> currentInstance, byte[] data, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            HashAlgorithmHelperImpl currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreHashAlgorithmHelper instance passed to sha256 method");
            }

            byte[] javaResult = currentInstanceObj.sha256(data);
            Map<String, byte[]> result = new HashMap<String, byte[]>();
            result.put("value", javaResult);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCoreHashAlgorithmHelper::sha256 : Failed to return byte[] from sha256 method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     *Hash algorithm used in ethereum
     *@param data in bytes, message to hash
     *@return 256 bits hashed message
     */
    @ReactMethod
    public void keccak256(Map<String, String> currentInstance, byte[] data, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            HashAlgorithmHelperImpl currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreHashAlgorithmHelper instance passed to keccak256 method");
            }

            byte[] javaResult = currentInstanceObj.keccak256(data);
            Map<String, byte[]> result = new HashMap<String, byte[]>();
            result.put("value", javaResult);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCoreHashAlgorithmHelper::keccak256 : Failed to return byte[] from keccak256 method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
}
