#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
QMK_HOME="${QMK_HOME:-$SCRIPT_DIR/.tmp/qmk_firmware}"

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
echo ""
echo "QMK done. You can now compile with:"
echo "  qmk compile -kb preonic/rev3 -km marco-default"
echo "  qmk compile -kb crkbd/rev1 -km marco-default"
echo ""
echo "ZMK keyboards (corne-zmk, babbit36-zmk) are built via GitHub Actions."
echo "Push changes to trigger a build, or run:"
echo "  gh workflow run zmk-build.yml -R marcoklein/keymaps"
