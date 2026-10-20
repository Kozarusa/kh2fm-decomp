# Target packet 001ce488

- Range: `001ce488`..`001ce508`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ce488`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001050d8` registry: `_ZN4AREA5AllocEj`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_callbackreturn_recovered_001050d8.cpp`
- `001ce3e8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`, `fm_primary_sixwordnext_recovered_001d7a50.cpp`
- `001db9a8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`, `fm_primary_sixwordnext_recovered_001d7a50.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ce488: 27bdffd0  addiu	sp,sp,-48
001ce48c: 240603e8  li	a2,1000
001ce490: e7b40028  swc1	$f20,40(sp)
001ce494: ffb30018  sd	s3,24(sp)
001ce498: 46006506  mov.s	$f20,$f12
001ce49c: ffb20010  sd	s2,16(sp)
001ce4a0: ffbf0020  sd	ra,32(sp)
001ce4a4: 00a0982d  move	s3,a1
001ce4a8: ffb00000  sd	s0,0(sp)
001ce4ac: 0080902d  move	s2,a0
001ce4b0: ffb10008  sd	s1,8(sp)
001ce4b4: 0c076e6a  jal	0x1db9a8
001ce4b8: 0000282d  move	a1,zero
001ce4bc: 0040882d  move	s1,v0
001ce4c0: 0c041436  jal	0x1050d8
001ce4c4: 24040a00  li	a0,2560
001ce4c8: 4600a306  mov.s	$f12,$f20
001ce4cc: 0040802d  move	s0,v0
001ce4d0: 0040202d  move	a0,v0
001ce4d4: 0220282d  move	a1,s1
001ce4d8: 0240302d  move	a2,s2
001ce4dc: 0c0738fa  jal	0x1ce3e8
001ce4e0: 0260382d  move	a3,s3
001ce4e4: 0200102d  move	v0,s0
001ce4e8: dfb10008  ld	s1,8(sp)
001ce4ec: dfb00000  ld	s0,0(sp)
001ce4f0: dfb20010  ld	s2,16(sp)
001ce4f4: dfb30018  ld	s3,24(sp)
001ce4f8: dfbf0020  ld	ra,32(sp)
001ce4fc: c7b40028  lwc1	$f20,40(sp)
001ce500: 03e00008  jr	ra
001ce504: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ce488(void)`

```c
undefined8 FUN_001ce488(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_001db9a8(param_2,0,1000);
  uVar2 = FUN_001050d8(0xa00);
  FUN_001ce3e8(param_1,uVar2,uVar1,param_2,param_3);
  return uVar2;
}
```

## Earlier attempts (newest first)

- 31 differing words, 132/128 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_04.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_04.cpp`)
