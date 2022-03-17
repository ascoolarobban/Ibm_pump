#include <Arduino.h>
#include <ArduinoJson.h>
#include "pumpControl.h"
#include "declare.h"
#include "sensorReadings.h"
#include "pumpSerialCommand.h"
#include "runTime.h"
#include "readButtons.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>





//Global button states:
int buttonAState;
int buttonBState;
int buttonCState;



void setup() {
  Serial.begin(9600);

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
  //*************************

  //TEMP
  dht.begin();


  //FAN
  pinMode(fan_relay, OUTPUT);

  //VALVE
  pinMode(valve_relay, OUTPUT);

  //DEBOUNCE AND INTERRUPT
  startMillis = millis();


  //TURN OFF PUMP JUST FOR SAFETY
  pumpOFF();

}

void loop() {



  //Checks what button has been pressed
  readButtons();
  //Idle button breath
  if(idleState() == true){
    ledShow();
  }
  //ledShow();

  //Get the time machine has been running
  runTime();

  //Send sensor data
  tempReading();



  //debouncing button
  debounce();


  //check for incomming char
  pumpSerial();



}
