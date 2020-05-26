#include QMK_KEYBOARD_H

enum keys {
	SLSH = 0,
	SCLN,
	COMM,
	DOT
};

enum layers {
	BASE = 0,
	GAME,
	NUMP,
	RAIS,
	ADJU
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
   	[SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_SLSH),
	[SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
	[COMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_LBRC),
	[DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_RBRC)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_arrow(
		KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, TD(SCLN), TD(SLSH),
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, TD(COMM), TD(DOT), KC_UP, LT(RAIS, KC_ENT),
		KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, MO(ADJU), KC_LEFT, KC_DOWN, KC_RGHT),

	[GAME] = LAYOUT_arrow(
		KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_1, KC_2, KC_3, KC_4, KC_5, KC_BSPC,
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_F1, KC_F2, KC_F3, KC_F4, KC_PSCR, KC_TRNS,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_F5, KC_F6, KC_F7, KC_F8, KC_UP, RSFT_T(KC_ENT),
		KC_LCTL, KC_LALT, KC_NO, KC_SPC, KC_SPC, MO(ADJU), KC_LEFT, KC_DOWN, KC_RGHT),

	[NUMP] = LAYOUT_arrow(
		KC_GESC, KC_NO, KC_NO, KC_NO, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_P7, KC_P8, KC_P9, KC_BSPC,
		KC_NLCK, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_PCMM, KC_P4, KC_P5, KC_P6, KC_TRNS,
		KC_TRNS, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_NO, KC_PEQL, KC_P1, KC_P2, KC_P3,KC_TRNS, LT(RAIS, KC_PENT),
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, LT(ADJU, KC_PDOT), KC_TRNS, KC_TRNS, KC_TRNS),

	[RAIS] = LAYOUT_arrow(
		KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
		RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO, KC_UNDS, KC_PLUS, KC_DQUO, KC_QUES,
		KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_LCBR, KC_RCBR, KC_MPLY, KC_TRNS,
		KC_MUTE, KC_VOLD, KC_VOLU, TG(GAME), TG(NUMP), KC_TRNS, KC_MPRV, KC_MSTP, KC_MNXT),

	[ADJU] = LAYOUT_arrow(
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
		RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO, KC_MINS, KC_EQL, KC_QUOT, KC_SLSH,
		KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_LBRC, KC_RBRC, KC_MPLY, KC_TRNS,
		KC_MUTE, KC_VOLD, KC_VOLU, TG(GAME), TG(NUMP), KC_TRNS, KC_MPRV, KC_MSTP, KC_MNXT),
};
