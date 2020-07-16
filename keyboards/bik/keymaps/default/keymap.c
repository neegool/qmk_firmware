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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
      MO(1),    KC_VOLD, KC_VOLU, \
      MO(2),    KC_UP,   KC_MPLY, \
      KC_LEFT,  KC_DOWN, KC_RGHT  \
  ),
  [1] = LAYOUT(
      _______, KC_MPRV, KC_MNXT,  \
      _______, KC_MSTP, KC_MPLY,  \
      _______, _______, _______   \
  ),
  [2] = LAYOUT(
      RGB_MOD, RGB_HUD, RGB_HUI,  \
      _______, RGB_SAD, RGB_SAI,  \
      RGB_TOG, RGB_VAD, RGB_VAI   \
  ),
  [3] = LAYOUT(
      _______, _______, _______,  \
      _______, _______, _______,  \
      _______, _______, _______   \
  ),
};
