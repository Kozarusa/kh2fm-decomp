# Target packet 00160de0

- Range: `00160de0`..`00160e4c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_00160de0`
- Registry names for this address: `_Z16wtarget_00160de0jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00160d28` registry: `func_00160d28`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00160de0: 27bdffe0  addiu	sp,sp,-32
00160de4: ffb00000  sd	s0,0(sp)
00160de8: ffb10008  sd	s1,8(sp)
00160dec: ffb20010  sd	s2,16(sp)
00160df0: 0000802d  move	s0,zero
00160df4: ffbf0018  sd	ra,24(sp)
00160df8: 0080882d  move	s1,a0
00160dfc: 3c12004f  lui	s2,0x4f
00160e00: 56000002  bnezl	s0,0x160e0c
00160e04: 8e040080  lw	a0,128(s0)
00160e08: 8e443b38  lw	a0,15160(s2)   ; = D_004f3b38
00160e0c: 14800008  bnez	a0,0x160e30
00160e10: 0080802d  move	s0,a0
00160e14: dfb00000  ld	s0,0(sp)
00160e18: dfb10008  ld	s1,8(sp)
00160e1c: dfb20010  ld	s2,16(sp)
00160e20: dfbf0018  ld	ra,24(sp)
00160e24: 03e00008  jr	ra
00160e28: 27bd0020  addiu	sp,sp,32
00160e2c: 00000000  nop
00160e30: 8c8f01a8  lw	t7,424(a0)
00160e34: 15f1fff2  bne	t7,s1,0x160e00
00160e38: 00000000  nop
00160e3c: 0c05834a  jal	0x160d28
00160e40: 00000000  nop
00160e44: 1000ffee  b	0x160e00
00160e48: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00160de0(void)`

```c
void FUN_00160de0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = DAT_004f3b38;
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x80);
    }
    if (iVar1 == 0) break;
    iVar2 = iVar1;
    if (*(int *)(iVar1 + 0x1a8) == param_1) {
      FUN_00160d28();
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
