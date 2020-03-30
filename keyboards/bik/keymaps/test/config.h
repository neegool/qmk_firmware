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

#pragma once

// place overrides here
#undef TAPPING_TERM
#define TAPPING_TERM 190
#define TAPPING_TOGGLE 2

#define DEBOUNCE 5
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define MUSIC_MASK (keycode != KC_NO)
#define MIDI_ADVANCED

#define BACKLIGHT_PIN B6

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { E6, B4, B5 }
#define MATRIX_COL_PINS { D4, C6, D7 }
#define BACKLIGHT_BREATHING
#define BACKLIGHT_LEVELS 3
