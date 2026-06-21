#include "caps_word.h"

// enum corne_keycodes {
//     GAME = SAFE_RANGE,
//     COLEMAK,
//     COL_EXP,
//     CAPS_WORD
// };

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

void caps_word_process_record_user(uint16_t keycode, const keyrecord_t *record) {
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
      case KC_A ... KC_Z:
        if (record->event.pressed) {
          caps_word_enable();
        }
      // ignore keys
      case KC_BSPC:
      case KC_UNDS:
        break;
      // keys that should not get shifted
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