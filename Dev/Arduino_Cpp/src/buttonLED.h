
//
// Created by Robin Ellingsen on 2022-04-04.
//

#ifndef ARDUINO_CPP_BUTTONLED_H
#define ARDUINO_CPP_BUTTONLED_H

extern unsigned long delayTime;
extern unsigned long timeNow;
extern unsigned long previousMillis;

void readButtons();
void readSerialInput();
bool idleState();
void setLedsToZero();
void makeHigh(int a, int b, int c );
void makeHighBreathe(int x);
void breathingLed();
void ledShow();
bool idleState();
void killallLights();
#endif //ARDUINO_CPP_BUTTONLED_H