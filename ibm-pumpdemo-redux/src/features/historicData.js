import { createSlice } from '@reduxjs/toolkit';

export const historicSlice = createSlice({
    name: "historicData",
    initialState: { value: {history_date: temp_history_date,
        history_value: temp_history_value}},
    reducers: {
        newMessage:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {historicData} = historicSlice.actions;

export default sensorSlice.reducer;
