#include QMK_KEYBOARD_H

#include "keymap.h"

enum preonic_keycodes {
  CAPS_WORD = SAFE_RANGE
};

enum preonic_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _NAV,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_preonic_grid(
  KC_TAB ,  KC_Q  , KC_W   , KC_F   ,  KC_P  ,    KC_B ,   KC_J , KC_L   , KC_U    ,    KC_Y , KC_SCLN , KC_DEL  ,
  KC_TAB ,  KC_Q  , KC_W   , KC_F   ,  KC_P  ,    KC_B ,   KC_J , KC_L   , KC_U    ,    KC_Y , KC_SCLN , KC_DEL  ,
  KC_ESC ,  GUI_A , ALT_R  , CTL_S  ,  SHFT_T,    KC_G ,   KC_M , SFT_N  , CTL_E   , ALT_I  , GUI_O   , KC_QUOT ,
  KC_LSFT,  KC_Z  , KC_X   , KC_C   ,  KC_D  ,    KC_V ,   KC_K , KC_H   , KC_COMM , KC_DOT , KC_SLSH , XXXXXXX ,
  _______, _______,MO(_NAV),  LSPACE , MBSPC  , MENTER , RSPACE  ,MO(_NAV), _______, _______, _______, _______
),

[_LOWER] = LAYOUT_preonic_grid(
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  _______,GUI_TILD,ALT_BSLS,CTL_MINS, SFT_EQL, _______,                      _______,SFT_LBRC,CTL_RBRC, _______,GUI_QUOT, _______,
  _______, _______, _______, _______, _______, _______,                      _______,   UC_AE,   UC_OE,   UC_UE,   UC_SS, _______,
  _______, _______, _______, _______, ADJUST,  ADJUST,  _______,    _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_preonic_grid(
  _______,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, _______,
  _______,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, _______,
  _______,  GUI_F1,ALT_CAPS, CTL_ESC, SFT_TAB, _______,                      _______, _______, _______, _______, GUI_F12, _______,
  _______, _______, _______,  KC_INS, KC_PSCR, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, ADJUST,  _______,  _______, ADJUST,  _______, _______, _______, _______, _______
),

[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______,
  _______, _______, _______, _______, _______, _______,                      _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
  _______, _______, _______, _______, ADJUST,  ADJUST,  _______,    _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_preonic_grid(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
)

};
