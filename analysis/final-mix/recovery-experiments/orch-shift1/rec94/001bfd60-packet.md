# Target packet 001bfd60

- Range: `001bfd60`..`001bfd9c`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bfd60`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bfd60: 0000602d  move	t4,zero
001bfd64: 0000682d  move	t5,zero
001bfd68: 8c8f0000  lw	t7,0(a0)
001bfd6c: 0080102d  move	v0,a0
001bfd70: 11e50008  beq	t7,a1,0x1bfd94
001bfd74: 39ee0000  xori	t6,t7,0x0
001bfd78: 008e600a  movz	t4,a0,t6
001bfd7c: 25ad0001  addiu	t5,t5,1
001bfd80: 29af0008  slti	t7,t5,8
001bfd84: 15e0fff8  bnez	t7,0x1bfd68
001bfd88: 24840010  addiu	a0,a0,16
001bfd8c: ad850000  sw	a1,0(t4)
001bfd90: 0180102d  move	v0,t4
001bfd94: 03e00008  jr	ra
001bfd98: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bfd60(void)`

```c
int * FUN_001bfd60(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)0x0;
  iVar2 = 0;
  do {
    if (*param_1 == param_2) {
      return param_1;
    }
    if (*param_1 == 0) {
      piVar1 = param_1;
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 4;
  } while (iVar2 < 8);
  *piVar1 = param_2;
  return piVar1;
}
```

## Earlier attempts (newest first)

- 13 differing words, 56/60 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_04.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_04.cpp`)
