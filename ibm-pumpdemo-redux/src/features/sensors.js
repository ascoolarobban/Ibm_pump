import { createSlice } from '@reduxjs/toolkit';

export const sensorSlice = createSlice({
    name: "sensors",
    initialState: { value: {temp: 0, flowrateOne: 0, flowrateTwo: 0,
    flowrateThree: 0, fanSpeed: 0, fanState: "", pumpSpeed: 0, pumpState: "",
    temp_history_date: 0, temp_history_value: 0, location: "", id: "",
    drainValveState: "", safetyValveState: ""}},
    reducers: {
        sensorData:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {sensorData} = sensorSlice.actions;

export default sensorSlice.reducer;

