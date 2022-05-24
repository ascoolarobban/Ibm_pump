//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "pumpControl.h"
#include "buttonLED.h"
#include "Servo.h"
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


//old safetyvalve, probably not gonna be used at all since new design.

void safetyValveOFF() {
    digitalWrite(safety_valve_relay, LOW);
    safety_valve_state = false;
}

void safetyValveON() {
    digitalWrite(safety_valve_relay, HIGH);
    safety_valve_state = true;


}

//turns the pump on.
void pumpON() {
    safetyValveON();
    digitalWrite(pumpPin, HIGH);
    digitalWrite(buttonA_ledRing, HIGH);
    pump_state = true;
    //send_warning(warning(1));

}
// turns the pump off.
void pumpOFF() {
    safetyValveOFF();
    digitalWrite(pumpPin, LOW);
    digitalWrite(buttonA_ledRing, LOW);
    pump_state = false;

}
//Turns the fan on.
void fanON() {
    fan_state = true;
    digitalWrite(fan_relay, HIGH);
    digitalWrite(buttonB_ledRing, HIGH);

}
//Turns the fan off
void fanOFF() {
    fan_state = false;
    digitalWrite(fan_relay, LOW);
    digitalWrite(buttonB_ledRing, LOW);

}




//Opens up the drain valve with a servo connected under the table
void drainValveOpen() {
/*    Servo servo;
    servo.attach(drain_valve_pwm_pin);
    servo.write(4);*/
    digitalWrite(buttonC_ledRing, HIGH);
    drain_valve_state = true;
//  Serial.println(pot_1);
}
//Closes the drain valve with a servo connected under the table
void drainValveClosed() {
/*    Servo servo;
    servo.attach(drain_valve_pwm_pin);
    servo.write(90);*/
    //analogWrite(drain_valve_pwm_pin, 0);
    digitalWrite(buttonC_ledRing, LOW);
    drain_valve_state = false;
   // Serial.println("{\"DRAIN_VALVE\":\"CLOSED\"}");
}


//Gets serial command and turns the pump off or on.
void pumpcontroller(bool command) {
    if (command) {

        pumpON();

    }
    else if (!command) {
        pumpOFF();
    }

}
//Gets serial command and turns the fan off or on.
void fancontroller(bool command) {
    if (command) {
        fanON();

    }
    else if (!command) {
        fanOFF();
    }


}
//Gets serial command and turns the valve off or on.
void valvecontroller(bool command) {
    if (command) {

        drainValveOpen();

    }
    else if (!command) {
        drainValveClosed();
    }


}
//Gets button push command and turns the valve off or on.
void valveControllerButton() {
    if (drain_valve_state == true) {
        drainValveClosed();
    }
    else {
        drainValveOpen();
    }
}
//Gets button push command and turns the fan off or on.
void fanControllerButton() {
    if (fan_state == true) {
        fanOFF();
    }
    else {
        fanON();
    }
}
//Gets button push command and turns the pump off or on.
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

