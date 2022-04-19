import React from 'react';
import { useSelector } from 'react-redux';
import { Toggle } from "carbon-components-react";
import { Slider } from "carbon-components-react";
import { useDispatch } from 'react-redux';
import pumpStateToggleReducer from '../features/pumpStateToggle';

function PumpFanValveStates() {
    
    const sensors = useSelector((state) => state.sensors.value);
    const dispatch = useDispatch();

    if (sensors !== 'undefined') {
        var pumpState = sensors.pumpState
        var location = sensors.location
        var id = sensors.id
        var fanState = sensors.fanState
        var drainState = sensors.drainStateValve
        var safetyState = sensors.safetyStateValve
        var fanSpeed = sensors.fanSpeed
    } 

    return(
        <h3>Location:&nbsp;{location}&nbsp;&nbsp;&nbsp;Id&nbsp;:&nbsp;{id}&nbsp;&nbsp;
        Fan State: &nbsp;{fanState}&nbsp;&nbsp;Drain valve:&nbsp;{drainState}&nbsp;&nbsp;Safety valve:&nbsp;{safetyState}
        <div><Toggle 
            aria-label="toggle button"
            id="toggle-1"
            labelText="Pump"
            toggled={pumpState}                
            onToggle={Toggle => dispatch(pumpStateToggleReducer(Toggle))}
        /></div>
        <div className="FanSpeedContainer">
        <Slider
            ariaLabelInput="1 - 100"
            id="slider"
            labelText="Fan Speed"
            max={100}
            min={1}
            step={5}
            stepMuliplier={4}
            value={fanSpeed}
        />
        </div>
        </h3>
    )};

export default PumpFanValveStates;
