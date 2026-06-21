---
name: qmk-crkbd-flashing
description: Use ONLY when building/flashing QMK firmware for Corne (crkbd) with marco-default keymap. Trigger: qmk, crkbd, corne, flash, compile, firmware, bootloader, caterina, ghosting, both halves.
---

# QMK Corne (crkbd) Build & Flash

## Prerequisites

QMK CLI must be installed. avr-gcc must be on PATH. Keymap must be symlinked into qmk_firmware.

```bash
# Install QMK
brew install qmk/qmk/qmk

# Path for avr-gcc (macOS Homebrew)
export PATH="/opt/homebrew/Cellar/avr-gcc@8/*/bin:$PATH"

# Symlink keymap into qmk_firmware
cd ~/code/keymaps && ./setup.sh
```

If qmk_firmware is missing submodules (LUFA etc.):

```bash
cd ~/code/qmk_firmware && git submodule update --init --recursive
```

## Compile

```bash
cd ~/code/qmk_firmware
qmk compile -kb crkbd -km marco-default
```

## Flash Both Halves

Split keyboard — **both halves must be flashed with identical firmware**. Skipping the slave causes ghosting.
Bootloader: Caterina. Enter via `QK_BOOT` key on the ADJUST layer (hold Lower+Raise, press top-left or top-right key) or double-tap the physical reset button.

1. **Unplug TRRS cable** from both halves.
2. Plug USB into first half, enter bootloader, run:
   ```bash
   cd ~/code/qmk_firmware && qmk flash -kb crkbd -km marco-default
   ```
3. Unplug USB from first half. Plug USB into second half, enter bootloader, run:
   ```bash
   qmk flash -kb crkbd -km marco-default
   ```
4. **Reconnect TRRS cable**. Plug USB into the half you use as master.

## Troubleshooting

| Symptom | Fix |
|---------|-----|
| Ghosting (`;lon/h` repeating) | Flash both halves with **identical firmware**. Never plug/unplug TRRS while USB is powered. |
| `avr-gcc: command not found` | Add to PATH: `export PATH="/opt/homebrew/Cellar/avr-gcc@8/*/bin:$PATH"` |
| `lib/lufa/LUFA/makefile` missing | Init submodules: `git submodule update --init --recursive` (in qmk_firmware dir) |
| `UG_TOGG` / `UG_HUEU` undeclared | Old RGB keycodes — replace `RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,RGB_HUD,RGB_SAD,RGB_VAD` with `UG_TOGG,UG_NEXT,UG_HUEU,UG_SATU,UG_VALU,UG_HUED,UG_SATD,UG_VALD` in keymap.c |
| `IGNORE_MOD_TAP_INTERRUPT` #error | Remove `#define IGNORE_MOD_TAP_INTERRUPT` from config.h (now default) |
| Flash waits forever / `butterfly_recv` error | Bootloader timed out (>8s). Reset again and re-run flash immediately. |
| Wrong serial port detected | Check `ls /dev/tty.usbmodem*` and flash manually: `avrdude -p atmega32u4 -c avr109 -P /dev/tty.usbmodemXXXX -U flash:w:.build/crkbd_rev1_marco-default.hex` |
