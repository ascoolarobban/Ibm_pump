//
// Created by Robin Ellingsen on 2022-04-04.
//

#ifndef ARDUINO_CPP_SENSORREADINGS_H
#define ARDUINO_CPP_SENSORREADINGS_H
#define DHTTYPE DHT11
#define DHTPIN A0

extern int temp;
extern int flowSensor_1;
extern int flowSensor_2;
extern int flowSensor_3;
extern float lastHumidity;
extern float lastTemperature;

extern float humidity;
extern float temperature;

//SENSORS
extern int temp;
extern int flowSensor_1;
extern int flowSensor_2;
extern int flowSensor_3;

extern int last_flowSensor_1;
extern int last_flowSensor_2;
extern int last_flowSensor_3;


extern int lastTemp;
extern int lastFlow;


#endif //ARDUINO_CPP_SENSORREADINGS_H
