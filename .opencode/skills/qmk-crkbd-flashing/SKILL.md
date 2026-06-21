---
name: qmk-crkbd-flashing
description: Use ONLY when building/flashing QMK firmware for Corne (crkbd) with marco-default keymap. Trigger: qmk, crkbd, corne, flash, compile, firmware, bootloader, caterina, ghosting, both halves.
---

# QMK Corne (crkbd) Build & Flash

## Pinned upstream commit

QMK firmware is cloned from upstream `qmk/qmk_firmware` (NOT the old fork `marcoklein/qmk_firmware-archive`) and pinned to a known-good commit.

```
PINNED_COMMIT=c6381000309a8d9300cb1ca8ec01cfa3d4ed4c5f
```

## Prerequisites

QMK CLI (`brew install qmk/qmk/qmk`). avr-gcc must be on PATH. Keymap is symlinked via `setup.sh`.

```bash
# Path for avr-gcc (macOS Homebrew)
export PATH="/opt/homebrew/opt/avr-gcc@8/bin:$PATH"
```

## First-time setup (or after wiping .tmp/)

```bash
cd ~/code/keymaps
rm -rf .tmp/qmk_firmware
git clone --depth 1 https://github.com/qmk/qmk_firmware.git .tmp/qmk_firmware
cd .tmp/qmk_firmware
git fetch --unshallow
git checkout c6381000309a8d9300cb1ca8ec01cfa3d4ed4c5f
git submodule update --init --recursive
cd ../..
./setup.sh
```

If `.tmp/qmk_firmware` already exists at the pinned commit, only re-run `./setup.sh` if the symlinks are missing.

## Compile

```bash
cd .tmp/qmk_firmware
qmk compile -kb crkbd/rev1 -km marco-default
```

## Flash Both Halves

Split keyboard — **both halves must be flashed** with identical firmware. Skipping the slave causes ghosting (`;lon/h` repeating).
Bootloader: Caterina. Enter via `QK_BOOT` key on the ADJUST layer (hold Lower+Raise, press top-left or top-right key) or double-tap the physical reset button.

**IMPORTANT**: When flashing, opencode MUST pause and wait for the user between halves. Do NOT proceed to the second half until the user confirms they have switched the USB cable.

### Flash the first half

1. **Tell the user**: "Unplug TRRS cable from both halves. Plug USB into the first half, then enter bootloader mode (double-tap reset or QK_BOOT)."

2. Run flash:
```bash
cd .tmp/qmk_firmware && qmk flash -kb crkbd/rev1 -km marco-default
```

### Wait for user to switch halves

3. **After first half succeeds**, tell the user: "First half done. Now unplug USB from the first half, plug USB into the second half, and enter bootloader mode. Confirm when ready."

4. **Wait for user confirmation** before proceeding.

### Flash the second half

5. Run flash again:
```bash
cd .tmp/qmk_firmware && qmk flash -kb crkbd/rev1 -km marco-default
```

6. **After second half succeeds**, tell the user: "Both halves flashed. Reconnect the TRRS cable, then plug USB into the half you use as master."

## Upgrading QMK to a newer commit

1. Fetch the latest upstream:
```bash
cd .tmp/qmk_firmware && git fetch origin master
```

2. Checkout the new commit and update submodules:
```bash
git checkout <new-commit-hash>
git submodule update --init --recursive
```

3. Test compile both keyboards:
```bash
qmk compile -kb crkbd/rev1 -km marco-default
qmk compile -kb preonic/rev3 -km marco-default
```

4. If successful, update the `PINNED_COMMIT` in this skill file and the preonic skill.

## Troubleshooting

| Symptom | Fix |
|---------|-----|
| Ghosting (`;lon/h` repeating) | Flash both halves with **identical firmware**. Never plug/unplug TRRS while USB is powered. |
| `avr-gcc: command not found` | Add to PATH: `export PATH="/opt/homebrew/opt/avr-gcc@8/bin:$PATH"` |
| `lib/lufa/LUFA/makefile` missing | Init submodules: `git submodule update --init --recursive` |
| Flash waits forever / `butterfly_recv` error | Bootloader timed out (>8s). Reset again and re-run flash immediately. |
| Wrong serial port detected | Check `ls /dev/tty.usbmodem*` and flash manually: `avrdude -p atmega32u4 -c avr109 -P /dev/tty.usbmodemXXXX -U flash:w:.build/crkbd_rev1_marco-default.hex` |
| `No rule to make target` | Use `qmk compile`/`qmk flash`, not `make`. QMK 0.33+ uses `qmk` as the build interface. |
| Missing `.tmp/qmk_firmware` | Run the first-time setup steps above to clone at the pinned commit. |
