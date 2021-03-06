//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "buttonLED.h"
#include <Arduino.h>
#include "pumpControl.h"
#include "idleState.h"
#include "buttonIsTriggered.h"


int A = 0;
int B = 0;
int C = 0;
int period = 500;
int delay_time = 3;
unsigned long time_now = 0;

void readButtons();

void readSerialInput();

bool idleState();

void setLedsToZero();

void makeHigh(int a, int b, int c) {

    analogWrite(buttonA_ledRing, a);  //pump led ring
    analogWrite(buttonB_ledRing, b);//fan led ring
    analogWrite(buttonC_ledRing, c); //Valve led ring

}

void makeHighBreathe(int x) {
    analogWrite(buttonA_ledRing, x);  //pump led ring
    analogWrite(buttonB_ledRing, x);//fan led ring
    analogWrite(buttonC_ledRing, x); //Valve led ring

}

void ibmLed_A();
void ibmLed_B();
void ibmLed_M();

void ibmLightShow() {
    ibmLed_A();
    ibmLed_B();
    ibmLed_M();



}
void short_A();

void ibmLed_A(){
    short_A();
    short_A();
}
void short_A() {
    for (int i = 0; i < 200; i++) {
        readButtons();
        readSerialInput();
        A++;
        makeHigh(A, B, C);
        if (idleState() != true) {
            setLedsToZero();
            break;
        }
        delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
        readButtons();
        readSerialInput();
        A--;
        makeHigh(A, B, C);
        //makeHighBreathe(A);
        if (idleState() != true) {
            setLedsToZero();
            break;
        }
        delay(delay_time);
    }

}
void long_B(){
        for (int i = 0; i < 200; i++) {
            readButtons();
            readSerialInput();
            B++;
            makeHigh(A, B, C);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            delay(delay_time);
        }
        for (int x = 0; x < 500; x++) {
            readButtons();
            readSerialInput();
            makeHigh(A, 200, C);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            delay(delay_time);
        }


        for (int i = 0; i < 200; i++) {
            readButtons();
            readSerialInput();
            B--;
            makeHigh(A, B, C);
            //makeHighBreathe(A);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            delay(delay_time);
        }

}
void short_B() {
        for (int i = 0; i < 200; i++) {
            readButtons();
            B++;
            makeHigh(A, B, C);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            readSerialInput();
            delay(delay_time);
        }
        for (int i = 0; i < 200; i++) {
            readButtons();
            readSerialInput();
            B--;
            makeHigh(A, B, C);
            //makeHighBreathe(A);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            delay(delay_time);
        }

}

void ibmLed_B() {
    long_B();
    short_B();
    short_B();
    short_B();

    if (idleState() != true) {
        setLedsToZero();
    }

}
void long_M(){
        for (int i = 0; i < 200; i++) {
            readButtons();
            readSerialInput();
            C++;
            makeHigh(A, B, C);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            delay(delay_time);
        }
        for (int x = 0; x < 500; x++) {
            makeHigh(A, B, 200);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            delay(delay_time);
        }

        for (int i = 0; i < 200; i++) {
            readButtons();
            readSerialInput();
            C--;
            makeHigh(A, B, C);
            //makeHighBreathe(A);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            delay(delay_time);
        }

}

void ibmLed_M() {
        long_M();
        long_M();


    if (idleState() != true) {
        setLedsToZero();
    }

}
void setLedsToZero() {
    A = 0;
    B = 0;
    C = 0;
    makeHigh(0, 0, 0);
}
//IBM MORSE CODE BLINK
void ibmBlink() {}
//This is the breathing startup led effect.
//from 0 up to 200 with some delay, to make it fade in and out.
void ledShow() {

    for (int i = 0; i < 200; i++) {
        readButtons();
        readSerialInput();
        A++;
        makeHigh(A, B, C);
        if (idleState() != true) {
            setLedsToZero();
            break;
        }
        delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
        readButtons();
        readSerialInput();
        A--;
        makeHigh(A, B, C);
        if (idleState() != true) {
            setLedsToZero();
            break;
        }
        delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
        readButtons();
        readSerialInput();
        B++;
        makeHigh(A, B, C);
        if (idleState() != true) {
            setLedsToZero();
            break;
        }
        delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
        readButtons();
        readSerialInput();
        B--;
        makeHigh(A, B, C);
        if (idleState() != true) {
            setLedsToZero();
            break;
        }
        delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
        readButtons();
        readSerialInput();
        C++;
        makeHigh(A, B, C);

        if (idleState() != true) {
            setLedsToZero();
            break;
        }
        delay(delay_time);

    }


    for (int i = 0;i < 200; i++) {
        readButtons();
        readSerialInput();
        C--;
        makeHigh(A, B, C);
        if (idleState()!= true) {
            setLedsToZero();
            break;
        }
        delay(delay_time);
    }
    if (idleState() != true) {
        setLedsToZero();
    }
// breathingLed();

}

//If needed, a function to turn off the lights, not used yet, all button leds turns on and off when pushed.
void killallLights() {
    digitalWrite(buttonA_ledRing, LOW);
    digitalWrite(buttonB_ledRing, LOW);
    digitalWrite(buttonC_ledRing, LOW);
}



