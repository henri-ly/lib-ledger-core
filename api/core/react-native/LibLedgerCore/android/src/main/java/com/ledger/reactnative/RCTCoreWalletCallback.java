// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

package com.ledger.reactnative;

import co.ledger.core.Error;
import co.ledger.core.Wallet;
import co.ledger.core.WalletCallback;
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

/**
 *Callback triggered by main completed task,
 *returns optional result of template type T
 */
public class RCTCoreWalletCallback extends WalletCallback {
    public Promise promise;
    public ReactContext reactContext;
    public static RCTCoreWalletCallback initWithPromise(Promise promise, ReactContext reactContext)
    {
        RCTCoreWalletCallback callback = new RCTCoreWalletCallback();
        callback.promise = promise;
        callback.reactContext = reactContext;
        return callback;
    }
    /**
     * Method triggered when main task complete
     * @params result optional of type T, non null if main task failed
     * @params error optional of type Error, non null if main task succeeded
     */
    public void onCallback(Wallet result, Error error) {
        try
        {
            if (error.getMessage().length() > 0)
            {
                this.promise.reject(error.toString(), error.getMessage());
            }
            String uuid = UUID.randomUUID().toString();
            RCTCoreWallet rctImpl_result = this.reactContext.getNativeModule(RCTCoreWallet.class);
            rctImpl_result.getJavaObjects().put(uuid, result);
            HashMap<String, String> converted_result = new HashMap<String, String>();
            converted_result.put("type","RCTCoreWallet");
            converted_result.put("uid",uuid);

            this.promise.resolve(converted_result);
        }
        catch(Exception e)
        {
            this.promise.reject(e.toString(), e.getMessage());
        }
    }
}
