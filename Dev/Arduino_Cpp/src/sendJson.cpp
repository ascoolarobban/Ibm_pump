//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "sendJson.h"
#include <ArduinoJson.h>
#include "pumpControl.h"
#include "runTime.h"
#include "sensorReadings.h"

//SERIAL NUMBER ARDUINO:
String SN = "8573432363035131A052";
// Speed
int fan_speed = 0;
int pump_speed= 0;
int old_pump_speed = 0;
int old_fan_speed = 0;
int valve_level = 0;



void send_json() {
    StaticJsonDocument<256> doc;
    JsonObject root = doc.to<JsonObject>();
    //root["Pump"] = "Pump1";
    JsonObject pump = root.createNestedObject("data");
    pump["drainValveState"] = drain_valve_state;
    pump["safetyValveState"] = safety_valve_state;
    pump["fanState"] = fan_state;
    pump["pumpState"] = pump_state;
    pump["fanSpeed"] = fan_speed;
    pump["pumpSpeed"] = pump_speed;
    pump["drainValveLevel"] = valve_level;
    pump["flowSensor1"] = flowSensor_1;
    pump["flowSensor2"] = flowSensor_2;
    pump["flowSensor3"] = flowSensor_3;
    pump["runtime"] = runTimeBuffer;
    pump["serialNumber"] = SN;
    serializeJson(root, Serial);
}