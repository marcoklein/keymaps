#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
QMK_HOME="${QMK_HOME:-$HOME/code/qmk_firmware}"

if [ ! -d "$QMK_HOME" ]; then
    echo "QMK firmware not found at $QMK_HOME"
    echo "Set QMK_HOME env var or clone qmk_firmware there first."
    exit 1
fi

echo "Linking keymaps into $QMK_HOME/keyboards..."

# Preonic
mkdir -p "$QMK_HOME/keyboards/preonic/keymaps"
ln -sfn "$SCRIPT_DIR/preonic-qmk/marco-default" "$QMK_HOME/keyboards/preonic/keymaps/marco-default"
echo "  preonic -> marco-default"

# Corne (crkbd)
mkdir -p "$QMK_HOME/keyboards/crkbd/keymaps"
ln -sfn "$SCRIPT_DIR/crkbd-qmk/marco-default" "$QMK_HOME/keyboards/crkbd/keymaps/marco-default"
echo "  crkbd   -> marco-default"

echo ""
echo "Done. You can now compile with:"
echo "  qmk compile -kb preonic -km marco-default"
echo "  qmk compile -kb crkbd   -km marco-default"
