# Target packet 001bff88

- Range: `001bff88`..`001bffd8`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bff88`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bff88: 3c0f01d5  lui	t7,0x1d5
001bff8c: 240e0007  li	t6,7
001bff90: 25ef9328  addiu	t7,t7,-27864   ; = D_01d49328
001bff94: ade00000  sw	zero,0(t7)
001bff98: 25ceffff  addiu	t6,t6,-1
001bff9c: 00000000  nop
001bffa0: 00000000  nop
001bffa4: 00000000  nop
001bffa8: 05c1fffa  bgez	t6,0x1bff94
001bffac: 25ef0004  addiu	t7,t7,4
001bffb0: 240d0100  li	t5,256
001bffb4: 3c0f01d5  lui	t7,0x1d5
001bffb8: 3c0e01d5  lui	t6,0x1d5
001bffbc: aded934c  sw	t5,-27828(t7)   ; = D_01d4934c
001bffc0: 3c0c01d5  lui	t4,0x1d5
001bffc4: adc09348  sw	zero,-27832(t6)   ; = D_01d49348
001bffc8: 258b9350  addiu	t3,t4,-27824   ; = D_01d49350
001bffcc: ad809350  sw	zero,-27824(t4)   ; = D_01d49350
001bffd0: 03e00008  jr	ra
001bffd4: ad600004  sw	zero,4(t3)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bff88(void)`

```c
void FUN_001bff88(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 7;
  puVar2 = &DAT_01d49328;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  DAT_01d4934c = 0x100;
  DAT_01d49348 = 0;
  DAT_01d49350 = 0;
  DAT_01d49354 = 0;
  return;
}
```

## Earlier attempts (newest first)

- 9 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
