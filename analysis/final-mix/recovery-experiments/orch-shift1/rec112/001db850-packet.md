# Target packet 001db850

- Range: `001db850`..`001db888`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001db850`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001db850: 8c8e0018  lw	t6,24(a0)
001db854: 19c0000a  blez	t6,0x1db880
001db858: 0000682d  move	t5,zero
001db85c: 8c8f0010  lw	t7,16(a0)
001db860: 000d7080  sll	t6,t5,0x2
001db864: 01cf7021  addu	t6,t6,t7
001db868: adcd0000  sw	t5,0(t6)
001db86c: 8c8e0018  lw	t6,24(a0)
001db870: 25ad0001  addiu	t5,t5,1
001db874: 01ae782a  slt	t7,t5,t6
001db878: 55e0fff9  bnezl	t7,0x1db860
001db87c: 8c8f0010  lw	t7,16(a0)
001db880: 03e00008  jr	ra
001db884: ac8e0008  sw	t6,8(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001db850(void)`

```c
void FUN_001db850(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  iVar1 = 0;
  if (0 < iVar2) {
    iVar2 = *(int *)(param_1 + 0x10);
    while( true ) {
      *(int *)(iVar1 * 4 + iVar2) = iVar1;
      iVar2 = *(int *)(param_1 + 0x18);
      iVar1 = iVar1 + 1;
      if (iVar2 <= iVar1) break;
      iVar2 = *(int *)(param_1 + 0x10);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  return;
}
```

## Earlier attempts (newest first)

- 5 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_05.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_05.cpp`)
