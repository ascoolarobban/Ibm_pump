import { createSlice } from '@reduxjs/toolkit';

export const historicSlice = createSlice({
    name: "historicData",
    initialState: { value: {historyDate: "",
        historyValue: 0}},
    reducers: {
        historicData:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {historicData} = historicSlice.actions;

export default historicSlice.reducer;
