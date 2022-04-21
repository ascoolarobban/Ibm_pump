//
// Created by Robin Ellingsen on 2022-04-04.
//
#include <Arduino.h>
#include "debounce.h"
#include "pumpControl.h"
#include "buttonIsTriggered.h"

long debounceDelay = 600;
unsigned long buttonAStartMillis = 0;
unsigned long buttonBStartMillis = 0;
unsigned long buttonCStartMillis = 0;

void debounce() {
    if (trigger_A) {

        if ((millis() - buttonAStartMillis) > debounceDelay) {
            //if pumpstate is true, set to false and vice versa.
            if (pump_state ? pump_state = false : pump_state = true);

            //pumpControllerButton();//Functio in pumpOnOff.h
        }
        buttonAStartMillis = millis();
        trigger_A = false;
    }
    if (trigger_B) {
        if ((millis() - buttonBStartMillis) > debounceDelay) {
            //fanControllerButton();
            //if fanstate is true, set to false and vice versa.
            if (fan_state ? fan_state = false : fan_state = true);
        }
        buttonBStartMillis = millis();
        trigger_B = false;
    }
    if (trigger_C) {
        if ((millis() - buttonCStartMillis) > debounceDelay) {
            //valveControllerButton();
            //if drain_valve_state is true, set to false and vice versa.
            if (drain_valve_state ? drain_valve_state = false : drain_valve_state = true);
        }
        buttonCStartMillis = millis();
        trigger_C = false;
    }
}