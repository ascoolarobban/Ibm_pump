//
// Created by Robin Ellingsen on 2022-04-04.
//

#ifndef ARDUINO_CPP_BREATHEBUTTON_H
#define ARDUINO_CPP_BREATHEBUTTON_H
void readButtons();
void pumpSerial();
bool idleState();
void setToZero();
void makeHigh(int a, int b, int c );
void makeHighBreathe(int x);
void breathingLed();
void ledShow();
bool idleState();
#endif //ARDUINO_CPP_BREATHEBUTTON_H
