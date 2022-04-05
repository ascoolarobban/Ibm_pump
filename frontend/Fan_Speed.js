import React from "react";
import ReactDOM from "react-dom";
import { GaugeChart } from "./@carbon_charts";
import "@carbon/charts/styles.css";

class FanSpeed extends React.Component {
	
	state = {
		data: [
	{
		"group": "value",
		"value": 35
	},
],
		options: {
	"title": "Fan Speed ",
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
ReactDOM.render(<FanSpeed />, document.getElementById("root"));

export default FanSpeed;