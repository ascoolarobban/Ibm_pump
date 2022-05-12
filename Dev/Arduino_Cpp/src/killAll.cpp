//
// Created by Robin Ellingsen on 5/12/22.
//

#include "killAll.h"
#include "pumpControl.h"
void killAll(){
    pumpOFF();
    fanOFF();
    drainValveClosed();
}