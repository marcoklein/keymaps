# keymaps

All my keyboard keymaps in one place.

## Keyboards

| Keyboard | Firmware | Keymap |
|----------|----------|--------|
| Preonic  | QMK      | `preonic-qmk/marco-default/` — Colemak with German keys, home-row mods, custom shift layer |
| Corne    | QMK      | `crkbd-qmk/marco-default/` — Colemak with home-row mods, OLED display, unicode, split |

## Setup

### Install QMK CLI

```bash
brew install qmk/qmk/qmk
```

You may also need to add GCC toolchains to your PATH:

```bash
export PATH="/opt/homebrew/Cellar/avr-gcc@8/*/bin:$PATH"
export PATH="/opt/homebrew/Cellar/arm-none-eabi-gcc@8/*/bin:$PATH"
export PATH="/opt/homebrew/Cellar/arm-none-eabi-binutils/*/bin:$PATH"
```

### Clone and set up QMK firmware

```bash
qmk setup marcoklein/qmk_firmware
```

### Link these keymaps into QMK

```bash
./setup.sh
```

This symlinks the keymap directories into `qmk_firmware/keyboards/<kbd>/keymaps/marco-default/`.

### Compile

```bash
qmk compile -kb preonic/rev3 -km marco-default
qmk compile -kb crkbd       -km marco-default
```

### Flash

```bash
qmk flash -kb preonic/rev3 -km marco-default
qmk flash -kb crkbd        -km marco-default
```
