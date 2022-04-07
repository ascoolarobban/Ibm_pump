import { combineReducers } from 'redux';
import  newMessage  from './features/sensors';
import  historicData from './features/historicData';


export default combineReducers({
    newMessage,
    historicData
});