//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "sensors.h"
#include <Arduino.h>


//VARIABLES

/*float humidity = 62.0;
float temperature = 23.0;

int temp = random(5, 32);
int flowSensor_1 = random(5, 200);
int flowSensor_2 = random(5, 200);
int flowSensor_3 = random(5, 200);

int last_flowSensor_1 = 0;
int last_flowSensor_2 = 0;
int last_flowSensor_3 = 0;*/

void Sensor::setFlowSensorValue(float s){
    this -> flowSensor = s;
}

float Sensor::getFlowSensorValue() const {
    return this -> flowSensor;
}

void Sensor::setLastFlowSensorValue(float s) {
    this -> lastFlowSensor = s;
}
