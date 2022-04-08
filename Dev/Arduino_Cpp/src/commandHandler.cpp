//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "commandHandler.h"
#include "pumpControl.h"
#include "Arduino.h"
#include "buttonLED.h"
//Recieve command from serial, check what it should do:
void setPWM(char x, int PWM);

void commandHandler(char* comdata) {
    Serial.println("*******************");
    Serial.print("in commandHandler: ");
    Serial.println(comdata);
    Serial.println("*******************");
    switch (*comdata) {

        case 'A': // A Starts pump

            pumpControllerButton();
            break;

        case 'B':

            pumpControllerButton();
            break;

        case 'C':
                fan_state = true;
            //fanControllerButton();
            break;

        case 'D':

            fanControllerButton();
            break;

        case 'E':

            valveControllerButton();
            break;

        case 'F':

            valveControllerButton();
            break;
    }
}

void setPot(String potVal) {
    if (potVal.startsWith("POTA")) {
        int input = potVal.substring(4).toInt();
        if (input >= 1 && input < 256) {
            setPWM('A',input);
        }

    }
    else if (potVal.startsWith("POTB")) {
        int input = potVal.substring(4).toInt();
        if (input >= 1 && input < 256) {
            setPWM('B',input);
        }
    }
    else if (potVal.startsWith("POTC")) {
        int input = potVal.substring(4).toInt();
        if (input >= 1 && input < 256) {
            setPWM('C',input);
        }
    }

}