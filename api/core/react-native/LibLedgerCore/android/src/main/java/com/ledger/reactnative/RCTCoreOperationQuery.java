// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

package com.ledger.reactnative;

import co.ledger.core.OperationListCallback;
import co.ledger.core.OperationOrderKey;
import co.ledger.core.OperationQuery;
import co.ledger.core.QueryFilter;
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

/**Class respresenting a query for a set of operations */
public class RCTCoreOperationQuery extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;
    private Map<String, OperationQuery> javaObjects;
    public Map<String, OperationQuery> getJavaObjects()
    {
        return javaObjects;
    }

    public RCTCoreOperationQuery(ReactApplicationContext reactContext)
    {
        super(reactContext);
        this.reactContext = reactContext;
        this.javaObjects = new HashMap<String, OperationQuery>();
    }

    @Override
    public String getName()
    {
        return "RCTCoreOperationQuery";
    }

    /**
     *Apply given order to query's operation
     *@param key, OperationOrderKey object which defines order
     *@param descending, bool
     *@return OperationQuery object, new ordered operation
     */
    @ReactMethod
    public void addOrder(Map<String, String> currentInstance, OperationOrderKey key, boolean descending, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            OperationQuery currentInstanceObj = this.javaObjects.get(sUid);

            OperationQuery javaResult = currentInstanceObj.addOrder(key, descending);

            String uuid = UUID.randomUUID().toString();
            RCTCoreOperationQuery rctImpl_javaResult = this.reactContext.getNativeModule(RCTCoreOperationQuery.class);
            rctImpl_javaResult.getJavaObjects().put(uuid, javaResult);
            HashMap<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCoreOperationQuery");
            result.put("uid",uuid);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     *Get applied filter on operation query
     *@return QueryFilter object
     */
    @ReactMethod
    public void filter(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            OperationQuery currentInstanceObj = this.javaObjects.get(sUid);

            QueryFilter javaResult = currentInstanceObj.filter();

            String uuid = UUID.randomUUID().toString();
            RCTCoreQueryFilter rctImpl_javaResult = this.reactContext.getNativeModule(RCTCoreQueryFilter.class);
            rctImpl_javaResult.getJavaObjects().put(uuid, javaResult);
            HashMap<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCoreQueryFilter");
            result.put("uid",uuid);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     *Add offset to the operation query
     *@param from, 64 bits integer
     */
    @ReactMethod
    public void offset(Map<String, String> currentInstance, long from, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            OperationQuery currentInstanceObj = this.javaObjects.get(sUid);

            OperationQuery javaResult = currentInstanceObj.offset(from);

            String uuid = UUID.randomUUID().toString();
            RCTCoreOperationQuery rctImpl_javaResult = this.reactContext.getNativeModule(RCTCoreOperationQuery.class);
            rctImpl_javaResult.getJavaObjects().put(uuid, javaResult);
            HashMap<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCoreOperationQuery");
            result.put("uid",uuid);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     *Add limit to the operation query results
     *@param count, 64 bits integer
     */
    @ReactMethod
    public void limit(Map<String, String> currentInstance, long count, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            OperationQuery currentInstanceObj = this.javaObjects.get(sUid);

            OperationQuery javaResult = currentInstanceObj.limit(count);

            String uuid = UUID.randomUUID().toString();
            RCTCoreOperationQuery rctImpl_javaResult = this.reactContext.getNativeModule(RCTCoreOperationQuery.class);
            rctImpl_javaResult.getJavaObjects().put(uuid, javaResult);
            HashMap<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCoreOperationQuery");
            result.put("uid",uuid);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     *TODO
     *Complete the operation query
     */
    @ReactMethod
    public void complete(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            OperationQuery currentInstanceObj = this.javaObjects.get(sUid);

            OperationQuery javaResult = currentInstanceObj.complete();

            String uuid = UUID.randomUUID().toString();
            RCTCoreOperationQuery rctImpl_javaResult = this.reactContext.getNativeModule(RCTCoreOperationQuery.class);
            rctImpl_javaResult.getJavaObjects().put(uuid, javaResult);
            HashMap<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCoreOperationQuery");
            result.put("uid",uuid);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**TODO */
    @ReactMethod
    public void partial(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            OperationQuery currentInstanceObj = this.javaObjects.get(sUid);

            OperationQuery javaResult = currentInstanceObj.partial();

            String uuid = UUID.randomUUID().toString();
            RCTCoreOperationQuery rctImpl_javaResult = this.reactContext.getNativeModule(RCTCoreOperationQuery.class);
            rctImpl_javaResult.getJavaObjects().put(uuid, javaResult);
            HashMap<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCoreOperationQuery");
            result.put("uid",uuid);

            promise.resolve(result);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
    /**
     *Execute query to retrieve operations
     *@param callback, if execute method succeed, ListCallback object returning a List of Operation objects
     */
    @ReactMethod
    public void execute(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");

            OperationQuery currentInstanceObj = this.javaObjects.get(sUid);

            RCTCoreOperationListCallback javaParam_0 = RCTCoreOperationListCallback.initWithPromise(promise, this.reactContext);
            currentInstanceObj.execute(javaParam_0);
        }
        catch(Exception e)
        {
            promise.reject(e.toString(), e.getMessage());
        }
    }
}
