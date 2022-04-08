//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "buttonLED.h"
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
void readSerialInput();
bool idleState();
void setLedsToZero();

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
            A++;
            makeHighBreathe(A);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            readSerialInput();
            delay(delay_time);
        }
        for (int i = 0; i < 200; i++) {
            readButtons();
            A--;
            makeHighBreathe(A);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            readSerialInput();
            delay(delay_time);
        }

    }

}
void setLedsToZero() {
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
                A++;
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
                A--;
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
                B--;
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
                C++;
                makeHigh(A, B, C);

                if (idleState() != true) {
                    setLedsToZero();
                    break;
                }
                readSerialInput();
                delay(delay_time);

            }
        }
        for (int i = 0; i < 200; i++) {
            readButtons();
            C--;
            makeHigh(A, B, C);
            if (idleState() != true) {
                setLedsToZero();
                break;
            }
            readSerialInput();
            delay(delay_time);
        }
        if (idleState() != true) {
            setLedsToZero();
            break;
        }


       // breathingLed();

    }


}


void killallLights(){
    digitalWrite(buttonA_ledRing,LOW);
    digitalWrite(buttonB_ledRing,LOW);
    digitalWrite(buttonC_ledRing,LOW);
}





bool idleState() {
    if (trigger_A == false &&
    trigger_B == false &&
    trigger_C == false &&
    pump_state == false &&
    fan_state == false &&
    drain_valve_state == false) {
        return true;
    }
    else {
        return false;
    }
}
