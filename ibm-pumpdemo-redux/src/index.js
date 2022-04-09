import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import reportWebVitals from './reportWebVitals';
import { createStore } from 'redux'
import { Provider } from 'react-redux';
import { newMessage } from './features/sensors';
import { newHistoricData } from './features/historicData';
import { combineReducers } from 'redux';

const rootReducer = combineReducers({
  sensor: newMessage,
  historicData: newHistoricData
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
