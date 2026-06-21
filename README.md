# keymaps

All my keyboard keymaps in one place.

## Keyboards

| Keyboard | Firmware | Controller | Keymap |
|----------|----------|------------|--------|
| Preonic  | QMK      | —          | `preonic-qmk/marco-default/` — Colemak with German keys, home-row mods, custom shift layer |
| Corne    | QMK      | Pro Micro  | `crkbd-qmk/marco-default/` — Colemak with home-row mods, OLED display, unicode, split |
| Corne    | ZMK      | nice!nano v2 | `corne-zmk/` — Wireless Colemak, home-row mods, 4 layers, split BLE |
| Babbit36 | ZMK      | XIAO BLE   | `babbit36-zmk/` — Wireless Colemak, 4 layers, custom shield, single PCB |

## Setup

### QMK (wired keyboards)

#### Install QMK CLI

```bash
brew install qmk/qmk/qmk
```

You may also need to add GCC toolchains to your PATH:

```bash
export PATH="/opt/homebrew/Cellar/avr-gcc@8/*/bin:$PATH"
export PATH="/opt/homebrew/Cellar/arm-none-eabi-gcc@8/*/bin:$PATH"
export PATH="/opt/homebrew/Cellar/arm-none-eabi-binutils/*/bin:$PATH"
```

#### Clone and set up QMK firmware

```bash
qmk setup marcoklein/qmk_firmware
```

#### Link keymaps into QMK

```bash
./setup.sh
```

This symlinks the keymap directories into `qmk_firmware/keyboards/<kbd>/keymaps/marco-default/`.

#### Compile

```bash
qmk compile -kb preonic/rev3 -km marco-default
qmk compile -kb crkbd       -km marco-default
```

#### Flash

```bash
qmk flash -kb preonic/rev3 -km marco-default
qmk flash -kb crkbd        -km marco-default
```

### ZMK (wireless keyboards)

ZMK firmware is built via GitHub Actions (see `.github/workflows/zmk-build.yml`).
Pushing to a `*-zmk/` directory automatically triggers a build for that keyboard.

#### Trigger a build manually

```bash
gh workflow run "zmk-build.yml" -R marcoklein/keymaps
```

#### Download and flash

See the OpenCode skills for per-keyboard flashing instructions:

- `zmk-corne-flashing` — Corne with nice!nano v2
- `zmk-babbit36-flashing` — Babbit36 with XIAO BLE
