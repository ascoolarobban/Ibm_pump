#include <Arduino.h>
#include <ArduinoJson.h>
#include "pumpControl.h"
#include "declare.h"
#include "sensors.h"
#include "readSerial.h"
#include "runTime.h"
#include "readButtons.h"
#include "readPotentiometers.h"
#include "welcomeBlink.h"
#include "detect_change.h"
#include "buttonLED.h"
#include "sendJson.h"
#include "debounce.h"
#include "setPWM.h"
#include <Wire.h>
#include "readSensors.h"
#include "convertToLitres.h"
#include "checkHardwareStateChange.h"
#include "idleState.h"
#include <stdio.h>
#include "killAll.h"
#include "Servo.h"
//FOR CODE QUESTIONS
char linkedin[50] = "linkedin.com/in/iotrobban/";


//Main loop millis
unsigned long nowTime;
unsigned long delayTime = 10000;
unsigned long previousMillis;



void setup() {
    Serial.begin(115200);

    /**BUTTONS**/
    //BUTTON A
    pinMode(button_A, INPUT);
    pinMode(buttonA_ledRing, OUTPUT);
    digitalWrite(buttonA_ledRing, LOW);

    //BUTTON B
    pinMode(button_B, INPUT);
    pinMode(buttonB_ledRing, OUTPUT);
    digitalWrite(buttonB_ledRing, LOW);

    //BUTTON C
    pinMode(button_C, INPUT);
    pinMode(buttonC_ledRing, OUTPUT);
    digitalWrite(buttonC_ledRing, LOW);


    //*************************

    //PUMP
    pinMode(pumpPin, OUTPUT);
    digitalWrite(pumpPin, LOW);
    //PUMP PWM
    pinMode(pump_pwm_pin, OUTPUT);
    //*************************

    //FAN RELAY
    pinMode(fan_relay, OUTPUT);

    //DRAIN RELAY
    pinMode(drain_valve_pwm_pin, OUTPUT);

    //SAFETY VALVE
    pinMode(safety_valve_relay, OUTPUT);

    //DEBOUNCE AND INTERRUPT
    startMillis = millis();


    //POTENTIOMETERS
    pinMode(potPin1, INPUT_PULLUP);
    pinMode(potPin2, INPUT_PULLUP);
    pinMode(potPin3, INPUT_PULLUP);

    //FLOW SENSORS
    pinMode(flowSensor1_pin, INPUT);
    pinMode(flowSensor2_pin, INPUT);
    pinMode(flowSensor3_pin, INPUT);


    //TURN OFF PUMP JUST FOR SAFETY
    pumpOFF();


    welcomeBlink();
    //Serial.println(startup);
    nowTime = millis();



}

void loop() {
    //All three flow sensors connected to the main pipes
    Sensor flowSensor1;
    Sensor flowSensor2;
    Sensor flowSensor3;




    //Checks what button has been pressed
    readButtons();

    //Read waterflowSensors
    readSensors(flowSensor1, flowSensor2, flowSensor3);

    //Read Potentiometer:
    readPotentiometers();

    //debouncing button
    debounce();

    //check for incomming char
    readSerialInput();

    //Checks if any buttons or potentiometers has changed
    checkHardwareStateChange();

    //Get the time machine has been running
    runTime();

    //If any change has been made such as somebody turning a potentiometer. If so, it sends json over serial to raspberry pi.
    if (detect_change_pot() || detect_change_onoff()) {

        send_json(flowSensor1, flowSensor2, flowSensor3);
        Serial.println("\n");
    }

// Here we'll make a program that only runs if nothing has changed for X minutes, then the buttons will start blinking IBM in morse.
/*    if (idleState()) {
        if (millis() - nowTime >= delayTime) {
            nowTime = millis();
            //ledShow();
            ibmLightShow();
        }

    }
    //KILL THE WHOLE PUMP IF IDLE IN MORE THAN 5 MIN
    if (millis() - nowTime >= 300000) {
        if (!detect_change_pot() || !detect_change_onoff()) {
            killAll();
            nowTime = millis();
            ibmLightShow();
        }
    }*/
}
