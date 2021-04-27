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
/*
#define LA_NAV_ENT LT(_NAV, KC_ENT)
#define LA_NAV_ESC LT(_NAV, KC_ESC)
#define LA_SYM_TAB LT(_SYM, KC_TAB)
#define LA_SYM_DEL LT(_SYM, KC_DEL)
*/
#define LA_NAV  MO(_NAV)
#define LA_SYM  MO(_SYM)
#define DF_QWE  DF(_QWERTY)
#define DF_GAME DF(_GAME)
#define DF_CLMK DF(_COLEMAKDHM)
/*
NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

/*

## Todo

 - maybe a media layer for the vol stuff
 - 'qq' tap dance esc? Or combo something for esc? 'fp' ?
 - Miryoku, 3 -> 6 layers ? (or 2 -> 4)
 - Layer tap thumbs

 combo shit only works with basic keycodes
 - combo enter on `.,` or `space L + R` ? Fuck it enter on l thumb
 - ^^^ maybe Enter on outer thumb. Layertap

 The 3x6 assholes we need to map:
 Left to right
 6 keys Esc, Tab, Space, Ent ⏎, Bspc, Del)


 Without
             ┌───┬───┬───┐ ┌───┬───┬───┐
             │   │Bsp│   │ │   │Spc│   │
             └───┴───┴───┘ └───┴───┴───┘
             ┌───┬───┬───┐ ┌───┬───┬───┐
             │   │Del│   │ │   │Tab│   │
             └───┴───┴───┘ └───┴───┴───┘


 all thumbsz idea
             ┌───┬───┬───┐ ┌───┬───┬───┐
             │Del│Bsp│Ent│ │Tab│Spc│Esc│
             └───┴───┴───┘ └───┴───┴───┘

 No adjust idea
             ┌───┬───┬───┐ ┌───┬───┬───┐
             │   │Bsp│   │ │   │Spc│   │
             └───┴───┴───┘ └───┴───┴───┘

             ┌───┬───┬───┐ ┌───┬───┬───┐
             │   │Del│Ent│ │Tab│   │   │
             └───┴───┴───┘ └───┴───┴───┘           
*/

#define _________THUMB_L_________                         LA_SYM,  KC_BSPC, LA_NAV
#define _________THUMB_R_________                                                    LA_SYM,  KC_SPC,  LA_NAV

#define _______MOD_THUMB_L_______                         _______, KC_DEL,  KC_ENT
#define _______MOD_THUMB_R_______                                                    KC_TAB,  KC_ESC, _______

//  BASE
// ┌───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┐
// │ Q │ W │ F │ P │ B │         │ J │ L │ U │ Y │ ` │
// ├───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┤
// │ A │ R │ S │ T │ G │         │ M │ N │ E │ I │ O │
// ├───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┤
// │ Z │ X │ C │ D │ V │         │ K │ H │ , │ . │ / │
// └───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┘
//             ┌───┬───┬───┐ ┌───┬───┬───┐
//             │   │Bsp│   │ │   │Spc│   │
//             └───┴───┴───┘ └───┴───┴───┘
// 


#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_GRV
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    TD_IJK,  KC_O
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

// NAV = left hand (home row) activator
// 
// todo: swapper
// ┌───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┐
// │Esc│SAT│AT │Tab│Esc│         │Ply│Prv│V- │V+ │Nxt│ 
// ├───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┤
// │ADJ│Alt│Sft│Ctl│Win│         │   │ ◄ │ ▼ │ ▲ │ ► │
// ├───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┤
// │^Z │^X │^C │^D │^V │         │   │Hom│Pgd│Pgu│End│
// └───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┘
//
/*
 │⏯ │<< │ v-│ v+│ >>│
 │⏯│⏪│🔉│🔊│⏩│
*/
// 

#define ________________NAV_L1_3x5_________________       KC_ESC,  SA_TAB,  A_TAB,   KC_TAB,  KC_ESC
#define ________________NAV_L2_3x5_________________       ____________HOMEROW_OS_MODS_L______________
#define ________________NAV_L3_3x5_________________       C(KC_Z), C(KC_X), C(KC_C), C(KC_D), C(KC_V)

#define ________________NAV_R1_3x5_________________       _________________MEDIA_3x5_________________
#define ________________NAV_R2_3x5_________________       _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
#define ________________NAV_R3_3x5_________________       _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END

// SYM = right hand activator

// 
// LAYOUT_split_3x5_3
// ┌───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┐
// │   │ [ │ { │ ( │ + │         │ : │ ) │ } │ ] │ & │
// ├───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┤
// │ ; │ ' │ @ │ " │ - │         │Win│Ctl│Sft│Alt│ADJ│ // Normal win here
// ├───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┤
// │ ` │ * │ $ │ = │ _ │         │ # │ ! │ < │ > │ ? │
// └───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┘
// 


#define ________________SYM_L1_3x5_________________       _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_PLUS
#define ________________SYM_L2_3x5_________________       KC_SCLN, KC_QUOT, KC_AT,   KC_DQT,  KC_MINS
#define ________________SYM_L3_3x5_________________       KC_GRV,  KC_ASTR, KC_DLR,  KC_EQL,  KC_UNDS

#define ________________SYM_R1_3x5_________________       KC_COLN, KC_RPRN, KC_RCBR, KC_RBRC, KC_AMPR
#define ________________SYM_R2_3x5_________________       ____________HOMEROW_OS_MODS_R______________
#define ________________SYM_R3_3x5_________________       KC_HASH, KC_EXLM, KC_LT,   KC_GT,   KC_QUES

// raise, number

// 
// ┌───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┐
// │   │ 4 │ 5 │ 6 │ ^ │         │ | │F4 │F5 │F6 │F11│
// ├───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┤
// │ 0 │ 1 │ 2 │ 3 │ 0 │         │ \ │F1 │F2 │F3 │F10│
// ├───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┤
// │ ~ │ 7 │ 8 │ 9 │ % │         │CAP│F7 │F8 │F9 │F12│
// └───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┘
// 

#define _______________ADJUST_L1_3x5_______________       _______, KC_4,    KC_5,    KC_6,    KC_CIRC
#define _______________ADJUST_L2_3x5_______________       KC_0,    KC_1,    KC_2,    KC_3,    KC_0
#define _______________ADJUST_L3_3x5_______________       KC_TILD, KC_7,    KC_8,    KC_9,    KC_PERC

#define _______________ADJUST_R1_3x5_______________       KC_PIPE, KC_F4,   KC_F5,   KC_F6,   KC_F11
#define _______________ADJUST_R2_3x5_______________       KC_BSLS, KC_F1,   KC_F2,   KC_F3,   KC_F10
#define _______________ADJUST_R3_3x5_______________       KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F12


/* full size stuff */
#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

/* helpers*/

#define ___________________BLANK___________________       _______, _______, _______, _______, _______
#define _________________MEDIA_3x5_________________       KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
#define ____________HOMEROW_OS_MODS_L______________       LA_SYM,  OS_ALT,  OS_SHFT, OS_CTRL, OS_GUI
#define ____________HOMEROW_OS_MODS_R______________       KC_LGUI, OS_CTRL, OS_SHFT, OS_ALT,  LA_NAV


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

 old
 esc [ { ( ~       ^ ) } ] `
 tab - * = _       $
 + | @ \ %         # & ' : !

 symbol layer: 30 keys - 7 reserved slots = 23 keys available

 28 symbols if every symbol needs to be mapped:
 5 keys need to be on adjust, bslsh pipe tilde (maybe backtick)

 24 symbols if not mapping alphas
 if not mapping <>?: alphas = 1 key on adjust

 ! @ # $ % ^ & * ( ) _ + { } : " | < > ? ~      || shifted 21
 ` - = \ [ ] '                                  || non shifted 7

 todo

 ---------------------------------------------------------------------------------------------------
*/