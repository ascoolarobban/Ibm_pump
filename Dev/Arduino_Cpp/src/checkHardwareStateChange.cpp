//
// Created by Robin Ellingsen on 2022-04-08.
//

#include "checkHardwareStateChange.h"
#include "pumpControl.h"
bool old_pump_state= false;
bool old_fan_state= false;
bool old_drain_valve_state= false;
void checkHardwareStateChange(){
    if(pump_state != old_pump_state){
        //pumpON();
        pumpcontroller(pump_state);
        old_pump_state = pump_state;
    }
    if(fan_state != old_fan_state){
        fancontroller(fan_state);
        old_fan_state = fan_state;
    }
    if(drain_valve_state != old_drain_valve_state){
        valvecontroller(drain_valve_state);
        old_drain_valve_state = drain_valve_state;
    }


}