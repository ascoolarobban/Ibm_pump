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

//lights everything up as much as the value thats passed to every led.
void makeHighs(int a, int b, int c ) {
    analogWrite(buttonA_ledRing, a);  //pump led ring
    analogWrite(buttonB_ledRing, b);//fan led ring
    analogWrite(buttonC_ledRing, c); //Valve led ring

}
//Pulsating light for all buttons
void makeHighBreathes(int x) {
    analogWrite(buttonA_ledRing, x);  //pump led ring
    analogWrite(buttonB_ledRing, x);//fan led ring
    analogWrite(buttonC_ledRing, x); //Valve led ring

}
//Loops from 0 up to 200 and back down again, making a "breathing" effect, much like old charging lamps on an older macbook pro
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




// The startup blink. blinks 3 times and then steps from left to right button led. its marvelous.
//there is a delay that is semi blocking but its for 5 milliseconds so it should be ok.
//but figure out a way to do it with millis would be optimal.
void welcomeBlink() {
    for (int i = 0; i < 3; i++) {
        for (int i = 0; i < 200; i++) {
            but1++;
            makeHighs(but1, but2, but3);
            //5 milliseconds delay for every loop otherwise the led will go wayyy to fast and just look like it turns on/off.
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
    //Back to the breathing led effect 3 times.*blink* *blink* *blink*
    breathingLeds();

}