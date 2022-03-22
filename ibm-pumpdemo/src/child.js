import React, { Component } from "react";
import "./carbon-components.min.css";
import "./carbon-components.css";
import "@carbon/charts/styles.css";
import { Toggle } from "carbon-components-react";
import TempGauge from "./TempGauge";
import FlowGauge1 from "./FlowGauge_1";
import FlowGauge2 from "./FlowGauge_2";
import FlowGauge3 from "./FlowGauge_3";
import FanSpeed from "./Fan_Speed";
import PumpSpeed from "./Pump_Speed";


Toggle.defaultProps = {
    onToggle: () => {},
    labelA: 'off',
    labelB: 'on',
};


/* = () => {
var state = {
	data: [
	{
		"group": "value",
		"value": this.props.temp
        }]
    };
//}*/


class ChildComponent extends Component {
    
    sendMessage=()=>{
        const {websocket} = this.props.websocket // websocket instance passed as props to the child component.

        try {
            websocket.send('Message: Connected') //send data to the server
        } catch (error) {
            console.log(error) // catch error
        }
    }

    sendReply=()=>{
        this.props.parentCallback("ButtonPressed");
    }

    render=()=>{

        return (
            <div>
            <br></br>
            <Toggle 
                aria-label="toggle button"
                id="toggle-1"
                labelText="Pump"
                onToggle={Toggle => this.sendReply(Toggle)}
            />
            <h2>Valve: {this.props.drainvalvestate}</h2>
            <h2>Fan: {this.props.fanState}</h2>
                <br></br>
                <div className="grid-container">
                    <div className="grid-item"><TempGauge temp = {this.props.temp}/></div>
                    <div className="grid-item"><FanSpeed fanspeed = {this.props.fanSpeed}/></div>
                    <div className="grid-item"><PumpSpeed pumpspeed = {this.props.pumpSpeed}/></div>
                    <div className="grid-item"><FlowGauge1 flow1 = {this.props.flow1}/></div>
                    <div className="grid-item"><FlowGauge2 flow2 = {this.props.flow2}/></div>
                    <div className="grid-item"><FlowGauge3 flow3 = {this.props.flow3}/></div>
                </div>
            </div>
        );
    }
}

export default ChildComponent;