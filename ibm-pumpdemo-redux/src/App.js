import './App.css';
import './index.css';
import TempGauge from './components/TempGauge';
import FlowOne from './components/FlowOne'
import FlowTwo from './components/FlowTwo';
import FlowThree from './components/FlowThree';
import FanSpeed from './components/Fanspeed';
import PumpSpeed from './components/Pumpspeed';
import {useDispatch} from 'react-redux';
import {newMessage} from './features/sensors'

function App() {
  const dispatch = useDispatch();

  function getRandomInt(max) {
    return Math.floor(Math.random() * max);
  }

  var ws = new WebSocket("ws://localhost:1880/ws/simple");

  ws.onopen = () => {
    console.log("connected websocket main component");
    ws.send("SendData");
    console.log(state);
    that.timeout = 250; // reset timer to 250 on open of websocket connection 
    clearTimeout(connectInterval); // clear Interval on on open of websocket connection
  };
  
  ws.onmessage = (event) => {
    console.log('Message from server ', event.data);
    const sensorObject = JSON.parse(event.data);
    var newPumpState = sensorObject["data"]["pumpstate"]
    var newFanspeed = sensorObject["data"]["fanspeed"]
    var newWaterflow1 = sensorObject["data"]["waterflow1"]
    var newWaterflow2 = sensorObject["data"]["waterflow2"]
    var newWaterflow3 = sensorObject["data"]["waterflow3"]
    var newFanState = sensorObject["data"]["fanstate"]
    var newPumpspeed = sensorObject["data"]["pumpspeed"]
    var newDrainvalvestate = sensorObject["data"]["drain valve state"]
    var temperature = 33
    
    dispatch(newMessage({temp: temperature, flowrateOne: newWaterflow1,
      flowrateTwo: newWaterflow2, flowrateThree: newWaterflow3, fanspeed: newFanspeed,
      pumpspeed: newPumpspeed}))
  }

  return (
    <div className="App"><h2>Pump Demo</h2>
    <button
      onClick={() => {
        dispatch(newMessage({temp: getRandomInt(60), flowrateOne: getRandomInt(20),
        flowrateTwo: getRandomInt(15), flowrateThree: getRandomInt(10), fanspeed: getRandomInt(100),
        pumpspeed: getRandomInt(100)}))
      }}> Fake = Receive data from NodeRed</button>
      <div>
        <div className="grid-container">
        <div className="grid-item"><TempGauge /></div>
        <div className="grid-item"><FanSpeed /></div>
        <div className="grid-item"><PumpSpeed /></div>
        <div className="grid-item"><FlowOne /></div>
        <div className="grid-item"><FlowTwo /></div>
        <div className="grid-item"><FlowThree /></div>
      </div>
    </div>
  </div>
  );
}
 
export default App;
