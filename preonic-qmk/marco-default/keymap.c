#include QMK_KEYBOARD_H

#include "keymap.h"

#ifdef AUDIO_ENABLE
float colemak_sound[][2] = SONG(COLEMAK_SOUND);
float game_sound[][2] = SONG(GUITAR_SOUND);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_preonic_grid(
  DE_GRV ,  DE_1  , DE_2   , DE_3   ,  DE_4  ,    DE_5,   DE_6 , DE_7   , DE_8   ,    DE_9, DE_0   , KC_BSPC,
  KC_TAB ,  DE_Q  , DE_W   , DE_F   ,  DE_P  ,    DE_B,   DE_J , DE_L   , DE_U   ,    DE_Y, DE_SCLN, KC_DEL ,
  KC_ESC ,  MOD_A , MOD_R  , MOD_S  ,  MOD_T ,    DE_G,   DE_M , MOD_N  , MOD_E  , MOD_I  , MOD_O  , DE_QUOT,
CAPS_WORD,  DE_Z  , DE_X   , DE_C   ,  DE_D  ,    DE_V,   DE_K , DE_H   , DE_COMM, DE_DOT , DE_SLSH, XXXXXXX,
  COL_EXP, XXXXXXX, XXXXXXX,MO(_NAV), LSPACE , MBSPC  , MENTER , RSPACE ,MO(_NAV), XXXXXXX, XXXXXXX, XXXXXXX
),

// custom key codes on shift
[_SHIFT] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_COLN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_DQUO,
  _______, _______, _______, _______, _______, _______, _______, _______, DE_LABK, DE_RABK, DE_QUES, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP  , KC_PGDN, _______, _______,
  _______, KC_LWIN, KC_LALT, KC_LCTL, KC_LSFT, _______, KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT, KC_END , _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

// DE_(A|O|U)DIA = ae, oe, ue
[_LOWER] = LAYOUT_preonic_grid(
  DE_TILD, DE_EXLM, DE_AT,   DE_HASH, DE_DLR,  DE_PERC, DE_CIRC, DE_AMPR, DE_ASTR, DE_LPRN, DE_RPRN, KC_BSPC,
  DE_TILD, DE_EXLM, DE_AT,   DE_HASH, DE_DLR,  DE_PERC, DE_CIRC, DE_AMPR, DE_ASTR, DE_LPRN, DE_RPRN, KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6  , DE_UNDS, DE_PLUS, DE_LCBR, DE_RCBR, DE_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 , DE_ADIA, DE_ODIA, DE_UDIA, DE_SS  , _______,
  _______, _______, _______, _______, ADJUST,  _______, _______, ADJUST , KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_preonic_grid(
  DE_GRV,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,   DE_6  ,    DE_7,    DE_8,    DE_9,    DE_0,    KC_BSPC,
  DE_GRV,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,   DE_6  ,    DE_7,    DE_8,    DE_9,    DE_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6 , DE_MINS, DE_EQL,   DE_LBRC, DE_RBRC, DE_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, _______, _______, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, ADJUST, ADJUST, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_COLEMAK_EXP] = LAYOUT_preonic_grid(
  DE_GRV , DE_1   , DE_2   , DE_3   , DE_4   , DE_5   ,   DE_6 , DE_7   , DE_8   , DE_9   , DE_0   , KC_BSPC,
  KC_TAB , DE_Q   , DE_W   , DE_F   , DE_P   , DE_B   ,   DE_J , DE_L   , DE_U   , DE_Y   , DE_SCLN, KC_DEL ,
  KC_ESC , MOD_A  , MOD_R  , MOD_S  , MOD_T  , DE_G   ,   DE_M , MOD_N  , MOD_E  , MOD_I  , MOD_O  , DE_QUOT,
  XXXXXXX, DE_Z   , DE_X   , DE_C   , DE_D   , DE_V   ,   DE_K , DE_H   , DE_COMM, DE_DOT , DE_SLSH, XXXXXXX,
  GAME   , XXXXXXX, XXXXXXX, XXXXXXX, LSPACE , MBSPC  , MENTER , RSPACE , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

// [_NAV] = LAYOUT_preonic_grid(
//   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, KC_7   , KC_8   , KC_9   , _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, KC_4   , KC_5   , KC_6   , _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, KC_1   , KC_2   , KC_3   , _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, KC_0   , _______, _______, _______, _______,
// ),

// no home row mods
[_GAME] = LAYOUT_preonic_grid(
  DE_GRV , DE_1  , DE_2   , DE_3   ,  DE_4  ,    DE_5 ,   DE_6 , DE_7   , DE_8    ,    DE_9 , DE_0    , KC_BSPC ,
  KC_TAB , DE_Q  , DE_W   , DE_F   ,  DE_P  ,    DE_B ,   DE_J , DE_L   , DE_U    ,    DE_Y , DE_SCLN , KC_DEL  ,
  KC_ESC , DE_A  , DE_R   , DE_S   ,  DE_T  ,    DE_G ,   DE_M , DE_N   , DE_E    , DE_I    , DE_O    , DE_QUOT ,
  KC_LSFT, DE_Z  , DE_X   , DE_C   ,  DE_D  ,    DE_V ,   DE_K , DE_H   , DE_COMM , DE_DOT  , DE_SLSH , KC_ENT  ,
  COLEMAK,KC_LCTL, KC_LALT, KC_LGUI, LSPACE , KC_LSFT, KC_RSFT , KC_SPACE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
)

}; // keymap function end


uint8_t mod_state;
bool process_shift_layer(uint16_t keycode, const keyrecord_t *record) {
  mod_state = get_mods();
  if (keycode == DE_COMM) {
    // FIXME initial call of this function still returns key of base layer
    // solution might be to manually handle the home row shift mod
    // or just remap the keys...
    keycode = DE_LABK;
  }
  switch (keycode) {
    // keycodes to send without shift
    case DE_LABK:
      if (record->event.pressed) {
        del_mods(MOD_MASK_SHIFT);
        register_code(keycode);
        set_mods(mod_state);
      } else {
        unregister_code(keycode);
      }
      return false;
  }
  return true;
}

// detect interrupts of dual function layer keys
bool layer_key_active = true;
uint8_t mods_on_layer_activation = 0;

// handle custom input
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  process_caps_word(keycode, record);

  if (record->event.pressed)
  {
    layer_key_active = false;
  }

  if (get_mods() & MOD_MASK_SHIFT) {
    layer_on(_SHIFT);
    if (!process_shift_layer(keycode, record)) {
     return false;
    }
  } else {
    layer_off(_SHIFT);
  }

  switch (keycode) {

    /* layer codes */
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(colemak_sound);
        #endif
        default_layer_set(1U << _COLEMAK);
      }
      return false;
    case COL_EXP:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(game_sound);
        #endif
        default_layer_set(1U << _COLEMAK_EXP);
      }
      return false;
    case GAME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(game_sound);
        #endif
        default_layer_set(1U << _GAME);
      }
      return false;

    /* custom key codes */

    case LSPACE:
    case RSPACE:
      if (record->event.pressed) {
        layer_key_active = true;
        mods_on_layer_activation = get_mods();
        layer_on(_RAISE);
      } else {
        if (layer_key_active) {
          // send key only if no other key has been pressed while holding down this key
          tap_code(KC_SPACE);
        }
        layer_off(_RAISE);
      }
      return false;

    case MBSPC:
      if (record->event.pressed) {
        layer_key_active = true;
        mods_on_layer_activation = get_mods();
        layer_on(_LOWER);
      } else {
        if (layer_key_active)
          tap_code(KC_BSPC);
        layer_off(_LOWER);
      }
      return false;

    case MENTER:
      if (record->event.pressed) {
        layer_key_active = true;
        mods_on_layer_activation = get_mods();
        layer_on(_LOWER);
      } else {
        if (layer_key_active)
          tap_code(KC_ENTER);
        layer_off(_LOWER);
      }
      return false;

    case CAPS_WORD:
      if (record->event.pressed) {
        caps_word_enable();
      }
      return false;

  }
  return true; // process key by qmk
};


// Enables the capitalization of complete words

void caps_word_enable(void) {
  caps_word_on = true;
  if (!(host_keyboard_led_state().caps_lock)) {
    tap_code(KC_CAPS);
  }
}

void caps_word_disable(void) {
  caps_word_on = false;
  if (host_keyboard_led_state().caps_lock) {
    tap_code(KC_CAPS);
  }
}

void process_caps_word(uint16_t keycode, const keyrecord_t *record) {
  if (caps_word_on) {
    switch (keycode) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        // no tap yet
        if (record->tap.count == 0) {
          return;
        }
        // base keycode of layer tap
        keycode = keycode & 0xFF;
        break;
      default:
        break;
    }

    switch (keycode) {
      // shifted keys
      case DE_UDIA: // ue
      case DE_ODIA: // oe
      case DE_ADIA: // ae
      case KC_A ... KC_Z:
        if (record->event.pressed) {
          caps_word_enable();
        }
      // ignore keys
      case KC_BSPC:
      case DE_UNDS:
        break;
      // keys that should not get shifted
      case DE_SS: // KC_MINS (ß)
      case CAPS_WORD:
        if (record->event.pressed && (get_mods() != MOD_LSFT) && (get_mods() != 0)) {
          // chording mods disables word caps
          caps_word_disable();
        }
        break;
      default:
        if (record->event.pressed) {
          caps_word_disable();
        }
        break;
    }
  }
}