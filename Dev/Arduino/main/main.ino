#include <Arduino.h>
#include <ArduinoJson.h>
#include "pumpOnOff.h"
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

  //BUTTON
  pinMode(button_A, INPUT_PULLUP);
  pinMode(ledRing, OUTPUT);
  digitalWrite(ledRing, LOW);
  //*************************
  
  //PUMP
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
  //*************************

  //TEMP
  dht.begin();

  
  //TURN OFF PUMP JUST FOR SAFETY
  pumpOFF();

  //DEBOUNCE AND INTERRUPT
  startMillis = millis();
  attachInterrupt(digitalPinToInterrupt(button_A), buttonAIsTriggered, RISING);


}

void loop() {

  tempReading();
  //Send sensor data
  // send_json();

  //debouncing button
  debounce();


  //check for incomming char
  pumpSerial();
  // delay(5000);


}
