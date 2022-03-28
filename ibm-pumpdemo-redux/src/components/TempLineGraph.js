import React from "react";
import ReactDOM from "react-dom";
import { LineChart } from "@carbon/charts-react";
import "@carbon/charts/styles.css";
// Or
// import "@carbon/charts/styles/styles.scss";

// IBM Plex should either be imported in your project by using Carbon
// or consumed manually through an import
//import "./plex-and-carbon-components.css";

function TempGraph() {
	
    var state = {
		data: [
	
	{
		"group": "Dataset",
		"date": "2022-03-01T23:00:00.000Z",
		"value": 0,
	},
	{
		"group": "Dataset",
		"date": "2022-03-05T23:00:00.000Z",
		"value": 12,
	},
	{
		"group": "Dataset",
		"date": "2022-03-06T23:00:00.000Z",
		"value": 16,
	},
	{
		"group": "Dataset",
		"date": "2022-03-07T23:00:00.000Z",
		"value": 18,
	},
	{
		"group": "Dataset",
		"date": "2022-03-14T23:00:00.000Z",
		"value": 21,
	},
	{
		"group": "Dataset",
		"date": "2022-03-18T23:00:00.000Z",
		"value": 11,
	},

],
		options: {
	"title": "Temperature - Last 16 days",
	"axes": {
		"bottom": {
			"title": "Date",
			"mapsTo": "date",
			"scaleType": "time"
		},
		"left": {
			"mapsTo": "value",
			"title": "Temperature",
			"scaleType": "linear"
		}
	},
	"curve": "curveMonotoneX",
	"height": "400px"
}
	};

	return (
		<LineChart
			data={state.data}
			options={state.options}>
		</LineChart>
	);
}

export default TempGraph;
  