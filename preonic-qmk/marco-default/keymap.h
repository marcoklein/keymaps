#pragma once

#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum preonic_layers {
  _COLEMAK,
  _SHIFT,
  _NAV,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAME,
  _COLEMAK_EXP
};

enum preonic_keycodes {
  GAME = SAFE_RANGE,
  COLEMAK,
  COL_EXP,
  LSPACE,
  RSPACE,
  MBSPC,
  MENTER,
  CAPS_WORD
};

#define ADJUST MO(_ADJUST)

// home row mods
#define MOD_A LGUI_T(DE_A)
#define MOD_R LALT_T(DE_R)
#define MOD_S LCTL_T(DE_S)
#define MOD_T LSFT_T(DE_T)

#define MOD_N RSFT_T(DE_N)
#define MOD_E RCTL_T(DE_E)
#define MOD_I LALT_T(DE_I)
#define MOD_O RGUI_T(DE_O)


bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);
void process_caps_word(uint16_t keycode, const keyrecord_t *record);