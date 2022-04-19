import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import reportWebVitals from './reportWebVitals';
import { configureStore } from '@reduxjs/toolkit'
import { Provider } from 'react-redux';
import { sensorData } from './features/sensors';
import { historicData } from './features/historicData';
import { pumpToggleStateReducer } from './features/pumpStateToggle';

/* const store = createStore(combineReducers({
  sensorMessage, historicData, pumpToggleState})); */

const store = configureStore({
  reducer: {
    sensorData: sensorData,
    pumpStateData: pumpToggleStateReducer,
    historicData: historicData,
  },
}); 

ReactDOM.render(
  <React.StrictMode>
    <Provider store={store}>
      <App />
    </Provider>
  </React.StrictMode>,
  document.getElementById('root')
);

reportWebVitals();
