#pragma once

#include QMK_KEYBOARD_H

// #include "caps_word.h"

// layers

#define ADJUST MO(_ADJUST)
#define LSPACE LT(_LOWER, KC_SPACE)
#define RSPACE LT(_LOWER, KC_SPACE)
#define MBSPC LT(_RAISE, KC_BSPC)
#define MENTER LT(_RAISE, KC_ENTER)

// umlauts

#define UC_AE UC(0x00E4)// uppercase, 0x00C4)
#define UC_OE UC(0x00F6)// uppercase, 0x00D6)
#define UC_UE UC(0x00FC)// uppercase, 0x00DC)
#define UC_SS UC(0x00DF)

// home row mods

// _COLEMAK
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

#define SFT_N RSFT_T(KC_N)
#define CTL_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

// _LOWER
#define GUI_TILD LGUI_T(KC_TILD)
#define ALT_BSLS LALT_T(KC_BSLS)
#define CTL_MINS LCTL_T(KC_MINS)
#define SFT_EQL LSFT_T(KC_EQL)

#define SFT_LBRC RSFT_T(KC_LBRC)
#define CTL_RBRC RCTL_T(KC_RBRC)
// #define ALT
#define GUI_QUOT RGUI_T(KC_QUOT)

// _RAISE
#define GUI_F1 LGUI_T(KC_F1)
#define ALT_CAPS LALT_T(CAPS_WORD)
#define CTL_ESC LCTL_T(KC_ESC)
#define SFT_TAB LSFT_T(KC_TAB)

#define GUI_F12 RGUI_T(KC_F12)