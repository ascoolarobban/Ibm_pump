import React from 'react';
import { useSelector } from 'react-redux';

function PumpFanValveStates() {

const sensorValue = useSelector((state) => state.sensors.value);
var location = sensorValue.location
var id = sensorValue.id
var fanState = sensorValue.fanState
var drainState = sensorValue.drainStateValve
var safetyState = sensorValue.safetyStateValve

return(
    <h3>Location:&nbsp;{location}&nbsp;&nbsp;&nbsp;Id&nbsp;:&nbsp;{id}&nbsp;&nbsp;
    Fan State: &nbsp;{fanState}&nbsp;&nbsp;Drain valve:&nbsp;{drainState}&nbsp;&nbsp;Safety valve:&nbsp;{safetyState}</h3>
)};

export default PumpFanValveStates;