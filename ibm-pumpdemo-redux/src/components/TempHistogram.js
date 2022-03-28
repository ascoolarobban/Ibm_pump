import React from "react";
import { HistogramChart } from "@carbon/charts-react";
import "@carbon/charts/styles.css";
// Or
// import "@carbon/charts/styles/styles.scss";

// IBM Plex should either be imported in your project by using Carbon
// or consumed manually through an import
//import "./plex-and-carbon-components.css";

//class App extends React.Component {
function TempHistogram () {
    
    var state = {
		data: [
	{
		"group": "Dataset 1",
		"value": 20
	},
	{
		"group": "Dataset 1",
		"value": 21  
	},
	{
		"group": "Dataset 1",
		"value": 23  
	},
	{
		"group": "Dataset 1",
		"value": 21  
	},
	{
		"group": "Dataset 1",
		"value": 23  
	},
	{
		"group": "Dataset 1",
		"value": 24  
	},
	{
		"group": "Dataset 1",
		"value": 25  
	},
	{
		"group": "Dataset 1",
		"value": 25
	},
	{
		"group": "Dataset 1",
		"value": 29  
	},
	{
		"group": "Dataset 1",
		"value": 30
	},
	{
		"group": "Dataset 1",
		"value": 32 
	},
	{
		"group": "Dataset 1",
		"value": 33 
	},
	{
		"group": "Dataset 1",
		"value": 32 
	},
	{
		"group": "Dataset 1",
		"value": 33 
	},
	{
		"group": "Dataset 1",
		"value": 32 
	},
	{
		"group": "Dataset 1",
		"value": 33 
	},
	{
		"group": "Dataset 1",
		"value": 34 
	},
	{
		"group": "Dataset 1",
		"value": 35 
	},
	{
		"group": "Dataset 1",
		"value": 30
	},
	{
		"group": "Dataset 1",
		"value": 40
	},
	{
		"group": "Dataset 1",
		"value": 42 
	},
	{
		"group": "Dataset 1",
		"value": 43 
	},
	{
		"group": "Dataset 1",
		"value": 45 
	},
	{
		"group": "Dataset 1",
		"value": 46 
	},
	{
		"group": "Dataset 1",
		"value": 46
	},
	{
		"group": "Dataset 1",
		"value": 46
	},
	{
		"group": "Dataset 1",
		"value": 40
	},
	{
		"group": "Dataset 1",
		"value": 43
	},
	{
		"group": "Dataset 1",
		"value": 45 
	},
	{
		"group": "Dataset 1",
		"value": 40
	},
	{
		"group": "Dataset 1",
		"value": 43
	},
	{
		"group": "Dataset 1",
		"value": 40
	},
	{
		"group": "Dataset 1",
		"value": 43
	},
	{
		"group": "Dataset 1",
		"value": 48
	},
	{
		"group": "Dataset 1",
		"value": 50
	},
	{
		"group": "Dataset 1",
		"value": 55
	},
	{
		"group": "Dataset 1",
		"value": 66
	},
	{
		"group": "Dataset 1",
		"value": 58
	},
	{
		"group": "Dataset 1",
		"value": 70
	},
	{
		"group": "Dataset 1",
		"value": 78
	},
	{
		"group": "Dataset 1",
		"value": 71
	},
	{
		"group": "Dataset 1",
		"value": 75
	},
	{
		"group": "Dataset 1",
		"value": 83
	},
	{
		"group": "Dataset 1",
		"value": 86
	},
	{
		"group": "Dataset 1",
		"value": 87
	},
	{
		"group": "Dataset 1",
		"value": 20
	},
	{
		"group": "Dataset 1",
		"value": 21
	},
	{
		"group": "Dataset 1",
		"value": 23
	},
	{
		"group": "Dataset 1",
		"value": 21
	},
	{
		"group": "Dataset 1",
		"value": 23
	},
	{
		"group": "Dataset 1",
		"value": 24
	},
	{
		"group": "Dataset 1",
		"value": 29
	},
	{
		"group": "Dataset 1",
		"value": 30
	},
	{
		"group": "Dataset 1",
		"value": 34
	},
	{
		"group": "Dataset 1",
		"value": 34
	},
	{
		"group": "Dataset 1",
		"value": 35
	},
	{
		"group": "Dataset 1",
		"value": 38
	},
	{
		"group": "Dataset 1",
		"value": 38
	},
	{
		"group": "Dataset 1",
		"value": 27
	},
	{
		"group": "Dataset 1",
		"value": 26
	},
	{
		"group": "Dataset 1",
		"value": 26
	},
	{
		"group": "Dataset 1",
		"value": 22
	},
	{
		"group": "Dataset 1",
		"value": 21
	},
	{
		"group": "Dataset 1",
		"value": 33
	},
	{
		"group": "Dataset 1",
		"value": 38
	},
	{
		"group": "Dataset 1",
		"value": 30
	},
	{
		"group": "Dataset 1",
		"value": 40
	},
	{
		"group": "Dataset 1",
		"value": 43
	},
	{
		"group": "Dataset 1",
		"value": 44
	},
	{
		"group": "Dataset 1",
		"value": 43
	},
	{
		"group": "Dataset 1",
		"value": 45
	},
	{
		"group": "Dataset 1",
		"value": 37
	},
	{
		"group": "Dataset 1",
		"value": 45
	},
	{
		"group": "Dataset 1",
		"value": 45
	},
	{
		"group": "Dataset 1",
		"value": 46
	},
	{
		"group": "Dataset 1",
		"value": 47
	},
	{
		"group": "Dataset 1",
		"value": 48
	},
	{
		"group": "Dataset 1",
		"value": 48
	},
	{
		"group": "Dataset 1",
		"value": 40
	},
	{
		"group": "Dataset 1",
		"value": 43
	},
	{
		"group": "Dataset 1",
		"value": 45
	},
	{
		"group": "Dataset 1",
		"value": 48
	},
	{
		"group": "Dataset 1",
		"value": 50
	},
	{
		"group": "Dataset 1",
		"value": 55
	},
	{
		"group": "Dataset 1",
		"value": 66
	},
	{
		"group": "Dataset 1",
		"value": 61
	},
	{
		"group": "Dataset 1",
		"value": 72
	},
	{
		"group": "Dataset 1",
		"value": 62
	},
	{
		"group": "Dataset 1",
		"value": 82
	},
	{
		"group": "Dataset 1",
		"value": 52
	},
	{
		"group": "Dataset 1",
		"value": 63
	},
	{
		"group": "Dataset 1",
		"value": 63
	},
	{
		"group": "Dataset 1",
		"value": 63
	},
	{
		"group": "Dataset 1",
		"value": 64
	},
	{
		"group": "Dataset 1",
		"value": 58
	},
	{
		"group": "Dataset 1",
		"value": 57
	},
	{
		"group": "Dataset 1",
		"value": 57
	},
	{
		"group": "Dataset 1",
		"value": 57
	},
	{
		"group": "Dataset 1",
		"value": 58
	},
	{
		"group": "Dataset 1",
		"value": 59
	},
	{
		"group": "Dataset 1",
		"value": 70
	},
	{
		"group": "Dataset 1",
		"value": 78
	},
	{
		"group": "Dataset 1",
		"value": 71
	},
	{
		"group": "Dataset 1",
		"value": 75
	},
	{
		"group": "Dataset 1",
		"value": 83
	},
	{
		"group": "Dataset 1",
		"value": 86
	},
	{
		"group": "Dataset 1",
		"value": 87
	}
],
		options: {
	"title": "Histogram Temperature",
	"axes": {
		"bottom": {
			"title": "Time",
			"mapsTo": "value",
			"bins": 37,
			"limitDomainToBins": true
		},
		"left": {
			"title": "Temperature C",
			"scaleType": "linear",
			"binned": true
		}
	},
	"height": "400px"
}
	};

	return (
		<HistogramChart
			data={state.data}
			options={state.options}>
		</HistogramChart>
	);
}

export default TempHistogram;

  