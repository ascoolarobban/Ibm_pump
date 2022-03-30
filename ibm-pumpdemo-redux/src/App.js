import './App.css';
import './index.css';
import 'carbon-components/css/carbon-components.min.css';
//import { action } from '@storybook/addon-actions';
//import { withKnobs, text, boolean, select } from '@storybook/addon-controls';
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

var ws = new WebSocket("ws://192.168.1.5:1880/ws/simple");

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

    var timeout = 250; // reset timer to 250 on open of websocket connection 
    //clearTimeout(connectInterval); // clear Interval on on open of websocket connection
  };
  
  ws.onmessage = (event) => {
    console.log('Message from server ', event.data);
    const sensorObject = JSON.parse(event.data);
    console.log('flow1 %s', newWaterflow1);
    var pumpstate = sensorObject["data"]["pumpstate"]
    var newFanspeed = sensorObject["data"]["fan speed"]
    var newWaterflow1 = sensorObject["data"]["flowSensor_1"]
    var newWaterflow2 = sensorObject["data"]["flowSensor_2"]
    var newWaterflow3 = sensorObject["data"]["flowSensor_3"]
    console.log('flow1 %s', newWaterflow1);
    var newFanState = sensorObject["data"]["fanstate"]
    var newPumpspeed = sensorObject["data"]["pump_speed"]
    var newDrainvalvestate = sensorObject["data"]["drain valve state"]
    var temperature = 33
    var newHistory_date = ""
    var newHistory_value = 12
        
    dispatch(newMessage({temp: temperature, flowrateOne: newWaterflow1,
      flowrateTwo: newWaterflow2, flowrateThree: newWaterflow3, fanspeed: newFanspeed,
      pumpspeed: newPumpspeed, temp_history_date: newHistory_date,
      temp_history_value: newHistory_value}))
  }

  return (
    <div className="App"><h2>Pump Demo</h2>
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