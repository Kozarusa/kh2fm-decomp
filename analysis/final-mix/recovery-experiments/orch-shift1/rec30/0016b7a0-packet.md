# Target packet 0016b7a0

- Range: `0016b7a0`..`0016b7fc`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016b7a0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016bff0` registry: `_ZN2YS3OBJ10get_serialEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_loadorder_recovered.cpp`
- `001b9bc8` registry: `_Z16ctarget_001b9bc8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016b7a0: 27bdffe0  addiu	sp,sp,-32
0016b7a4: ffb00000  sd	s0,0(sp)
0016b7a8: ffb10008  sd	s1,8(sp)
0016b7ac: ffbf0010  sd	ra,16(sp)
0016b7b0: 0000802d  move	s0,zero
0016b7b4: 0080882d  move	s1,a0
0016b7b8: 0c06e6f2  jal	0x1b9bc8
0016b7bc: 0200202d  move	a0,s0
0016b7c0: 0040802d  move	s0,v0
0016b7c4: 14400007  bnez	v0,0x16b7e4
0016b7c8: 0040202d  move	a0,v0
0016b7cc: 0200102d  move	v0,s0
0016b7d0: dfb10008  ld	s1,8(sp)
0016b7d4: dfb00000  ld	s0,0(sp)
0016b7d8: dfbf0010  ld	ra,16(sp)
0016b7dc: 03e00008  jr	ra
0016b7e0: 27bd0020  addiu	sp,sp,32
0016b7e4: 0c05affc  jal	0x16bff0
0016b7e8: 00000000  nop
0016b7ec: 1051fff8  beq	v0,s1,0x16b7d0
0016b7f0: 0200102d  move	v0,s0
0016b7f4: 1000fff0  b	0x16b7b8
0016b7f8: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016b7a0(void)`

```c
long FUN_0016b7a0(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = 0;
  do {
    lVar2 = FUN_001b9bc8(lVar2);
    if (lVar2 == 0) {
      return 0;
    }
    lVar1 = FUN_0016bff0(lVar2);
  } while (lVar1 != param_1);
  return lVar2;
}
```

## Earlier attempts (newest first)

- none found
