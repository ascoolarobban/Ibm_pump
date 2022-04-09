import { combineReducers } from 'redux';
import { newMessage } from './features/sensors';
import { historicData } from './features/historicData';

const rootreducer = combineReducers({
    newMessage,
    historicData
})

export default rootreducer;
