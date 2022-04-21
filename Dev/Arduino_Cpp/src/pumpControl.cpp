//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "pumpControl.h"
#include "buttonLED.h"

int pumpPin = 7;
int buttonA_ledRing = 5;  //pump led ring
int buttonB_ledRing = 6;//fan led ring
int buttonC_ledRing = 9; //Valve led ring
int fan_relay = 12;
int drain_valve_pwm_pin = 11;
int safety_valve_relay = 8;

bool pump_state = false;
bool fan_state = false;
bool drain_valve_state = false;
bool safety_valve_state = false;

bool last_pump_state = false;
bool last_fan_state = false;
bool last_drain_valve_state = false;



void safetyValveOFF() {
    digitalWrite(safety_valve_relay, LOW);
    //Serial.println("{SAFETY_VALVE:CLOSED}");
    safety_valve_state = false;
}

void safetyValveON() {
    digitalWrite(safety_valve_relay, HIGH);
    //Serial.println("{SAFETY_VALVE:OPEN}");
    safety_valve_state = true;


}

void pumpON() {
    safetyValveON();
    digitalWrite(pumpPin, HIGH);
    digitalWrite(buttonA_ledRing, HIGH);
    pump_state = true;
    //Serial.println("{PUMP:ON}");
    // send_warning(warning(1));

}
void pumpOFF() {
    safetyValveOFF();
    digitalWrite(pumpPin, LOW);
    digitalWrite(buttonA_ledRing, LOW);
    pump_state = false;
    //Serial.println("{PUMP:OFF}");

}
void fanON() {
    fan_state = true;
    digitalWrite(fan_relay, HIGH);
    digitalWrite(buttonB_ledRing, HIGH);
   // Serial.println("{FAN:ON}");
}
void fanOFF() {
    fan_state = false;
    digitalWrite(fan_relay, LOW);
    digitalWrite(buttonB_ledRing, LOW);
   // Serial.println("{FAN:OFF}");

}





void drainValveOpen() {
    analogWrite(drain_valve_pwm_pin, 255);
    digitalWrite(buttonC_ledRing, HIGH);
    drain_valve_state = true;
   // Serial.println("{DRAIN_VALVE:OPEN}");
//  Serial.println(pot_1);
}
void drainValveClosed() {
    analogWrite(drain_valve_pwm_pin, 0);
    digitalWrite(buttonC_ledRing, LOW);
    drain_valve_state = false;
  //  Serial.println("{DRAIN_VALVE:CLOSED}");
}



void pumpcontroller(bool command) {
    if (command) {

        pumpON();

    }
    else if (!command) {
        pumpOFF();
    }

}

void fancontroller(bool command) {
    if (command) {
        fanON();

    }
    else if (!command) {
        fanOFF();
    }


}

void valvecontroller(bool command) {
    if (command) {

        drainValveOpen();

    }
    else if (!command) {
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
}//
// Created by Robin Ellingsen on 2022-04-04.
//

