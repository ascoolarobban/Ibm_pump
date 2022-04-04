//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "welcomeBlink.h"
#include <Arduino.h>
#include "pumpControl.h"
int but1 = 0;
int but2 = 0;
int but3 = 0;
long timeN = 0;
int waitPeriod = 10000;

float delaytime = 1;


void makeHighs(int a, int b, int c ) {
    analogWrite(buttonA_ledRing, a);  //pump led ring
    analogWrite(buttonB_ledRing, b);//fan led ring
    analogWrite(buttonC_ledRing, c); //Valve led ring

}
void makeHighBreathes(int x) {
    analogWrite(buttonA_ledRing, x);  //pump led ring
    analogWrite(buttonB_ledRing, x);//fan led ring
    analogWrite(buttonC_ledRing, x); //Valve led ring

}

void breathingLeds() {
    for (int i = 0; i < 200; i++) {
        but1++;
        makeHighBreathes(but1);
        delay(delaytime);
    }
    for (int i = 0; i < 200; i++) {
        but1--;
        makeHighBreathes(but1);
        delay(delaytime);
    }
    for (int i = 0; i < 200; i++) {
        but2++;
        makeHighBreathes(but2);
        delay(delaytime);
    }
    for (int i = 0; i < 200; i++) {
        but2--;
        makeHighBreathes(but2);
        delay(delaytime);
    }
    for (int i = 0; i < 200; i++) {
        but3++;
        makeHighBreathes(but3);
        delay(delaytime);
    }
    for (int i = 0; i < 200; i++) {
        but3--;
        makeHighBreathes(but3);
        delay(delaytime);
    }

}





void welcomeBlink() {
    for (int i = 0; i < 3; i++) {
        for (int i = 0; i < 200; i++) {
            but1++;
            makeHighs(but1, but2, but3);
            delay(delaytime);
        }
        for (int i = 0; i < 200; i++) {
            but1--;
            makeHighs(but1, but2, but3);
            delay(delaytime);
        }
        for (int i = 0; i < 200; i++) {
            but2++;
            makeHighs(but1, but2, but3);
            delay(delaytime);
        }
        for (int i = 0; i < 200; i++) {
            but2--;
            makeHighs(but1, but2, but3);
            delay(delaytime);
        }
        for (int i = 0; i < 200; i++) {
            but3++;
            makeHighs(but1, but2, but3);
            delay(delaytime);
        }
        for (int i = 0; i < 200; i++) {
            but3--;
            makeHighs(but1, but2, but3);
            delay(delaytime);
        }


    }

    breathingLeds();

}