// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

package com.ledger.reactnative;

import co.ledger.core.BitcoinLikeAddress;
import co.ledger.core.BitcoinLikeNetworkParameters;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Optional;
import java.util.UUID;

/** Helper class for manipulating Bitcoin like addresses */
public class RCTCoreBitcoinLikeAddress extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;
    private Map<String, BitcoinLikeAddress> javaObjects;
    public Map<String, BitcoinLikeAddress> getJavaObjects()
    {
        return javaObjects;
    }

    public RCTCoreBitcoinLikeAddress(ReactApplicationContext reactContext)
    {
        super(reactContext);
        this.reactContext = reactContext;
        this.javaObjects = new HashMap<String, BitcoinLikeAddress>();
    }

    @Override
    public String getName()
    {
        return "RCTCoreBitcoinLikeAddress";
    }

    /**
     * Gets the version of the address (P2SH or P2PKH)
     * @return The version of the address
     */
    @ReactMethod
    public void getVersion(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            BitcoinLikeAddress currentInstanceObj = this.javaObjects.get(sUid);

            byte[] javaResult = currentInstanceObj.getVersion();
            Map<String, byte[]> result = new HashMap<String, byte[]>();
            result.put("value", javaResult);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     * Gets the raw hash160 of the public key
     * @return The 20 bytes of the public key hash160
     */
    @ReactMethod
    public void getHash160(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            BitcoinLikeAddress currentInstanceObj = this.javaObjects.get(sUid);

            byte[] javaResult = currentInstanceObj.getHash160();
            Map<String, byte[]> result = new HashMap<String, byte[]>();
            result.put("value", javaResult);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     * Gets the network parameters used for serializing the address
     * @return The network parameters of the address
     */
    @ReactMethod
    public void getNetworkParameters(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            BitcoinLikeAddress currentInstanceObj = this.javaObjects.get(sUid);

            BitcoinLikeNetworkParameters javaResult = currentInstanceObj.getNetworkParameters();

            String uuid = UUID.randomUUID().toString();
            RCTCoreBitcoinLikeNetworkParameters rctImpl_javaResult = this.reactContext.getNativeModule(RCTCoreBitcoinLikeNetworkParameters.class);
            rctImpl_javaResult.getJavaObjects().put(uuid, javaResult);
            HashMap<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCoreBitcoinLikeNetworkParameters");
            result.put("uid",uuid);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     * Serializes the hash160 into a Base58 encoded address (with checksum)
     * @return The Base58 serialization
     */
    @ReactMethod
    public void toBase58(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            BitcoinLikeAddress currentInstanceObj = this.javaObjects.get(sUid);

            String javaResult = currentInstanceObj.toBase58();
            Map<String, String> result = new HashMap<String, String>();
            result.put("value", javaResult);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     * Serializes the hash160 to a payment uri (i.e bitcoin:16UwLL9Risc3QfPqBUvKofHmBQ7wMtjvM)
     * @return A payment uri to this address
     * toPaymentUri(): string;
     * Checks if the given address is a P2SH address
     * @return True if the version byte matches the P2SH byte version of the address network parameters
     */
    @ReactMethod
    public void isP2SH(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            BitcoinLikeAddress currentInstanceObj = this.javaObjects.get(sUid);

            boolean javaResult = currentInstanceObj.isP2SH();
            Map<String, Boolean> result = new HashMap<String, Boolean>();
            result.put("value", javaResult);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     * Checks if the given address is a P2PKH address
     * @return True if the version byte matches the P2PKH byte version of the address network parameters
     */
    @ReactMethod
    public void isP2PKH(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            BitcoinLikeAddress currentInstanceObj = this.javaObjects.get(sUid);

            boolean javaResult = currentInstanceObj.isP2PKH();
            Map<String, Boolean> result = new HashMap<String, Boolean>();
            result.put("value", javaResult);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
}
