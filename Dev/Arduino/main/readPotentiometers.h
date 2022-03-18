#define potPin1 A3
#define potPin2 A4
#define potPin3 A5
#include "setPWM.h"
int new_pot_1 = 0;
int new_pot_2 = 0;
int new_pot_3 = 0;

int readPotentiometers() {
  new_pot_1 = map(analogRead(potPin1), 200, 1000, 0, 255);
  new_pot_1 = constrain(new_pot_1, 0, 255);

  new_pot_2 = map(analogRead(potPin2), 200, 1000, 0, 255);
  new_pot_2 = constrain(new_pot_2, 0, 255);

  new_pot_3 = map(analogRead(potPin3), 150, 1000, 0, 255);
  new_pot_3 = constrain(new_pot_3, 0, 255);

  if (pump_state == true) {
    //analogWrite(drain_valve, new_pot_3);
    setPWM('A', new_pot_1);
    pot_1 = new_pot_1;
  }


  if (fan_state == true) {
    //analogWrite(drain_valve, new_pot_3);
    setPWM('B', new_pot_2);
    pot_2 = new_pot_2;
  }

  if (drain_valve_state == true) {
    //analogWrite(drain_valve, new_pot_3);
    setPWM('C', new_pot_3);
    pot_3 = new_pot_3;
  }

}
