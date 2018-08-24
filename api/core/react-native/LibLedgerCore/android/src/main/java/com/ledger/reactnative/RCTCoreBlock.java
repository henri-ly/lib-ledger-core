// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

package com.ledger.reactnative;

import co.ledger.core.Block;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Optional;
import java.util.UUID;

/**Structure of a block in the blockchain */
public class RCTCoreBlock extends ReactContextBaseJavaModule {
    private final ReactApplicationContext reactContext;
    private Map<String, Block> javaObjects;
    public Map<String, Block> getJavaObjects()
    {
        return javaObjects;
    }

    public RCTCoreBlock(ReactApplicationContext reactContext)
    {
        super(reactContext);
        this.reactContext = reactContext;
        this.javaObjects = new HashMap<String, Block>();
    }

    @Override
    public String getName()
    {
        return "RCTCoreBlock";
    }
    public void init(String blockHash, String uid, Date time, String currencyName, long height, Promise promise) {
        Block javaResult = new Block(blockHash, uid, time, currencyName, height);

        String uuid = UUID.randomUUID().toString();
        this.javaObjects.put(uuid, javaResult);
        Map<String, String> finalResult = new HashMap<String, String>();
        finalResult.put("type","RCTCoreBlock");
        finalResult.put("uid",uuid);
        promise.resolve(finalResult);
    }
}
