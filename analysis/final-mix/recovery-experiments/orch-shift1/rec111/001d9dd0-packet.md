# Target packet 001d9dd0

- Range: `001d9dd0`..`001d9e2c`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d9dd0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d9dd0: 3c0f01d6  lui	t7,0x1d6
001d9dd4: 0000682d  move	t5,zero
001d9dd8: 8deebaa8  lw	t6,-17752(t7)   ; = D_01d5baa8
001d9ddc: 8dcf0004  lw	t7,4(t6)
001d9de0: 19e0000f  blez	t7,0x1d9e20
001d9de4: 25ce0008  addiu	t6,t6,8
001d9de8: 01e0602d  move	t4,t7
001d9dec: 91cf0004  lbu	t7,4(t6)
001d9df0: 55e40008  bnel	t7,a0,0x1d9e14
001d9df4: 25ad0001  addiu	t5,t5,1
001d9df8: 91cf0005  lbu	t7,5(t6)
001d9dfc: 55e50005  bnel	t7,a1,0x1d9e14
001d9e00: 25ad0001  addiu	t5,t5,1
001d9e04: 91cf0006  lbu	t7,6(t6)
001d9e08: 11e60006  beq	t7,a2,0x1d9e24
001d9e0c: 01c0102d  move	v0,t6
001d9e10: 25ad0001  addiu	t5,t5,1
001d9e14: 01ac782a  slt	t7,t5,t4
001d9e18: 15e0fff4  bnez	t7,0x1d9dec
001d9e1c: 25ce000a  addiu	t6,t6,10
001d9e20: 0000102d  move	v0,zero
001d9e24: 03e00008  jr	ra
001d9e28: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d9dd0(void)`

```c
int FUN_001d9dd0(ulong param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = DAT_01d5baa8 + 8;
  if (0 < *(int *)(DAT_01d5baa8 + 4)) {
    do {
      if (((*(byte *)(iVar2 + 4) == param_1) && (*(byte *)(iVar2 + 5) == param_2)) &&
         (*(byte *)(iVar2 + 6) == param_3)) {
        return iVar2;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 10;
    } while (iVar1 < *(int *)(DAT_01d5baa8 + 4));
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 15 differing words, 92/92 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.cpp`)
