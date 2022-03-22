import React from "react";
import ReactDOM from "react-dom";
import { GaugeChart } from "./@carbon_charts";
import "@carbon/charts/styles.css";

class FlowGauge3 extends React.Component {
	
	state = {
		data: [
	{
		"group": "value",
		"value": 6
	},
],
		options: {
	"title": "Flow #3   rate  l/min",
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
ReactDOM.render(<FlowGauge3 />, document.getElementById("root"));

export default FlowGauge3;
  
