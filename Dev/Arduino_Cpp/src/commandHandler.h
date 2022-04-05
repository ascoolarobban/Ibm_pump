//
// Created by Robin Ellingsen on 2022-04-04.
//

#ifndef ARDUINO_CPP_COMMANDHANDLER_H
#define ARDUINO_CPP_COMMANDHANDLER_H
#include <Arduino.h>

void setPWM(char x, int PWM);
void commandHandler(char* comdata);
void setPot(String potVal);
#endif //ARDUINO_CPP_COMMANDHANDLER_H
