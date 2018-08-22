// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http_client.djinni

package com.ledger.reactnative;

import HttpUrlConnectionImpl;
import RCTCoreHttpReadBodyResult;
import co.ledger.core.HttpReadBodyResult;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import java.util.HashMap;
import java.util.UUID;;

/**Class representing an Http connection */
public class RCTCoreHttpUrlConnection extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;
    private Map<String, HttpUrlConnectionImpl> javaObjects;

    public RNLedgerCoreModule(ReactApplicationContext reactContext)
    {
        super(reactContext);
        this.reactContext = reactContext;
        this.javaObjects = new HashMap<String, HttpUrlConnectionImpl>();
    }

    @Override
    public String getName()
    {
        return "RCTCoreHttpUrlConnection";
    }

    /**
     * Gets the HTTP response status code
     * @return The HTTP response status code
     */
    @ReactMethod
    public void getStatusCode(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            HttpUrlConnectionImpl currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreHttpUrlConnection instance passed to getStatusCode method");
            }

            int javaResult = currentInstanceObj.getStatusCode();
            Map<String, int> result = new HashMap<String, int>();
            result.put("value", javaResult);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCoreHttpUrlConnection::getStatusCode : Failed to return int from getStatusCode method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     * Gets the HTTP response status text
     * @return The HTTP response status text
     */
    @ReactMethod
    public void getStatusText(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            HttpUrlConnectionImpl currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreHttpUrlConnection instance passed to getStatusText method");
            }

            String javaResult = currentInstanceObj.getStatusText();
            Map<String, String> result = new HashMap<String, String>();
            result.put("value", javaResult);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCoreHttpUrlConnection::getStatusText : Failed to return String from getStatusText method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     * Gets the HTTP response headers
     * @return The HTTP response headers
     */
    @ReactMethod
    public void getHeaders(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            HttpUrlConnectionImpl currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreHttpUrlConnection instance passed to getHeaders method");
            }

            HashMap<String, String> javaResult = currentInstanceObj.getHeaders();
            Map<String, HashMap<String, String>> result = new HashMap<String, HashMap<String, String>>();
            result.put("value", javaResult);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCoreHttpUrlConnection::getHeaders : Failed to return HashMap<String, String> from getHeaders method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     * Reads available HTTP response body. This method will be called multiple times until it returns a empty bytes array.
     * @returns A chunk of the body data wrapped into a HttpReadBodyResult (for error management)
     */
    @ReactMethod
    public void readBody(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            HttpUrlConnectionImpl currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreHttpUrlConnection instance passed to readBody method");
            }

            HttpReadBodyResult javaResult = currentInstanceObj.readBody();

            String uuid = UUID.randomUUID().toString();
            RCTCoreHttpReadBodyResult rctImpl_objcResult = (RCTCoreHttpReadBodyResult)self.bridge moduleForName("RCTCoreHttpReadBodyResult");
            rctImpl_objcResult.javaObjects.put(uuid, objcResult);
            Map<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCoreHttpReadBodyResult");
            result.put("uid",uuid);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCoreHttpUrlConnection::readBody : Failed to return HttpReadBodyResult from readBody method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
}
