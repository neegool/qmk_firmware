#pragma once

// place overrides here

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

#define MATRIX_ROW_PINS  { C7, D6, B7, B6 }
#define MATRIX_COL_PINS  { B5, D7, C6, D0, D3, D2, F0, F1, F4, F5, F6, F7 }

#define PERMISSIVE_HOLD
#define TAPPING_TERM 175

#define DYNAMIC_KEYMAP_LAYER_COUNT 5