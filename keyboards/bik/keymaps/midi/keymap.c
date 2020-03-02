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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
      TT(1),    MI_C_1,   MI_D_1,
      MI_E_1,   MI_F_1,   MI_G_1,
      MI_A_1,   MI_B_1,   MI_C_2
  ),
  [1] = LAYOUT( /* Base */
      _______,  MI_C_2,   MI_D_2,
      MI_E_2,   MI_F_2,   MI_G_2,
      MI_A_2,   MI_B_2,   MI_C_3
  ),
};