# Target packet 001bb7f8

- Range: `001bb7f8`..`001bb854`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bb7f8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00198d00` registry: `func_00198d00`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`
- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bb7f8: 27bdfff0  addiu	sp,sp,-16
001bb7fc: ffb00000  sd	s0,0(sp)
001bb800: ffbf0008  sd	ra,8(sp)
001bb804: 0c06ed28  jal	0x1bb4a0
001bb808: 0000802d  move	s0,zero
001bb80c: 24040008  li	a0,8
001bb810: 1040000b  beqz	v0,0x1bb840
001bb814: 2405ffff  li	a1,-1
001bb818: 0c066340  jal	0x198d00
001bb81c: 00000000  nop
001bb820: 54400007  bnezl	v0,0x1bb840
001bb824: 24100001  li	s0,1
001bb828: 3c0f01d5  lui	t7,0x1d5
001bb82c: 8dee9320  lw	t6,-27872(t7)   ; = D_01d49320
001bb830: 8dcd00ac  lw	t5,172(t6)
001bb834: 11a00003  beqz	t5,0x1bb844
001bb838: 0200102d  move	v0,s0
001bb83c: 24100001  li	s0,1
001bb840: 0200102d  move	v0,s0
001bb844: dfbf0008  ld	ra,8(sp)
001bb848: dfb00000  ld	s0,0(sp)
001bb84c: 03e00008  jr	ra
001bb850: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bb7f8(void)`

```c
undefined4 FUN_001bb7f8(void)

{
  long lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  lVar1 = FUN_001bb4a0();
  if (lVar1 != 0) {
    lVar1 = FUN_00198d00(8,0xffffffffffffffff);
    if (lVar1 == 0) {
      uVar2 = 0;
      if (*(int *)(DAT_01d49320 + 0xac) != 0) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- none found
