//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "readButtons.h"
#include "buttonLED.h"
#include "buttonIsTriggered.h"
#include <Arduino.h>

void readButtons() {
    if (digitalRead(button_A) == HIGH) {
        buttonAIsTriggered();
    }
    if (digitalRead(button_B) == HIGH) {

        buttonBIsTriggered();
    }
    if (digitalRead(button_C) == HIGH) {

        buttonCIsTriggered();
    }
    /*else if (digitalRead(button_A) == LOW && digitalRead(button_B) == LOW && digitalRead(button_C) == LOW){
      ledShow();
      }*/

}