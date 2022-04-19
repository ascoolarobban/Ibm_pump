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
import {sensorData} from './features/sensors'
import {historicData} from './features/historicData';
import { pumpToggleState, pumpToggleStateReducer } from './features/pumpStateToggle';

var ws = new WebSocket("ws://192.168.1.5:1880/ws/data");

Toggle.defaultProps = {
  onToggle: () => {},
  labelA: 'off',
  labelB: 'on',
};

function App() {
  const dispatch = useDispatch();
  var sendMessage = false;
    
  ws.onopen = () => {
        
    if (sendMessage === false) {
      ws.send("SendData");
      sendMessage = true;
    }
  };
  
  ws.onmessage = (event) => {
    console.log('Message from server ', event.data);
    const sensorObject = JSON.parse(event.data);
    
    if (sensorObject.hasOwnProperty('ts')) {
      var temp_history_date = sensorObject.ts
      var temp_history_value = sensorObject.sv
      
      dispatch(historicData({historyDate: temp_history_date, 
        historyValue: temp_history_value}))

    }

    if (sensorObject.hasOwnProperty('location')) {
      var PumpState = sensorObject.data.pumpState
      var FanSpeed = sensorObject.data.fanSpeed
      var Waterflow1 = sensorObject.data.flowSensor1
      var Waterflow2 = sensorObject.data.flowSensor2
      var Waterflow3 = sensorObject.data.flowSensor3
      var FanState = sensorObject.data.fanState
      var PumpSpeed = sensorObject.data.pumpSpeed
      var DrainValveState = sensorObject.data.drainValveState
      var SafetyValveState = sensorObject.data.safetyValveState
      var Temperature = sensorObject.data.temp
      var Location = sensorObject.data.location
      var Id = sensorObject.data.id

      dispatch(sensorData({temp: Temperature, flowrateOne: Waterflow1,
        flowrateTwo: Waterflow2, flowrateThree: Waterflow3, fanspeed: FanSpeed,
        fanState: FanState, pumpspeed: PumpSpeed, pumpState: PumpState, 
        location: Location, id: Id, drainStateValve: DrainValveState, 
        safetyStateValve: SafetyValveState}))
  
      dispatch(pumpToggleStateReducer({
        pumpStateValue: PumpState}))
    }
      
  }
  
  return (
    <div className="App"><h2>Pump Demo</h2>
      <PumpFanValveStates />    
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