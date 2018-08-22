// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

package com.ledger.reactnative;

import AccountListCallbackImpl;
import RCTCoreAccount;
import RCTCoreError;
import co.ledger.core.Account;
import co.ledger.core.Error;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import java.util.ArrayList;
import java.util.UUID;;

/**
 *Callback triggered by main completed task,
 *returns optional result as list of template type T
 */
public class RCTCoreAccountListCallback extends AccountListCallback {
    public Promise promise;
    public Bridge bridge;
    public static RCTCoreAccountListCallback initWithPromise(Promise promise, (RCTBridge *) bridge)
    {
        RCTCoreAccountListCallback callback = new RCTCoreAccountListCallback();
        if(callback)
        {
            callback.promise = promise;
            callback.bridge = bridge;
        }
        return callback;
    }
    /**
     * Method triggered when main task complete
     * @params result optional of type list<T>, non null if main task failed
     * @params error optional of type Error, non null if main task succeeded
     */
    public void onCallback(ArrayList<Account> result, Error error, ) {
        try
        {
            if (error)
            {
                self.promise.reject(ERROR, error.message);
            }
            ArrayList<HashMap <String, String>> converted_result = new ArrayList<HashMap <String, String>>();
            for (HashMap <String, String> result_elem : result)
            {
                String uuid = UUID.randomUUID().toString();
                RCTCoreAccount rctImpl_result_elem = (RCTCoreAccount)self.bridge moduleForName("RCTCoreAccount");
                rctImpl_result_elem.javaObjects.put(uuid, result_elem);
                Map<String, String> converted_result_elem = new HashMap<String, String>();
                converted_result_elem.put("type","RCTCoreAccount");
                converted_result_elem.put("uid",uuid);
                converted_result.add(converted_result_elem);
            }

            self.promise.resolve(converted_result);
        }
        catch(Exception e)
        {
            self.promise.reject(ERROR, e);
        }
    }
}
