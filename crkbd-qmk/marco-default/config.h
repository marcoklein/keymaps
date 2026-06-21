#pragma once

// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

/** Home Row Mods **/

// milliseconds to differentiate between tab and hold
#define TAPPING_TERM 200 // default 200

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
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

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

// #define UNICODE_SELECTED_MODES UC_WINC, UC_MAC, UC_LNX