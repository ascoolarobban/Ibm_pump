//
// Created by Robin Ellingsen on 2022-04-04.
//

#include "detect_change.h"
#include "sensors.h"
#include "readPotentiometers.h"
#include "pumpControl.h"
#include "readSensors.h"

bool detect_change_pot() {
    if (pot_1_change == true) {
        pot_1_change = false;
        return true;
    }
    if (pot_2_change == true) {
        pot_2_change = false;
        return true;
    }
    if (pot_3_change == true) {
        pot_3_change = false;
        return true;
    }

    else {
        return false;
    }

}

bool detect_change_sensors() {
    if (last_flowSensor_1 != flowSensor_1) {
        last_flowSensor_1 = flowSensor_1;
        return true;
    }
    else if (last_flowSensor_2 != flowSensor_2) {
        last_flowSensor_2 = flowSensor_2;
        return true;
    }
    else if (last_flowSensor_3 != flowSensor_3) {
        last_flowSensor_3 = flowSensor_3;
        return true;
    }
    else {
        return false;
    }
}

bool detect_change_onoff() {
    if (last_pump_state != pump_state) {
        last_pump_state = pump_state;
        return true;
    }
    else if (last_fan_state != fan_state) {
        last_fan_state = fan_state;
        return true;
    }
    else if (last_drain_valve_state != drain_valve_state) {
        last_drain_valve_state = drain_valve_state;
        return true;
    }
    else {
        return false;
    }
}