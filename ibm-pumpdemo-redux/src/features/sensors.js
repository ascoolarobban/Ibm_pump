import { createSlice } from '@reduxjs/toolkit';



export const sensorSlice = createSlice({
    name: "sensors",
    initialState: { value: {temp: 0, flowrateOne: 0, flowrateTwo: 0,
    flowrateThree: 0, fanspeed: 0, fanState: "", pumpspeed: 0, 
    temp_history_date: "", temp_history_value: 0, location: "", id: "",
    drainValveState: "", safetyValveState: ""}},
    reducers: {
        newMessage:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {newMessage} = sensorSlice.actions;

export default sensorSlice.reducer;
