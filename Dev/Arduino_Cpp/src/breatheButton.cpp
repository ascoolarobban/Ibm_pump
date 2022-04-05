//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "breatheButton.h"
#include <Arduino.h>
#include "pumpControl.h"
#include "buttonIsTriggered.h"


int A = 0;
int B = 0;
int C = 0;
int period = 500;
int delay_time = 5;
unsigned long time_now = 0;

void readButtons();
void pumpSerial();
bool idleState();
void setToZero();

void makeHigh(int a, int b, int c ) {
    analogWrite(buttonA_ledRing, a);  //pump led ring
    analogWrite(buttonB_ledRing, b);//fan led ring
    analogWrite(buttonC_ledRing, c); //Valve led ring

}
void makeHighBreathe(int x) {
    analogWrite(buttonA_ledRing, x);  //pump led ring
    analogWrite(buttonB_ledRing, x);//fan led ring
    analogWrite(buttonC_ledRing, x); //Valve led ring

}

void breathingLed() {

    for (int i = 0; i < 3; i++) {
        for (int i = 0; i < 200; i++) {
            readButtons();
            pumpSerial();
            A++;
            makeHighBreathe(A);
            if (idleState() != true) {
                setToZero();
                break;
            }
            delay(delay_time);
        }
        for (int i = 0; i < 200; i++) {
            readButtons();
            pumpSerial();
            A--;
            makeHighBreathe(A);
            if (idleState() != true) {
                setToZero();
                break;
            }
            delay(delay_time);
        }

    }

}
void setToZero() {
    A = 0;
    B = 0;
    C = 0;
    makeHigh(0, 0, 0);
}

void ledShow() {
    while (idleState() == true) {
        {
            for (int i = 0; i < 200; i++) {
                readButtons();
                pumpSerial();
                A++;
                makeHigh(A, B, C);
                delay(delay_time);
                if (idleState() != true) {
                    setToZero();
                    break;
                }
            }
            for (int i = 0; i < 200; i++) {
                readButtons();
                pumpSerial();
                A--;
                makeHigh(A, B, C);
                delay(delay_time);
                if (idleState() != true) {
                    setToZero();
                    break;
                }
            }
            for (int i = 0; i < 200; i++) {
                readButtons();
                pumpSerial();
                B++;
                makeHigh(A, B, C);
                delay(delay_time);
                if (idleState() != true) {
                    setToZero();
                    break;
                }
            }
            for (int i = 0; i < 200; i++) {
                readButtons();
                pumpSerial();
                B--;
                makeHigh(A, B, C);
                if (idleState() != true) {
                    setToZero();
                    break;
                }
                delay(delay_time);
            }
            for (int i = 0; i < 200; i++) {
                readButtons();
                pumpSerial();
                C++;
                makeHigh(A, B, C);

                delay(delay_time);
                if (idleState() != true) {
                    setToZero();
                    break;
                }

            }
        }
        for (int i = 0; i < 200; i++) {
            readButtons();
            pumpSerial();
            C--;
            makeHigh(A, B, C);
            delay(delay_time);
            if (idleState() != true) {
                setToZero();
                break;
            }
        }
        if (idleState() != true) {
            setToZero();
            break;
        }


        breathingLed();

    }


}








bool idleState() {
    if (trigger_A == false && trigger_B == false && trigger_C == false && pump_state == false && fan_state == false && drain_valve_state == false) {
        return true;
    }
    else {
        return false;
    }
}