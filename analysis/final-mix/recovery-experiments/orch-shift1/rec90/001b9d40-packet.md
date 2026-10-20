# Target packet 001b9d40

- Range: `001b9d40`..`001b9db0`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b9d40`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b9d40: 27bdffe0  addiu	sp,sp,-32
001b9d44: ffb00000  sd	s0,0(sp)
001b9d48: ffb10008  sd	s1,8(sp)
001b9d4c: ffbf0010  sd	ra,16(sp)
001b9d50: 0080802d  move	s0,a0
001b9d54: 8c8f0000  lw	t7,0(a0)
001b9d58: 8de20040  lw	v0,64(t7)
001b9d5c: 0040f809  jalr	v0
001b9d60: 0000882d  move	s1,zero
001b9d64: 1040000c  beqz	v0,0x1b9d98
001b9d68: 0000682d  move	t5,zero
001b9d6c: 8e040160  lw	a0,352(s0)
001b9d70: 308f0004  andi	t7,a0,0x4
001b9d74: 15e00006  bnez	t7,0x1b9d90
001b9d78: 308e0008  andi	t6,a0,0x8
001b9d7c: 55c00005  bnezl	t6,0x1b9d94
001b9d80: 240d0001  li	t5,1
001b9d84: 308f0010  andi	t7,a0,0x10
001b9d88: 11e00003  beqz	t7,0x1b9d98
001b9d8c: 01a0882d  move	s1,t5
001b9d90: 240d0001  li	t5,1
001b9d94: 01a0882d  move	s1,t5
001b9d98: 0220102d  move	v0,s1
001b9d9c: dfb00000  ld	s0,0(sp)
001b9da0: dfb10008  ld	s1,8(sp)
001b9da4: dfbf0010  ld	ra,16(sp)
001b9da8: 03e00008  jr	ra
001b9dac: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b9d40(void)`

```c
undefined4 FUN_001b9d40(int *param_1)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  lVar2 = (**(code **)(*param_1 + 0x40))();
  if (lVar2 != 0) {
    uVar1 = param_1[0x58];
    if ((((uVar1 & 4) != 0) || ((uVar1 & 8) != 0)) || (uVar3 = 0, (uVar1 & 0x10) != 0)) {
      uVar3 = 1;
    }
  }
  return uVar3;
}
```

## Earlier attempts (newest first)

- none found
