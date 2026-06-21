---
name: qmk-preonic-flashing
description: Use ONLY when building/flashing QMK firmware for Preonic (rev3) with marco-default keymap. Trigger: qmk, preonic, flash, compile, firmware, stm32, dfu, bootloader, arm.
---

# QMK Preonic (preonic/rev3) Build & Flash

## Prerequisites

QMK CLI must be installed. arm-none-eabi-gcc and arm-none-eabi-binutils must be on PATH. Keymap must be symlinked into qmk_firmware.

```bash
# Install QMK
brew install qmk/qmk/qmk

# Path for ARM GCC and binutils (macOS Homebrew)
export PATH="/opt/homebrew/Cellar/arm-none-eabi-gcc@8/*/bin:/opt/homebrew/Cellar/arm-none-eabi-binutils/*/bin:$PATH"

# Symlink keymap into qmk_firmware
cd ~/code/keymaps && ./setup.sh
```

If qmk_firmware is missing submodules:

```bash
cd ~/code/qmk_firmware && git submodule update --init --recursive
```

## Compile

```bash
cd ~/code/qmk_firmware
qmk compile -kb preonic/rev3 -km marco-default
```

## Flash

Preonic is a single keyboard (not split). One flash is sufficient.
Bootloader: stm32-dfu. Enter via `QK_BOOT` on the ADJUST layer (hold Lower+Raise, second key from the left) or press the physical reset button on the PCB.

```bash
cd ~/code/qmk_firmware && qmk flash -kb preonic/rev3 -km marco-default
```
