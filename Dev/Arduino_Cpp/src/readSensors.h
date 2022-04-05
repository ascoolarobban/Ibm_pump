//
// Created by Robin Ellingsen on 2022-04-05.
//

#ifndef ARDUINO_CPP_READSENSORS_H
#define ARDUINO_CPP_READSENSORS_H
#include "sensors.h"
#define flowSensor1_pin  A0
#define flowSensor2_pin  A1
#define flowSensor3_pin  A2

extern int flowSensor_1;
extern int flowSensor_2;
extern int flowSensor_3;

extern int last_flowSensor_1;
extern int last_flowSensor_2;
extern int last_flowSensor_3;





void readSensors (Sensor &flowSensor1,Sensor &flowSensor2,Sensor &flowSensor3);

#endif //ARDUINO_CPP_READSENSORS_H
