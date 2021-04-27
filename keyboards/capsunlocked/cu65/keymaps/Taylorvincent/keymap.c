/*
Copyright 2020 CapsUnlocked

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "Taylorvincent.h"

#define LAYOUT_65_wrapper(...) LAYOUT_65_ansi_international_split_bs(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_wrapper(
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Hom│End│Ins│  16
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ Bsp │Del│  15
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ MO(1)│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │Pg+│  14 
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │Sft │ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │Pg-│  15
     * ├────┴───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │Ctrl│LGUI│LAlt│         Space          │RAlt│RCtl│ │ ← │ ↓ │ → │  9
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
        KC_ESC,           ________________NUMBER_LEFT________________,    ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_HOME, KC_END, KC_INS,
        KC_TAB,           _________________QWERTY_L1_________________,    _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,
        MO(1),            _________________QWERTY_L2_________________,    _________________QWERTY_R2_________________, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT, KC_NUBS, _________________QWERTY_L3_________________,    _________________QWERTY_R3_________________,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_wrapper(
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│   │   │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │ Del │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │   │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │    │    │                        │RST │    │ │   │   │   │
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
        KC_GRV,           _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, KC_F11,  KC_F12,  _______, _______, _______,
        _______,          _______________60FN_L1_3x5_________________, _______________60FN_R1_3x5_________________, _______, _______, KC_DEL,  _______,
        _______,          _______________60FN_L2_3x5_________________, _______________60FN_R2_3x5_________________, _______,          _______, _______,
        _______, _______, _______________60FN_L3_3x5_________________, _______________60FN_R3_3x5_________________, _______, _______, _______,
        _______, _______, _______,                   _______,                            RESET,   _______,          _______, _______, _______
    ),
};

