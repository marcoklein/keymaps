---
name: keymap-formatting
description: Use when writing, editing, or reformatting ZMK (.keymap) or QMK (keymap.c) keymap files. Trigger on: keymap, format, alignment, box drawing, grid, reformat, styling.
---

# Keymap Formatting

## Overview

W=12 fixed-width columns, Unicode box drawings. Each binding is right-padded to exactly 12 chars. >12 chars → `#define` alias.

**Binding line separators**: `│` for QMK (C comments allow it). For ZMK, use **space only** — the devicetree parser rejects `│` inside `<...>` blocks. ZMK `│` separators go only in `//` comment lines (box drawings).

## Column rules

- **W = 12** uniform across all keyboards (ZMK and QMK).
- **Padding**: right-pad to W with trailing spaces.
  - ZMK: `&kp Q` → `"&kp Q       "` (5+7). No commas.
  - QMK: `KC_TAB,` → `"KC_TAB,     "` (7+5). Comma counts toward W.
- **ZMK binding lines**: Space-padded only. No `│` — the devicetree parser inside `<...>` rejects non-reference characters. Use space to separate columns (e.g. `&kp Q       &kp W       &kp F`). `│` separators go in `//` comment lines exclusively.
- **QMK binding lines**: `│` between every column within a half: `│<C0>│<C1>│…│<C4>│`
- **Edge**: ZMK binding lines omit edge `│` and start at W=12 grid position (no leading `│`). QMK has leading `│` at both half edges.
- **Gap**: 3 spaces between halves (between last column of left half and first column of right half).
- **Indent**: 3 spaces ZMK, 5 spaces QMK. Binding line first column starts after indent.
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

- **ZMK**: 3 spaces indent (binding line first column position). `//` comment lines start at same indent for box drawings (e.g. `// ╭`). No `│` on binding lines — column alignment uses W=12 spacing.
- **QMK**: 5 spaces indent (aligns `│` under `╭` at position 5: `  // ╭` → `     │`).
- Thumb lines: skip = `INDENT + T×(W+1)` spaces.
- Box drawings use the same indent as their binding lines.

## Reference

- `babbit36-zmk/config/babbit36.keymap` — ZMK split (5 cols, T=2)
- `corne-zmk/config/corne.keymap` — ZMK split (6 cols, T=3)
- `crkbd-qmk/marco-default/keymap.c` — QMK split (6 cols, T=3)
- `preonic-qmk/marco-default/keymap.c` — QMK ortho (12 cols, no thumbs)
