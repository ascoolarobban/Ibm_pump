//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "sendJson.h"
#include <ArduinoJson.h>
#include "pumpControl.h"
#include "runTime.h"
#include "sensors.h"
#include "readSensors.h"

//SERIAL NUMBER ARDUINO: (its actually real!)
String SN = "8573432363035131A052";
// Speed
int fan_speed = 0;
int pump_speed= 0;
int old_pump_speed = 0;
int old_fan_speed = 0;
int valve_level = 0;



void send_json(Sensor flowSensor1,Sensor flowSensor2,Sensor flowSensor3) {
    //Uses jSon6 to nicely send json as a serial print..
    //Rest of the data such as id and location is set in node red.
    StaticJsonDocument<500> doc;
    JsonObject root = doc.to<JsonObject>();
    JsonObject pump = root.createNestedObject("data");
    pump["drainValveState"] = drain_valve_state;
    pump["safetyValveState"] = safety_valve_state;
    pump["fanState"] = fan_state;
    pump["pumpState"] = pump_state;
    pump["fanSpeed"] = fan_speed;
    pump["pumpSpeed"] = pump_speed;
    pump["drainValveLevel"] = valve_level;
    pump["flowSensor1"] = flowSensor1.getFlowSensorValue();
    pump["flowSensor2"] = flowSensor2.getFlowSensorValue();
    pump["flowSensor3"] = flowSensor3.getFlowSensorValue();
    pump["runtime"] = runTimeBuffer;
    pump["serialNumber"] = SN;
    serializeJson(root, Serial);


}
