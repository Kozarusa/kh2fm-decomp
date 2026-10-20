# Target packet 001db9a8

- Range: `001db9a8`..`001dba18`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001db9a8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001050d8` registry: `_ZN4AREA5AllocEj`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_callbackreturn_recovered_001050d8.cpp`
- `001db950` registry: `func_001db950`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001dba18` registry: none
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001db9a8: 27bdffd0  addiu	sp,sp,-48
001db9ac: ffb10008  sd	s1,8(sp)
001db9b0: ffb20010  sd	s2,16(sp)
001db9b4: ffb30018  sd	s3,24(sp)
001db9b8: 0080882d  move	s1,a0
001db9bc: ffb00000  sd	s0,0(sp)
001db9c0: 00a0902d  move	s2,a1
001db9c4: ffbf0020  sd	ra,32(sp)
001db9c8: 0c076e86  jal	0x1dba18
001db9cc: 00c0982d  move	s3,a2
001db9d0: 1440000a  bnez	v0,0x1db9fc
001db9d4: 24040a00  li	a0,2560
001db9d8: 0c041436  jal	0x1050d8
001db9dc: 00000000  nop
001db9e0: 0040802d  move	s0,v0
001db9e4: 0040202d  move	a0,v0
001db9e8: 0220282d  move	a1,s1
001db9ec: 0240302d  move	a2,s2
001db9f0: 0c076e54  jal	0x1db950
001db9f4: 0260382d  move	a3,s3
001db9f8: 0200102d  move	v0,s0
001db9fc: dfb00000  ld	s0,0(sp)
001dba00: dfb10008  ld	s1,8(sp)
001dba04: dfb20010  ld	s2,16(sp)
001dba08: dfb30018  ld	s3,24(sp)
001dba0c: dfbf0020  ld	ra,32(sp)
001dba10: 03e00008  jr	ra
001dba14: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001db9a8(void)`

```c
long FUN_001db9a8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = FUN_001dba18();
  if (lVar1 == 0) {
    lVar1 = FUN_001050d8(0xa00);
    FUN_001db950(lVar1,param_1,param_2,param_3);
  }
  return lVar1;
}
```

## Earlier attempts (newest first)

- 16 differing words, 116/112 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_08_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_08_1.cpp`)
