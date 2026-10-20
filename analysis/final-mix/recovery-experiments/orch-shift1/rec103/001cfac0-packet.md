# Target packet 001cfac0

- Range: `001cfac0`..`001cfaf0`, **48 bytes = 12 instructions**. This size is the acceptance size.
- Layout name: `FUN_001cfac0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001cfac0: 3c0f0037  lui	t7,0x37
001cfac4: 25efe360  addiu	t7,t7,-7328   ; = D_0036e360
001cfac8: c5e00000  lwc1	$f0,0(t7)
001cfacc: 46006302  mul.s	$f12,$f12,$f0
001cfad0: 46006b42  mul.s	$f13,$f13,$f0
001cfad4: 46007382  mul.s	$f14,$f14,$f0
001cfad8: 46007bc2  mul.s	$f15,$f15,$f0
001cfadc: e48c0b90  swc1	$f12,2960(a0)
001cfae0: e48d0b94  swc1	$f13,2964(a0)
001cfae4: e48e0b98  swc1	$f14,2968(a0)
001cfae8: 03e00008  jr	ra
001cfaec: e48f0b9c  swc1	$f15,2972(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001cfac0(void)`

```c
void FUN_001cfac0(float param_1,float param_2,float param_3,float param_4,int param_5)

{
  param_2 = param_2 * DAT_0036e360;
  param_3 = param_3 * DAT_0036e360;
  param_4 = param_4 * DAT_0036e360;
  *(float *)(param_5 + 0xb90) = param_1 * DAT_0036e360;
  *(float *)(param_5 + 0xb94) = param_2;
  *(float *)(param_5 + 0xb98) = param_3;
  *(float *)(param_5 + 0xb9c) = param_4;
  return;
}
```

## Earlier attempts (newest first)

- 11 differing words, 44/48 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
