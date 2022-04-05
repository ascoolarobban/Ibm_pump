//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "pumpSerialCommand.h"

#include "commandHandler.h"
char buf[25];
int count = 0;
void pumpSerial() {
    if (Serial.available() > 0) {
        String cmd = Serial.readStringUntil('\n');
        cmd.toCharArray(buf, 25);
        count = strlen(buf);


        if ( count > 1) {
            Serial.println("Potentiometer");
            setPot(cmd);
        }
        else if(count <=1) {
            Serial.print("cmd2: ");
            Serial.println(buf);
            commandHandler(buf);
        }
        //char comdata = char(Serial.read());
        //send comdata to a commando handler.
    }
}