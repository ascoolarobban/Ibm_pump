//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "runTime.h"
#include <Arduino.h>

char runTimeBuffer[21];

unsigned long runTime() {
    unsigned long runMillis = millis();
    unsigned long allSeconds = millis() / 1000;
    int runHours = allSeconds / 3600;
    int secsRemaining = allSeconds % 3600;
    int runMinutes = secsRemaining / 60;
    int runSeconds = secsRemaining % 60;


    sprintf(reinterpret_cast<char *>(runTimeBuffer), "%02d:%02d:%02d", runHours, runMinutes, runSeconds);

}