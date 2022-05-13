//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "readSerial.h"
#include "buttonLED.h"
#include "readPotentiometers.h"

#include "commandHandler.h"
char buf[25];
int count = 0;
void readSerialInput() {
    //Gets string and checks if command or if its potentiometer value.
    if (Serial.available() > 0) {
        String cmd = Serial.readStringUntil('\n');
        cmd.toCharArray(buf, 25);
        //checks how long the incomming string is.
        count = strlen(buf);


        //send last 3 digit comdata to commandhandler.
        if ( count > 1) {
            setPot(cmd);

        }
        else if(count <=1) {
            //If the incomming data is less than 1 char, it sends it to the commandHandler.
            //pumpON/OFF fanON/OFF or Valve Open/Closed.
            Serial.print("cmd2: ");
            Serial.println(buf);
            commandHandler(buf);
        }
    }
}