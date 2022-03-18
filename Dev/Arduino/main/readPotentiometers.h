#define potPin1 A3
#define potPin2 A4
#define potPin3 A5
#include "setPWM.h"
int new_pot_1 = 0;
int new_pot_2 = 0;
int new_pot_3 = 0;

int readPotentiometers() {
  new_pot_3 = map(analogRead(potPin3), 180, 583, 0, 255);
  new_pot_3 = constrain(pot_3, 0, 255);

  if (drain_valve_state == true) {
    new_pot_3 = map(analogRead(potPin3), 100, 957, 0, 255);
    new_pot_3 = constrain(new_pot_3, 0, 255);
    pot_3 = new_pot_3;
    //analogWrite(drain_valve, new_pot_3);
    setPWM('C', new_pot_3);
  }

}
