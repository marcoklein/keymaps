---
name: zmk-babbit36-flashing
description: Use ONLY when building and flashing ZMK firmware for the Babbit36 keyboard. Trigger on: babbit36, zmk, flash, firmware, keymap, xiao_ble, bootloader, uf2, XIAO-SENSE.
---

# ZMK Babbit36 Flashing

## Overview

The Babbit36 uses a Seeed XIAO BLE (nRF52840) with a 74HC595 SPI shift register.
Firmware is built via GitHub Actions and flashed over USB as a `.uf2` file.
Keymap source: `babbit36-zmk/` in the `marcoklein/keymaps` repo.

## Build & flash workflow

### 1. Commit and push

Push changes to `babbit36-zmk/` — this automatically triggers the CI build via `zmk-build.yml`.

```bash
git add babbit36-zmk/
git commit -m "<message>"
git push
```

### 2. Trigger GitHub Actions build (if manual trigger needed)

Only needed if pushing didn't trigger the build (e.g. push to a different directory):

```bash
gh workflow run "zmk-build.yml" -R marcoklein/keymaps
```

This returns a URL with the run ID. Extract the numeric run ID from the URL.

### 3. Wait for build to complete

Poll every 8 seconds until status is `completed`:

```bash
run_id=<ID>; for i in $(seq 1 30); do s=$(gh run view $run_id -R marcoklein/keymaps --json status,conclusion --jq '"\(.status)|\(.conclusion)"'); echo "$s"; case "$s" in *completed*) break;; esac; sleep 8; done
```

Timeout: 360000ms (6 minutes). If conclusion is not `success`, read the build log with `gh run view $run_id --log` to diagnose.

### 4. Download firmware

```bash
rm -rf .tmp/babbit36-firmware
gh run download <run_id> -R marcoklein/keymaps --dir .tmp/babbit36-firmware -n babbit36-firmware
```

Produces two files:
- `.tmp/babbit36-firmware/babbit36.uf2` — actual firmware
- `.tmp/babbit36-firmware/settings_reset.uf2` — clears Bluetooth pairings

### 5. Flash firmware

Flash steps must be done sequentially — one file at a time, with the user double-tapping reset between each.

First, check if XIAO-SENSE is mounted:

```bash
ls /Volumes/XIAO-SENSE
```

If **not mounted** — tell the user to double-tap the reset button on the XIAO BLE.

If **mounted** — copy the `.uf2` file:

```bash
cp .tmp/babbit36-firmware/babbit36.uf2 /Volumes/XIAO-SENSE/
```

The `cp` command will produce an **I/O error** (`fcopyfile failed: Input/output error`) — this is NORMAL. The XIAO accepts the file and reboots before `cp` can `fchmod`. Verify success by checking that `/Volumes/XIAO-SENSE` no longer exists:

```bash
ls /Volumes/XIAO-SENSE 2>/dev/null || echo "Rebooted - flash done"
```

## Settings reset (clear Bluetooth pairings)

Use the settings reset when:

- Bluetooth pairing fails or is unreliable
- Switching between hosts (phone, laptop)
- After changing BLE config options

Flash `settings_reset.uf2` FIRST (same flash steps as above), THEN flash `babbit36.uf2` immediately after. The user must double-tap reset between the two flashes.

After settings reset, the user must:

1. Hold left outer thumb (NAV) + press Q to select BT profile 0
2. Re-pair from the host device (look for "Babbit36")

## After flashing

The keyboard auto-reboots after each `.uf2` copy. No further action needed. The user can:

- Test keys over USB-C immediately
- For BLE: select profile (NAV+Q), pair from host Bluetooth settings

## Troubleshooting

| Symptom | Fix |
|---------|-----|
| `cp` I/O error | Normal — check that XIAO-SENSE disappeared (flash succeeded) |
| BLE disconnects after short time | Flash settings reset, then re-flash firmware, re-pair |
| BLE pairs but no input | USB cable still plugged in — unplug USB to enable BLE output |
| Build fails | Check `gh run view $run_id --log` for errors |
| Can't find XIAO-SENSE | Double-tap reset button, wait 2 seconds, try again |
| Wrong keys | Edit `config/babbit36.keymap`, re-flash |

## Hardware notes

- **Controller:** Seeed XIAO BLE (nRF52840)
- **Board name:** `xiao_ble//zmk`
- **Shield name:** `babbit36`
- **Matrix:** 4 rows x 10 columns, col2row diodes, 74HC595 shift register on SPI
- **Thumb keys:** 3 per side (6 total)
- **One XIAO, one PCB** — both halves integrated on a single board
- **Same firmware for both halves** — not split left/right like Corne
