// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from configuration.djinni

package com.ledger.reactnative;

import KeychainEngines;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import java.util.UUID;;

public class RCTCoreKeychainEngines extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;
    private Map<String, KeychainEngines> javaObjects;

    public RNLedgerCoreModule(ReactApplicationContext reactContext)
    {
        super(reactContext);
        this.reactContext = reactContext;
        this.javaObjects = new HashMap<String, KeychainEngines>();
    }

    @Override
    public String getName()
    {
        return "RCTCoreKeychainEngines";
    }

}
