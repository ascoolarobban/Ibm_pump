#include "breatheButton.h"
#include "buttonIsTriggered.h"

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
