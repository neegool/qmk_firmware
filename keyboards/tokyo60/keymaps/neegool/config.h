#pragma once

// place overrides here
#define PERMISSIVE_HOLD
#define TAPPING_TERM 150

// #undef USB_MAX_POWER_CONSUMPTION
// #define USB_MAX_POWER_CONSUMPTION 500

#undef USB_POLLING_INTERVAL_MS
#define USB_POLLING_INTERVAL_MS 4

#define IGNORE_MOD_TAP_INTERRUPT          // Enable ignore mod tap interrupt: https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY  // Allows configuration of ignore mod tap interrupt per key in keymap.c

#define COMBO_COUNT 1  // Number of defined combos
#define COMBO_TERM 20  // Delay for combo keys to be chained together

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
