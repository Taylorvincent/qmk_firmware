#include "Taylorvincent.h"

// [Init Variables] ----------------------------------------------------------//
extern uint8_t is_master;
// Boolean to store
bool eeprom_oled_enabled = false;

// [Keymaps] -----------------------------------------------------------------//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAKDH] = LAYOUT_wrapper(
        _______, ______________COLEMAK_MOD_DH_L1____________,    ______________COLEMAK_MOD_DH_R1____________, _______,
        _______, ______________COLEMAK_MOD_DH_L2____________,    ______________COLEMAK_MOD_DH_R2____________, _______,
        _______, ______________COLEMAK_MOD_DH_L3____________,    ______________COLEMAK_MOD_DH_R3____________, _______,
                                   _________THUMB_L_________,    _________THUMB_R_________
  ),
	[_QWERTY] = LAYOUT_wrapper(
        _______, _________________QWERTY_L1_________________,    _________________QWERTY_R1_________________, _______,
        _______, _________________QWERTY_L2_________________,    _________________QWERTY_R2_________________, _______,
        _______, _________________QWERTY_L3_________________,    _________________QWERTY_R3_________________, _______,
                                   _________THUMB_L_________,    _________THUMB_R_________
  ),
    [_NAV] = LAYOUT_wrapper(
        _______, ________________NAV_L1_3x5_________________,    ________________NAV_R1_3x5_________________, _______,
        _______, ________________NAV_L2_3x5_________________,    ________________NAV_R2_3x5_________________, _______,
        _______, ________________NAV_L3_3x5_________________,    ________________NAV_R3_3x5_________________, _______,
                                   _______, _______, _______,    _______, _______, _______
    ),
    [_SYM] = LAYOUT_wrapper(
        _______, ________________SYM_L1_3x5_________________,    ________________SYM_R1_3x5_________________, _______,
        _______, ________________SYM_L2_3x5_________________,    ________________SYM_R2_3x5_________________, _______,
        _______, ________________SYM_L3_3x5_________________,    ________________SYM_R3_3x5_________________, _______,
                                   _______, _______, _______,    _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_wrapper(
        _______, _______________ADJUST_L1_3x5_______________,    _______________ADJUST_R1_3x5_______________, _______,
        _______, _______________ADJUST_L2_3x5_______________,    _______________ADJUST_R2_3x5_______________, _______,
        _______, _______________ADJUST_L3_3x5_______________,    _______________ADJUST_R3_3x5_______________, _______,
                                   _______, KC_0,    _______,    _______, _______, _______
    ),
};


// [OLED Configuration] ------------------------------------------------------//
#ifdef OLED_DRIVER_ENABLE


// Oled timer similar to Drashna's
static uint32_t oled_timer = 0;
// Init Oled and Rotate....
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (has_usb())
      return OLED_ROTATION_180;  // flips the display 180 to see it from my side
    return rotation;
}

// Read logo from font file
const char *read_logo(void);

// {OLED helpers} -----------------------------------------------//

// Render Blank Space
void render_space(void) {
    oled_write_ln_P(PSTR("     "), false);
}

// Render separator lines for oled display
void render_separator(void) {
    switch (get_highest_layer(layer_state)){
        default:
            oled_write_ln_P(PSTR("++++++++++++++++++++"), false);
    }
}

// Render current layer state
void render_layer_state(void){
	// If you want to change the display of OLED, you need to change here
    switch (get_highest_layer(layer_state)){
        case _QWERTY:
            oled_write_ln_P(PSTR("| MODE | QWERTY    ]"), false);
            break;
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("| MODE | COLEMAK   ]"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("| MODE | NUMBERS   ]"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("| MODE | FUNCTION  ]"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("| MODE | ADJUST    ]"), false);
            break;
        default:
            oled_write_ln_P(PSTR("| MODE | UNDEF     ]"), false);
    }
}

// Render USB State
void render_usb_state(void) {
    switch (USB_DeviceState) {
      case DEVICE_STATE_Unattached:
          oled_write_ln_P(PSTR("| USB  | FREE      ]"), false);
          break;
      case DEVICE_STATE_Suspended:
          oled_write_ln_P(PSTR("| USB  | SLEEP     ]"), false);
          break;
      case DEVICE_STATE_Configured:
          oled_write_ln_P(PSTR("| USB  | READY     ]"), false);
          break;
      case DEVICE_STATE_Powered:
          oled_write_ln_P(PSTR("| USB  | PWRD      ]"), false);
          break;
      case DEVICE_STATE_Default:
          oled_write_ln_P(PSTR("| USB  | DFLT      ]"), false);
          break;
      case DEVICE_STATE_Addressed:
          oled_write_ln_P(PSTR("| USB  | ADDRS     ]"), false);
          break;
      default:
          oled_write_ln_P(PSTR("| USB  | INVALID   ]"), false);
    }
}

// Render Logo
void render_logo(void) {
    oled_write(read_logo(), false);
}

// Master OLED Screen (Left Hand )
void render_master_oled(void) {
    // Switch display based on Layer
    switch (get_highest_layer(layer_state)){
        default:
            render_separator();
            render_layer_state();
            render_separator();
            render_usb_state();
    }
}

// slave OLED scren (Right Hand)
void render_slave_oled(void) {
    render_logo();
}

// {OLED Task} -----------------------------------------------//
void oled_task_user(void) {
      // Drashna style timeout for LED and OLED Roughly 5mins
      if (timer_elapsed32(oled_timer) > 300000) {
          oled_off();
          // rgb_matrix_disable_noeeprom();
          return;
      }
      else {
          oled_on();
      }
      // Show logo when USB dormant
      switch (USB_DeviceState) {
          case DEVICE_STATE_Unattached:
          case DEVICE_STATE_Powered:
          case DEVICE_STATE_Suspended:
            render_logo();
            break;
          default:
            if (is_master) {
                render_master_oled();
            } else {
                render_slave_oled();
            }
      }
}
#endif

#ifdef RGB_MATRIX_ENABLE

rgb_config_t rgb_matrix_config;

void suspend_power_down_keymap(void) { rgb_matrix_set_suspend_state(true); }

void suspend_wakeup_init_keymap(void) { rgb_matrix_set_suspend_state(false); }


void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode, uint8_t speed, uint8_t led_type) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_config.hsv.v) {
        hsv.v = rgb_matrix_config.hsv.v;
    }

    // switch (mode) {
    //     case 1:  // breathing
    //     {
    //         uint16_t time = scale16by8(g_rgb_counters.tick, speed / 8);
    //         hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    //         RGB rgb       = hsv_to_rgb(hsv);
    //         for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
    //             if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
    //                 rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    //             }
    //         }
    //         break;
    //     }
    //     default:  // Solid Color
    //     {
            RGB rgb = hsv_to_rgb(hsv);
            for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
            }
    //         break;
    //     }
    // }
}


void check_default_layer(uint8_t mode, uint8_t type) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            rgb_matrix_layer_helper(HSV_PINK, mode, rgb_matrix_config.speed, type);
            break;
        // case _COLEMAKDH:
        //     rgb_matrix_layer_helper(HSV_MAGENTA, mode, rgb_matrix_config.speed, type);
        //     break;
    }
}


void rgb_matrix_indicators_user(void) {

        switch (get_highest_layer(layer_state)) {
            case _NAV:
                rgb_matrix_layer_helper(HSV_RED, 0, rgb_matrix_config.speed, LED_FLAG_KEYLIGHT);
                rgb_matrix_layer_helper(HSV_RED, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                rgb_matrix_layer_helper(HSV_RED, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _SYM:
                rgb_matrix_layer_helper(HSV_GREEN, 0, rgb_matrix_config.speed, LED_FLAG_KEYLIGHT);
                rgb_matrix_layer_helper(HSV_GREEN, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                rgb_matrix_layer_helper(HSV_GREEN, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _ADJUST:
                rgb_matrix_layer_helper(HSV_BLUE, 0, rgb_matrix_config.speed, LED_FLAG_KEYLIGHT);
                rgb_matrix_layer_helper(HSV_BLUE, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                rgb_matrix_layer_helper(HSV_BLUE, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            // default: {
            //     check_default_layer(IS_LAYER_ON(_MODS), LED_FLAG_UNDERGLOW);
            //     break;
            // }
        }
        // Color modifiers based on qwerty/colemak
        check_default_layer(0, LED_FLAG_KEYLIGHT);
    }

#endif
