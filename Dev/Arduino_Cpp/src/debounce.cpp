//
// Created by Robin Ellingsen on 2022-04-04.
//
#include <Arduino.h>
#include "debounce.h"
#include "pumpControl.h"
#include "buttonIsTriggered.h"

long debounceDelay = 200;
unsigned long buttonAStartMillis = 0;
unsigned long buttonBStartMillis = 0;
unsigned long buttonCStartMillis = 0;

void debounce() {
    if (trigger_A) {

        if ((millis() - buttonAStartMillis) > debounceDelay) {
            pumpControllerButton();//Functio in pumpOnOff.h
        }
        buttonAStartMillis = millis();
        trigger_A = false;
    }
    if (trigger_B) {
        if ((millis() - buttonBStartMillis) > debounceDelay) {
            fanControllerButton();
        }
        buttonBStartMillis = millis();
        trigger_B = false;
    }
    if (trigger_C) {
        if ((millis() - buttonCStartMillis) > debounceDelay) {
            valveControllerButton();
        }
        buttonCStartMillis = millis();
        trigger_C = false;
    }
}