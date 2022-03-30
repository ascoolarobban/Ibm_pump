import React from 'react';
import { GaugeChart } from "@carbon/charts-react";
import "@carbon/charts/styles.css";
import { useSelector } from 'react-redux';

function TempGauge() {

    const sensorValue = useSelector((state) => state.sensors.value);
    var tempvalue = sensorValue.temp
    
    var state = {
		data: [
	    {
		"group": "value",
		"value": tempvalue
	    },
    ],
		options: {
	    "title": "Temperature °C",
	    "resizable": true,
	    "height": "200px",
	    "gauge": {
		"status": "warning",
        showPercentageSymbol: false,
		"type": "full"
	        }   
        }
	};
    

    return (
        <GaugeChart
			data={state.data}
			options={state.options}>
		</GaugeChart>
    );
}

export default TempGauge;