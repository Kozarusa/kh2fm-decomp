# Target packet 001d7f40

- Range: `001d7f40`..`001d7f7c`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d7f40`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d7f40: 8c8c0000  lw	t4,0(a0)
001d7f44: 1980000a  blez	t4,0x1d7f70
001d7f48: 0000682d  move	t5,zero
001d7f4c: 24840004  addiu	a0,a0,4
001d7f50: 908f0000  lbu	t7,0(a0)
001d7f54: 01a0102d  move	v0,t5
001d7f58: 25ad0001  addiu	t5,t5,1
001d7f5c: 24840044  addiu	a0,a0,68
001d7f60: 11e50004  beq	t7,a1,0x1d7f74
001d7f64: 01ac702a  slt	t6,t5,t4
001d7f68: 55c0fffa  bnezl	t6,0x1d7f54
001d7f6c: 908f0000  lbu	t7,0(a0)
001d7f70: 2402ffff  li	v0,-1
001d7f74: 03e00008  jr	ra
001d7f78: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d7f40(void)`

```c
int FUN_001d7f40(int *param_1,ulong param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  if (*param_1 < 1) {
LAB_001d7f70:
    iVar3 = -1;
  }
  else {
    pbVar2 = (byte *)(param_1 + 1);
    bVar1 = *pbVar2;
    iVar3 = 0;
    while( true ) {
      pbVar2 = pbVar2 + 0x44;
      if (bVar1 == param_2) break;
      if (*param_1 <= iVar3 + 1) goto LAB_001d7f70;
      bVar1 = *pbVar2;
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}
```

## Earlier attempts (newest first)

- none found
