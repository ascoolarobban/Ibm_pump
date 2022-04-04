import React from 'react';
import { useSelector } from 'react-redux';
import { Toggle } from "carbon-components-react";
import {useDispatch} from 'react-redux';
import {newPumpState} from './features/sensors'
function togglePumpState(newPumpState) {
    const dispatch = useDispatch();
    dispatch(newPumpState({pumpState: newPumpState}))
}

function PumpFanValveStates() {

const sensorValue = useSelector((state) => state.sensors.value);
var location = sensorValue.location
var id = sensorValue.id
var ws = sensorValue.ws
var fanState = sensorValue.fanState
var drainState = sensorValue.drainStateValve
var safetyState = sensorValue.safetyStateValve
var pumpState = sensorValue.pumpState
let fanStateText;
let safetyStateText;
let drainStateText;

fanStateText = fanState === true ? 'ON' : 'OFF';
drainStateText = drainState === true ? 'ON' : 'OFF';
safetyStateText = safetyState === true ? 'ON' : 'OFF';

return(
    <h3>Location:&nbsp;{location}&nbsp;&nbsp;&nbsp;Id&nbsp;:&nbsp;{id}&nbsp;&nbsp;
        Fan State: &nbsp;{fanStateText}&nbsp;&nbsp;Drain valve:&nbsp;{drainStateText}&nbsp;&nbsp;Safety valve:&nbsp;{safetyStateText}</h3>
)};

export default PumpFanValveStates;