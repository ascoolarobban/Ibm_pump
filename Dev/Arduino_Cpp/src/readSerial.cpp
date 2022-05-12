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
    if (Serial.available() > 0) {
        String cmd = Serial.readStringUntil('\n');
        cmd.toCharArray(buf, 25);
        count = strlen(buf);


        //send last 3 digit comdata to commandhandler.
        if ( count > 1) {
            setPot(cmd);

        }
        else if(count <=1) {

            Serial.print("cmd2: ");
            Serial.println(buf);
            commandHandler(buf);
        }
        //char comdata = char(Serial.read());
    }
}