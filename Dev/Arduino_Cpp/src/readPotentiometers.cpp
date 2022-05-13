//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "readPotentiometers.h"
#include <Arduino.h>


#include "setPWM.h"
int new_pot_1 = 0;
int new_pot_2 = 0;
int new_pot_3 = 0;

bool pot_1_change = false;
bool pot_2_change = false;
bool pot_3_change = false;

int pot_1 = 0;
int pot_2 = 0;
int pot_3 = 0;

int readPotentiometers() {
    //Gets value from the potentiometers and maps it to new PWM value.
    //Had to put constrains because the mapping was not always right for some reason...Tech debt I guess.
    new_pot_1 = map(analogRead(potPin1), 200, 1000, 0, 255);
    new_pot_1 = constrain(new_pot_1, 0, 255);

    new_pot_2 = map(analogRead(potPin2), 200, 1000, 0, 255);
    new_pot_2 = constrain(new_pot_2, 0, 255);

    //This is the servo value, it goes from five because at zero it acts weird, 5 seem to be a good start. 100 is straight up aka fully opened.
    new_pot_3 = map(analogRead(potPin3), 150, 1000, 0, 90);
    new_pot_3 = constrain(new_pot_3, 5, 100);
//Difference between - + 10, otherwise the shitty hardwares sends signals constantly and it will flood the raspberry with jsons.
    if (new_pot_1 < (pot_1 - 10) || new_pot_1 > (pot_1 + 10)) {
        setPWM('A', new_pot_1);
        pot_1 = new_pot_1;
        pot_1_change = true;

    }
//Difference between - + 10, otherwise the shitty hardwares sends signals constantly and it will flood the raspberry with jsons.
    if (new_pot_2 < (pot_2 - 10) || new_pot_2 > (pot_2 + 10)) {
        setPWM('B', new_pot_2);
        pot_2 = new_pot_2;
        pot_2_change = true;
    }
//Difference between - + 3, otherwise the shitty hardwares sends signals constantly and it will flood the raspberry with jsons.
    else if (new_pot_3 < (pot_3 - 3) || new_pot_3 > (pot_3 + 3)) {
        setPWM('C', new_pot_3);
        pot_3 = new_pot_3;
        pot_3_change = true;

    }
    return 0;

}
