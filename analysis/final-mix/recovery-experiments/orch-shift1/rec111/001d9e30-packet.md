# Target packet 001d9e30

- Range: `001d9e30`..`001d9e74`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d9e30`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d9e30: 14800005  bnez	a0,0x1d9e48
001d9e34: 3c0e01d6  lui	t6,0x1d6
001d9e38: 3c0f01d6  lui	t7,0x1d6
001d9e3c: 8deebaa8  lw	t6,-17752(t7)   ; = D_01d5baa8
001d9e40: 03e00008  jr	ra
001d9e44: 25c20008  addiu	v0,t6,8
001d9e48: 240d000a  li	t5,10
001d9e4c: 8dcfbaa8  lw	t7,-17752(t6)
001d9e50: 2484000a  addiu	a0,a0,10
001d9e54: 0000102d  move	v0,zero
001d9e58: 8dee0004  lw	t6,4(t7)
001d9e5c: 01cd7018  mult	t6,t6,t5
001d9e60: 01ee7821  addu	t7,t7,t6
001d9e64: 25ef0008  addiu	t7,t7,8
001d9e68: 008f782b  sltu	t7,a0,t7
001d9e6c: 03e00008  jr	ra
001d9e70: 008f100b  movn	v0,a0,t7
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d9e30(void)`

```c
uint FUN_001d9e30(long param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return DAT_01d5baa8 + 8;
  }
  uVar2 = (int)param_1 + 10;
  uVar1 = 0;
  if (uVar2 < DAT_01d5baa8 + *(int *)(DAT_01d5baa8 + 4) * 10 + 8U) {
    uVar1 = uVar2;
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- 12 differing words, 64/68 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_1.cpp`)
