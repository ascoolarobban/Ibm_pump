#define pumpPin 7
#define buttonA_ledRing 5  //pump led ring
#define buttonB_ledRing 6 //fan led ring
#define buttonC_ledRing 9 //Valve led ring
#define fan_relay 12
#define valve_relay 13
#include "warnings.h"

bool pump_state = false;
bool fan_state = false;
bool valve_state = false;


void pumpON() {
    digitalWrite(pumpPin, HIGH);
    digitalWrite(buttonA_ledRing, HIGH);
    pump_state = true;
    Serial.println("PUMP:ON");
   // send_warning(warning(1));

}
void pumpOFF() {
  digitalWrite(pumpPin, LOW);
  digitalWrite(buttonA_ledRing, LOW);
  pump_state = false;
  Serial.println("PUMP:OFF");

}
void fanON() {
  digitalWrite(fan_relay, HIGH);
  digitalWrite(buttonB_ledRing, HIGH);
  fan_state = true;
  Serial.println("FAN ON");
}
void fanOFF() {
  digitalWrite(fan_relay, LOW);
  digitalWrite(buttonB_ledRing, LOW);
  fan_state = false;
  Serial.println("FAN OFF");

}





void valveON() {
  digitalWrite(valve_relay, HIGH);
  digitalWrite(buttonC_ledRing, HIGH);
  valve_state = true;
  Serial.println("RELAY OPEN");
}
void valveOFF() {
  digitalWrite(valve_relay, LOW);
  digitalWrite(buttonC_ledRing, LOW);
  valve_state = false;
  Serial.println("RELAY CLOSED");
}



void pumpcontroller(char command) {

  if (command == 'A') {
    pumpON();

  }
  else if (command == 'B') {
    pumpOFF();
  }

}

void fancontroller(char command) {
  if (command == 'C') {
    fanON();

  }
  else if (command == 'D') {
    fanOFF();
  }


}

void valvecontroller(char command) {
  if (command == 'E') {
    valveON();

  }
  else if (command == 'F') {
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

void fanControllerButton() {
  if (fan_state == true) {
    fanOFF();
  }
  else {
    fanON();
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
