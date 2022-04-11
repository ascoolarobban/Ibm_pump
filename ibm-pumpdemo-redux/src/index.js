import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import reportWebVitals from './reportWebVitals';
import { createStore } from 'redux'
import { Provider } from 'react-redux';
import { SensorMessage } from './features/sensors';
import { HistoricData } from './features/historicData';
import { PumpToggleState } from './features/pumpStateToggle';
import { combineReducers } from 'redux';

const rootReducer = combineReducers({
  sensors: SensorMessage,
  historicData: HistoricData,
  pumpToggleState: PumpToggleState
})

const store = createStore(rootReducer);

ReactDOM.render(
  <React.StrictMode>
    <Provider store={store}>
      <App />
    </Provider>
  </React.StrictMode>,
  document.getElementById('root')
);

reportWebVitals();
