//
// Created by Robin Ellingsen on 2022-04-04.
//

#ifndef ARDUINO_CPP_SENDJSON_H
#define ARDUINO_CPP_SENDJSON_H

extern int fan_speed ;
extern int pump_speed;
extern int old_pump_speed;
extern int old_fan_speed;
extern int valve_level;

void send_json();

#endif //ARDUINO_CPP_SENDJSON_H
