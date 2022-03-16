import { index } from "d3";
import React, { Component } from "react";
import ChildComponent from "./child";

class App extends Component {
  constructor(props) {
      super(props);

      this.state = {
          ws: null,
          pumpState: 'OFF',
          fanState: 'OFF',
          valveState: 'OFF',
		  temp: null,
          flow: null,
          data: [
            {
                "group": "value",
                "value": null
            },
          ]}
       
  }
 

  // single websocket instance for the own application and constantly trying to reconnect.

  componentDidMount() {
      this.connect();
  }

  timeout = 250; // Initial timeout duration as a class variable

  /**
   * @function connect
   * This function establishes the connect with the websocket and also ensures constant reconnection if connection closes
   */
  connect = () => {
      var ws = new WebSocket("ws://9.246.252.249:1880/ws/simple");
      //var ws = new WebSocket("ws://localhost:1880/ws/simple");
      let that = this; // cache the this
      var connectInterval;

      console.log('ws: %s', ws);


      // websocket onopen event listener
      ws.onopen = () => {
          console.log("connected websocket main component");

          this.setState({ ws: ws });

          console.log(this.state);
          ws.send("React Message");
          that.timeout = 250; // reset timer to 250 on open of websocket connection 
          clearTimeout(connectInterval); // clear Interval on on open of websocket connection
      };

      

      ws.onmessage = (event) => {
        console.log('Message from server ', event.data);
        const sensorObject = JSON.parse(event.data);
        var pumpState = sensorObject["Pump"]["pumpstatus"]
        var temp = sensorObject["Pump"]["temp"]
        var flow = sensorObject["Pump"]["flow"]
        var fanState = sensorObject["Pump"]["fanstatus"]
        var valveState = sensorObject["Pump"]["valvestatus"]
        
        this.setState({ pumpState: pumpState});
        this.setState({ fanState: fanState});
        this.setState({ valveState: valveState});
        this.setState({ temp: temp});
        this.setState({ flow: flow});
         
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
      if (!ws || ws.readyState === WebSocket.CLOSED) this.connect(); //check if websocket instance is closed, if so call `connect` function.
  };

  render() {
      return <ChildComponent websocket={this.state.ws} temp={this.state.temp} pumpState={this.state.pumpState} />;
  }
}
export default App;

