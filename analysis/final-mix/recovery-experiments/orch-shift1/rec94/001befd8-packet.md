# Target packet 001befd8

- Range: `001befd8`..`001bf010`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001befd8`
- Registry names for this address: `func_001befd8`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bd5b0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`, `fm_scalar_extra_recovered_12.cpp`
- `001bd668` registry: `func_001bd668`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001befd8: 27bdfff0  addiu	sp,sp,-16
001befdc: ac850aa8  sw	a1,2728(a0)
001befe0: ffb00000  sd	s0,0(sp)
001befe4: ffbf0008  sd	ra,8(sp)
001befe8: ac860aac  sw	a2,2732(a0)
001befec: 0c06f59a  jal	0x1bd668
001beff0: 0080802d  move	s0,a0
001beff4: 0200202d  move	a0,s0
001beff8: dfbf0008  ld	ra,8(sp)
001beffc: dfb00000  ld	s0,0(sp)
001bf000: 2405000a  li	a1,10
001bf004: 0000302d  move	a2,zero
001bf008: 0806f56c  j	0x1bd5b0
001bf00c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001befd8(void)`

```c
void FUN_001befd8(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)((int)param_1 + 0xaa8) = param_2;
  *(undefined4 *)((int)param_1 + 0xaac) = param_3;
  FUN_001bd668();
  FUN_001bd5b0(param_1,10,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
