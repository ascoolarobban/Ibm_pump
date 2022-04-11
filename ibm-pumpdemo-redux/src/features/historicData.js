import { createSlice } from '@reduxjs/toolkit';

export const historicSlice = createSlice({
    name: "historicData",
    initialState: { value: {historyDate: "",
        historyValue: 0}},
    reducers: {
        HistoricData:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {HistoricData} = historicSlice.actions;

export default historicSlice.reducer;
