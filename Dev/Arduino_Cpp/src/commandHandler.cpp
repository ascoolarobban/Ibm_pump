//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "commandHandler.h"
#include "pumpControl.h"
#include "Arduino.h"
#include "buttonLED.h"
#include "readPotentiometers.h"
void setPWM(char x, int PWM);
//Takes a char from readSerial() and switches the state to true,
//If the states are true the debounce will handle the switch.

void commandHandler(char* comdata) {
    Serial.println(comdata);
    switch (*comdata) {

        case 'A': // A Starts pump
                pump_state = true;
            //pumpControllerButton();
            break;

        case 'B':
                pump_state = false;
            //pumpControllerButton();
            break;

        case 'C':
                fan_state = true;
            //fanControllerButton();
            break;

        case 'D':
            fan_state = false;
            //fanControllerButton();
            break;

        case 'E':
            drain_valve_state = true;
           // valveControllerButton();
            break;

        case 'F':
            drain_valve_state = false;
            //valveControllerButton();
            break;
    }
}

void setPot(String potVal) {
    if (potVal.startsWith("POTA")) {
        int input = potVal.substring(4).toInt();
        if (input >= 1 && input < 256) {
            pot_1_change = true;
            setPWM('A',input);
        }

    }
    else if (potVal.startsWith("POTB")) {
        int input = potVal.substring(4).toInt();
        if (input >= 1 && input < 256) {
            pot_2_change = true;
            setPWM('B',input);
        }
    }
    else if (potVal.startsWith("POTC")) {
        int input = potVal.substring(4).toInt();
        if (input >= 1 && input < 256) {
            pot_3_change = true;
            setPWM('C',input);
        }
    }

}