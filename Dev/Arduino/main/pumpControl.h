#define pumpPin 10
#define ledRing 4
#define buttonB_ledRing 8
#define valve 12
#include "warnings.h"

bool valve_state = false;
bool pump_state = false;

void valveON() {
  digitalWrite(valve, HIGH);
  valve_state = true;
  digitalWrite(buttonB_ledRing, HIGH);
  Serial.println("VALVE OPEN");
}
void pumpOFF() {
  digitalWrite(pumpPin, LOW);
  digitalWrite(ledRing, LOW);
  pump_state = false;
  Serial.println("PUMP:OFF");

}

void valveOFF() {
  digitalWrite(valve, LOW);
  valve_state = false;
  digitalWrite(buttonB_ledRing, LOW);
  Serial.println("VALVE CLOSED");
  pumpOFF();

}



void pumpON() {
  if (valve_state == true) {
    digitalWrite(pumpPin, HIGH);
    digitalWrite(ledRing, HIGH);
    pump_state = true;
    Serial.println("PUMP:ON");
  }
  else if (valve_state == false) {
    send_warning(warning(1));
  }

}



void pumpcontroller(char command) {

  if (command == 'A') {
    pumpON();

  }
  if (command == 'B') {
    pumpOFF();
  }

}

void valvecontroller(char command) {
  if (command == 'C') {
    valveON();

  }
  if (command == 'D') {
    valveOFF();
  }


}

void valveControllerButton() {
  if (valve_state == true) {
    valveOFF();
  }
  else {
    valveON();
  }
}
void pumpControllerButton() {
  if (pump_state == true) {
    pumpOFF();
  }
  else {
    pumpON();
  }
}
