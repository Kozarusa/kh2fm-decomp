# Target packet 001dba98

- Range: `001dba98`..`001dbacc`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dba98`
- Registry names for this address: `func_001dba98`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dba98: 27bdfff0  addiu	sp,sp,-16
001dba9c: ffbf0000  sd	ra,0(sp)
001dbaa0: 8c8f09f8  lw	t7,2552(a0)
001dbaa4: 25efffff  addiu	t7,t7,-1
001dbaa8: 15e00005  bnez	t7,0x1dbac0
001dbaac: ac8f09f8  sw	t7,2552(a0)
001dbab0: 8c8f0000  lw	t7,0(a0)
001dbab4: 8dee0020  lw	t6,32(t7)
001dbab8: 01c0f809  jalr	t6
001dbabc: 00000000  nop
001dbac0: dfbf0000  ld	ra,0(sp)
001dbac4: 03e00008  jr	ra
001dbac8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dba98(void)`

```c
void FUN_001dba98(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x27e];
  param_1[0x27e] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    (**(code **)(*param_1 + 0x20))();
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
