//
// Created by Robin Ellingsen on 5/12/22.
//

#include "killAll.h"
#include "pumpControl.h"
//not used yet but good to have a complete shut down function.
void killAll(){
    pumpOFF();
    fanOFF();
    drainValveClosed();
}