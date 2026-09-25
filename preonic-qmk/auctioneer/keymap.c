#include QMK_KEYBOARD_H

enum auctioneer_keycodes {
  START_0 = SAFE_RANGE,
  START_1,
  START_2,
  START_3,
  START_4,
  START_5,
  START_6,
  START_7,
  START_8,
  START_9,
  ABNEH_0,
  ABNEH_1,
  ABNEH_2,
  ABNEH_3,
  ABNEH_4,
  ABNEH_5,
  ABNEH_6,
  ABNEH_8,
  WAGON,
  DELIVERY_NOTE,
  NEXT_LOT,
  CHAIN_STOP,
  DELIVERY_DETAILS,
  VST_SEQUENCE,
  CORRECTION_1,
  CORRECTION_2,
  CORRECTION_3,
  CLOCK_STOP,
  PACKEN,
  STG,
  WAGON_REST,
  ER1,
};

#define MACRO_KEY_DELAY 10

static void tap_shifted_sequence(uint8_t first, uint8_t second) {
  register_code(KC_LSFT);
  tap_code_delay(first, MACRO_KEY_DELAY);
  wait_ms(MACRO_KEY_DELAY);
  tap_code_delay(second, MACRO_KEY_DELAY);
  unregister_code(KC_LSFT);
}

static void tap_shift_alt(uint8_t keycode) {
  register_code(KC_LSFT);
  register_code(KC_LALT);
  tap_code_delay(keycode, MACRO_KEY_DELAY);
  unregister_code(KC_LALT);
  unregister_code(KC_LSFT);
}

static void tap_prefixed_digit(uint8_t prefix, uint8_t digit) {
  register_code(KC_LSFT);
  tap_code_delay(prefix, MACRO_KEY_DELAY);
  unregister_code(KC_LSFT);
  wait_ms(MACRO_KEY_DELAY);
  tap_code_delay(digit, MACRO_KEY_DELAY);
}

static void tap_shifted_key(uint8_t keycode) {
  register_code(KC_LSFT);
  tap_code_delay(keycode, MACRO_KEY_DELAY);
  unregister_code(KC_LSFT);
}

static uint8_t digit_keycode(uint8_t digit) {
  static const uint8_t keycodes[] = {
    KC_0,
    KC_1,
    KC_2,
    KC_3,
    KC_4,
    KC_5,
    KC_6,
    KC_7,
    KC_8,
    KC_9,
  };
  return keycodes[digit];
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_preonic_grid(
  // Start block             Production controls                         Quantity block
     KC_F8,   KC_F6,   WAGON,       KC_F7, PACKEN, ABNEH_5, DELIVERY_NOTE, NEXT_LOT, CHAIN_STOP, VST_SEQUENCE, CORRECTION_3, KC_BSPC,
     START_7, START_8, START_9,      KC_F9, STG,    ABNEH_4, DELIVERY_DETAILS, KC_P7, KC_P8, KC_P9, CORRECTION_2, WAGON_REST,
     START_4, START_5, START_6,      KC_F5, KC_F4,  ABNEH_3, ABNEH_0, KC_P4,    KC_P5,     KC_P6,            CORRECTION_1, ER1,
     START_1, START_2, START_3,      KC_F3, KC_F2,  ABNEH_2, ABNEH_8, KC_P1,    KC_P2,     KC_P3,            KC_NO, KC_PPLS,
     CLOCK_STOP, START_0, CLOCK_STOP, KC_F1, KC_F10, ABNEH_1, ABNEH_6, KC_NO,    KC_P0,     KC_NO,            KC_NO, KC_PENT
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return keycode < SAFE_RANGE;
  }

  if (keycode >= START_0 && keycode <= START_9) {
    tap_prefixed_digit(KC_U, digit_keycode(keycode - START_0));
    return false;
  }

  if (keycode >= ABNEH_0 && keycode <= ABNEH_6) {
    tap_prefixed_digit(KC_Q, digit_keycode(keycode - ABNEH_0));
    return false;
  }

  switch (keycode) {
    case ABNEH_8:
      tap_prefixed_digit(KC_Q, KC_8);
      return false;
    case WAGON:
      tap_shift_alt(KC_F1);
      return false;
    case DELIVERY_NOTE:
      tap_shift_alt(KC_F2);
      return false;
    case NEXT_LOT:
      tap_shift_alt(KC_F3);
      return false;
    case CHAIN_STOP:
      tap_shift_alt(KC_F5);
      return false;
    case DELIVERY_DETAILS:
      tap_shift_alt(KC_F6);
      return false;
    case VST_SEQUENCE:
      tap_shift_alt(KC_F7);
      return false;
    case CORRECTION_1:
      tap_shift_alt(KC_F10);
      return false;
    case CORRECTION_2:
      tap_shift_alt(KC_F9);
      return false;
    case CORRECTION_3:
      tap_shift_alt(KC_F11);
      return false;
    case CLOCK_STOP:
      tap_shifted_sequence(KC_U, KC_R);
      return false;
    case PACKEN:
      tap_shifted_key(KC_P);
      return false;
    case STG:
      tap_shifted_sequence(KC_S, KC_T);
      return false;
    case WAGON_REST:
      tap_shifted_sequence(KC_S, KC_K);
      return false;
    case ER1:
      tap_shifted_sequence(KC_S, KC_E);
      return false;
  }

  return true;
}
