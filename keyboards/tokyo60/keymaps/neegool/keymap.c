#include QMK_KEYBOARD_H
#include "shared_enum.h"

#define L12 0

static td_state_t td_state;

int cur_dance (qk_tap_dance_state_t *state) {
	if (state->count == 1) {
    	if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
		else { return SINGLE_HOLD; }
  	}
  	if (state->count == 2) {
		  if (state->interrupted || !state->pressed) { return DOUBLE_TAP; }
		  else { return 3; }
	}
  	else { return 3; } // any number higher than the maximum state value you return above
}

void altlp_finished (qk_tap_dance_state_t *state, void *user_data) {
  	td_state = cur_dance(state);
  	switch (td_state) {
   		case SINGLE_TAP:
    	case SINGLE_HOLD:
	  		layer_on(2);
      		break;
    	case DOUBLE_TAP:
	  		layer_off(2);
      		layer_invert(1);
  	}
}

void altlp_reset (qk_tap_dance_state_t *state, void *user_data) {
  	switch (td_state) {
    	case SINGLE_TAP:
    	case SINGLE_HOLD:
      		layer_off(KL);
      		break;
    	case DOUBLE_TAP:
      	layer_off(KL);
	 	 break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [L12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altlp_finished, altlp_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BL] = LAYOUT_60_hhkb(
        KC_ESC,   KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS, KC_DEL, \
        KC_TAB,    KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSPC,      \
        KC_LCTL,   KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,       KC_ENT,      \
        KC_LSFT,            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH,      LM(RA, MOD_LSFT), MO(FN), \
             KC_LALT, LM(1, MOD_LGUI),              KC_SPC,                         LM(RA, MOD_LALT), LM(RA, MOD_LCTL) ),

[CO] = LAYOUT_60_hhkb(
        _______,   _______, _______,_______,_______,_______,_______,_______,_______, _______, _______, _______,  _______, _______, _______, \
        _______,   _______, _______,_______,_______,_______,_______,_______,_______, _______, _______, _______, _______, _______,      \
        _______,   _______, _______,_______,_______,_______,_______,_______,_______, _______,  _______, _______,       _______,      \
        _______,            _______,_______,_______,_______,_______,_______,_______, _______, _______, _______,      _______,KC_APP,  \
             _______, _______,              _______,                        _______, _______),

[KL] = LAYOUT_60_hhkb(
        _______,   _______, _______,_______,_______,_______,_______,_______,_______, _______, _______, _______,  _______, _______, _______, \
        _______,   _______, _______,_______,_______,_______,_______,_______,_______, _______, _______, KC_UP, _______, _______,      \
        _______,   _______, _______,_______,_______,_______,_______,_______,_______, _______,  KC_LEFT, KC_RIGHT,       _______,      \
        _______,            _______,_______,_______,_______,_______,_______,_______, _______, _______, KC_DOWN,      _______,_______,  \
             _______, _______,              _______,                        _______, _______),


[FN] = LAYOUT_60_hhkb(
       KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  RESET, \
       RGB_TOG,  RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_PSCR, KC_SLCK, KC_PAUS,   KC_UP, MAGIC_TOGGLE_NKRO, KC_TRNS,  \
       KC_CAPS,  KC_MUTE, KC_VOLD,  KC_VOLU, KC_EJCT, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,       KC_PENT,       \
       KC_TRNS,       KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_TRNS, KC_PPLS, KC_PMNS,  KC_END, KC_PGDN, KC_DOWN,       KC_RSFT, KC_TRNS, \
             KC_TRNS, TO(CO),                   KC_TRNS,                         KC_RALT, KC_RCTL ),

[RA] = LAYOUT_60_hhkb(
       _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______,  _______, \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,       \
       _______,       _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,       _______, _______, \
             _______, _______,                   _______,                         _______, _______ ),
};


