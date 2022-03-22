import React, { Component } from "react";
import ChildComponent from "./child";
import { useDispatch } from "react-redux";
import { updateSensors } from "./features/Sensors";
import { dispatch } from "d3";

//var ws = new WebSocket("ws://9.246.252.225:1880/ws/simple");
var ws = new WebSocket("ws://localhost:1880/ws/simple");

class App extends Component {
  constructor(props) {
      super(props);

      this.state = {
          ws: null,
          pumpState : false,
          fanspeed : null,
          fanState : false,
          drainvalvestate : false,
          waterflow: 4,
          sendButtonPressed: false,
          temp: 16
          }
       
  }

  
  handleCallback = (childData) =>{
    this.setState({data: childData})
    console.log("Message from child %s",childData );
    if (childData === 'ButtonPressed'){
        console.log('child data if statement')
        this.setState({sendButtonPressed: true});
        ws.send("ButtonPressed");
    }
  }
 

  // single websocket instance for the own application and constantly trying to reconnect.

  componentDidMount() {
      this.connect();
      var temp = 33;
      dispatch(updateSensors({tempvalue: temp}));
  }

  timeout = 250; // Initial timeout duration as a class variable

  /**
   * @function connect
   * This function establishes the connect with the websocket and also ensures constant reconnection if connection closes
   */
  connect = () => {
      //var ws = new WebSocket("ws://9.246.252.225:1880/ws/simple");
      //var ws = new WebSocket("ws://localhost:1880/ws/simple");
      let that = this; // cache the this
      var connectInterval;

      console.log('ws data in: %s', ws);
      this.setState({ ws: ws });
      
      // websocket onopen event listener
      ws.onopen = () => {
          console.log("connected websocket main component");
          ws.send("SendData");
          console.log(this.state);
          that.timeout = 250; // reset timer to 250 on open of websocket connection 
          clearTimeout(connectInterval); // clear Interval on on open of websocket connection
      };
       
      ws.onmessage = (event) => {
        console.log('Message from server ', event.data);
        const sensorObject = JSON.parse(event.data);
        var pumpState = sensorObject["data"]["pumpstate"]
        var fanspeed = sensorObject["data"]["fanspeed"]
        var waterflow = sensorObject["data"]["waterflow"]
        var fanState = sensorObject["data"]["fanstate"]
        var drainvalvestate = sensorObject["data"]["drain valve state"]
        var temp = 33

        this.setState({ pumpState: pumpState});
        this.setState({ fanspeed: fanspeed});
        this.setState({ waterflow: waterflow});
        this.setState({ fanState: fanState});
        this.setState({ drainvalvestate: drainvalvestate});
        
        dispatch(updateSensors({tempvalue: temp}));
      }

      // websocket onclose 
      ws.onclose = e => {
          console.log(
              `Socket is closed. Reconnect will be attempted in ${Math.min(
                  10000 / 1000,
                  (that.timeout + that.timeout) / 1000
              )} second.`,
              e.reason
          );

          that.timeout = that.timeout + that.timeout; //increment retry interval
          connectInterval = setTimeout(this.check, Math.min(10000, that.timeout)); //call check function after timeout
      };

      // websocket onerror event listener
      ws.onerror = err => {
          console.error(
              "Socket encountered error: ",
              err.message,
              "Closing socket"
          );

          ws.close();
      };
  };

  /**
   * utilited by the @function connect to check if the connection is close, if so attempts to reconnect
   */
  check = () => {
      const { ws } = this.state;
      if (!ws || ws.readyState === WebSocket.CLOSED) { //check if websocket instance is closed, if so call `connect` function.
        ws = new WebSocket("ws://9.246.252.162:1880/ws/simple");
        this.connect(); 

      } 
  };

  render() {
      return <ChildComponent parentCallback = {this.handleCallback} 
      websocket={this.state.ws} drainvalvestate={this.state.drainvalvestate}
      pumpState={this.state.pumpState} fanState={this.state.fanState}
      waterflow={this.state.waterflow} temp={this.state.temp}/>;
  }
}
export default App;