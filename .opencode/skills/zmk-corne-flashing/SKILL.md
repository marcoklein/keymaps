---
name: zmk-corne-flashing
description: Use ONLY when building and flashing ZMK firmware for the Corne (crkbd) with nice!nano v2. Trigger on: corne, crkbd, zmk, flash, firmware, keymap, nice_nano, nice!nano, bootloader, uf2, NICENANO, bluetooth, split, wireless, both halves, nrf52840.
---

# ZMK Corne (crkbd) Build & Flash

## Overview

Wireless Corne split keyboard with two nice!nano v2 controllers (nRF52840).
Firmware is built via GitHub Actions and flashed over USB as `.uf2` files.
Keymap source: `corne-zmk/` in the `marcoklein/keymaps` repo.

The Corne is a **split keyboard** — left and right halves each have their own nice!nano controller and must be flashed with **different firmware** (corne_left vs corne_right).

## Build & flash workflow

### 1. Commit and push

Push changes to `corne-zmk/` — this automatically triggers the CI build via `zmk-build.yml`.
Commit and push:

```bash
git add corne-zmk/
git commit -m "<message>"
git push
```

### 2. Trigger GitHub Actions build (if manual trigger needed)

If pushing doesn't trigger the build (e.g. workflow file changed), trigger manually:

```bash
gh workflow run "zmk-build.yml" -R marcoklein/keymaps
```

This triggers both corne and babbit36 builds. Extract the numeric run ID from the URL.

### 3. Wait for build to complete

Poll every 8 seconds until status is `completed`:

```bash
run_id=<ID>; for i in $(seq 1 30); do s=$(gh run view $run_id -R marcoklein/keymaps --json status,conclusion --jq '"\(.status)|\(.conclusion)"'); echo "$s"; case "$s" in *completed*) break;; esac; sleep 8; done
```

Timeout: 360000ms (6 minutes). If conclusion is not `success`, read the build log with `gh run view $run_id --log` to diagnose.

### 4. Download firmware

```bash
rm -rf .tmp/corne-firmware
gh run download <run_id> -R marcoklein/keymaps --dir .tmp/corne-firmware -n corne-firmware
```

The build produces two `.uf2` files:

- `zmk.uf2` (left build) — firmware for the **left** half
- `zmk.uf2` (right build) — firmware for the **right** half

Both are in `.tmp/corne-firmware/`.

### 5. Flash both halves

**Both halves must be flashed with their respective firmware.** The halves communicate over BLE — there is no TRRS cable.

1. **Unplug USB from both halves.**
2. Plug USB into **left half**, double-tap reset button, check mount:

   ```bash
   ls /Volumes/NICENANO
   ```

3. If mounted, flash the left firmware:

   ```bash
   cp .tmp/corne-firmware/<left-uf2> /Volumes/NICENANO/
   ```

4. The nice!nano reboots (`cp` may produce an I/O error — normal). Verify:

   ```bash
   ls /Volumes/NICENANO 2>/dev/null || echo "Rebooted - flash done"
   ```

5. Unplug USB from left half. Plug USB into **right half**, double-tap reset, and repeat steps 2-4 with the right firmware.

### 6. After flashing

- The halves auto-connect to each other via BLE.
- Plug USB into the **left half** (typically the central/peripheral — if halves don't speak, try the right half instead).
- Wait ~5 seconds for the halves to sync.
- Select BT profile on the connected half: hold **NAV** (left outer thumb) + press **Q** to select profile 0.
- Pair from host Bluetooth settings (look for "Corne").

## Settings reset (clear Bluetooth pairings)

To clear all BLE pairings on a nice!nano (not built by this CI workflow, use the settings_reset UF2 from ZMK docs):

If BLE is unreliable or you switch hosts, you can flash a settings reset UF2:

1. Double-tap reset to mount NICENANO.
2. Flash a `settings_reset-nice_nano_v2-zmk.uf2` (download from zmk.dev).
3. Then re-flash the corne firmware for that half.
4. Re-pair both halves and the host.

## Troubleshooting

| Symptom | Fix |
|---------|-----|
| `cp` I/O error | Normal — check that NICENANO disappeared (flash succeeded) |
| Halves don't communicate | Flash both halves with matching firmware. Wait 5-10s for sync. Try plugging USB into the other half. |
| BLE disconnects frequently | Flash settings reset, then re-flash both halves, re-pair |
| BLE pairs but no keys | Unplug USB cable — BLE output is disabled while USB is connected |
| Ghosting / wrong keys | Both halves must run the same version firmware. Re-flash both. |
| Build fails | Check `gh run view $run_id --log` for errors |
| Can't find NICENANO | Double-tap reset button on the nice!nano, wait 2 seconds, try again. If still not found, try a different USB cable. |
| Only one half works | Make sure you flashed corne_left to left half and corne_right to right half. They are NOT interchangeable. |

## Hardware notes

- **Controller:** nice!nano v2 (nRF52840)
- **Board name:** `nice_nano_v2`
- **Shield:** `corne_left` / `corne_right`
- **Matrix:** 3 rows × 6 columns per half (42 keys total)
- **No TRRS cable** — halves communicate over BLE
- **Bootloader:** Double-tap reset button to enter UF2 bootloader (mounts as NICENANO volume)
- **Charging:** Each half has a LiPo battery. Charge via the USB-C port on each half.
