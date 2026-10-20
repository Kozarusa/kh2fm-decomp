# Target packet 001d6cc8

- Range: `001d6cc8`..`001d6d00`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d6cc8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d6cc8: 14800004  bnez	a0,0x1d6cdc
001d6ccc: 3c0f01d6  lui	t7,0x1d6
001d6cd0: 8deeba98  lw	t6,-17768(t7)   ; = D_01d5ba98
001d6cd4: 03e00008  jr	ra
001d6cd8: 25c20008  addiu	v0,t6,8
001d6cdc: 24820040  addiu	v0,a0,64
001d6ce0: 8deeba98  lw	t6,-17768(t7)   ; = D_01d5ba98
001d6ce4: 8dcd0004  lw	t5,4(t6)
001d6ce8: 000d6980  sll	t5,t5,0x6
001d6cec: 01cd7021  addu	t6,t6,t5
001d6cf0: 25ce0008  addiu	t6,t6,8
001d6cf4: 004e702b  sltu	t6,v0,t6
001d6cf8: 03e00008  jr	ra
001d6cfc: 000e100a  movz	v0,zero,t6
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d6cc8(void)`

```c
uint FUN_001d6cc8(long param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return DAT_01d5ba98 + 8;
  }
  uVar1 = (int)param_1 + 0x40;
  if (DAT_01d5ba98 + *(int *)(DAT_01d5ba98 + 4) * 0x40 + 8U <= uVar1) {
    uVar1 = 0;
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- 15 differing words, 60/56 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_1.cpp`)
