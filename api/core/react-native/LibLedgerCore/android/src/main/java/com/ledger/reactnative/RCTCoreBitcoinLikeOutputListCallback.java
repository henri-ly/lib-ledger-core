// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

package com.ledger.reactnative;

import co.ledger.core.BitcoinLikeOutput;
import co.ledger.core.BitcoinLikeOutputListCallback;
import co.ledger.core.Error;
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
 *returns optional result as list of template type T
 */
public class RCTCoreBitcoinLikeOutputListCallback extends BitcoinLikeOutputListCallback {
    public Promise promise;
    public ReactContext reactContext;
    public static RCTCoreBitcoinLikeOutputListCallback initWithPromise(Promise promise, ReactContext reactContext)
    {
        RCTCoreBitcoinLikeOutputListCallback callback = new RCTCoreBitcoinLikeOutputListCallback();
        callback.promise = promise;
        callback.reactContext = reactContext;
        return callback;
    }
    /**
     * Method triggered when main task complete
     * @params result optional of type list<T>, non null if main task failed
     * @params error optional of type Error, non null if main task succeeded
     */
    public void onCallback(ArrayList<BitcoinLikeOutput> result, Error error) {
        try
        {
            if (error.getMessage().length() > 0)
            {
                this.promise.reject(error.toString(), error.getMessage());
            }
            ArrayList<HashMap <String, String>> converted_result = new ArrayList<HashMap <String, String>>();
            for (BitcoinLikeOutput result_elem : result)
            {
                String uuid = UUID.randomUUID().toString();
                RCTCoreBitcoinLikeOutput rctImpl_result_elem = this.reactContext.getNativeModule(RCTCoreBitcoinLikeOutput.class);
                rctImpl_result_elem.getJavaObjects().put(uuid, result_elem);
                HashMap<String, String> converted_result_elem = new HashMap<String, String>();
                converted_result_elem.put("type","RCTCoreBitcoinLikeOutput");
                converted_result_elem.put("uid",uuid);
                converted_result.add(converted_result_elem);
            }

            this.promise.resolve(converted_result);
        }
        catch(Exception e)
        {
            this.promise.reject(e.toString(), e.getMessage());
        }
    }
}
