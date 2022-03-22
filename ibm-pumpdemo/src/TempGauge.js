import { ToolbarOptions } from "carbon-components-react";
import React from "react";
import ReactDOM from "react-dom";
import { GaugeChart } from "./@carbon_charts";
//import "@carbon/charts/styles.css";

// Or
// import "@carbon/charts/styles/styles.scss";

// IBM Plex should either be imported in your project by using Carbon
// or consumed manually through an import
//import "./plex-and-carbon-components.css";

//console.log("temp: ");
//console.log(this.state.temp);

var temp = 2;

class TempGauge extends React.Component {
	
	
	state = {
		data: [
	{
		"group": "value",
		"value": temp
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
  
