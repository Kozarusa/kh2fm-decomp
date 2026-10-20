# Target packet 0024eff8

- Range: `0024eff8`..`0024f06c`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_0024eff8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `0023f5b8` registry: `func_0023f5b8(int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0024eff8: 27bdffe0  addiu	sp,sp,-32
0024effc: ffb10008  sd	s1,8(sp)
0024f000: ffb00000  sd	s0,0(sp)
0024f004: ffbf0010  sd	ra,16(sp)
0024f008: 3c110036  lui	s1,0x36
0024f00c: 0080802d  move	s0,a0
0024f010: 8e2fee0c  lw	t7,-4596(s1)   ; = D_0035ee0c
0024f014: 11e00010  beqz	t7,0x24f058
0024f018: 01e0202d  move	a0,t7
0024f01c: 0c04e75e  jal	0x139d78
0024f020: 00000000  nop
0024f024: 3c0f0037  lui	t7,0x37
0024f028: 00107080  sll	t6,s0,0x2
0024f02c: 25ef23a0  addiu	t7,t7,9120   ; = D_003723a0
0024f030: 0000302d  move	a2,zero
0024f034: 10400008  beqz	v0,0x24f058
0024f038: 01cf2021  addu	a0,t6,t7
0024f03c: 8c850000  lw	a1,0(a0)
0024f040: dfb00000  ld	s0,0(sp)
0024f044: 8e24ee0c  lw	a0,-4596(s1)   ; = D_0035ee0c
0024f048: dfbf0010  ld	ra,16(sp)
0024f04c: dfb10008  ld	s1,8(sp)
0024f050: 0808fd6e  j	0x23f5b8
0024f054: 27bd0020  addiu	sp,sp,32
0024f058: dfb00000  ld	s0,0(sp)
0024f05c: dfb10008  ld	s1,8(sp)
0024f060: dfbf0010  ld	ra,16(sp)
0024f064: 03e00008  jr	ra
0024f068: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0024eff8(void)`

```c
void FUN_0024eff8(int param_1)

{
  long lVar1;
  
  if (DAT_0035ee0c != 0) {
    lVar1 = FUN_00139d78(DAT_0035ee0c);
    if (lVar1 != 0) {
      FUN_0023f5b8(DAT_0035ee0c,*(undefined4 *)(&DAT_003723a0 + param_1 * 4),0);
      return;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
