//
// Created by Robin Ellingsen on 2022-04-05.
//

#include "readSensors.h"
#include <Arduino.h>
#include "sensors.h"
#include "convertToLitres.h"


float flowSensor_1 = random(5, 200);
float flowSensor_2 = random(5, 200);
float flowSensor_3 = random(5, 200);

int last_flowSensor_1 = 0;
int last_flowSensor_2 = 0;
int last_flowSensor_3 = 0;
float f1;
float f2;
float f3;
Convert s1;
Convert s2;
Convert s3;



void readSensors (Sensor &flowSensor1,Sensor &flowSensor2,Sensor &flowSensor3){
    f1 = analogRead(flowSensor1_pin);
    f2 = analogRead(flowSensor2_pin);
    f3 = analogRead(flowSensor3_pin);
    //Sends the flow value to sensor class to set new value.
    flowSensor1.setFlowSensorValue(f1);
    flowSensor2.setFlowSensorValue(f2);
    flowSensor3.setFlowSensorValue(f3);

    //this works but is unnecessary because of node red conversion.
    /*flowSensor2.setFlowSensorValue(s2.convertToLitres(f2));
    flowSensor3.setFlowSensorValue(s3.convertToLitres(f3));*/




}

