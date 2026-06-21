---
name: keymap-formatting
description: Use when writing, editing, or reformatting ZMK (.keymap) or QMK (keymap.c) keymap files. Trigger on: keymap, format, alignment, box drawing, grid, reformat, styling.
---

# Keymap Formatting

## Overview

W=12 fixed-width columns, Unicode box drawings, `│` column separators.
Each binding is right-padded to exactly 12 chars. >12 chars → `#define` alias.

## Column rules

- **W = 12** uniform across all keyboards (ZMK and QMK).
- **Padding**: right-pad to W with trailing spaces.
  - ZMK: `&kp Q` → `"&kp Q       "` (5+7). No commas.
  - QMK: `KC_TAB,` → `"KC_TAB,     "` (7+5). Comma counts toward W.
- **Separator**: `│` between every column within a half.
- **Edge**: `│` at both ends of each half: `│<C0>│<C1>│…│<C4>│`
- **Gap**: 3 spaces between halves (`│   │`).
- **Indent**: 3 spaces (aligns leading `│` under box-drawing `╭`).
- **Zero overflow**: every binding must be ≤12 chars. Use aliases for anything longer.

## Aliases

`#define` aliases (≤8 chars) for any binding >12 chars.
Naming: `{L|R}{ModAbbrev}{KeyAbbrev}` for home-row mods, descriptive for layer-taps.
Examples: `LACAPS`→`&hml LALT CAPSLOCK`, `LOWSPC`→`&lt LOWER SPACE`, `RGF12`→`&hmr RGUI F12`.

## Box drawings

`//` comments. Connectors:

| Border | Connector |
|--------|-----------|
| Top | `┬` (between all columns) |
| Row separator | `┼` (between all columns) |
| Above thumbs: no-thumb cols | `┴` (C0–C{skip-1} terminate here) |
| Above thumbs: thumb cols | `┼` (C{skip}+ continue to thumb row) |
| Thumb bottom | `┴` (terminal, no rows below) |

**Split (N cols/half, T thumb cols per half):**
```
// ╭<12 dashes>┬…┬<12 dashes>╮   ╭<12 dashes>┬…┬<12 dashes>╮
// ├<12 dashes>┼…┼<12 dashes>┤   ├<12 dashes>┼…┼<12 dashes>┤
// ╰<12 dashes>┴…┴<12 dashes>┼…┼<12 dashes>┤   ├<12 dashes>┼…┼<12 dashes>┴…┴<12 dashes>╯
//                           ╰<12 dashes>┴<12 dashes>┴<12 dashes>╯   ╰…╯
```
Above thumbs: `┴` for columns without thumbs, `┼` for columns with thumbs (and transition). Thumb bottom: `┴` throughout.

Thumb `╰` position: `INDENT + T*(W+1) - 2` spaces after `//`.

**Ortho grid (no split, no thumbs):**
```
// ╭<12 dashes>┬…┬<12 dashes>╮
// ├<12 dashes>┼…┼<12 dashes>┤
// ╰<12 dashes>┴…┴<12 dashes>╯
```
Bottom uses `┴` throughout (all columns terminate).

## Layout formulas

| Item | Formula |
|------|---------|
| Half width | `2 + (W+1)×cols - 1` |
| Binding line | `INDENT + half + GAP + half` |
| Thumb skip | `INDENT + T×(W+1)` (T = columns before first thumb) |
| Thumb half | `2 + (W+1)×T - 1` |
| Thumb line | `THUMB_SKIP + thumb_half + GAP + thumb_half` |

Per-keyboard values with W=12:

| Keyboard | Cols/half | T | Half | Binding line | Thumb skip | Thumb half | Thumb line |
|----------|-----------|---|------|-------------|------------|------------|------------|
| Babbit36 | 5 | 2 | 66 | 138 | 29 | 40 | 112 |
| Corne | 6 | 3 | 79 | 164 | 42 | 40 | 125 |
| Crkbd (QMK) | 6 | 3 | 79 | 164 | 42 | 40 | 125 |
| Preonic | 12 | — | 157 | 160 | — | — | — |

## Layer structure

Order: `default → raise → lower → nav → adjust`. Blank line between layers.
- ZMK: `        layer_name { bindings = < ... >; };`
- QMK split: `  [_NAME] = LAYOUT_split_3x6_3( ... ),` (indent 2 before `[`)
- QMK ortho: `  [_NAME] = LAYOUT_preonic_grid( ... ),` (indent 2 before `[`)

## Indentation

- **ZMK**: 3 spaces (aligns `│` under `╭` at position 3: `// ╭` → `   │`).
- **QMK**: 5 spaces (aligns `│` under `╭` at position 5: `  // ╭` → `     │`).
- Thumb lines: skip = `INDENT + T×(W+1)` spaces.
- Box drawings use the same indent as their binding lines.

## Reference

- `babbit36-zmk/config/babbit36.keymap` — ZMK split (5 cols, T=2)
- `corne-zmk/config/corne.keymap` — ZMK split (6 cols, T=3)
- `crkbd-qmk/marco-default/keymap.c` — QMK split (6 cols, T=3)
- `preonic-qmk/marco-default/keymap.c` — QMK ortho (12 cols, no thumbs)
