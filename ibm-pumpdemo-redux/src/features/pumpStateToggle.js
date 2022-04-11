import { createSlice } from '@reduxjs/toolkit';

export const PumpStateSlice = createSlice({
    name: "pumpStateToggle",
    initialState: { value: {pumpState: ""}},
    reducers: {
        PumpStateToggle:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {PumpStateToggle} = PumpStateSlice.actions;