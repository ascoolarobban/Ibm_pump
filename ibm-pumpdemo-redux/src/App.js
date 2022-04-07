import './App.css';
import './index.css';
import 'carbon-components/css/carbon-components.min.css';
import { Toggle } from "carbon-components-react";
import TempGauge from './components/TempGauge';
import FlowOne from './components/FlowOne'
import FlowTwo from './components/FlowTwo';
import FlowThree from './components/FlowThree';
import FanSpeed from './components/Fanspeed';
import PumpSpeed from './components/Pumpspeed';
import TempGraph from './components/TempLineGraph';
import TinyDBGraph from './components/TinyDBGraph';
import TempHistogram from './components/TempHistogram';
import PumpFanValveStates from './components/PumpFanValveStates';
import {useDispatch} from 'react-redux';
import {newMessage} from './features/sensors'
import React, {useState} from 'react'

var ws = new WebSocket("ws://192.168.1.5:1880/ws/simple");
var ws_history = new WebSocket("ws://192.168.1.5:1880/ws/history");

Toggle.defaultProps = {
  onToggle: () => {},
  labelA: 'off',
  labelB: 'on',
};

function sendButtonPressedMessage(buttonState){
  var newButtonState = null;
  buttonState = "ON" ? (newButtonState = 'OFF') : (newButtonState = 'ON'); 
  ws.send("PUMP " + newButtonState);
} 

function App() {
  const [pumpLocation, setpumpLocation] = useState('');
  const [pumpID, setpumpID] = useState('');
  const dispatch = useDispatch();
  var sendMessage = false;
  var sensorValue;
  var sensorTimeStamp;
  

  ws_history.onopen = () => {
    console.log("connected websocket main component - history ");
    
    if (sendMessage === false) {
      ws.send("SendData");
      sendMessage = true;
    }

    var timeout = 250; 
  };

  ws_history.onmessage = (event) => {
    /* try {
      const historyData = JSON.parse(event.data);
       = historyData.sv
      historyData. = historyData.ts
    } catch(e) {
      console.log('Parse error %s ', e);
    } */

    const historyData = JSON.parse(event.data);
    console.log(data.hasOwnProperty('ts'));

    
    const temp_history_value = [];
    const temp_history_date = [];
    temp_history_value.push();
    temp_history_date.push();
    
    dispatch(historicData({history_date: temp_history_date,
      history_value, temp_history_value}))
  }

  ws.onopen = () => {
    console.log("connected websocket main component");
    
    if (sendMessage === false) {
      ws.send("SendData");
      sendMessage = true;
    }

    var timeout = 250; // reset timer to 250 on open of websocket connection 
    //clearTimeout(connectInterval); // clear Interval on on open of websocket connection
  };
  
  ws.onmessage = (event) => {
    console.log('Message from server ', event.data);
    const sensorObject = JSON.parse(event.data);
    var newPumpState = sensorObject.data.pumpState
    var newFanSpeed = sensorObject.data.fanSpeed
    var newWaterflow1 = sensorObject.data.flowSensor1
    var newWaterflow2 = sensorObject.data.flowSensor2
    var newWaterflow3 = sensorObject.data.flowSensor3
    var newFanState = sensorObject.data.fanState
    var newPumpSpeed = sensorObject.data.pumpSpeed
    var newDrainValveState = sensorObject.data.drainValveState
    var newSafetyValveState = sensorObject.data.safetyValveState
    //var temperature = sensorObject.data.temp
    var temperature = 80
    var newLocation = sensorObject.data.location
    var newId = sensorObject.data.id
    var temp_history_date = sensorObject.data.timestamp
    var temp_history_value = 1
    
    
    dispatch(newMessage({temp: temperature, flowrateOne: newWaterflow1,
      flowrateTwo: newWaterflow2, flowrateThree: newWaterflow3, fanspeed: newFanSpeed,
      fanState: newFanState, pumpspeed: newPumpSpeed, pumpState: newPumpState, 
      temp_history_date: temp_history_date, temp_history_value: temp_history_value,
      location: newLocation, id: newId, drainStateValve: newDrainValveState, 
      safetyStateValve: newSafetyValveState}))
  }
  
  return (
    <div className="App"><h2>Pump Demo</h2>
      <PumpFanValveStates />
      <Toggle 
            aria-label="toggle button"
            id="toggle-1"
            labelText="Pump"
            onToggle={Toggle => sendButtonPressedMessage(Toggle)}
      />
      <br></br>
      <div>
        <div className="grid-container">
        <div className="grid-item"><TempGauge /></div>
        <div className="grid-item"><FanSpeed /></div>
        <div className="grid-item"><PumpSpeed /></div>
        <div className="grid-item"><FlowOne /></div>
        <div className="grid-item"><FlowTwo /></div>
        <div className="grid-item"><FlowThree /></div>
        <div className="grid-item"><TempGraph /></div>
        <div className="grid-item"><TinyDBGraph /></div>
        <div className="grid-item"><TempHistogram /></div>

      </div>
    </div>
  </div>
  );
}
 
export default App;