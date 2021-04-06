#include "Taylorvincent.h"

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
    KC_ESC,  ________________NUMBER_LEFT________________,                   ________________NUMBER_RIGHT_______________, KC_DEL,
    KC_TAB,  _________________QWERTY_L1_________________,                   _________________QWERTY_R1_________________, KC_BSPC,
    KC_LCTL, _________________QWERTY_L2_________________,                   _________________QWERTY_R2_________________, KC_ENT,
    KC_LSFT, _________________QWERTY_L3_________________, _______, _______, _________________QWERTY_R3_________________, KC_RSFT,
                      DF_GAME, _________THUMB_L_________,                   _________THUMB_R_________, DF_CLMK
    ),
    [_GAME] = LAYOUT_wrapper(
    KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,                      ________________NUMBER_RIGHT_______________, KC_DEL,
    KC_T,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                      _________________QWERTY_R1_________________, KC_BSPC,
    KC_G,    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,                      _________________QWERTY_R2_________________, KC_ENT,
    KC_B,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    _______, _______, _________________QWERTY_R3_________________, KC_RSFT,
                   DF_CLMK, KC_LALT, KC_LALT,  KC_SPC,                      _________THUMB_R_________, DF_GAME
    ),
    [_COLEMAKDH] = LAYOUT_wrapper(
    KC_ESC,  ________________NUMBER_LEFT________________,                   ________________NUMBER_RIGHT_______________, KC_DEL,
    KC_TAB,  ______________COLEMAK_MOD_DH_L1____________,                   ______________COLEMAK_MOD_DH_R1____________, KC_BSPC,
    KC_LCTL, ______________COLEMAK_MOD_DH_L2____________,                   ______________COLEMAK_MOD_DH_R2____________, KC_ENT,
    KC_LSFT, ______________COLEMAK_MOD_DH_L3____________, _______, _______, ______________COLEMAK_MOD_DH_R3____________, KC_RSFT,
                      DF_GAME, _________THUMB_L_________,                   _________THUMB_R_________, DF_CLMK
    ),
    [_NAV] = LAYOUT_wrapper(
    _______, _________________FUNC_LEFT_________________,                   _________________FUNC_RIGHT________________, _______,
    _______, ________________NAV_L1_3x5_________________,                   ________________NAV_R1_3x5_________________, _______,
    _______, ________________NAV_L2_3x5_________________,                   ________________NAV_R2_3x5_________________, _______,
    _______, ________________NAV_L3_3x5_________________, _______, _______, ________________NAV_R3_3x5_________________, _______,
                      DF_CLMK, _______MOD_THUMB_L_______,                   _______MOD_THUMB_R_______, _______
    ),
    [_SYM] = LAYOUT_wrapper(
    _______, _________________FUNC_LEFT_________________,                   _________________FUNC_RIGHT________________, _______,
    _______, ________________SYM_L1_3x5_________________,                   ________________SYM_R1_3x5_________________, _______,
    _______, ________________SYM_L2_3x5_________________,                   ________________SYM_R2_3x5_________________, _______,
    _______, ________________SYM_L3_3x5_________________, _______, _______, ________________SYM_R3_3x5_________________, _______,
                      _______, _______MOD_THUMB_L_______,                   _______MOD_THUMB_R_______, _______
    ),
    [_ADJUST] = LAYOUT_wrapper(
    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,                   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
    _______, _______________ADJUST_L1_3x5_______________,                   _______________ADJUST_R1_3x5_______________, _______,
    _______, _______________ADJUST_L2_3x5_______________,                   _______________ADJUST_R2_3x5_______________, _______,
    _______, _______________ADJUST_L3_3x5_______________, _______, _______, _______________ADJUST_R3_3x5_______________, _______,
                      _______, _______MOD_THUMB_L_______,                   _______MOD_THUMB_R_______, _______
    ),
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {
    // 'logo', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00,
    0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83,
    0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x80, 0xb6, 0xb6, 0x80,
    0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0,
    0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x3f, 0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x03, 0x02, 0x06, 0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 0xff, 0xff, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0x7f, 0x3f, 0x00,
    0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06,
    0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04,
    0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00
};
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}


#    define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}


void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    uint8_t currentDefault = get_highest_layer(default_layer_state);
    uint8_t currentLayer = get_highest_layer(layer_state);

    switch (currentLayer) {
        case _NAV:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        default:
            switch (currentDefault){
                case _QWERTY:
                    oled_write_P(PSTR("QRTY"), false);
                    break;
                case _GAME:
                    oled_write_P(PSTR("GAME"), false);
                    break;
                case _COLEMAKDH:
                    oled_write_P(PSTR("CLMK"), false);
                    break;
                default:
                    oled_write_ln_P(PSTR("Undefined"), false);
            }
    }
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("C"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_ln_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_leds());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show modifier status
    render_mod_status(get_mods());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    render_keylogger_status();
}

void oled_task_user(void) {
  update_log();
  if (is_keyboard_master()) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_lily58_logo();
  }
}

#endif // OLED_DRIVER_ENABLE


// Rotary encoder related code
#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Encoder on master side
    if(IS_LAYER_ON(_SYM)) { // on Raise layer
      // Cursor control
      if (clockwise) {
          tap_code(KC_MNXT);
      } else {
          tap_code(KC_MPRV);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
    }
  }
  else if (index == 1) { // Encoder on slave side
    if(IS_LAYER_ON(_NAV)) { // on Lower layer
      //
      if (clockwise) {
          tap_code(KC_RIGHT);
      } else {
          tap_code(KC_LEFT);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_DOWN);
      } else {
          tap_code(KC_UP);
      }
    }
  }
}
#endif
