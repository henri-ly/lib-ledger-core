// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

package com.ledger.reactnative;

import co.ledger.core.Currency;
import co.ledger.core.CurrencyListCallback;
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
public class RCTCoreCurrencyListCallback extends CurrencyListCallback {
    public Promise promise;
    public ReactContext reactContext;
    public static RCTCoreCurrencyListCallback initWithPromise(Promise promise, ReactContext reactContext)
    {
        RCTCoreCurrencyListCallback callback = new RCTCoreCurrencyListCallback();
        callback.promise = promise;
        callback.reactContext = reactContext;
        return callback;
    }
    /**
     * Method triggered when main task complete
     * @params result optional of type list<T>, non null if main task failed
     * @params error optional of type Error, non null if main task succeeded
     */
    public void onCallback(ArrayList<Currency> result, Error error) {
        try
        {
            if (error.getMessage().length() > 0)
            {
                this.promise.reject(error.toString(), error.getMessage());
            }
            ArrayList<HashMap <String, String>> converted_result = new ArrayList<HashMap <String, String>>();
            for (Currency result_elem : result)
            {
                String uuid = UUID.randomUUID().toString();
                RCTCoreCurrency rctImpl_result_elem = this.reactContext.getNativeModule(RCTCoreCurrency.class);
                rctImpl_result_elem.getJavaObjects().put(uuid, result_elem);
                HashMap<String, String> converted_result_elem = new HashMap<String, String>();
                converted_result_elem.put("type","RCTCoreCurrency");
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
