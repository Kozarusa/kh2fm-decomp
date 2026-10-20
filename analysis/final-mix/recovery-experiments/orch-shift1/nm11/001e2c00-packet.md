# Target packet 001e2c00

- Range: `001e2c00`..`001e2c5c`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e2c00`
- Registry names for this address: none
- Queue: state `leased`, queue `privileged-instructions`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec120\\001e2c00-BLOCKED.md", "sha256": "e894c6df71c98e0443814033f439ad6d8dfef39f2c33ded91be05eb912f42ac5", "hypothesis": "Original has break 0 after second call; find accepted break-0 primitive, make function void with non-tail call"}`

## Callees

- `001e7cc0` registry: none
- `002fdfc8` registry: `func_002fdfc8`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e2c00: 27bdfff0  addiu	sp,sp,-16
001e2c04: ffb00000  sd	s0,0(sp)
001e2c08: ffbf0008  sd	ra,8(sp)
001e2c0c: 1480000d  bnez	a0,0x1e2c44
001e2c10: 0080802d  move	s0,a0
001e2c14: 3c040037  lui	a0,0x37
001e2c18: 3c050037  lui	a1,0x37
001e2c1c: 2484e978  addiu	a0,a0,-5768   ; = D_0036e978
001e2c20: 0c0bf7f2  jal	0x2fdfc8
001e2c24: 24a5e9c0  addiu	a1,a1,-5696   ; = D_0036e9c0
001e2c28: 3c050037  lui	a1,0x37
001e2c2c: 3c040037  lui	a0,0x37
001e2c30: 24a5e9d0  addiu	a1,a1,-5680   ; = D_0036e9d0
001e2c34: 24060165  li	a2,357
001e2c38: 0c0bf7f2  jal	0x2fdfc8
001e2c3c: 2484e998  addiu	a0,a0,-5736   ; = D_0036e998
001e2c40: 0000000d  break
001e2c44: 0c079f30  jal	0x1e7cc0
001e2c48: 0200202d  move	a0,s0
001e2c4c: dfb00000  ld	s0,0(sp)
001e2c50: dfbf0008  ld	ra,8(sp)
001e2c54: 03e00008  jr	ra
001e2c58: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e2c00(void)`

```c
void FUN_001e2c00(long param_1)

{
  if (param_1 == 0) {
    FUN_002fdfc8(0x36e978,0x36e9c0);
    FUN_002fdfc8(0x36e998,0x36e9d0,0x165);
    trap(0);
  }
  FUN_001e7cc0(param_1);
  return;
}
```

## Earlier attempts (newest first)

- 11 differing words, 88/92 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec120/orch1_rec120_001e2c00_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec120/001e2c00-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec120/001e2c00-packet.md`
