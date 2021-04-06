#include "tapdance.h"

#include "quantum.h"

void tap(uint16_t keycode){
    register_code(keycode);
    unregister_code(keycode);
};

void dance_ijk_eachTap(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap(KC_I);
            break;
        case 2:
            tap(KC_J);
            break;
        case 3:
            tap(KC_K);
            reset_tap_dance(state);
            break;
    }
}

// All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_IJK] = ACTION_TAP_DANCE_FN_ADVANCED(dance_ijk_eachTap, NULL, NULL),
    [CT_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [CT_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [CT_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};