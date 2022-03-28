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
import {useDispatch} from 'react-redux';
import {newMessage} from './features/sensors'

var ws = new WebSocket("ws://9.246.252.242:1880/ws/simple");

Toggle.defaultProps = {
  onToggle: () => {},
  labelA: 'off',
  labelB: 'on',
};

function sendButtonPressedMessage(toggleState){
  /* if (!ws || ws.readyState === WebSocket.CLOSED) {
    var ws = new WebSocket("ws://9.246.252.242:1880/ws/simple");
  } */
  ws.send("BP:" + toggleState);
} 

function App() {
  const dispatch = useDispatch();
  
  //var ws = new WebSocket("ws://localhost:1880/ws/simple");
  //var ws = new WebSocket("ws://9.246.252.242:1880/ws/simple"); // My laptop
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
  
  if (!ws || ws.readyState === WebSocket.CLOSED) { //check if websocket instance is closed, if so call `connect` function.
    ws = new WebSocket("ws://9.246.252.242:1880/ws/simple");
  } 

  ws.onmessage = (event) => {
    console.log('Message from server ', event.data);
    
  
    const sensorObject = JSON.parse(event.data);
    var newPumpState = sensorObject["data"]["pumpstate"]
    var newFanspeed = sensorObject["data"]["fanspeed"]
    var newWaterflow1 = sensorObject["data"]["flowSensor_1"]
    var newWaterflow2 = sensorObject["data"]["flowSensor_2"]
    var newWaterflow3 = sensorObject["data"]["flowSensor_3"]
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
    <div>
        <div className="grid-container">
        <div className="grid-item"><TempGauge /></div>
        <div className="grid-item"><FanSpeed /></div>
        <div className="grid-item"><PumpSpeed /></div>
        <div className="grid-item"><FlowOne /></div>
        <div className="grid-item"><FlowTwo /></div>
        <div className="grid-item"><FlowThree /></div>
        <div className="grid-item"><TempGraph /></div>
        <div className="grid-item"><TempHistogram /></div>
        <div className="grid-item"><TinyDBGraph /></div>
      </div>
    </div>
  </div>
  );
}
 
export default App;

// <div className="grid-item"><TinyDBGraph /></div>
