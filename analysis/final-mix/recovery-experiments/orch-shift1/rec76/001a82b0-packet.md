# Target packet 001a82b0

- Range: `001a82b0`..`001a82f0`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a82b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a82b0: 14800005  bnez	a0,0x1a82c8
001a82b4: 3c0e01c7  lui	t6,0x1c7
001a82b8: 3c0f01c7  lui	t7,0x1c7
001a82bc: 8deecb98  lw	t6,-13416(t7)   ; = D_01c6cb98
001a82c0: 03e00008  jr	ra
001a82c4: 25c20004  addiu	v0,t6,4
001a82c8: 240d000c  li	t5,12
001a82cc: 8dcfcb98  lw	t7,-13416(t6)
001a82d0: 2482000c  addiu	v0,a0,12
001a82d4: 95ee0002  lhu	t6,2(t7)
001a82d8: 01cd7018  mult	t6,t6,t5
001a82dc: 01ee7821  addu	t7,t7,t6
001a82e0: 25ef0004  addiu	t7,t7,4
001a82e4: 004f782b  sltu	t7,v0,t7
001a82e8: 03e00008  jr	ra
001a82ec: 000f100a  movz	v0,zero,t7
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a82b0(void)`

```c
uint FUN_001a82b0(long param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return DAT_01c6cb98 + 4;
  }
  uVar1 = (int)param_1 + 0xc;
  if (DAT_01c6cb98 + (uint)*(ushort *)(DAT_01c6cb98 + 2) * 0xc + 4 <= uVar1) {
    uVar1 = 0;
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- 5 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_1.cpp`)
