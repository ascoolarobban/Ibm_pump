import { ToolbarOptions } from "carbon-components-react";
import React from "react";
import ReactDOM from "react-dom";
import { GaugeChart } from "./@carbon_charts";
import { useSelector } from "react-redux";
import userEvent from "@testing-library/user-event";

const sensor = useSelector((state) => state.sensor.value);

class TempGauge extends React.Component {
	
	state = {
		data: [
	{
		"group": "value",
		"value": sensor.tempvalue
	},
],
		options: {
	"title": "Temperature °C",
	"resizable": false,
	"height": "150px",
	"width": "100%",
	"hidden": false,
	"gauge": {
		"type": "semi",
		"status": "danger",
		showPercentageSymbol: false,
		"aria-disabled": true,
		
	},
	//toolbar-control bx--overflow-menu cds--overflow-menu:
}
	};
	
	render = () => (
	
		<GaugeChart
			data={this.state.data}
			//data={this.props.tempStateData}
			options={this.state.options}>
		</GaugeChart>
	);
}
ReactDOM.render(<TempGauge />, document.getElementById("root"));

export default TempGauge;
  
