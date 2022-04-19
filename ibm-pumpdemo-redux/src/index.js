import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import reportWebVitals from './reportWebVitals';
import { configureStore } from '@reduxjs/toolkit'
import { Provider } from 'react-redux';
import sensorDataReducer from './features/sensors';
import historicDataReducer from './features/historicData';
import pumpToggleStateReducer from './features/pumpStateToggle';

const store = configureStore({
  reducer: {
    sensors: sensorDataReducer,
    pumpState: pumpToggleStateReducer,
    historic: historicDataReducer,
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
