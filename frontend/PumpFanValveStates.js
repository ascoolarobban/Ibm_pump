import React from 'react';
import { useSelector } from 'react-redux';
import { Toggle } from "carbon-components-react";
//import { Slider } from "carbon-components-react";
import ErrorBoundary from './ErrorBoundary';

function PumpFanValveStates(props) {

    let sensors = useSelector((state) => state.sensors.value);
    if (sensors !== 'undefined') {
        var pumpState = sensors.pumpState
        var location = sensors.location
        var id = sensors.id
        var fanState = sensors.fanState
        var drainState = sensors.drainStateValve
    } 
   
    return(
        <h3>Location:&nbsp;{location}&nbsp;&nbsp;&nbsp;Id&nbsp;:&nbsp;{id}&nbsp;&nbsp;
        <br></br><br></br>
        <div className="grid-container">
            <ErrorBoundary>
            <div className="grid-item-hdrx"><Toggle 
                aria-label="toggle button"
                id="toggle-1"
                labelText="Pump"
                toggled={pumpState}
                onToggle={(Toggle) => props.changePumpToggleState(Toggle)}
            /></div>
            </ErrorBoundary>
            <ErrorBoundary>
            <div className="grid-item-hdrx"><Toggle 
                aria-label="toggle button"
                id="toggle-2"
                labelText="Fan"
                toggled={fanState}
                onToggle={(FanToggle) => props.changeFanToggleState(FanToggle)}
            /></div>   
            </ErrorBoundary>
            <ErrorBoundary>       
            <div className="grid-item-hdrx"><Toggle 
                aria-label="toggle button"
                id="toggle-3"
                labelText="Flush"
                toggled={drainState}
                onToggle={(FlushToggle) => props.changeFlushToggleState(FlushToggle)}
            /></div>
            </ErrorBoundary>
        </div>
        </h3>
    )};
   
   
export default PumpFanValveStates;
