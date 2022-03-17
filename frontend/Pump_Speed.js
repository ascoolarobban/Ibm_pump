import React from "react";
import ReactDOM from "react-dom";
import { GaugeChart } from "./@carbon_charts";
import "@carbon/charts/styles.css";

class PumpSpeed extends React.Component {
	
	state = {
		data: [
	{
		"group": "value",
		"value": 40
	},
],
		options: {
	"title": "Pump Speed   ",
	"resizable": false,
	"height": "150px",
	"width": "100%",
	"gauge": {
		"type": "semi",
		"status": "danger",
		showPercentageSymbol: false
	}
}
	};
	
	render = () => (
	
		<GaugeChart
			data={this.state.data}
			options={this.state.options}>
		</GaugeChart>
	);
}
ReactDOM.render(<PumpSpeed />, document.getElementById("root"));

export default PumpSpeed;
  
