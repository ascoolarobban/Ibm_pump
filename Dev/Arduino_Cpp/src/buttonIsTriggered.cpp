//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "buttonIsTriggered.h"
bool trigger_A = false;
bool trigger_B = false;
bool trigger_C = false;
// Trigger switch.

//Cheks if the button is triggered, to later on be used by the debounce() function.
void buttonAIsTriggered() {
    trigger_A = true;

}

void buttonBIsTriggered() {
    trigger_B = true;
}

void buttonCIsTriggered() {
    trigger_C = true;
}