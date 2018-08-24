// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http_client.djinni

package com.ledger.reactnative;

import co.ledger.core.Error;
import co.ledger.core.HttpReadBodyResult;
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

/**Structure representing Http response body */
public class RCTCoreHttpReadBodyResult extends ReactContextBaseJavaModule {
    private final ReactApplicationContext reactContext;
    private Map<String, HttpReadBodyResult> javaObjects;
    public Map<String, HttpReadBodyResult> getJavaObjects()
    {
        return javaObjects;
    }

    public RCTCoreHttpReadBodyResult(ReactApplicationContext reactContext)
    {
        super(reactContext);
        this.reactContext = reactContext;
        this.javaObjects = new HashMap<String, HttpReadBodyResult>();
    }

    @Override
    public String getName()
    {
        return "RCTCoreHttpReadBodyResult";
    }
    public void init(Optional<HashMap <String, String>> error, byte[] data, Promise promise) {
        RCTCoreError rctParam_error = this.reactContext.getNativeModule(RCTCoreError.class);
        Error javaParam_0 = rctParam_error.getJavaObjects().get(error.get().get("uid"));
        HttpReadBodyResult javaResult = new HttpReadBodyResult(javaParam_0, data);

        String uuid = UUID.randomUUID().toString();
        this.javaObjects.put(uuid, javaResult);
        Map<String, String> finalResult = new HashMap<String, String>();
        finalResult.put("type","RCTCoreHttpReadBodyResult");
        finalResult.put("uid",uuid);
        promise.resolve(finalResult);
    }
}
