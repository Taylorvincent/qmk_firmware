/*
Copyright 2017 Christopher Courtney <drashna@live.com> @drashna

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

#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"
#include "swapper.h"
#include "oneshot.h"
#include "tapdance.h"

enum userspace_layers {
    _COLEMAKDH,
    _QWERTY,
    _GAME,
    _SYM,
    _NAV,
    _ADJUST
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
    A_TAB,
    SA_TAB,
    // SW_WIN,  // Switch to next window         (cmd-tab)
    // SW_LANG, // Switch to next input language (ctl-spc)
};
