import React, { useState, useEffect } from 'react';
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
import PumpFanValveStates from './components/PumpFanValveStates';
import {useDispatch} from 'react-redux';
import { sensorDataReducer } from './features/sensors'
import ErrorBoundary from './components/ErrorBoundary';

//var ws = new WebSocket("ws://192.168.1.2:1880/ws/data");
var ws = new WebSocket("ws://raspberrypi:1880/ws/data");
var isConnectedToWebSocket = false;

Toggle.defaultProps = {
  onToggle: () => {},
  labelA: 'off',
  labelB: 'on',
};

function IsJsonString(str) {
  try {
    var json = JSON.parse(str);
    return (typeof json === "object");
  } catch (e) {
    return false;
  }
}

function convertInputToPWMValue(x, in_min, in_max, out_min, out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

function SendButtonPressedMessage(inputState,msgType){
  var newButtonState = null;
  var newmsg;
  var pwmValue=0;
  newButtonState = inputState !== true ? 'OFF' : 'ON' ;
  if (inputState === null) {
    return
  }
  switch (msgType) {
    case 'Pump':
      newmsg = "{PUMP:" + newButtonState + "}" ;
      console.log('%s', newmsg);
      break;
    case 'Fan':
      newmsg = "{FAN:" + newButtonState + "}" ;
      console.log('%s', newmsg);
      break;
    case 'Drain':
      newButtonState = inputState !== true ? 'CLOSED' : 'OPEN' ;
      newmsg = "{DRAIN_VALVE:" + newButtonState + "}" ;
      console.log('%s', newmsg);
      break;
    case 'PumpSpeed':
        console.log('pump speed input: %s', inputState);
        pwmValue = convertInputToPWMValue(inputState,0,3000,0,255);
        pwmValue = pwmValue.toFixed(0);
        newmsg = "POTA" + pwmValue ;
        console.log('%s', newmsg);
        break;
    case 'FanSpeed':
        console.log('fan speed input: %s', inputState);
        pwmValue = convertInputToPWMValue(inputState,0,1900,0,255);
        pwmValue = pwmValue.toFixed(0);
        newmsg = "POTB" + pwmValue ;
        console.log('%s', newmsg);
        break;
    case 'Servo':
        console.log('Servo input: %s', inputState);
        pwmValue = convertInputToPWMValue(inputState,0,100,4,95);
        pwmValue = pwmValue.toFixed(0);
        newmsg = "POTC" + pwmValue ;
        console.log('%s', newmsg);
        break;
    default:
      console.log('unknown sensor type: %s', msgType);
  }

  if (isConnectedToWebSocket) {
    ws.send(newmsg);
  }   
}

function App() {
  const dispatch = useDispatch();
  const [globalPumpState, setGlobalPumpState] = useState(false)
  const [globalFanState, setGlobalFanState] = useState(false)
  const [globalDrainState, setGlobalDrainState] = useState(false)
  const [globalPumpSpeed, setGlobalPumpSpeed] = useState(0)
  const [globalFanSpeed, setGlobalFanSpeed] = useState(0)
  const [globalServo, setGlobalServo] = useState(0)
  
  useEffect(() => {
    SendButtonPressedMessage(globalPumpState,"Pump");
  }, [globalPumpState]);

  useEffect(() => {
    SendButtonPressedMessage(globalFanState,"Fan");
  }, [globalFanState]);

  useEffect(() => {
    SendButtonPressedMessage(globalDrainState,"Drain");
  }, [globalDrainState]);

  useEffect(() => {
    SendButtonPressedMessage(globalPumpSpeed,"PumpSpeed");
  }, [globalPumpSpeed]);

  useEffect(() => {
    SendButtonPressedMessage(globalFanSpeed,"FanSpeed");
  }, [globalFanSpeed]);

  useEffect(() => {
    SendButtonPressedMessage(globalServo,"Servo");
  }, [globalServo]);  

  ws.onopen = () => {
    console.log('Connected to Websocket');  
    isConnectedToWebSocket = true;
  };
  
  ws.onmessage = (event) => {
    console.log('Message from server ', event.data);
    const sensorObject = JSON.parse(event.data);
    if (IsJsonString(event.data)) {
      //console.log("returned true: %s", event.data )
    } else {
      //console.log("Returned false:");
    }

    try {
      var PumpState = sensorObject.data.pumpState
      var FanSpeed = sensorObject.data.fanSpeed
      var Waterflow1 = sensorObject.data.flowSensor1
      var Waterflow2 = sensorObject.data.flowSensor2
      var Waterflow3 = sensorObject.data.flowSensor3
      var FanState = sensorObject.data.fanState
      var PumpSpeed = sensorObject.data.pumpSpeed
      var DrainValveState = sensorObject.data.drainValveState
      var DrainValveLevel = sensorObject.data.DrainValveLevel
      var SafetyValveState = sensorObject.data.safetyValveState
      var Temperature = sensorObject.data.temp
      var Location = sensorObject.data.location
      var Id = sensorObject.data.id
    
      dispatch(sensorDataReducer({temp: Temperature, flowrateOne: Waterflow1,
        flowrateTwo: Waterflow2, flowrateThree: Waterflow3, fanSpeed: FanSpeed,
        fanState: FanState, pumpSpeed: PumpSpeed, pumpState: PumpState, 
        location: Location, id: Id, drainStateValve: DrainValveState, 
        drainValveLevel: DrainValveLevel, safetyStateValve: SafetyValveState}))
    
    
    } catch (error) {
      try {
        const warningMessage = JSON.parse(event.data);
        var TempWarning = warningMessage.payload.tempNormal;
      } catch (e) {
        console.log('unknown message %s', e);
      }
      console.log('Cannot parse incoming sensor data: %s ', error);
    }
  }
 
  return (

    <div>
      <div className="App"><h2>Pump Demo</h2>
        <ErrorBoundary>
          <PumpFanValveStates changePumpToggleState={toggled => setGlobalPumpState(toggled)}
          changeFanToggleState={toggled => setGlobalFanState(toggled)}
          changeFlushToggleState={toggled => setGlobalDrainState(toggled)}
          changePumpSpeed={value => setGlobalPumpSpeed(value)}
          changeFanSpeed={value => setGlobalFanSpeed(value)}
          changeServo={value => setGlobalServo(value)}/>    
        </ErrorBoundary>
        <br></br>
        <div>
          <div className="grid-container">
          <div className="grid-item"><PumpSpeed /></div>
          <div className="grid-item"><FanSpeed /></div>
          <div className="grid-item"><TempGauge /></div>
          <div className="grid-item"><FlowOne /></div>
          <div className="grid-item"><FlowTwo /></div>
          <div className="grid-item"><FlowThree /></div>
        </div>
      </div>
    </div>
  </div>
  );
}
 
export default App;
