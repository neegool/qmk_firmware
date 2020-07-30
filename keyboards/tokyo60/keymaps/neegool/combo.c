/* Copyright 2020 Christopher Ko <chriskopher@gmail.com>
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

#include "shared_enum.h"
#include "quantum.h"

enum combo_event {
    SD_LAYER_COMBO,
};

const uint16_t PROGMEM sd_combo[] = {KC_APP, KC_BSPC, COMBO_END};  // Combo: S + D for SuperDuper mode

// Register the combo action
combo_t key_combos[COMBO_COUNT] = {
    [SD_LAYER_COMBO] = COMBO_ACTION(sd_combo),
};

// Called after a combo event is triggered
void process_combo_event(uint8_t combo_index, bool pressed) {
    switch (combo_index) {
        case SD_LAYER_COMBO:
            layer_off(CO);
            // if (pressed) {
            //     layer_on(FN);
            // } else {
            //     layer_off(FN);
            // }
            break;
    }
}
