// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from emitter.djinni

package com.ledger.reactnative;

import EventPublisher;
import RCTCoreEvent;
import RCTCoreEventBus;
import RCTCoreEventPublisher;
import RCTCoreExecutionContext;
import co.ledger.core.Event;
import co.ledger.core.EventBus;
import co.ledger.core.EventPublisher;
import co.ledger.core.ExecutionContext;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import java.util.UUID;;

/**Class representing an event publisher */
public class RCTCoreEventPublisher extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;
    private Map<String, EventPublisher> javaObjects;

    public RNLedgerCoreModule(ReactApplicationContext reactContext)
    {
        super(reactContext);
        this.reactContext = reactContext;
        this.javaObjects = new HashMap<String, EventPublisher>();
    }

    @Override
    public String getName()
    {
        return "RCTCoreEventPublisher";
    }

    /**
     *Get event bus through which publisher broadcast its events
     *@return EventBus object
     */
    @ReactMethod
    public void getEventBus(Map<String, String> currentInstance, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            EventPublisher currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreEventPublisher instance passed to getEventBus method");
            }

            EventBus javaResult = currentInstanceObj.getEventBus();

            String uuid = UUID.randomUUID().toString();
            RCTCoreEventBus rctImpl_objcResult = (RCTCoreEventBus)self.bridge moduleForName("RCTCoreEventBus");
            rctImpl_objcResult.javaObjects.put(uuid, objcResult);
            Map<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCoreEventBus");
            result.put("uid",uuid);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCoreEventPublisher::getEventBus : Failed to return EventBus from getEventBus method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     *Broadcast an event through eventbus (to all subscribed receivers to this EventBus)
     *@param event, Event object
     */
    @ReactMethod
    public void post(Map<String, String> currentInstance, HashMap <String, String> event, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            EventPublisher currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreEventPublisher instance passed to post method");
            }

            RCTCoreEvent rctParam_event = (RCTCoreEvent)self.bridge.moduleForName("RCTCoreEvent");
            Event javaParam_0 = (Event)rctParam_event.javaObjects.get(event.get("uid"));
            currentInstanceObj.post(javaParam_0);
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     *Same as post method but with an sticky event
     *@param event, Event object
     *@param tag, 32 bits integer, tag of sticky event
     */
    @ReactMethod
    public void postSticky(Map<String, String> currentInstance, HashMap <String, String> event, int tag, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            EventPublisher currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreEventPublisher instance passed to postSticky method");
            }

            RCTCoreEvent rctParam_event = (RCTCoreEvent)self.bridge.moduleForName("RCTCoreEvent");
            Event javaParam_0 = (Event)rctParam_event.javaObjects.get(event.get("uid"));
            currentInstanceObj.postSticky(javaParam_0, tag);
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     *Relay an event to another EventBus (other than EventPublisher's event bus)
     *@param bus, EventBus object, through which we want to broadcast EventPublisher's event to EventPublisher's receiver
     */
    @ReactMethod
    public void relay(Map<String, String> currentInstance, HashMap <String, String> bus, Promise promise) {
        try
        {
            String sUid = currentInstance.get("uid");
            String sType = currentInstance.get("type");

            EventPublisher currentInstanceObj = self.javaObjects.get("uid");
            if (!javaObj)
            {
                throw new Exception("Wrong RCTCoreEventPublisher instance passed to relay method");
            }

            RCTCoreEventBus rctParam_bus = (RCTCoreEventBus)self.bridge.moduleForName("RCTCoreEventBus");
            EventBus javaParam_0 = (EventBus)rctParam_bus.javaObjects.get(bus.get("uid"));
            currentInstanceObj.relay(javaParam_0);
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
    /**
     *Create a new instance of EventPublisher class
     *@param context, executionContext object, context in which event publisher broadcast its events
     */
    @ReactMethod
    public void newInstance(Map<String, String> currentInstance, HashMap <String, String> context, Promise promise) {
        try
        {
            EventPublisher javaResult = EventPublisher.newInstance(javaParam_0);

            String uuid = UUID.randomUUID().toString();
            RCTCoreEventPublisher rctImpl_objcResult = (RCTCoreEventPublisher)self.bridge moduleForName("RCTCoreEventPublisher");
            rctImpl_objcResult.javaObjects.put(uuid, objcResult);
            Map<String, String> result = new HashMap<String, String>();
            result.put("type","RCTCoreEventPublisher");
            result.put("uid",uuid);

            if(result)
            {
                promise.resolve(result);
            }
            else
            {
                throw new Exception("RCTCoreEventPublisher::newInstance : Failed to return EventPublisher from newInstance method");
            }
        }
        catch(Exception e)
        {
            promise.reject(ERROR, e);
        }
    }
}
