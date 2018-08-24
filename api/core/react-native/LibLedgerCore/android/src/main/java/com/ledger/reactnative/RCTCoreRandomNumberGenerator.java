// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from random.djinni

package com.ledger.reactnative;

import co.ledger.core.RandomNumberGeneratorImpl;
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

/** Class to generate random numbers */
public class RCTCoreRandomNumberGenerator extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;
    private Map<String, RandomNumberGeneratorImpl> javaObjects;
    public Map<String, RandomNumberGeneratorImpl> getJavaObjects()
    {
        return javaObjects;
    }

    public RCTCoreRandomNumberGenerator(ReactApplicationContext reactContext)
    {
        super(reactContext);
        this.reactContext = reactContext;
        this.javaObjects = new HashMap<String, RandomNumberGeneratorImpl>();
    }

    @Override
    public String getName()
    {
        return "RCTCoreRandomNumberGenerator";
    }

    /**
     * Generates random bytes.
     * @params size number of bytes to generate
     * @return 'size' random bytes
     */
    @ReactMethod
    public void getRandomBytes(Map<String, String> currentInstance, int size, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            RandomNumberGeneratorImpl currentInstanceObj = this.javaObjects.get(sUid);

            byte[] javaResult = currentInstanceObj.getRandomBytes(size);
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
     * Generates random 32 bits integer.
     * @return random 32 bits integer
     */
    @ReactMethod
    public void getRandomInt(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            RandomNumberGeneratorImpl currentInstanceObj = this.javaObjects.get(sUid);

            int javaResult = currentInstanceObj.getRandomInt();
            Map<String, Integer> result = new HashMap<String, Integer>();
            result.put("value", javaResult);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     * Generates random 64 bits integer.
     * @return random 64 bits integer
     */
    @ReactMethod
    public void getRandomLong(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            RandomNumberGeneratorImpl currentInstanceObj = this.javaObjects.get(sUid);

            long javaResult = currentInstanceObj.getRandomLong();
            Map<String, Long> result = new HashMap<String, Long>();
            result.put("value", javaResult);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     * Generates random byte.
     * @return random byte
     */
    @ReactMethod
    public void getRandomByte(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            RandomNumberGeneratorImpl currentInstanceObj = this.javaObjects.get(sUid);

            byte javaResult = currentInstanceObj.getRandomByte();
            Map<String, Byte> result = new HashMap<String, Byte>();
            result.put("value", javaResult);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
}
