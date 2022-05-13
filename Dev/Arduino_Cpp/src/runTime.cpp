//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "runTime.h"
#include <Arduino.h>

char runTimeBuffer[21];

unsigned long runTime() {
    //Counts how long the pump been awake and running for. Resets everytime the arduino is restarted.
    //Converts millis to human readable format.
    unsigned long runMillis = millis();
    unsigned long allSeconds = millis() / 1000;
    int runHours = allSeconds / 3600;
    int secsRemaining = allSeconds % 3600;
    int runMinutes = secsRemaining / 60;
    int runSeconds = secsRemaining % 60;

    //what a beauty..
    sprintf(reinterpret_cast<char *>(runTimeBuffer), "%02d:%02d:%02d", runHours, runMinutes, runSeconds);
    return 0;
}