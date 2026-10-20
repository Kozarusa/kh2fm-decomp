# Target packet 001acf38

- Range: `001acf38`..`001acfb0`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001acf38`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001acdc0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001acf38: 27bdfff0  addiu	sp,sp,-16
001acf3c: 240f0002  li	t7,2
001acf40: ffbf0000  sd	ra,0(sp)
001acf44: 8c8e0064  lw	t6,100(a0)
001acf48: 15cf000d  bne	t6,t7,0x1acf80
001acf4c: 8c87005c  lw	a3,92(a0)
001acf50: 8c880060  lw	t0,96(a0)
001acf54: 0000482d  move	t1,zero
001acf58: 8c860008  lw	a2,8(a0)
001acf5c: 00087842  srl	t7,t0,0x1
001acf60: 8c850004  lw	a1,4(a0)
001acf64: 00c84021  addu	t0,a2,t0
001acf68: 00073842  srl	a3,a3,0x1
001acf6c: dfbf0000  ld	ra,0(sp)
001acf70: 00a73821  addu	a3,a1,a3
001acf74: 00cf3021  addu	a2,a2,t7
001acf78: 0806b370  j	0x1acdc0
001acf7c: 27bd0010  addiu	sp,sp,16
001acf80: 0000482d  move	t1,zero
001acf84: 8c880060  lw	t0,96(a0)
001acf88: 8c860008  lw	a2,8(a0)
001acf8c: 00073842  srl	a3,a3,0x1
001acf90: 8c850004  lw	a1,4(a0)
001acf94: 00084042  srl	t0,t0,0x1
001acf98: 00c84021  addu	t0,a2,t0
001acf9c: 0c06b370  jal	0x1acdc0
001acfa0: 00a73821  addu	a3,a1,a3
001acfa4: dfbf0000  ld	ra,0(sp)
001acfa8: 03e00008  jr	ra
001acfac: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001acf38(void)`

```c
void FUN_001acf38(int param_1)

{
  if (*(int *)(param_1 + 100) == 2) {
    FUN_001acdc0(param_1,*(int *)(param_1 + 4),
                 *(int *)(param_1 + 8) + (*(uint *)(param_1 + 0x60) >> 1),
                 *(int *)(param_1 + 4) + (*(uint *)(param_1 + 0x5c) >> 1),
                 *(int *)(param_1 + 8) + *(uint *)(param_1 + 0x60),0);
    return;
  }
  FUN_001acdc0();
  return;
}
```

## Earlier attempts (newest first)

- 15 differing words, 92/120 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.cpp`)
