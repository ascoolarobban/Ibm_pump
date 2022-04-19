import { createSlice } from '@reduxjs/toolkit';

export const historicSlice = createSlice({
    name: "historicData",
    initialState: { value: {historyDate: "",
        historyValue: 0}},
    reducers: {
        historicDataReducer:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {historicDataReducer} = historicSlice.actions;

export default historicSlice.reducer;
