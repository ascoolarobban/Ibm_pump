//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "sensors.h"
#include <Arduino.h>

//FLOW SENSOR GALLORE.
//sets the flowSensor value
void Sensor::setFlowSensorValue(float s){
    this -> flowSensor = s;
}
//Gets the flowSensor value
float Sensor::getFlowSensorValue() const {
    return this -> flowSensor;
}
//Sets last value so we know if the new value indicates a change. if its the same value the json wont be sent later on.
void Sensor::setLastFlowSensorValue(float s) {
    this -> lastFlowSensor = s;
}
