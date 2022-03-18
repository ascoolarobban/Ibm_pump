#define pumpPin 7
#define buttonA_ledRing 5  //pump led ring
#define buttonB_ledRing 6 //fan led ring
#define buttonC_ledRing 9 //Valve led ring
#define fan_relay 12
#define drain_valve 11
#define safety_valve_relay 8
#include "warnings.h"

bool pump_state = false;
bool fan_state = false;
bool drain_valve_state = false;
bool safety_valve_state = false;

void safetyValveOFF() {
  digitalWrite(safety_valve_relay, LOW);
  Serial.println("SAFETY VALVE: CLOSED");
  safety_valve_state = false;
}

void safetyValveON() {
  digitalWrite(safety_valve_relay, HIGH);
  Serial.println("SAFETY VALVE: OPEN");
  safety_valve_state = true;
  

}

void pumpON() {
  safetyValveON();
  digitalWrite(pumpPin, HIGH);
  digitalWrite(buttonA_ledRing, HIGH);
  pump_state = true;
  Serial.println("PUMP:ON");
  // send_warning(warning(1));

}
void pumpOFF() {
  safetyValveOFF();
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





void drainValveOpen() {
  analogWrite(drain_valve, 255);
  digitalWrite(buttonC_ledRing, HIGH);
  drain_valve_state = true;
  Serial.println("DRAIN VALVE: OPEN ");
//  Serial.println(pot_1);
}
void drainValveClosed() {
  analogWrite(drain_valve, 0);
  digitalWrite(buttonC_ledRing, LOW);
  drain_valve_state = false;
  Serial.println("DRAIN VALVE: CLOSED");
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
    drainValveOpen();

  }
  else if (command == 'F') {
    drainValveClosed();
  }


}

void valveControllerButton() {
  if (drain_valve_state == true) {
    drainValveClosed();
  }
  else {
    drainValveOpen();
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
