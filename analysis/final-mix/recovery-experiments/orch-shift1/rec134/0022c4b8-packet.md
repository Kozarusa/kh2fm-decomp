# Target packet 0022c4b8

- Range: `0022c4b8`..`0022c504`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_0022c4b8`
- Registry names for this address: `func_0022c4b8`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002fee78` registry: `_Z16wtarget_002fee78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_framealias_recovered_address.cpp`, `fm_primary_loadorder_recovered.cpp`
- `002ff3fc` registry: `func_002ff3fc`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_03.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_framealias_recovered_address.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0022c4b8: 27bdfff0  addiu	sp,sp,-16
0022c4bc: 3c0f0034  lui	t7,0x34
0022c4c0: ffb00000  sd	s0,0(sp)
0022c4c4: 0080382d  move	a3,a0
0022c4c8: ffbf0008  sd	ra,8(sp)
0022c4cc: 3c050037  lui	a1,0x37
0022c4d0: 3c1001db  lui	s0,0x1db
0022c4d4: 8de6caf4  lw	a2,-13580(t7)   ; = D_0033caf4
0022c4d8: 2610d960  addiu	s0,s0,-9888   ; = D_01dad960
0022c4dc: 24a51190  addiu	a1,a1,4496   ; = D_00371190
0022c4e0: 0c0bfb9e  jal	0x2fee78
0022c4e4: 0200202d  move	a0,s0
0022c4e8: 0c0bfcff  jal	0x2ff3fc
0022c4ec: 0200202d  move	a0,s0
0022c4f0: 0200102d  move	v0,s0
0022c4f4: dfbf0008  ld	ra,8(sp)
0022c4f8: dfb00000  ld	s0,0(sp)
0022c4fc: 03e00008  jr	ra
0022c500: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0022c4b8(void)`

```c
undefined8 FUN_0022c4b8(undefined8 param_1)

{
  FUN_002fee78(0x1dad960,0x371190,DAT_0033caf4,param_1);
  FUN_002ff3fc(0x1dad960);
  return 0x1dad960;
}
```

## Earlier attempts (newest first)

- none found
