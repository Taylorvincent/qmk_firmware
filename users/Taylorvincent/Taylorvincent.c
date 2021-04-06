#include QMK_KEYBOARD_H

#include "Taylorvincent.h"

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_NAV:
        case LA_SYM:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NAV:
    case LA_SYM:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

bool sw_altTab_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_altTab_active, KC_LALT, KC_TAB, A_TAB, SA_TAB,
        keycode, record
    );
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYM, _NAV, _ADJUST);
    # if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

    rgblight_set_layer_state(1, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(2, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));

    # endif

    return state;
}

# if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAKDH));
    return state;
}
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_IJK:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM colemakdh_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 70, 6, 250, 250}
);
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 70, HSV_RED}
);
const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 70, HSV_GREEN}
);
const rgblight_segment_t PROGMEM adj_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 70, HSV_BLUE}
);

// gold 36, 255, 255

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    colemakdh_layer,
    nav_layer,
    sym_layer,    // Overrides caps lock layer
    adj_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}
#endif
