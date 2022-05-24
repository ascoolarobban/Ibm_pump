//
// Created by Robin Ellingsen on 2022-04-04.
//

#ifndef ARDUINO_CPP_READPOTENTIOMETERS_H
#define ARDUINO_CPP_READPOTENTIOMETERS_H

#define potPin1 A3
#define potPin2 A4
#define potPin3 A5

extern int pot_1;
extern int pot_2;
extern int pot_3;
extern int new_pot_1;
extern int new_pot_2;
extern int new_pot_3;

extern bool pot_1_change;
extern bool pot_2_change;
extern bool pot_3_change;
int readPotentiometers();

#endif //ARDUINO_CPP_READPOTENTIOMETERS_H
