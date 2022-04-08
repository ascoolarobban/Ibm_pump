//
// Created by Robin Ellingsen on 2022-04-04.
//

#ifndef ARDUINO_CPP_PUMPCONTROL_H
#define ARDUINO_CPP_PUMPCONTROL_H

#include <Arduino.h>
extern int pumpPin;
extern int buttonA_ledRing;  //pump led ring
extern int buttonB_ledRing; //fan led ring
extern int buttonC_ledRing; //Valve led ring
extern int fan_relay;
extern int drain_valve_pwm_pin;
extern int safety_valve_relay;
extern bool pump_state;
extern bool fan_state;
extern bool drain_valve_state;
extern bool safety_valve_state;

extern bool last_pump_state;
extern bool last_fan_state;
extern bool last_drain_valve_state;

void safetyValveOFF();
void safetyValveON();
void pumpON();
void pumpOFF();
void fanON();
void fanOFF();
void drainValveOpen();
void drainValveClosed();
void pumpcontroller(bool command);
void fancontroller(bool command);
void valvecontroller(bool command);
void valveControllerButton();
void fanControllerButton();
void pumpControllerButton();



#endif //ARDUINO_CPP_PUMPCONTROL_H
// Created by Robin Ellingsen on 2022-04-04.
//