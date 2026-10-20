# Target packet 00251ec8

- Range: `00251ec8`..`00251f3c`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_00251ec8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `0023f5b8` registry: `func_0023f5b8(int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00251ec8: 27bdffe0  addiu	sp,sp,-32
00251ecc: ffb10008  sd	s1,8(sp)
00251ed0: ffb00000  sd	s0,0(sp)
00251ed4: ffbf0010  sd	ra,16(sp)
00251ed8: 3c110036  lui	s1,0x36
00251edc: 0080802d  move	s0,a0
00251ee0: 8e2fee64  lw	t7,-4508(s1)   ; = D_0035ee64
00251ee4: 11e00010  beqz	t7,0x251f28
00251ee8: 01e0202d  move	a0,t7
00251eec: 0c04e75e  jal	0x139d78
00251ef0: 00000000  nop
00251ef4: 3c0f0037  lui	t7,0x37
00251ef8: 00107080  sll	t6,s0,0x2
00251efc: 25ef2668  addiu	t7,t7,9832   ; = D_00372668
00251f00: 0000302d  move	a2,zero
00251f04: 10400008  beqz	v0,0x251f28
00251f08: 01cf2021  addu	a0,t6,t7
00251f0c: 8c850000  lw	a1,0(a0)
00251f10: dfb00000  ld	s0,0(sp)
00251f14: 8e24ee64  lw	a0,-4508(s1)   ; = D_0035ee64
00251f18: dfbf0010  ld	ra,16(sp)
00251f1c: dfb10008  ld	s1,8(sp)
00251f20: 0808fd6e  j	0x23f5b8
00251f24: 27bd0020  addiu	sp,sp,32
00251f28: dfb00000  ld	s0,0(sp)
00251f2c: dfb10008  ld	s1,8(sp)
00251f30: dfbf0010  ld	ra,16(sp)
00251f34: 03e00008  jr	ra
00251f38: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00251ec8(void)`

```c
void FUN_00251ec8(int param_1)

{
  long lVar1;
  
  if (DAT_0035ee64 != 0) {
    lVar1 = FUN_00139d78(DAT_0035ee64);
    if (lVar1 != 0) {
      FUN_0023f5b8(DAT_0035ee64,*(undefined4 *)(&DAT_00372668 + param_1 * 4),0);
      return;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
