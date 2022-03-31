#include <Arduino.h>
#include <ArduinoJson.h>
#include "pumpControl.h"
#include "declare.h"
#include "sensorReadings.h"
#include "pumpSerialCommand.h"
#include "runTime.h"
#include "readButtons.h"
#include "readPotentiometers.h"
#include "welcomeBlink.h"
#include "detect_change.h"
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
  //PUMP PWM
  pinMode(pump_pwm_pin, OUTPUT);
  //*************************

  //TEMP
  dht.begin();

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


  //TURN OFF PUMP JUST FOR SAFETY
  pumpOFF();

  welcomeBlink();
  Serial.println(startup);

}
unsigned long lastMill = 0;
void loop() {
  unsigned long currentMill = millis();

  //Checks what button has been pressed
  readButtons();

  //Read Potentiometer:
  readPotentiometers();




  //Send sensor data
  //sensorReading();



  //debouncing button
  debounce();


  //check for incomming char
  pumpSerial();


  //Get the time machine has been running
  runTime();

   if(detect_change_pot() == true || detect_change_onoff() == true){
    Serial.println("Change detected");
    
    send_json();
  }


  //Idle button breath
  if (idleState() == true) {
    if (currentMill - lastMill  > waitPeriod) {
      lastMill = currentMill;
      ledShow();
    }
  }



}
