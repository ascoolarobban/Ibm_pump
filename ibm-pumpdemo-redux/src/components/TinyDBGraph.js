import React from "react";
import { LineChart } from "@carbon/charts-react";
import "@carbon/charts/styles.css";
import { useSelector } from 'react-redux';

function TinyDBGraph() {

	const sensorValue = useSelector((state) => state.sensors.value);
	var temp_history_value = sensorValue.temp_history_value
	var temp_history_date = sensorValue.temp_history_date

    var state = {
		data: [
	
	{
		"group": "Dataset",
		"date": temp_history_date,
		"value": temp_history_value
	}],/*
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
	} */


		options: {
	"title": "TinyDB data",
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

export default TinyDBGraph;
  