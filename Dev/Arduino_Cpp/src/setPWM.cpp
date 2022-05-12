//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "setPWM.h"
#include <Arduino.h>
#include "sendJson.h"
#include "pumpControl.h"
#include <Servo.h>

int pump_pwm_pin =  3;
int fan_pwm_pin = 10;
Servo servo;


void setPWM(char x, int PWM) {
    servo.attach(drain_valve_pwm_pin);

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
            servo.write(PWM);
            //analogWrite(drain_valve_pwm_pin, PWM);
            Serial.println(PWM);
            valve_level = PWM;
            break;
    }
}