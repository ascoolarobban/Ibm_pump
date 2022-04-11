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
import {SensorMessage} from './features/sensors'
import historicData from './features/historicData';
import { pumpStateToggle, PumpToggleState } from './features/pumpStateToggle';
import { useSelector } from 'react-redux';

var ws = new WebSocket("ws://10.135.5.141:1880/ws/data");

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
  const dispatch = useDispatch();
  var sendMessage = false;
    
  ws.onopen = () => {
    console.log("connected websocket main component");
    
    if (sendMessage === false) {
      ws.send("SendData");
      sendMessage = true;
    }
  };
  
  ws.onmessage = (event) => {
    console.log('Message from server ', event.data);
    const sensorObject = JSON.parse(event.data);

    if (sensorObject.data.value in sensorObject) {
      var temp_history_date = sensorObject.data.timestamp
      var temp_history_value = sensorObject.data.value
      
      dispatch(historicData({historyDate: temp_history_date, 
        historyValue: temp_history_value}))

    }

    if (sensorObject.data.location in sensorObject) {
      var PumpState = sensorObject.data.pumpState
      var FanSpeed = sensorObject.data.fanSpeed
      var Waterflow1 = sensorObject.data.flowSensor1
      var Waterflow2 = sensorObject.data.flowSensor2
      var Waterflow3 = sensorObject.data.flowSensor3
      var FanState = sensorObject.data.fanState
      var PumpSpeed = sensorObject.data.pumpSpeed
      var DrainValveState = sensorObject.data.drainValveState
      var SafetyValveState = sensorObject.data.safetyValveState
      var temperature = sensorObject.data.temp
      var Location = sensorObject.data.location
      var Id = sensorObject.data.id
    }
    
    dispatch(SensorMessage({temp: temperature, flowrateOne: Waterflow1,
      flowrateTwo: Waterflow2, flowrateThree: Waterflow3, fanspeed: FanSpeed,
      fanState: FanState, pumpspeed: PumpSpeed, pumpState: PumpState, 
      location: Location, id: Id, drainStateValve: DrainValveState, 
      safetyStateValve: SafetyValveState}))

    dispatch(PumpToggleState({
      pumpStateValue: PumpState}))
  }
  
  const pumpValue = useSelector((state) => state.pumpStateValue);
  var pumpState = pumpValue.pumpState
  
  return (
    <div className="App"><h2>Pump Demo</h2>
      <PumpFanValveStates />
      <Toggle 
            aria-label="toggle button"
            id="toggle-1"
            labelText="Pump"
            toggled={pumpState}          
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