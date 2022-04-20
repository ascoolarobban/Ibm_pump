import { createSlice } from '@reduxjs/toolkit';

export const pumpStateSlice = createSlice({
    name: "pumpToggleState",
    initialState: { value: {pumpStateValue: false, pumpSpeedValue: 0, fanSpeedValue: 0}},
    reducers: {
        pumpToggleStateReducer:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {pumpToggleStateReducer} = pumpStateSlice.actions;

export default pumpStateSlice.reducer;
