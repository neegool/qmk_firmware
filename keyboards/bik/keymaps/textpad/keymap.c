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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

typedef struct {
    bool is_press_action;
    int  state;
} tap;

enum {
    SINGLE_TAP        = 1,
    SINGLE_HOLD       = 2,
    DOUBLE_TAP        = 3,
    DOUBLE_HOLD       = 4,
    DOUBLE_SINGLE_TAP = 5,  // send two single taps
    TRIPLE_TAP        = 6,
    TRIPLE_HOLD       = 7
};

enum {
  TD_1 = 0,
  TD_2,
  TD_3,
  TD_4,
  TD_5,
  TD_6,
  TD_7,
  TD_8,
  TD_9
  

const uint16_t keys_2[] = { KC_A, KC_B, KC_C, KC_2 };
const uint16_t keys_3[] = { KC_D, KC_E, KC_F, KC_3 };
const uint16_t keys_4[] = { KC_G, KC_H, KC_I, KC_4 };
const uint16_t keys_5[] = { KC_J, KC_K, KC_L, KC_5 };
const uint16_t keys_6[] = { KC_M, KC_N, KC_O, KC_6 };
const uint16_t keys_7[] = { KC_P, KC_Q, KC_R, KC_S, KC_7 };
const uint16_t keys_8[] = { KC_T, KC_U, KC_V, KC_8 };
const uint16_t keys_9[] = { KC_W, KC_X, KC_Y, KC_Z, KC_9 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
      TD(TD_1), TD(TD_2), TD(TD_3), \
      TD(TD_4), TD(TD_5), TD(TD_6), \
      TD(TD_7), TD(TD_8), TD(TD_9)  \
  ),
};

// int cur_dance (qk_tap_dance_state_t *state) {
//   if (state->count == 1) {
//     if (state->interrupted || !state->pressed)  return TAP;
//     //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
//     else return HOLD;
// }

static tap tap_state1 = {
  .is_press_action = true,
  .state = 0
};

/* 1 key */
void dance_cln_tap_1(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(keys_2[0]);
    } else {
        unregister_code(KC_BSPC);
        unregister_code(keys_2[(state->count - 2) % 4]);
        register_code(KC_BSPC);
        register_code(keys_2[(state->count - 1) % 4]);
    }
}

void dance_cln_reset_1(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_BSPC);
    unregister_code(keys_2[0]);
    unregister_code(keys_2[1]);
    unregister_code(keys_2[2]);
    unregister_code(keys_2[3]);
}
/* end 1 key */

/* 2 key */
void dance_cln_tap_2(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(keys_2[0]);
    } else {
        unregister_code(KC_BSPC);
        unregister_code(keys_2[(state->count - 2) % 4]);
        register_code(KC_BSPC);
        register_code(keys_2[(state->count - 1) % 4]);
    }
}

void dance_cln_reset_2(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_BSPC);
    unregister_code(keys_2[0]);
    unregister_code(keys_2[1]);
    unregister_code(keys_2[2]);
    unregister_code(keys_2[3]);
}
/* end 2 key */

/* 3 key */
void dance_cln_tap_3(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(keys_3[0]);
    } else {
        unregister_code(KC_BSPC);
        unregister_code(keys_3[(state->count - 2) % 4]);
        register_code(KC_BSPC);
        register_code(keys_3[(state->count - 1) % 4]);
    }
}

void dance_cln_reset_3(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_BSPC);
    unregister_code(keys_3[0]);
    unregister_code(keys_3[1]);
    unregister_code(keys_3[2]);
    unregister_code(keys_3[3]);
}
/* end 3 key */

/* 4 key */
void dance_cln_tap_4(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(keys_4[0]);
    } else {
        unregister_code(KC_BSPC);
        unregister_code(keys_4[(state->count - 2) % 4]);
        register_code(KC_BSPC);
        register_code(keys_4[(state->count - 1) % 4]);
    }
}

void dance_cln_reset_4(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_BSPC);
    unregister_code(keys_4[0]);
    unregister_code(keys_4[1]);
    unregister_code(keys_4[2]);
    unregister_code(keys_4[3]);
}
/* end 4 key */

/* 5 key */
void dance_cln_tap_5(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(keys_5[0]);
    } else {
        unregister_code(KC_BSPC);
        unregister_code(keys_5[(state->count - 2) % 4]);
        register_code(KC_BSPC);
        register_code(keys_5[(state->count - 1) % 4]);
    }
}

void dance_cln_reset_5(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_BSPC);
    unregister_code(keys_5[0]);
    unregister_code(keys_5[1]);
    unregister_code(keys_5[2]);
    unregister_code(keys_5[3]);
}
/* end 5 key */

/* 6 key */
void dance_cln_tap_6(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(keys_6[0]);
    } else {
        unregister_code(KC_BSPC);
        unregister_code(keys_6[(state->count - 2) % 4]);
        register_code(KC_BSPC);
        register_code(keys_6[(state->count - 1) % 4]);
    }
}

void dance_cln_reset_6(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_BSPC);
    unregister_code(keys_6[0]);
    unregister_code(keys_6[1]);
    unregister_code(keys_6[2]);
    unregister_code(keys_6[3]);
}
/* end 6 key */

/* 7 key */
void dance_cln_tap_7(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(keys_7[0]);
    } else {
        unregister_code(KC_BSPC);
        unregister_code(keys_7[(state->count - 2) % 5]);
        register_code(KC_BSPC);
        register_code(keys_7[(state->count - 1) % 5]);
    }
}

void dance_cln_reset_7(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_BSPC);
    unregister_code(keys_7[0]);
    unregister_code(keys_7[1]);
    unregister_code(keys_7[2]);
    unregister_code(keys_7[3]);
    unregister_code(keys_7[4]);
}
/* end 7 key */

/* 8 key */
void dance_cln_tap_8(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(keys_8[0]);
    } else {
        unregister_code(KC_BSPC);
        unregister_code(keys_8[(state->count - 2) % 4]);
        register_code(KC_BSPC);
        register_code(keys_8[(state->count - 1) % 4]);
    }
}

void dance_cln_finish_8(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (!state->interrupted && state->pressed)
        {
            unregister_code(keys_8[0]);
            register_code(KC_BSPC);
            register_code(KC_SPC);
            reset_tap_dance(state);
        }
        else
        {
          /* code */
        }
        
    }
}

void dance_cln_reset_8(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_SPC);
    unregister_code(KC_BSPC);
    unregister_code(keys_8[0]);
    unregister_code(keys_8[1]);
    unregister_code(keys_8[2]);
    unregister_code(keys_8[3]);
}
/* end 8 key */

/* 9 key */
void dance_cln_tap_9(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(keys_9[0]);
    } else {
        unregister_code(KC_BSPC);
        unregister_code(keys_9[(state->count - 2) % 4]);
        register_code(KC_BSPC);
        register_code(keys_9[(state->count - 1) % 4]);
    }
}

void dance_cln_reset_9(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_BSPC);
    unregister_code(keys_9[0]);
    unregister_code(keys_9[1]);
    unregister_code(keys_9[2]);
    unregister_code(keys_9[3]);
    unregister_code(keys_9[4]);
}
/* end 9 key */

qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_2] = ACTION_TAP_DANCE_FN_ADVANCED (dance_cln_tap_2, dance_cln_reset_2, dance_cln_reset_2),
 [TD_3] = ACTION_TAP_DANCE_FN_ADVANCED (dance_cln_tap_3, dance_cln_reset_3, dance_cln_reset_3),
 [TD_4] = ACTION_TAP_DANCE_FN_ADVANCED (dance_cln_tap_4, dance_cln_reset_4, dance_cln_reset_4),
 [TD_5] = ACTION_TAP_DANCE_FN_ADVANCED (dance_cln_tap_5, dance_cln_reset_5, dance_cln_reset_5),
 [TD_6] = ACTION_TAP_DANCE_FN_ADVANCED (dance_cln_tap_6, dance_cln_reset_6, dance_cln_reset_6),
 [TD_7] = ACTION_TAP_DANCE_FN_ADVANCED (dance_cln_tap_7, dance_cln_reset_7, dance_cln_reset_7),
 [TD_8] = ACTION_TAP_DANCE_FN_ADVANCED (dance_cln_tap_8, dance_cln_reset_8, dance_cln_reset_8),
 [TD_9] = ACTION_TAP_DANCE_FN_ADVANCED (dance_cln_tap_9, dance_cln_reset_9, dance_cln_reset_9)

};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 
// }

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
