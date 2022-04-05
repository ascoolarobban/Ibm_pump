//
// Created by Robin Ellingsen on 2022-04-05.
//


#include "convertToLitres.h"
#include <Arduino.h>

float Convert::convertToLitres(float inflow){
    this ->X = pulseIn(inflow, HIGH);
    this ->Y = pulseIn(inflow, LOW);
    this->TIME = X + Y;
    this->FREQUENCY = 1000000/this->TIME;
    this->WATER = this->FREQUENCY/7.5;
    this->LS = this->WATER/60;
    this->TOTAL = this->TOTAL + this->LS;
    return this-> TOTAL;
}
