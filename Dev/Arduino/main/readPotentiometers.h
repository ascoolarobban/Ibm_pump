#define potPin1 A3
#define potPin2 A4
#define potPin3 A5
#include "setPWM.h"
int new_pot_1 = 0;
int new_pot_2 = 0;
int new_pot_3 = 0;

bool pot_1_change = false;
bool pot_2_change = false;
bool pot_3_change = false;

int readPotentiometers() {
  new_pot_1 = map(analogRead(potPin1), 200, 1000, 0, 255);
  new_pot_1 = constrain(new_pot_1, 0, 255);

  new_pot_2 = map(analogRead(potPin2), 200, 1000, 0, 255);
  new_pot_2 = constrain(new_pot_2, 0, 255);

  new_pot_3 = map(analogRead(potPin3), 150, 1000, 0, 255);
  new_pot_3 = constrain(new_pot_3, 0, 255);

  if (new_pot_1 < (pot_1 - 10) || new_pot_1 > (pot_1 + 10)) {
    setPWM('A', new_pot_1);
    pot_1 = new_pot_1;
    pot_1_change = true;

  }

  if (new_pot_2 < (pot_2 - 10) || new_pot_2 > (pot_2 + 10)) {
    setPWM('B', new_pot_2);
    pot_2 = new_pot_2;
    pot_2_change = true;
  }

  else if (new_pot_3 < (pot_3 - 10) || new_pot_3 > (pot_3 + 10)) {
    setPWM('C', new_pot_3);
    pot_3 = new_pot_3;
    pot_3_change = true;

  }

}
