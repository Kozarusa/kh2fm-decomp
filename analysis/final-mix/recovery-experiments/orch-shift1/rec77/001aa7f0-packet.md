# Target packet 001aa7f0

- Range: `001aa7f0`..`001aa84c`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aa7f0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00192f78` registry: `func_00192f78`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`
- `001ab750` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aa7f0: 27bdfff0  addiu	sp,sp,-16
001aa7f4: ac850000  sw	a1,0(a0)
001aa7f8: ffb00000  sd	s0,0(sp)
001aa7fc: 3c0f6000  lui	t7,0x6000
001aa800: ac8f0014  sw	t7,20(a0)
001aa804: 0080802d  move	s0,a0
001aa808: ffbf0008  sd	ra,8(sp)
001aa80c: ae000004  sw	zero,4(s0)
001aa810: 0c064bde  jal	0x192f78
001aa814: 24840020  addiu	a0,a0,32
001aa818: ae000038  sw	zero,56(s0)
001aa81c: 260f0040  addiu	t7,s0,64
001aa820: ae00003c  sw	zero,60(s0)
001aa824: 01e0282d  move	a1,t7
001aa828: ae000040  sw	zero,64(s0)
001aa82c: ade00008  sw	zero,8(t7)
001aa830: ade00004  sw	zero,4(t7)
001aa834: dfbf0008  ld	ra,8(sp)
001aa838: ae00004c  sw	zero,76(s0)
001aa83c: 8e040000  lw	a0,0(s0)
001aa840: dfb00000  ld	s0,0(sp)
001aa844: 0806add4  j	0x1ab750
001aa848: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aa7f0(void)`

```c
void FUN_001aa7f0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[5] = 0x60000000;
  param_1[1] = 0;
  FUN_00192f78(param_1 + 8);
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  FUN_001ab750(*param_1,param_1 + 0x10);
  return;
}
```

## Earlier attempts (newest first)

- 10 differing words, 92/92 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.cpp`)
