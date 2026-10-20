# Target packet 0024b1a0

- Range: `0024b1a0`..`0024b1f4`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_0024b1a0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0024ac88` registry: `func_0024ac88`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0024b1a0: 27bdfff0  addiu	sp,sp,-16
0024b1a4: 240f0001  li	t7,1
0024b1a8: ffb00000  sd	s0,0(sp)
0024b1ac: ffbf0008  sd	ra,8(sp)
0024b1b0: 148f000a  bne	a0,t7,0x24b1dc
0024b1b4: 0080802d  move	s0,a0
0024b1b8: 0c092b22  jal	0x24ac88
0024b1bc: 00000000  nop
0024b1c0: 10400006  beqz	v0,0x24b1dc
0024b1c4: 3c0f0037  lui	t7,0x37
0024b1c8: 25e21eb8  addiu	v0,t7,7864   ; = D_00371eb8
0024b1cc: dfb00000  ld	s0,0(sp)
0024b1d0: dfbf0008  ld	ra,8(sp)
0024b1d4: 03e00008  jr	ra
0024b1d8: 27bd0010  addiu	sp,sp,16
0024b1dc: 240f0006  li	t7,6
0024b1e0: 3c0e0037  lui	t6,0x37
0024b1e4: 020f7818  mult	t7,s0,t7
0024b1e8: 25ce1ea8  addiu	t6,t6,7848   ; = D_00371ea8
0024b1ec: 1000fff7  b	0x24b1cc
0024b1f0: 01ee1021  addu	v0,t7,t6
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0024b1a0(void)`

```c
undefined * FUN_0024b1a0(long param_1)

{
  undefined *puVar1;
  long lVar2;
  
  if ((param_1 == 1) && (lVar2 = FUN_0024ac88(), lVar2 != 0)) {
    puVar1 = &DAT_00371eb8;
  }
  else {
    puVar1 = (undefined *)((int)param_1 * 6 + 0x371ea8);
  }
  return puVar1;
}
```

## Earlier attempts (newest first)

- none found
