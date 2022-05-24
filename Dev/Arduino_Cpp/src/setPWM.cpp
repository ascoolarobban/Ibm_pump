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
    //using the servo library to determine what pin the servo is attached to
    servo.attach(drain_valve_pwm_pin);

    switch (x) {
        //if setPWM recieves an A, the pump PWM is controlled
        case 'A':
            analogWrite(pump_pwm_pin, PWM);
            pump_speed = PWM;
            break;
        //B for FAN
        case 'B':
            Serial.println(PWM);
            analogWrite(fan_pwm_pin, PWM);
            fan_speed = PWM;

            break;
        //C for servo, pwm in this case will be 0 for closed and 100 for fully open.
        //its not completely stepless but functionally stepless...
        case 'C':
            servo.write(PWM);
            //analogWrite(drain_valve_pwm_pin, PWM);
            valve_level = PWM;
            break;
    }
}