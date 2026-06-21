---
name: qmk-preonic-flashing
description: Use ONLY when building/flashing QMK firmware for Preonic (rev3) with marco-default keymap. Trigger: qmk, preonic, flash, compile, firmware, stm32, dfu, bootloader, arm.
---

# QMK Preonic (preonic/rev3) Build & Flash

## Pinned upstream commit

QMK firmware is cloned from upstream `qmk/qmk_firmware` (NOT the old fork `marcoklein/qmk_firmware-archive`) and pinned to a known-good commit.

```
PINNED_COMMIT=c6381000309a8d9300cb1ca8ec01cfa3d4ed4c5f
```

## Prerequisites

QMK CLI (`brew install qmk/qmk/qmk`). arm-none-eabi-gcc and arm-none-eabi-binutils must be on PATH. Keymap is symlinked via `setup.sh`.

```bash
# Path for ARM GCC and binutils (macOS Homebrew)
export PATH="/opt/homebrew/opt/arm-none-eabi-binutils/bin:/opt/homebrew/opt/arm-none-eabi-gcc@8/bin:$PATH"
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
qmk compile -kb preonic/rev3 -km marco-default
```

## Flash

Preonic is a single keyboard (not split). One flash is sufficient.
Bootloader: stm32-dfu. Enter via `QK_BOOT` on the ADJUST layer (hold Lower+Raise, press the second key from the left) or press the physical reset button on the PCB.

```bash
cd .tmp/qmk_firmware && qmk flash -kb preonic/rev3 -km marco-default
```

The flash command will wait for the device to enter DFU mode. If the device is not found, put it in bootloader mode and it will be detected automatically (retries every 0.5s).

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

4. If successful, update the `PINNED_COMMIT` in this skill file and the crkbd skill.

## Troubleshooting

| Symptom | Fix |
|---------|-----|
| `arm-none-eabi-gcc: command not found` | Add to PATH: `export PATH="/opt/homebrew/opt/arm-none-eabi-binutils/bin:/opt/homebrew/opt/arm-none-eabi-gcc@8/bin:$PATH"` |
| `arm-none-eabi-size: command not found` | arm-none-eabi-binutils not in PATH — see above |
| Bootloader not found | Put keyboard in DFU mode (reset button or QK_BOOT). Flash retries every 0.5s. |
| `dfu-suffix: Please remove existing DFU suffix` | Normal transient error on ARM builds — retry or run `qmk clean` first |
| `No rule to make target` | Use `qmk compile`/`qmk flash`, not `make`. QMK 0.33+ uses `qmk` as the build interface. |
| Missing `.tmp/qmk_firmware` | Run the first-time setup steps above to clone at the pinned commit. |
