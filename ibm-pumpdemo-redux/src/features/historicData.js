import { createSlice } from '@reduxjs/toolkit';

export const historicSlice = createSlice({
    name: "historicData",
    initialState: { value: {history_date: "",
        history_value: 0}},
    reducers: {
        newHistoricData:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {newHistoricData} = historicSlice.actions;

export default historicSlice.reducer;
