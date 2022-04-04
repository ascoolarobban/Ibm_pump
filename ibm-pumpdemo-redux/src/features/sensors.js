import { createSlice } from '@reduxjs/toolkit';



export const sensorSlice = createSlice({
    name: "sensors",
    initialState: { value: {temp: 0, flowrateOne: 0, flowrateTwo: 0,
    flowrateThree: 0, fanSpeed: 0, fanState: "", pumpSpeed: 0, pumpState: "", 
    temp_history_date: "", temp_history_value: 0, location: "", id: "",
    drainValveState: "", safetyValveState: ""}},
    reducers: {
        newMessage:(state, action) => {
            state.value = action.payload;
        },
    },
    name: "togglePumpState",
    initialState: { value: {pumpState: ""}},
    reducers: {
        newPumpState:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {newMessage} = sensorSlice.actions;

export default sensorSlice.reducer;
