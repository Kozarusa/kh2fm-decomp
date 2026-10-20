# Target packet 001c9db0

- Range: `001c9db0`..`001c9df8`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c9db0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c9db0: 3c0f0035  lui	t7,0x35
001c9db4: 8def1f30  lw	t7,7984(t7)   ; = D_00351f30
001c9db8: 19e0000c  blez	t7,0x1c9dec
001c9dbc: 0000682d  move	t5,zero
001c9dc0: 01e0602d  move	t4,t7
001c9dc4: 3c0f01d5  lui	t7,0x1d5
001c9dc8: 25ee9980  addiu	t6,t7,-26240   ; = D_01d49980
001c9dcc: 8dcf0000  lw	t7,0(t6)
001c9dd0: 24020001  li	v0,1
001c9dd4: 11e40006  beq	t7,a0,0x1c9df0
001c9dd8: 25ce0004  addiu	t6,t6,4
001c9ddc: 25ad0001  addiu	t5,t5,1
001c9de0: 01ac782a  slt	t7,t5,t4
001c9de4: 55e0fffb  bnezl	t7,0x1c9dd4
001c9de8: 8dcf0000  lw	t7,0(t6)
001c9dec: 0000102d  move	v0,zero
001c9df0: 03e00008  jr	ra
001c9df4: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c9db0(void)`

```c
undefined4 FUN_001c9db0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  if (DAT_00351f30 < 1) {
LAB_001c9dec:
    uVar1 = 0;
  }
  else {
    piVar3 = &DAT_01d49980;
    uVar1 = 1;
    iVar4 = DAT_01d49980;
    while (piVar3 = piVar3 + 1, iVar4 != param_1) {
      iVar2 = iVar2 + 1;
      if (DAT_00351f30 <= iVar2) goto LAB_001c9dec;
      iVar4 = *piVar3;
    }
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- none found
