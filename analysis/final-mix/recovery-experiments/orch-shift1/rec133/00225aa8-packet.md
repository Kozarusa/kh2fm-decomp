# Target packet 00225aa8

- Range: `00225aa8`..`00225afc`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_00225aa8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00225a68` registry: `func_00225a68`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00225aa8: 27bdfff0  addiu	sp,sp,-16
00225aac: 3c0f0036  lui	t7,0x36
00225ab0: ffb00000  sd	s0,0(sp)
00225ab4: ffbf0008  sd	ra,8(sp)
00225ab8: 91eedaec  lbu	t6,-9492(t7)   ; = D_0035daec
00225abc: 15c00009  bnez	t6,0x225ae4
00225ac0: 0000802d  move	s0,zero
00225ac4: 3c0f0036  lui	t7,0x36
00225ac8: 91eedaed  lbu	t6,-9491(t7)   ; = D_0035daed
00225acc: 55c00006  bnezl	t6,0x225ae8
00225ad0: 24100001  li	s0,1
00225ad4: 0c08969a  jal	0x225a68
00225ad8: 00000000  nop
00225adc: 10400003  beqz	v0,0x225aec
00225ae0: 0200102d  move	v0,s0
00225ae4: 24100001  li	s0,1
00225ae8: 0200102d  move	v0,s0
00225aec: dfbf0008  ld	ra,8(sp)
00225af0: dfb00000  ld	s0,0(sp)
00225af4: 03e00008  jr	ra
00225af8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00225aa8(void)`

```c
undefined4 FUN_00225aa8(void)

{
  long lVar1;
  
  if (((DAT_0035daec == '\0') && (DAT_0035daed == '\0')) && (lVar1 = FUN_00225a68(), lVar1 == 0)) {
    return 0;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- none found
