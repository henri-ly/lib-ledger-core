// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from preferences.djinni

package com.ledger.reactnative;

import PreferencesEditor;
import RCTCorePreferencesEditor;
import co.ledger.core.PreferencesEditor;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import java.util.ArrayList;
import java.util.UUID;;

/** Interface for editting Preferences. All changes to the editor are persisted to the disk only when comitted. */
public class RCTCorePreferencesEditor extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;
    private Map<String, PreferencesEditor> javaObjects;

    public RNLedgerCoreModule(ReactApplicationContext reactContext)
    {
        super(reactContext);
        this.reactContext = reactContext;
        this.javaObjects = new HashMap<String, PreferencesEditor>();
    }

    @Override
    public String getName()
    {
        return "RCTCorePreferencesEditor";
    }

    /**
     * Sets the value to the given key in the Preferences.
     * @param key The data key.
     * @param value The value to store
     * @return The reference of self in order to chain the call to the editor.
     */
    @ReactMethod
    public void putString(Map<String, String> currentInstance, String key, String value, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            PreferencesEditor currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCorePreferencesEditor instance passed to putString method");
            }

            PreferencesEditor javaResult = currentInstanceObj.putString(key, value);

            String uuid = UUID.randomUUID().toString();
            RCTCorePreferencesEditor rctImpl_objcResult = (RCTCorePreferencesEditor)self.bridge moduleForName("RCTCorePreferencesEditor");
            rctImpl_objcResult.javaObjects.put(uuid, objcResult);
            Map<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCorePreferencesEditor");
            result.put("uid",uuid);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCorePreferencesEditor::putString : Failed to return PreferencesEditor from putString method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     * Sets the value to the given key in the Preferences.
     * @param key The data key.
     * @param value The value to store
     * @return The reference of self in order to chain the call to the editor.
     */
    @ReactMethod
    public void putInt(Map<String, String> currentInstance, String key, int value, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            PreferencesEditor currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCorePreferencesEditor instance passed to putInt method");
            }

            PreferencesEditor javaResult = currentInstanceObj.putInt(key, value);

            String uuid = UUID.randomUUID().toString();
            RCTCorePreferencesEditor rctImpl_objcResult = (RCTCorePreferencesEditor)self.bridge moduleForName("RCTCorePreferencesEditor");
            rctImpl_objcResult.javaObjects.put(uuid, objcResult);
            Map<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCorePreferencesEditor");
            result.put("uid",uuid);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCorePreferencesEditor::putInt : Failed to return PreferencesEditor from putInt method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     * Sets the value to the given key in the Preferences.
     * @param key The data key.
     * @param value The value to store
     * @return The reference of self in order to chain the call to the editor.
     */
    @ReactMethod
    public void putLong(Map<String, String> currentInstance, String key, long value, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            PreferencesEditor currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCorePreferencesEditor instance passed to putLong method");
            }

            PreferencesEditor javaResult = currentInstanceObj.putLong(key, value);

            String uuid = UUID.randomUUID().toString();
            RCTCorePreferencesEditor rctImpl_objcResult = (RCTCorePreferencesEditor)self.bridge moduleForName("RCTCorePreferencesEditor");
            rctImpl_objcResult.javaObjects.put(uuid, objcResult);
            Map<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCorePreferencesEditor");
            result.put("uid",uuid);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCorePreferencesEditor::putLong : Failed to return PreferencesEditor from putLong method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     * Sets the value to the given key in the Preferences.
     * @param key The data key.
     * @param value The value to store
     * @return The reference of self in order to chain the call to the editor.
     */
    @ReactMethod
    public void putBoolean(Map<String, String> currentInstance, String key, boolean value, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            PreferencesEditor currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCorePreferencesEditor instance passed to putBoolean method");
            }

            PreferencesEditor javaResult = currentInstanceObj.putBoolean(key, value);

            String uuid = UUID.randomUUID().toString();
            RCTCorePreferencesEditor rctImpl_objcResult = (RCTCorePreferencesEditor)self.bridge moduleForName("RCTCorePreferencesEditor");
            rctImpl_objcResult.javaObjects.put(uuid, objcResult);
            Map<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCorePreferencesEditor");
            result.put("uid",uuid);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCorePreferencesEditor::putBoolean : Failed to return PreferencesEditor from putBoolean method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     * Sets the value to the given key in the Preferences.
     * @param key The data key.
     * @param value The value to store
     * @return The reference of self in order to chain the call to the editor.
     */
    @ReactMethod
    public void putStringArray(Map<String, String> currentInstance, String key, ArrayList<String> value, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            PreferencesEditor currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCorePreferencesEditor instance passed to putStringArray method");
            }

            PreferencesEditor javaResult = currentInstanceObj.putStringArray(key, value);

            String uuid = UUID.randomUUID().toString();
            RCTCorePreferencesEditor rctImpl_objcResult = (RCTCorePreferencesEditor)self.bridge moduleForName("RCTCorePreferencesEditor");
            rctImpl_objcResult.javaObjects.put(uuid, objcResult);
            Map<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCorePreferencesEditor");
            result.put("uid",uuid);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCorePreferencesEditor::putStringArray : Failed to return PreferencesEditor from putStringArray method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     * Sets the value to the given key in the Preferences.
     * @param key The data key.
     * @param value The value to store
     * @return The reference of self in order to chain the call to the editor.
     */
    @ReactMethod
    public void putData(Map<String, String> currentInstance, String key, byte[] value, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            PreferencesEditor currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCorePreferencesEditor instance passed to putData method");
            }

            PreferencesEditor javaResult = currentInstanceObj.putData(key, value);

            String uuid = UUID.randomUUID().toString();
            RCTCorePreferencesEditor rctImpl_objcResult = (RCTCorePreferencesEditor)self.bridge moduleForName("RCTCorePreferencesEditor");
            rctImpl_objcResult.javaObjects.put(uuid, objcResult);
            Map<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCorePreferencesEditor");
            result.put("uid",uuid);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCorePreferencesEditor::putData : Failed to return PreferencesEditor from putData method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     * Removes the data associated with the given key.
     * @param key The key to remove from the Preferences
     * @return The reference of self in order to chain the call to the editor.
     */
    @ReactMethod
    public void remove(Map<String, String> currentInstance, String key, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            PreferencesEditor currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCorePreferencesEditor instance passed to remove method");
            }

            PreferencesEditor javaResult = currentInstanceObj.remove(key);

            String uuid = UUID.randomUUID().toString();
            RCTCorePreferencesEditor rctImpl_objcResult = (RCTCorePreferencesEditor)self.bridge moduleForName("RCTCorePreferencesEditor");
            rctImpl_objcResult.javaObjects.put(uuid, objcResult);
            Map<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCorePreferencesEditor");
            result.put("uid",uuid);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCorePreferencesEditor::remove : Failed to return PreferencesEditor from remove method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /** Persists the changes to the Preferences. */
    @ReactMethod
    public void commit(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            PreferencesEditor currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCorePreferencesEditor instance passed to commit method");
            }

            currentInstanceObj.commit();
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
}
