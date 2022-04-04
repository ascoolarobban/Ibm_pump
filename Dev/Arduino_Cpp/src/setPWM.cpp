//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "setPWM.h"
#include <Arduino.h>
#include "sendJson.h"
#include "pumpControl.h"

int pump_pwm_pin =  3;
int fan_pwm_pin = 10;

void setPWM(char x, int PWM) {
    switch (x) {
        case 'A':
            analogWrite(pump_pwm_pin, PWM);
            pump_speed = PWM;
            break;

        case 'B':
            analogWrite(fan_pwm_pin, PWM);
            fan_speed = PWM;
            break;

        case 'C':
            analogWrite(drain_valve_pwm_pin, PWM);
            valve_level = PWM;
            break;
    }
}