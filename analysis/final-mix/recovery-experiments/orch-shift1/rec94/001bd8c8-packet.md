# Target packet 001bd8c8

- Range: `001bd8c8`..`001bd918`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bd8c8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b8e88` registry: `_Z16u_call4_001b8e88jjjj`
  - accepted sources that already call it (copy their declaration): `fm_fallback_small.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`
- `001bd918` registry: `func_001bd918`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bd8c8: 27bdfff0  addiu	sp,sp,-16
001bd8cc: ffbf0008  sd	ra,8(sp)
001bd8d0: ffb00000  sd	s0,0(sp)
001bd8d4: 8c8e08c0  lw	t6,2240(a0)
001bd8d8: 0080802d  move	s0,a0
001bd8dc: 8dcd0000  lw	t5,0(t6)
001bd8e0: 8daf006c  lw	t7,108(t5)
001bd8e4: 240e000c  li	t6,12
001bd8e8: 01ee7818  mult	t7,t7,t6
001bd8ec: 01af6821  addu	t5,t5,t7
001bd8f0: 0c06e3a2  jal	0x1b8e88
001bd8f4: 95a4000e  lhu	a0,14(t5)
001bd8f8: 0200202d  move	a0,s0
001bd8fc: 0040282d  move	a1,v0
001bd900: 0c06f646  jal	0x1bd918
001bd904: 0000302d  move	a2,zero
001bd908: dfb00000  ld	s0,0(sp)
001bd90c: dfbf0008  ld	ra,8(sp)
001bd910: 03e00008  jr	ra
001bd914: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bd8c8(void)`

```c
void FUN_001bd8c8(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = **(int **)((int)param_1 + 0x8c0);
  uVar2 = FUN_001b8e88(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0x6c) * 0xc + 0xe));
  FUN_001bd918(param_1,uVar2,0);
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/fm_width_all_06_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_width_all_06_1.cpp`)
- 16 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round25_001bd8c8_v02.verification.json`
- 16 differing words, 72/80 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round25_001bd8c8_v01.verification.json`
