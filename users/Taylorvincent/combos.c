#include "Taylorvincent.h"

enum combos {
  WF_TAB,
  XC_ESC,
  UY_BSP,
  PC_ENT,
  CC_CAP,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM pc_combo[] = {KC_DOT, KC_COMMA, COMBO_END};
const uint16_t PROGMEM cc_combo[] = {KC_C, KC_COMMA, COMBO_END};

combo_t key_combos[] = {
  [WF_TAB] = COMBO(wf_combo, KC_TAB),
  [XC_ESC] = COMBO(xc_combo, KC_ESC),
  [UY_BSP] = COMBO(uy_combo, KC_BSPC),
  [PC_ENT] = COMBO(pc_combo, KC_ENT),
  [CC_CAP] = COMBO(cc_combo, KC_CAPS),
};
