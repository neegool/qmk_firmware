/* Copyright 2019 neegool
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum {
  L12 = 0
};

typedef enum {
	SINGLE_TAP,
  	SINGLE_HOLD,
  	DOUBLE_TAP
} td_state_t;

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
      		layer_off(2);
      		break;
    	case DOUBLE_TAP:
      	layer_off(2);
	 	 break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [L12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altlp_finished, altlp_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      TD(L12),  KC_MSTP, KC_MPLY,
      KC_MPRV,  KC_UP,   KC_MNXT,
      KC_LEFT,  KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT(
      _______, _______, BL_BRTG,
      BL_STEP, BL_DEC,  BL_INC,
      BL_TOGG, BL_OFF,  BL_ON
  ),
  [2] = LAYOUT(
      _______, KC_VOLD, KC_VOLU,
      _______, _______, _______,
      _______, _______, _______
  ),
  [3] = LAYOUT(
      TT(4),    MI_C_1,   MI_D_1,
      MI_E_1,   MI_F_1,   MI_G_1,
      MI_A_1,   MI_B_1,   MI_C_2
  ),
  [4] = LAYOUT(
      _______,  MI_C_2,   MI_D_2,
      MI_E_2,   MI_F_2,   MI_G_2,
      MI_A_2,   MI_B_2,   MI_C_3
  )
};

void bootmagic_lite(void) {
    matrix_scan();
    wait_ms(DEBOUNCE * 2);
    matrix_scan();

    if (matrix_get_row(BOOTMAGIC_LITE_ROW) & (1 << BOOTMAGIC_LITE_COLUMN)) {
      layer_on(3);
    }
    else if (matrix_get_row(BOOTMAGIC_LITE_ROW) & (1 << 1)) {
      bootloader_jump();
    }
}
