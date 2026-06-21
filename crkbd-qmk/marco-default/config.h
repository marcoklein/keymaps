#pragma once


// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

/** Home Row Mods **/

// milliseconds to differentiate between tab and hold
#define TAPPING_TERM 200 // default 200

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// you may change this to a "TAPPING_FORCE_HOLD_PER_KEY" option
#define TAPPING_FORCE_HOLD

#ifndef __ASSEMBLER__
    enum corne_layers {
        _COLEMAK,
        _LOWER,
        _RAISE,
        _NAV,
        _ADJUST
    };
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLIGHT_LED_COUNT
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif


#define BOOTMAGIC_KEY_SALT KC_TAB
#define BOOTMAGIC_KEY_EEPROM_CLEAR KC_C

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

// #define UNICODE_SELECTED_MODES UC_WINC, UC_MAC, UC_LNX