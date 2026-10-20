# Target packet 0019f5d8

- Range: `0019f5d8`..`0019f610`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019f5d8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019f5d8: 248e0060  addiu	t6,a0,96
0019f5dc: 8c8f0000  lw	t7,0(a0)
0019f5e0: 55e50005  bnel	t7,a1,0x19f5f8
0019f5e4: 2484000c  addiu	a0,a0,12
0019f5e8: 8c8f0004  lw	t7,4(a0)
0019f5ec: 11e60006  beq	t7,a2,0x19f608
0019f5f0: 0080102d  move	v0,a0
0019f5f4: 2484000c  addiu	a0,a0,12
0019f5f8: 008e782a  slt	t7,a0,t6
0019f5fc: 55e0fff8  bnezl	t7,0x19f5e0
0019f600: 8c8f0000  lw	t7,0(a0)
0019f604: 0000102d  move	v0,zero
0019f608: 03e00008  jr	ra
0019f60c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019f5d8(void)`

```c
int * FUN_0019f5d8(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 0x18;
  iVar2 = *param_1;
  while ((iVar2 != param_2 || (param_1[1] != param_3))) {
    param_1 = param_1 + 3;
    if ((int)piVar1 <= (int)param_1) {
      return (int *)0x0;
    }
    iVar2 = *param_1;
  }
  return param_1;
}
```

## Earlier attempts (newest first)

- none found
