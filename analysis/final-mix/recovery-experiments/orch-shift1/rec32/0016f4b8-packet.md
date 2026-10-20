# Target packet 0016f4b8

- Range: `0016f4b8`..`0016f51c`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016f4b8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002fee78` registry: `_Z16wtarget_002fee78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_framealias_recovered_address.cpp`, `fm_primary_loadorder_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016f4b8: 27bdfff0  addiu	sp,sp,-16
0016f4bc: 24860008  addiu	a2,a0,8
0016f4c0: ffb00000  sd	s0,0(sp)
0016f4c4: 0000102d  move	v0,zero
0016f4c8: ffbf0008  sd	ra,8(sp)
0016f4cc: 908f0048  lbu	t7,72(a0)
0016f4d0: 39ef0001  xori	t7,t7,0x1
0016f4d4: 31ef0001  andi	t7,t7,0x1
0016f4d8: 11e0000c  beqz	t7,0x16f50c
0016f4dc: 00a0802d  move	s0,a1
0016f4e0: 14a00004  bnez	a1,0x16f4f4
0016f4e4: 3c0f0034  lui	t7,0x34
0016f4e8: 3c0f004f  lui	t7,0x4f
0016f4ec: 25f063d8  addiu	s0,t7,25560   ; = D_004f63d8
0016f4f0: 3c0f0034  lui	t7,0x34
0016f4f4: 3c050037  lui	a1,0x37
0016f4f8: 8de7caf0  lw	a3,-13584(t7)   ; = D_0033caf0
0016f4fc: 24a5c450  addiu	a1,a1,-15280   ; = D_0036c450
0016f500: 0c0bfb9e  jal	0x2fee78
0016f504: 0200202d  move	a0,s0
0016f508: 0200102d  move	v0,s0
0016f50c: dfb00000  ld	s0,0(sp)
0016f510: dfbf0008  ld	ra,8(sp)
0016f514: 03e00008  jr	ra
0016f518: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016f4b8(void)`

```c
long FUN_0016f4b8(int param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0;
  if (((*(byte *)(param_1 + 0x48) ^ 1) & 1) != 0) {
    lVar1 = param_2;
    if (param_2 == 0) {
      lVar1 = 0x4f63d8;
    }
    FUN_002fee78(lVar1,0x36c450,param_1 + 8,DAT_0033caf0);
  }
  return lVar1;
}
```

## Earlier attempts (newest first)

- none found
