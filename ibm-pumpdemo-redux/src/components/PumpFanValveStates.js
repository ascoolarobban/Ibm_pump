import React from 'react';
import { useSelector } from 'react-redux';

function sendButtonPressedMessage(buttonState){
    var newButtonState = null;
    buttonState = "ON" ? (newButtonState = 'OFF') : (newButtonState = 'ON'); 
    //ws.send("PUMP " + newButtonState);
} 

function PumpFanValveStates() {

const sensorValue = useSelector((state) => state.sensors.value);
var pumpstate = sensorValue.pumpstate
console.log('pump state %s', pumpstate);

return(
    <button
      onClick={() => {
        sendButtonPressedMessage(sensorValue.pumpstate)
      }}> Pump: {pumpstate} </button>
)};

export default PumpFanValveStates;