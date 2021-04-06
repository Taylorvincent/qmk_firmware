#include "Taylorvincent.h"

// COMBOS DONT WORK WITH OSM aaaaaaaaaaaaaa

enum combos {
  WF_TAB,
  XC_ESC,
  UY_ENT,
  PC_ENT,
};

const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM pc_combo[] = {KC_DOT, KC_COMMA, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [WF_TAB] = COMBO(wf_combo, KC_TAB),
  [XC_ESC] = COMBO(xc_combo, KC_ESC),
  [UY_ENT] = COMBO(uy_combo, KC_ENT),
  [PC_ENT] = COMBO(pc_combo, KC_ENT),
};
