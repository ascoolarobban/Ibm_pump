//
// Created by Robin Ellingsen on 2022-04-04.
//

#ifndef ARDUINO_CPP_SETPWM_H
#define ARDUINO_CPP_SETPWM_H

#include "Servo.h"

extern int pump_pwm_pin;// 3
extern int fan_pwm_pin; // 10
extern Servo servo;
void setPWM(char x, int PWM);

#endif //ARDUINO_CPP_SETPWM_H
