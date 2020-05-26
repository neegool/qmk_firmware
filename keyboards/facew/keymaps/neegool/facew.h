#pragma once

#include "quantum.h"

#define LAYOUT_60_ansi2( \
    K61, K71, K72, K73, K74, K64, K65, K75, K76, K77, K78, K68, K66, K6A,        \
    K11,   K01, K02, K03, K04, K14, K15, K05, K06, K07, K08, K18, K16, K2A,      \
    K12,    K21, K22, K23, K24, K34, K35, K25, K26, K27, K28, K38, K4A,          \
    K19,       K41, K42, K43, K44, K54, K55, K45, K46, K47, K58, K49,            \
    K09,  K0A,  K39,              K3A,                K59,  K69,  K57,  K29      \
) { \
    { KC_NO, K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A }, \
    { KC_NO, K11,   K12,   KC_NO, K14,   K15,   K16,   KC_NO, K18,   K19,   KC_NO }, \
    { KC_NO, K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A   }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, K34,   K35,   KC_NO, KC_NO, K38,   K39,   K3A }, \
    { KC_NO, K41,   K42,   K43,   K44,   K45,   K46,   K47,   KC_NO, K49,   K4A   }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, K54,   K55,   KC_NO, K57,   K58,   K59,   KC_NO }, \
    { KC_NO, K61,   KC_NO, KC_NO, K64,   K65,   K66,   KC_NO, K68,   K69,   K6A   }, \
    { KC_NO, K71,   K72,   K73,   K74,   K75,   K76,   K77,   K78,   KC_NO, KC_NO }, \
}
