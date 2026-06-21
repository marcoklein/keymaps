---
name: qmk-firmware-update
description: Use ONLY when updating the pinned QMK firmware commit (upgrading, testing a newer upstream). Trigger: update qmk, upgrade firmware, bump qmk, pinned commit, qmk_firmware version.
---

# QMK Firmware Pinned Commit

Upstream QMK firmware is cloned into `.tmp/qmk_firmware` and pinned to a known-good commit. This skill manages the pinned commit and upgrade process.

## Current pinned commit

```
PINNED_COMMIT=c6381000309a8d9300cb1ca8ec01cfa3d4ed4c5f
```

## Upgrade procedure

1. Fetch latest upstream:
```bash
cd .tmp/qmk_firmware && git fetch origin master
```

2. Checkout the new commit and update submodules:
```bash
git checkout <new-commit-hash>
git submodule update --init --recursive
```

3. Test compile both keyboards:
```bash
export PATH="/opt/homebrew/opt/avr-gcc@8/bin:$PATH"
qmk compile -kb crkbd/rev1 -km marco-default

export PATH="/opt/homebrew/opt/arm-none-eabi-binutils/bin:/opt/homebrew/opt/arm-none-eabi-gcc@8/bin:$PATH"
qmk compile -kb preonic/rev3 -km marco-default
```

4. If successful, update `PINNED_COMMIT` in this file AND in:
   - `.opencode/skills/qmk-crkbd-flashing/SKILL.md`
   - `.opencode/skills/qmk-preonic-flashing/SKILL.md`

5. If compilation fails, roll back:
```bash
git checkout c6381000309a8d9300cb1ca8ec01cfa3d4ed4c5f
git submodule update --init --recursive
```
