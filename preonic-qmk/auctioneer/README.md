# Preonic auctioneer keymap

This keymap emulates the PrehKeyTec Versteigerer-Tastatur used by the flower auction auctioneer app.
It sends the same HID keycodes and modifier sequences as the production keyboard rather than simpler
application-specific shortcuts.

Macro event timing preserves the captured hardware patterns: prefix macros release Shift before the
following digit, while held macros keep Shift or Shift+Alt active across their target key events.
Key holds and inter-key gaps are 10 ms so the browser observes each HID report reliably.

The source mapping is `apps/auctioneer-app/docs/auctioneer-keyboard-keycodes.md` in the
`flower-auction` repository.

## Layout

The outer three columns reproduce the two physical digit blocks. `Start 0-9` sends the physical
keyboard's released `Shift+U` prefix followed by a top-row digit. `Qty 0-9` sends numpad digits.
Open [`layout.html`](./layout.html) in a browser for a visual keyboard diagram with shortcut details.

```text
R1-    R1+    Wagen  | 1EUR Packen ABN5 Lfs     | Next Stop VST | C3 BS
Start7 Start8 Start9 | 50ct STG    ABN4 LfsInfo | Qty7 Qty8 Qty9 | C2 Express
Start4 Start5 Start6 | 10ct Round2 ABN3 ABN10 | Qty4  Qty5  Qty6    | C1    ER1
Start1 Start2 Start3 | 5ct  Round1 ABN2 ABN8  | Qty1  Qty2  Qty3    | ----  PR
UV     Start0 UV     | 1ct  Round0 ABN1 ABN6  | ----  Qty0  ----    | ----  ER
```

Notes:

- `UV` is the clock stop sequence shown on the original keyboard; it emits held Shift with `U`, then
  `R`, matching the captured hardware despite the `UV` keycap text. Both physical `UV` positions send
  the same sequence.
- `R1-` and `R1+` emit the documented round decrement (`F8`) and increment (`F6`) events.
- `WR` is labeled `Express` on the old hardware, but its legacy behavior is Wagen-Rest.
- `ABN10` is the physical `0` key: the application interprets it as an Abnahme-Einheit of 10.
- `Express` emits the documented production Wagen-Rest sequence but is not handled by the new
  auctioneer app.
- This layout deliberately has no bootloader key because all 60 positions represent the production
  console. Use the Preonic's hardware reset button when flashing.

## Build and flash

From the `keymaps` repository:

```bash
./setup.sh
qmk compile -kb preonic/rev3 -km auctioneer
qmk flash -kb preonic/rev3 -km auctioneer
```
