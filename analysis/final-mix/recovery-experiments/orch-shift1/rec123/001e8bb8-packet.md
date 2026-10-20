# Target packet 001e8bb8

- Range: `001e8bb8`..`001e8c24`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e8bb8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e7878` registry: none
- `001e8330` registry: none
- `001e8ac8` registry: none
- `002fdfc8` registry: `func_002fdfc8`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e8bb8: 27bdfff0  addiu	sp,sp,-16
001e8bbc: ffb00000  sd	s0,0(sp)
001e8bc0: ffbf0008  sd	ra,8(sp)
001e8bc4: 1480000d  bnez	a0,0x1e8bfc
001e8bc8: 0080802d  move	s0,a0
001e8bcc: 3c040037  lui	a0,0x37
001e8bd0: 3c050037  lui	a1,0x37
001e8bd4: 2484ef58  addiu	a0,a0,-4264   ; = D_0036ef58
001e8bd8: 0c0bf7f2  jal	0x2fdfc8
001e8bdc: 24a5efc8  addiu	a1,a1,-4152   ; = D_0036efc8
001e8be0: 3c050037  lui	a1,0x37
001e8be4: 3c040037  lui	a0,0x37
001e8be8: 24a5ef88  addiu	a1,a1,-4216   ; = D_0036ef88
001e8bec: 240603d6  li	a2,982
001e8bf0: 0c0bf7f2  jal	0x2fdfc8
001e8bf4: 2484ef98  addiu	a0,a0,-4200   ; = D_0036ef98
001e8bf8: 0000000d  break
001e8bfc: 0c079e1e  jal	0x1e7878
001e8c00: 0200202d  move	a0,s0
001e8c04: 0c07a2b2  jal	0x1e8ac8
001e8c08: 0200202d  move	a0,s0
001e8c0c: 0c07a0cc  jal	0x1e8330
001e8c10: 0200202d  move	a0,s0
001e8c14: dfb00000  ld	s0,0(sp)
001e8c18: dfbf0008  ld	ra,8(sp)
001e8c1c: 03e00008  jr	ra
001e8c20: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e8bb8(void)`

```c
void FUN_001e8bb8(long param_1)

{
  if (param_1 == 0) {
    FUN_002fdfc8(0x36ef58,0x36efc8);
    FUN_002fdfc8(0x36ef98,0x36ef88,0x3d6);
    trap(0);
  }
  FUN_001e7878(param_1);
  FUN_001e8ac8(param_1);
  FUN_001e8330(param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
