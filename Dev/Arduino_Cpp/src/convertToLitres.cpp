//
// Created by Robin Ellingsen on 2022-04-05.
//


#include "convertToLitres.h"
#include <Arduino.h>

float Convert::convertToLitres(float inflow){
    X = pulseIn(analogRead(0), HIGH);
    Y = pulseIn(analogRead(0), LOW);
    TIME = X + Y;
    FREQUENCY = 1000000/TIME;
    WATER = FREQUENCY/7.5;
    LS = WATER/60;
    TOTAL = TOTAL + LS;
    return TOTAL;
}
