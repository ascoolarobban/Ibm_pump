import { createSlice } from "@reduxjs/toolkit";

export const sensorSlice = createSlice({
    name: "sensors",
    initialState: {value: {tempvalue: 0} },
    reducers: {
        updateSensors: (state, action) => {
            state.value = action.payload;
        },
    },
});

export const { updateSensors } = sensorSlice.actions;

export default sensorSlice.reducer;