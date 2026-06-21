# Babbit36 Target Layout

> Matches Corne crkbd keymap at `/Users/mkle/code/qmk_firmware/keyboards/crkbd/keymaps/marco-plus/`
>
> Babbit36 cols 0-4 ≈ Corne cols 1-5 (left), Bab cols 5-9 ≈ Corne cols 6-10 (right).
> Pinky columns (Corne col 0 & col 11) omitted — TAB, ESC, DEL moved to thumbs.

## Position grid

```
Row 0:  0   1   2   3   4       5   6   7   8   9
Row 1: 10  11  12  13  14      15  16  17  18  19
Row 2: 20  21  22  23  24      25  26  27  28  29
Row 3:         30  31  32          33  34  35
```

---

## DEFAULT (0)

```
  Q    W    F    P    B     |   J    L    U    Y    ;
LGUI_A LALT_R LCTL_S LSHFT_T G | M RSHFT_N RCTL_E RALT_I RGUI_O
  Z    X    C    D    V     |   K    H    ,    .    /
     NAV/ESC LOWER/TAB RAISE/BSPC | RAISE/RET LOWER/SPC DEL
```

| Pos | Binding | Tap | Hold |
|-----|---------|-----|------|
| 0-4 | `&kp Q`–`B` | Q W F P B | — |
| 5-9 | `&kp J`–`SEMI` | J L U Y ; | — |
| 10 | `&hml LGUI A` | A | LGUI |
| 11 | `&hml LALT R` | R | LALT |
| 12 | `&hml LCTRL S` | S | LCTRL |
| 13 | `&hml LSHFT T` | T | LSHFT |
| 14 | `&kp G` | G | — |
| 15 | `&kp M` | M | — |
| 16 | `&hmr RSHFT N` | N | RSHFT |
| 17 | `&hmr RCTRL E` | E | RCTRL |
| 18 | `&hmr RALT I` | I | RALT |
| 19 | `&hmr RGUI O` | O | RGUI |
| 20-24 | `&kp Z`–`V` | Z X C D V | — |
| 25-29 | `&kp K`–`FSLH` | K H , . / | — |
| 30 | `&lt NAV ESC` | ESC | NAV layer |
| 31 | `&lt LOWER TAB` | TAB | LOWER layer |
| 32 | `&lt RAISE BSPC` | BSPC | RAISE layer |
| 33 | `&lt RAISE RET` | RET | RAISE layer |
| 34 | `&lt LOWER SPACE` | SPACE | LOWER layer |
| 35 | `&kp DEL` | DEL | — |

---

## LOWER (2)

```
  1    2    3    4    5     |   6    7    8    9    0
  ~  LALT_\ LCTL_- LSHFT_=  ___  | ___ RSHFT_[ RCTL_] ___ RGUI_'
  |   ___  ___  ___  ___    |  ___  ___  ___  ___  ___
```

| Pos | Binding | Tap | Hold |
|-----|---------|-----|------|
| 0 | `&kp N1` | 1 | — |
| 1 | `&kp N2` | 2 | — |
| 2 | `&kp N3` | 3 | — |
| 3 | `&kp N4` | 4 | — |
| 4 | `&kp N5` | 5 | — |
| 5 | `&kp N6` | 6 | — |
| 6 | `&kp N7` | 7 | — |
| 7 | `&kp N8` | 8 | — |
| 8 | `&kp N9` | 9 | — |
| 9 | `&kp N0` | 0 | — |
| 10 | `&kp TILDE` | `~` | — |
| 11 | `&hml LALT BSLH` | `\` | LALT |
| 12 | `&hml LCTRL MINUS` | `-` | LCTRL |
| 13 | `&hml LSHFT EQUAL` | `=` | LSHFT |
| 14 | `&trans` | — | — |
| 15 | `&trans` | — | — |
| 16 | **`&hmr RSHFT LBKT`** | **`[`** | **RSHFT** |
| 17 | `&hmr RCTRL RBKT` | `]` | RCTRL |
| 18 | `&trans` | — | — |
| 19 | `&hmr RGUI SQT` | `'` | RGUI |
| 20 | `&kp PIPE` | `\|` | — |
| 21-29 | `&trans` | — | — |

**Shifted symbols via LOWER home row mods:** hold RSHFT (N) or LSFT (T) + number key → `!@#$%^&*()`  
**`"`** = hold RSHFT (N) + tap `'` (O)  
**`{` `}`** = hold LSFT (T) + tap `[` (N) / `]` (E)  
**`+` `_`** = LSFT + `=` / LSFT + `-`

---

## RAISE (1)

```
  F2   F3   F4   F5   F6    |  F7   F8   F9  F10  F11
LGUI_F1 LALT_CAPS LCTL_ESC LSHFT_TAB ___ | ___ ___ ___ ___ RGUI_F12
 ___  ___  ___  INS PSCRN   |  ___  ___  ___  ___  ___
```

| Pos | Binding | Tap | Hold |
|-----|---------|-----|------|
| 0 | `&kp F2` | F2 | — |
| 1 | `&kp F3` | F3 | — |
| 2 | `&kp F4` | F4 | — |
| 3 | `&kp F5` | F5 | — |
| 4 | `&kp F6` | F6 | — |
| 5 | `&kp F7` | F7 | — |
| 6 | `&kp F8` | F8 | — |
| 7 | `&kp F9` | F9 | — |
| 8 | `&kp F10` | F10 | — |
| 9 | `&kp F11` | F11 | — |
| 10 | `&hml LGUI F1` | F1 | LGUI |
| 11 | `&hml LALT CAPS` | CAPS | LALT |
| 12 | `&hml LCTRL ESC` | ESC | LCTRL |
| 13 | `&hml LSHFT TAB` | TAB | LSHFT |
| 14 | `&trans` | — | — |
| 15-18 | `&trans` | — | — |
| 19 | `&hmr RGUI F12` | F12 | RGUI |
| 20-22 | `&trans` | — | — |
| 23 | `&kp INS` | INS | — |
| 24 | `&kp PSCRN` | PSCRN | — |
| 25-29 | `&trans` | — | — |

> **CAPS note:** Corne uses `CAPS_WORD` custom keycode here. ZMK's `&caps_word` can't be used as tap inside `&hml`. Using `&kp CAPS` as fallback.

---

## NAV (3)

```
  BT0  BT1  BT2  BT3  BT4   |  ___ BTPRV BTNXT ___ PSCRN
BT_CLR ___ ___ SYS_RESET BOOT | LEFT DOWN  UP RIGHT ___
  ___  ___  ___  ___  ___   | HOME PGDN PGUP END  ___
```

| Pos | Binding | Tap | Hold |
|-----|---------|-----|------|
| 0-4 | `&bt BT_SEL 0`–`4` | BT profile 0-4 | — |
| 5 | `&trans` | — | — |
| 6 | `&bt BT_PRV` | BT prev | — |
| 7 | `&bt BT_NXT` | BT next | — |
| 8 | `&trans` | — | — |
| 9 | `&kp PSCRN` | PSCRN | — |
| 10 | `&bt BT_CLR` | BT clear | — |
| 11-12 | `&trans` | — | — |
| 13 | `&sys_reset` | sys reset | — |
| 14 | `&bootloader` | bootloader | — |
| 15 | `&kp LEFT` | ← | — |
| 16 | `&kp DOWN` | ↓ | — |
| 17 | `&kp UP` | ↑ | — |
| 18 | `&kp RIGHT` | → | — |
| 19 | `&trans` | — | — |
| 20-24 | `&trans` | — | — |
| 25 | `&kp HOME` | HOME | — |
| 26 | `&kp PG_DN` | PGDN | — |
| 27 | `&kp PG_UP` | PGUP | — |
| 28 | `&kp END` | END | — |
| 29 | `&trans` | — | — |
| 30-35 | `&trans` | — | — |

---

## Behaviors (unchanged)

```dts
&lt {
    quick-tap-ms = <200>;
    flavor = "hold-preferred";
};

hml: home_row_mods_left {
    compatible = "zmk,behavior-hold-tap";
    #binding-cells = <2>;
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <175>;
    require-prior-idle-ms = <50>;
    bindings = <&kp>, <&kp>;
    hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 25 26 27 28 29 33 34 35>;
};

hmr: home_row_mods_right {
    compatible = "zmk,behavior-hold-tap";
    #binding-cells = <2>;
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <175>;
    require-prior-idle-ms = <50>;
    bindings = <&kp>, <&kp>;
    hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 23 24 30 31 32>;
};
```

## Layer activation timing

ZMK `&lt` activates the layer on another key-press (not on thumb-key press). You must **hold the thumb key while pressing** the target key — QMK-style simultaneous press (chording) won't see the layer. Pre-hold the thumb key for 200ms before pressing, or ensure the target key is pressed while the thumb key is held.
