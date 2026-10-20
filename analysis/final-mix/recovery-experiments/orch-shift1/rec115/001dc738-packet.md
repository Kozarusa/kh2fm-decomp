# Target packet 001dc738

- Range: `001dc738`..`001dc78c`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dc738`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dc738: 8c8d0008  lw	t5,8(a0)
001dc73c: 3c0f0040  lui	t7,0x40
001dc740: 01af7824  and	t7,t5,t7
001dc744: 15e0000e  bnez	t7,0x1dc780
001dc748: 0000102d  move	v0,zero
001dc74c: 3c0e0035  lui	t6,0x35
001dc750: 8dcff240  lw	t7,-3520(t6)   ; = D_0034f240
001dc754: 31ef0020  andi	t7,t7,0x20
001dc758: 11e00004  beqz	t7,0x1dc76c
001dc75c: 240f0003  li	t7,3
001dc760: 8c8e0004  lw	t6,4(a0)
001dc764: 55cf0007  bnel	t6,t7,0x1dc784
001dc768: 24020001  li	v0,1
001dc76c: 000d7e83  sra	t7,t5,0x1a
001dc770: 31ef0001  andi	t7,t7,0x1
001dc774: 31ef00ff  andi	t7,t7,0xff
001dc778: 11e00002  beqz	t7,0x1dc784
001dc77c: 00000000  nop
001dc780: 24020001  li	v0,1
001dc784: 03e00008  jr	ra
001dc788: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dc738(void)`

```c
undefined4 FUN_001dc738(int param_1)

{
  if ((*(uint *)(param_1 + 8) & 0x400000) == 0) {
    if (((DAT_0034f240 & 0x20) != 0) && (*(int *)(param_1 + 4) != 3)) {
      return 1;
    }
    if (((int)*(uint *)(param_1 + 8) >> 0x1a & 1U) == 0) {
      return 0;
    }
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 9 differing words, 80/84 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.cpp`)
