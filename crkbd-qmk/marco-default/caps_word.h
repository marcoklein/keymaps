#pragma once

#include "keymap.h"

// Capitalize the next word

bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);
void caps_word_process_record_user(uint16_t keycode, const keyrecord_t *record);