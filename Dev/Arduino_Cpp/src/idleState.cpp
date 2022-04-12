//
// Created by Robin Ellingsen on 2022-04-08.
//

#include "idleState.h"
#include "pumpControl.h"
#include "buttonIsTriggered.h"

bool idleState() {
    if (trigger_A == false &&
        trigger_B == false &&
        trigger_C == false &&
        pump_state == false &&
        fan_state == false &&
        drain_valve_state == false) {
        return true;
    } else {
        return false;
    }
}