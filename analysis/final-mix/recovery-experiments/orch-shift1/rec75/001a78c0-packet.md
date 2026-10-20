# Target packet 001a78c0

- Range: `001a78c0`..`001a7918`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a78c0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001a7a48` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`
- `001a7da8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a78c0: 27bdffb0  addiu	sp,sp,-80
001a78c4: e7b50044  swc1	$f21,68(sp)
001a78c8: e7b40040  swc1	$f20,64(sp)
001a78cc: 46007d46  mov.s	$f21,$f15
001a78d0: ffb00030  sd	s0,48(sp)
001a78d4: 46007506  mov.s	$f20,$f14
001a78d8: ffbf0038  sd	ra,56(sp)
001a78dc: 0080802d  move	s0,a0
001a78e0: 0c069e92  jal	0x1a7a48
001a78e4: 03a0202d  move	a0,sp
001a78e8: 4600a306  mov.s	$f12,$f20
001a78ec: 0200202d  move	a0,s0
001a78f0: 4600ab46  mov.s	$f13,$f21
001a78f4: 0c069f6a  jal	0x1a7da8
001a78f8: 03a0282d  move	a1,sp
001a78fc: 0200102d  move	v0,s0
001a7900: dfbf0038  ld	ra,56(sp)
001a7904: dfb00030  ld	s0,48(sp)
001a7908: c7b50044  lwc1	$f21,68(sp)
001a790c: c7b40040  lwc1	$f20,64(sp)
001a7910: 03e00008  jr	ra
001a7914: 27bd0050  addiu	sp,sp,80
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a78c0(void)`

```c
undefined8
FUN_001a78c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined8 param_5)

{
  undefined1 auStack_50 [48];
  
  FUN_001a7a48(auStack_50);
  FUN_001a7da8(param_3,param_4,param_5,auStack_50);
  return param_5;
}
```

## Earlier attempts (newest first)

- 15 differing words, 88/88 bytes: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_05_0.cpp`)
