import React from 'react';
import { useSelector } from 'react-redux';
import { Toggle } from "carbon-components-react";

function sendTogglePumpState(pumpToggleState){
    console.log(pumpToggleState);
    let newState = pumpToggleState !== false ? 'ON' : 'OFF';
    let newToggleStateMessage = "PUMP:" + newState;
    const newStateMessage = JSON.stringify(newToggleStateMessage);
    //ws.send(newStateMessage);
    console.log('ToggleState: ', newStateMessage);
} 

function PumpFanValveStates() {

const sensorValue = useSelector((state) => state.sensors.value);
var location = sensorValue.location
var id = sensorValue.id
var fanState = sensorValue.fanState
var drainState = sensorValue.drainStateValve
var safetyState = sensorValue.safetyStateValve
var pumpState = sensorValue.pumpState
let fanStateText;
let safetyStateText;
let drainStateText;

fanStateText = fanState = true ? 'ON' : 'OFF';
drainStateText = drainState = true ? 'ON' : 'OFF';
safetyStateText = safetyState = true ? 'ON' : 'OFF';

return(
    <p><h3>Location:&nbsp;{location}&nbsp;&nbsp;&nbsp;Id&nbsp;:&nbsp;{id}&nbsp;&nbsp;
    Fan State: &nbsp;{fanStateText}&nbsp;&nbsp;Drain valve:&nbsp;{drainStateText}&nbsp;&nbsp;Safety valve:&nbsp;{safetyStateText}</h3>
    <Toggle 
        aria-label="toggle button"
        id="toggle-1"
        labelText="Pump"
        toggled={pumpState}
        //onToggle={Toggle => sendTogglePumpState(Toggle)}
    /></p>
)};

export default PumpFanValveStates;