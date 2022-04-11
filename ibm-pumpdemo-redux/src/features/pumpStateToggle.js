import { createSlice } from '@reduxjs/toolkit';

export const PumpStateSlice = createSlice({
    name: "pumpToggleState",
    initialState: { value: {pumpStateValue: ""}},
    reducers: {
        PumpToggleState:(state, action) => {
            state.value = action.payload;
        },
    },
});

export const {PumpToggleState} = PumpStateSlice.actions;