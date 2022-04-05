//
// Created by Robin Ellingsen on 2022-04-04.
//

#ifndef ARDUINO_CPP_SENSORS_H
#define ARDUINO_CPP_SENSORS_H
#define DHTTYPE DHT11
#define DHTPIN A0


//SENSORS
extern int flowSensor_1;
extern int flowSensor_2;
extern int flowSensor_3;
/*
extern int last_flowSensor_1;
extern int last_flowSensor_2;
extern int last_flowSensor_3;*/

class Sensor{
private:
    int flowSensor;
    int lastFlowSensor;
public:
    //SETTER
    void setFlowSensorValue(float s);
    void setLastFlowSensorValue(float s);
    //GETTER
    float getFlowSensorValue() const;
};



#endif //ARDUINO_CPP_SENSORS_H
