import React from "react";
import ReactDOM from "react-dom";
import { GaugeChart } from "./@carbon_charts";
import "@carbon/charts/styles.css";

class FlowGauge_1 extends React.Component {
	
	state = {
		data: [
	{
		"group": "value",
		"value": 5
	},
],
		options: {
	"title": "Flow #1   rate  l/min",
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
ReactDOM.render(<FlowGauge_1 />, document.getElementById("root"));

export default FlowGauge_1;
  
