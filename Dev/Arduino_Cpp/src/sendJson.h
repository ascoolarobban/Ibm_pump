//
// Created by Robin Ellingsen on 2022-04-04.
//

#ifndef ARDUINO_CPP_SENDJSON_H
#define ARDUINO_CPP_SENDJSON_H

#include "sensors.h"

extern int fan_speed ;
extern int pump_speed;
extern int old_pump_speed;
extern int old_fan_speed;
extern int valve_level;

void send_json(Sensor flowSensor1,Sensor flowSensor2,Sensor flowSensor3);

#endif //ARDUINO_CPP_SENDJSON_H
