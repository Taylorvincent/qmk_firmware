#include "swapper.h"

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t triggerShift,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger || keycode == triggerShift) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            if(keycode == triggerShift){
                register_code(KC_LSFT);
            }
            register_code(tabish);

        } else {
            unregister_code(tabish);
            if(keycode == triggerShift){
                unregister_code(KC_LSFT);
            }
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active) {
        unregister_code(cmdish);
        *active = false;
    }
}

