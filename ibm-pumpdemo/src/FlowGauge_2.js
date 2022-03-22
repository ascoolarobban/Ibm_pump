import React from "react";
import ReactDOM from "react-dom";
import { GaugeChart } from "./@carbon_charts";
import "@carbon/charts/styles.css";

class FlowGauge2 extends React.Component {
	
	state = {
		data: [
	{
		"group": "value",
		"value": 8
	},
],
		options: {
	"title": "Flow #2   rate  l/min",
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
ReactDOM.render(<FlowGauge2 />, document.getElementById("root"));

export default FlowGauge2;
  
