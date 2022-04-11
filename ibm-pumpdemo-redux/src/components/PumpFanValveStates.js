import React from 'react';
import { useSelector } from 'react-redux';
import { Toggle } from "carbon-components-react";

//var ws_pumpState = new WebSocket("ws://10.135.5.141:1880/ws/pumpState");

function sendButtonPressedMessage(buttonState){
    var newButtonState = null;
    buttonState = "ON" ? (newButtonState = 'OFF') : (newButtonState = 'ON'); 
    // ws_pumpState.send("PUMP " + newButtonState);
  } 

function PumpFanValveStates() {

    const sensorValue = useSelector((state) => state.sensors.value);
    const pumpValue = useSelector((state) => state.pumpToggleState.value);
    var pumpState = pumpValue.pumpStateValue

    var location = sensorValue.location
    var id = sensorValue.id
    var fanState = sensorValue.fanState
    var drainState = sensorValue.drainStateValve
    var safetyState = sensorValue.safetyStateValve

    return(
        <h3>Location:&nbsp;{location}&nbsp;&nbsp;&nbsp;Id&nbsp;:&nbsp;{id}&nbsp;&nbsp;
        Fan State: &nbsp;{fanState}&nbsp;&nbsp;Drain valve:&nbsp;{drainState}&nbsp;&nbsp;Safety valve:&nbsp;{safetyState}
        <div><Toggle 
            aria-label="toggle button"
            id="toggle-1"
            labelText="Pump"
            toggled={pumpState}          
            onToggle={Toggle => sendButtonPressedMessage(Toggle)}
        /></div></h3>
    )};

export default PumpFanValveStates;
