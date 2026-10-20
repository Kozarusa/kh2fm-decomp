# Target packet 001b8e00

- Range: `001b8e00`..`001b8e78`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b8e00`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00181550` registry: `YS::PROGRESS::IsSecond()`
- `001b8838` registry: none
- `001b8958` registry: `_ZN2YS9WORLDFLAG5CheckEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b8e00: 27bdfff0  addiu	sp,sp,-16
001b8e04: ffb00000  sd	s0,0(sp)
001b8e08: ffbf0008  sd	ra,8(sp)
001b8e0c: 0c060554  jal	0x181550
001b8e10: 0080802d  move	s0,a0
001b8e14: 3c0f0037  lui	t7,0x37
001b8e18: 00107080  sll	t6,s0,0x2
001b8e1c: 25efdbb0  addiu	t7,t7,-9296   ; = D_0036dbb0
001b8e20: 10400010  beqz	v0,0x1b8e64
001b8e24: 01cf2021  addu	a0,t6,t7
001b8e28: 84900002  lh	s0,2(a0)
001b8e2c: 0602000a  bltzl	s0,0x1b8e58
001b8e30: dfb00000  ld	s0,0(sp)
001b8e34: 0c06e256  jal	0x1b8958
001b8e38: 0200202d  move	a0,s0
001b8e3c: 14400005  bnez	v0,0x1b8e54
001b8e40: 0200202d  move	a0,s0
001b8e44: dfb00000  ld	s0,0(sp)
001b8e48: dfbf0008  ld	ra,8(sp)
001b8e4c: 0806e20e  j	0x1b8838
001b8e50: 27bd0010  addiu	sp,sp,16
001b8e54: dfb00000  ld	s0,0(sp)
001b8e58: dfbf0008  ld	ra,8(sp)
001b8e5c: 03e00008  jr	ra
001b8e60: 27bd0010  addiu	sp,sp,16
001b8e64: 3c0f0037  lui	t7,0x37
001b8e68: 25efdbb0  addiu	t7,t7,-9296   ; = D_0036dbb0
001b8e6c: 01cf7821  addu	t7,t6,t7
001b8e70: 1000ffee  b	0x1b8e2c
001b8e74: 85f00000  lh	s0,0(t7)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b8e00(void)`

```c
void FUN_001b8e00(int param_1)

{
  short sVar1;
  long lVar2;
  
  lVar2 = FUN_00181550();
  if (lVar2 == 0) {
    sVar1 = *(short *)(&DAT_0036dbb0 + param_1 * 4);
  }
  else {
    sVar1 = *(short *)(&DAT_0036dbb2 + param_1 * 4);
  }
  if ((-1 < sVar1) && (lVar2 = FUN_001b8958(sVar1), lVar2 == 0)) {
    FUN_001b8838(sVar1);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
