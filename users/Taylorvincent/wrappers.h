#pragma once
#include "Taylorvincent.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

#define LA_NAV  MO(_NAV)
#define LA_SYM  MO(_SYM)
#define LA_ADJ  MO(_ADJUST)
#define DF_QWE  DF(_QWERTY)
#define DF_GAME DF(_GAME)
#define DF_CLMK DF(_COLEMAKDH)
/*
NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

/*

## Todo

 The 3x6 assholes we need to map:
 Left to right
 6 keys Esc, Tab ⭾, Space, Ent ⏎, Bspc ⌫ , Del ⌦)
        
*/

#define _________THUMB_L_________                         LA_SYM,  OS_SHFT, LA_NAV
#define _________THUMB_R_________                                                    LA_SYM,  KC_SPC,  LA_NAV

/*
#define _______MOD_THUMB_L_______                         _______, KC_DEL,  KC_ENT
#define _______MOD_THUMB_R_______                                                    KC_TAB,  KC_ESC, _______
*/

//  BASE
// ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
// │  Q  │  W tab F  │  P  │  B  │       │  J  │  L  │  U Bsp Y  │  `  │
// ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
// │  A  │  R  │  S  │  T  │  G  │       │  M  │  N  │  E  │  I  │  O  │
// ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
// │  Z  │  X esc C  │  D  │  V  │       │  K  │  H  │  , Ent .  │  /  │
// └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
//             ┌─────┬─────┬─────┐       ┌─────┬─────┬─────┐ 
//             │     │Shift│ NAV │       │ SYM │Space│     │
//             └─────┴─────┴─────┘       └─────┴─────┴─────┘
//


#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_GRV
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    TD_IJK,  KC_O
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

/*
 │⏯ │<< │ v-│ v+│ >>│
 │⏯│⏪│🔉│🔊│⏩│
*/

//  NAV
// ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
// │     │ SAT │  AT │     │     │       │ Pgu │ Hom │  ▲  │ End │     │
// ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
// │ FUN │ Alt │ Sft │ Ctl │ Gui │       │ Pgd │  ◄  │  ▼  │  ►  │     │
// ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
// │ ^Z  │ ^X  │ ^C  │ ^D  │ ^V  │       │ Ply │ Prv │ V-  │ V+  │ Nxt │ // movable if needed
// └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
//             ┌─────┬─────┬─────┐       ┌─────┬─────┬─────┐
//             │     │     │     │       │     │     │     │
//             └─────┴─────┴─────┘       └─────┴─────┴─────┘
//

#define ________________NAV_L1_3x5_________________       _______, SA_TAB,  A_TAB,   _______, _______
#define ________________NAV_L2_3x5_________________       ____________HOMEROW_OS_MODS_L______________
#define ________________NAV_L3_3x5_________________       C(KC_Z), C(KC_X), C(KC_C), C(KC_D), C(KC_V)

#define ________________NAV_R1_3x5_________________       KC_PGUP, KC_HOME, KC_UP,   KC_END,   _______
#define ________________NAV_R2_3x5_________________       KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______   
#define ________________NAV_R3_3x5_________________       _________________MEDIA_3x5_________________

// SYM = right hand activator
// ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
// │  `  │  {  │  (  │  [  │     │       │  ^  │  |  │  &  │  *  │  ;  │
// ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
// │  :  │  -  │  +  │  =  │  @  │       │ Gui │ Ctl │ Sft │ Alt │ NUM │
// ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
// │  \  │  _  │  '  │  "  │  $  │       │  ~  │  !  │  <  │  >  │  ?  │
// └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
//             ┌─────┬─────┬─────┐       ┌─────┬─────┬─────┐
//             │     │     │     │       │     │     │     │
//             └─────┴─────┴─────┘       └─────┴─────┴─────┘



#define ________________SYM_L1_3x5_________________       KC_GRV,  TD_CBR,  TD_PRN,  TD_BRC,  _______
#define ________________SYM_L2_3x5_________________       KC_COLN, KC_MINS, KC_PLUS, KC_EQL, KC_AT
#define ________________SYM_L3_3x5_________________       KC_BSLS, KC_UNDS, KC_QUOT, KC_DQT, KC_DLR

#define ________________SYM_R1_3x5_________________       KC_CIRC, KC_PIPE, KC_AMPR, KC_ASTR, KC_SCLN
#define ________________SYM_R2_3x5_________________       ____________HOMEROW_OS_MODS_R______________
#define ________________SYM_R3_3x5_________________       KC_TILD, KC_EXLM, KC_LT,   KC_GT,   KC_QUES

// ADJUST
// 
// ┌─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┐
// │     │  7  │  8  │  9  │     │         │     │ F7  │ F8  │ F9  │ F12 │
// ├─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┤
// │  #  │  4  │  5  │  6  │  %  │         │     │ F4  │ F5  │ F6  │ F11 │
// ├─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┤
// │  0  │  1  │  2  │  3  │     │         │     │ F1  │ F2  │ F3  │ F10 │
// └─────┴─────┴─────┴─────┴─────┘         └─────┴─────┴─────┴─────┴─────┘
//             ┌─────┬─────┬─────┐         ┌─────┬─────┬─────┐
//             │     │  0  │     │         │     │     │     │
//             └─────┴─────┴─────┘         └─────┴─────┴─────┘
//            

#define _______________ADJUST_L1_3x5_______________       _______, KC_7,    KC_8,    KC_9,    _______
#define _______________ADJUST_L2_3x5_______________       KC_HASH, KC_4,    KC_5,    KC_6,    KC_PERC
#define _______________ADJUST_L3_3x5_______________       KC_0,    KC_1,    KC_2,    KC_3,    _______

#define _______________ADJUST_R1_3x5_______________       _______, KC_F7,   KC_F8,   KC_F9,   KC_F12
#define _______________ADJUST_R2_3x5_______________       _______, KC_F4,   KC_F5,   KC_F6,   KC_F11
#define _______________ADJUST_R3_3x5_______________       _______, KC_F1,   KC_F2,   KC_F3,   KC_F10


/* full size stuff */
#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

/* helpers*/

#define ___________________BLANK___________________       _______, _______, _______, _______, _______
#define _________________MEDIA_3x5_________________       KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
#define ____________HOMEROW_OS_MODS_L______________       LA_ADJ,  OS_ALT,  OS_SHFT, OS_CTRL, OS_GUI
#define ____________HOMEROW_OS_MODS_R______________       KC_LGUI, OS_CTRL, OS_SHFT, OS_ALT,  LA_ADJ


#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _______________60FN_L1_3x5_________________       _______, KC_UP,   _______, _______, _______
#define _______________60FN_L2_3x5_________________       KC_LEFT, KC_DOWN, KC_RGHT, _______, _______
#define _______________60FN_L3_3x5_________________       _______, _______, _______, _______, _______

#define _______________60FN_R1_3x5_________________       ________________NAV_R1_3x5_________________
#define _______________60FN_R2_3x5_________________       ________________NAV_R2_3x5_________________
#define _______________60FN_R3_3x5_________________       ________________NAV_R3_3x5_________________
/*
 Symbol brainstorm:
 ---------------------------------------------------------------------------------------------------

 28 symbols if every symbol needs to be mapped:

 ! @ # $ % ^ & * ( ) _ + { } : " | < > ? ~      || shifted 21
 ` - = \ [ ] '                                  || non shifted 7


 ---------------------------------------------------------------------------------------------------
*/