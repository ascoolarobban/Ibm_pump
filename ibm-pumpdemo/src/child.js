import React, { Component } from "react";
import TempGauge from "./TempGauge";
import FlowGauge_1 from "./FlowGauge_1";
import FlowGauge_2 from "./FlowGauge_2";
import FlowGauge_3 from "./FlowGauge_3";
import FanSpeed from "./Fan_Speed";
import PumpSpeed from "./Pump_Speed";

 /*var tempStateData = () => {
    let state = {
		data: [
	{
		"group": "value",
		"value": null
	},
	
    this.tempStateData.data.value = this.props.temp
],
		options: {
	"title": "Temperature",
	"resizable": false,
	"height": "250px",
	"width": "100%",
	"gauge": {
		"type": "semi",
		"status": "danger"
	}
}
	};
} */

class ChildComponent extends Component {
    
    sendMessage=()=>{
        const {websocket} = this.props.websocket // websocket instance passed as props to the child component.

        try {
            websocket.send('Connected') //send data to the server
        } catch (error) {
            console.log(error) // catch error
        }
    }
    render=()=>{

        return (
            <div id="heading">
                <h2>Pump: {this.props.pumpState}Valve: {this.props.valveState}Fan: {this.props.fanState}</h2>
                <br></br>
                <div class="grid-container">
                    <div class="grid-item"><TempGauge temperature = {this.props.temp}/></div>
                    <div class="grid-item"><FanSpeed fanspeed = {this.props.fanSpeed}/></div>
                    <div class="grid-item"><PumpSpeed pumpSpeed = {this.props.pumpSpeed}/></div>
                    <div class="grid-item"><FlowGauge_1 flow = {this.props.flow1}/></div>
                    <div class="grid-item"><FlowGauge_2 flow = {this.props.flow2}/></div>
                    <div class="grid-item"><FlowGauge_3 flow = {this.props.flow3}/></div>
                </div>
            </div>
        );
    }
}

export default ChildComponent;