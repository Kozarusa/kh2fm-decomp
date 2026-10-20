# Target packet 001adbc0

- Range: `001adbc0`..`001adc08`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_001adbc0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001a15d0` registry: `_ZN2YS5SHEET11AllocPlayerEii`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbr_recovered_001a1658.cpp`
- `001a17c8` registry: `func_001a17c8`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`
- `001a1c70` registry: `func_001a1c70`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001adbc0: 3c0f0033  lui	t7,0x33
001adbc4: 27bdfff0  addiu	sp,sp,-16
001adbc8: 25efbb30  addiu	t7,t7,-17616   ; = D_0032bb30
001adbcc: ffbf0008  sd	ra,8(sp)
001adbd0: ffb00000  sd	s0,0(sp)
001adbd4: 2405ffff  li	a1,-1
001adbd8: a1e03525  sb	zero,13605(t7)
001adbdc: 24040001  li	a0,1
001adbe0: 0c068574  jal	0x1a15d0
001adbe4: a1e03524  sb	zero,13604(t7)
001adbe8: 0040802d  move	s0,v0
001adbec: 0c06871c  jal	0x1a1c70
001adbf0: 0040202d  move	a0,v0
001adbf4: 0200202d  move	a0,s0
001adbf8: dfbf0008  ld	ra,8(sp)
001adbfc: dfb00000  ld	s0,0(sp)
001adc00: 080685f2  j	0x1a17c8
001adc04: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001adbc0(void)`

```c
void FUN_001adbc0(void)

{
  undefined8 uVar1;
  
  DAT_0032f050._5_1_ = 0;
  DAT_0032f050._4_1_ = 0;
  uVar1 = FUN_001a15d0(1,0xffffffffffffffff);
  FUN_001a1c70(uVar1);
  FUN_001a17c8(uVar1);
  return;
}
```

## Earlier attempts (newest first)

- none found
