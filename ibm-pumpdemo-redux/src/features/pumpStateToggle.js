import { createSlice } from '@reduxjs/toolkit';

export const pumpStateSlice = createSlice({
    name: "pumpToggleState",
    initialState: { value: {pumpStateValue: ""}},
    reducers: {
        PumpToggleState:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {PumpToggleState} = pumpStateSlice.actions;

export default pumpStateSlice.reducer;