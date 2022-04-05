//
// Created by Robin Ellingsen on 2022-04-05.
//

#include "readSensors.h"
#include <Arduino.h>
#include "sensors.h"
#include "convertToLitres.h"


int flowSensor_1 = 0;
int flowSensor_2 = random(5, 200);
int flowSensor_3 = random(5, 200);

int last_flowSensor_1 = 0;
int last_flowSensor_2 = 0;
int last_flowSensor_3 = 0;

Convert s1;
Convert s2;
Convert s3;

void readSensors (Sensor &flowSensor1,Sensor &flowSensor2,Sensor &flowSensor3){
    float f1 = analogRead(flowSensor1_pin);
    float f2 = analogRead(flowSensor2_pin);
    float f3 = analogRead(flowSensor3_pin);

    flowSensor1.setFlowSensorValue(s1.convertToLitres(f1));
    flowSensor2.setFlowSensorValue(s2.convertToLitres(f2));
    flowSensor3.setFlowSensorValue(s3.convertToLitres(f3));
}

