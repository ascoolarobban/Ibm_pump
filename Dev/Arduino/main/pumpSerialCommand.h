
#include "commandHandler.h"

void pumpSerial(){
  if (Serial.available() > 0) {
    char comdata = char(Serial.read());
    commandHandler(comdata);//send comdata to a commando handler.
  }
}
