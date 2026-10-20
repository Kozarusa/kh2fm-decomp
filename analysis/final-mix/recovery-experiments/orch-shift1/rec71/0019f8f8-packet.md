# Target packet 0019f8f8

- Range: `0019f8f8`..`0019f94c`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019f8f8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c0150` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019f8f8: 27bdfff0  addiu	sp,sp,-16
0019f8fc: ffb00000  sd	s0,0(sp)
0019f900: ffbf0008  sd	ra,8(sp)
0019f904: 0080802d  move	s0,a0
0019f908: ae050000  sw	a1,0(s0)
0019f90c: 24840048  addiu	a0,a0,72
0019f910: 0c070054  jal	0x1c0150
0019f914: ae000004  sw	zero,4(s0)
0019f918: 2610000c  addiu	s0,s0,12
0019f91c: 240f0007  li	t7,7
0019f920: ae000000  sw	zero,0(s0)
0019f924: 25efffff  addiu	t7,t7,-1
0019f928: 00000000  nop
0019f92c: 00000000  nop
0019f930: 00000000  nop
0019f934: 05e1fffa  bgez	t7,0x19f920
0019f938: 26100008  addiu	s0,s0,8
0019f93c: dfb00000  ld	s0,0(sp)
0019f940: dfbf0008  ld	ra,8(sp)
0019f944: 03e00008  jr	ra
0019f948: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019f8f8(void)`

```c
void FUN_0019f8f8(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  *param_1 = param_2;
  param_1[1] = 0;
  FUN_001c0150(param_1 + 0x12);
  param_1 = param_1 + 3;
  iVar1 = 7;
  do {
    *param_1 = 0;
    iVar1 = iVar1 + -1;
    param_1 = param_1 + 2;
  } while (-1 < iVar1);
  return;
}
```

## Earlier attempts (newest first)

- 6 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_0.cpp`)
