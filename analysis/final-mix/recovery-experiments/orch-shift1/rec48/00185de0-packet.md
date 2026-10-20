# Target packet 00185de0

- Range: `00185de0`..`00185e20`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_00185de0`
- Registry names for this address: `_Z16ctarget_00185de0jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016b0d0` registry: `_ZN2YS3OBJ9GetPlayerEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_orchas_recovered_001608c0.cpp`, `fm_primary_twowordfresh_recovered_00149ec0.cpp`, `fm_scalar_extra_recovered_01.cpp`, `fm_scalar_recovered_01.cpp`
- `0019ba60` registry: `_Z16ctarget_0019ba60jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00185de0: 27bdfff0  addiu	sp,sp,-16
00185de4: ffb00000  sd	s0,0(sp)
00185de8: ffbf0008  sd	ra,8(sp)
00185dec: 3c1001c6  lui	s0,0x1c6
00185df0: 0c066e98  jal	0x19ba60
00185df4: 8e0408b8  lw	a0,2232(s0)   ; = D_01c608b8
00185df8: 14400005  bnez	v0,0x185e10
00185dfc: 8e0208b8  lw	v0,2232(s0)   ; = D_01c608b8
00185e00: dfb00000  ld	s0,0(sp)
00185e04: dfbf0008  ld	ra,8(sp)
00185e08: 0805ac34  j	0x16b0d0
00185e0c: 27bd0010  addiu	sp,sp,16
00185e10: dfbf0008  ld	ra,8(sp)
00185e14: dfb00000  ld	s0,0(sp)
00185e18: 03e00008  jr	ra
00185e1c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00185de0(void)`

```c
undefined4 FUN_00185de0(void)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_0019ba60(DAT_01c608b8);
  if (lVar2 == 0) {
    uVar1 = FUN_0016b0d0();
    return uVar1;
  }
  return DAT_01c608b8;
}
```

## Earlier attempts (newest first)

- none found
