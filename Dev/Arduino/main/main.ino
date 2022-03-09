#include <Arduino.h>
#include <ArduinoJson.h>
#include "pumpControl.h"
#include "declare.h"
#include "sensorReadings.h"
#include "pumpSerialCommand.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>





//Global button states:
int buttonAState;
int buttonBState;
int buttonCState;



void setup() {
  Serial.begin(9600);

  //BUTTONS
  //BUTTON A
  pinMode(button_A, INPUT_PULLUP);
  pinMode(ledRing, OUTPUT);
  digitalWrite(ledRing, LOW);

  //BUTTON B
  pinMode(button_B, INPUT_PULLUP);
  pinMode(buttonB_ledRing, OUTPUT);
  digitalWrite(buttonB_ledRing, LOW);
  
  
  //*************************
  
  //PUMP
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
  //*************************

  //TEMP
  dht.begin();

  
  //VALVE
  pinMode(valve, OUTPUT);
  
  //DEBOUNCE AND INTERRUPT
  startMillis = millis();
  startMillisB = millis();
  attachInterrupt(digitalPinToInterrupt(button_A), buttonAIsTriggered, RISING);
  attachInterrupt(digitalPinToInterrupt(button_B), buttonBIsTriggered, RISING);
  
  
  //TURN OFF PUMP JUST FOR SAFETY
  pumpOFF();

}

void loop() {
  //Send sensor data
  tempReading();

 

  //debouncing button
  debounce();


  //check for incomming char
  pumpSerial();



}
