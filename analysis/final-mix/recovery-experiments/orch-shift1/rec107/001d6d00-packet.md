# Target packet 001d6d00

- Range: `001d6d00`..`001d6d58`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d6d00`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d6cc8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d6d00: 27bdfff0  addiu	sp,sp,-16
001d6d04: 0000102d  move	v0,zero
001d6d08: ffb00000  sd	s0,0(sp)
001d6d0c: ffbf0008  sd	ra,8(sp)
001d6d10: 0080802d  move	s0,a0
001d6d14: 0c075b32  jal	0x1d6cc8
001d6d18: 0040202d  move	a0,v0
001d6d1c: 54400006  bnezl	v0,0x1d6d38
001d6d20: 944f0000  lhu	t7,0(v0)
001d6d24: 0000102d  move	v0,zero
001d6d28: dfb00000  ld	s0,0(sp)
001d6d2c: dfbf0008  ld	ra,8(sp)
001d6d30: 03e00008  jr	ra
001d6d34: 27bd0010  addiu	sp,sp,16
001d6d38: 15f0fff6  bne	t7,s0,0x1d6d14
001d6d3c: 3c0e01d6  lui	t6,0x1d6
001d6d40: 8dcfba98  lw	t7,-17768(t6)   ; = D_01d5ba98
001d6d44: 004f7823  subu	t7,v0,t7
001d6d48: 25effff8  addiu	t7,t7,-8
001d6d4c: 000f7983  sra	t7,t7,0x6
001d6d50: 1000fff5  b	0x1d6d28
001d6d54: 25e20001  addiu	v0,t7,1
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d6d00(void)`

```c
int FUN_001d6d00(ulong param_1)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    lVar1 = FUN_001d6cc8(lVar1);
    if (lVar1 == 0) {
      return 0;
    }
  } while (*(ushort *)lVar1 != param_1);
  return ((int)(ushort *)lVar1 + (-8 - DAT_01d5ba98) >> 6) + 1;
}
```

## Earlier attempts (newest first)

- none found
