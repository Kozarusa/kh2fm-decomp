# Target packet 0018fde0

- Range: `0018fde0`..`0018fe0c`, **44 bytes = 11 instructions**. This size is the acceptance size.
- Layout name: `FUN_0018fde0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b50e0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`, `fm_primary_sixword_recovered_0018f2a8.cpp`, `fm_primary_sixword_recovered_0018f2d0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0018fde0: 27bdfff0  addiu	sp,sp,-16
0018fde4: ffbf0000  sd	ra,0(sp)
0018fde8: 8c86000c  lw	a2,12(a0)
0018fdec: 8c8f0000  lw	t7,0(a0)
0018fdf0: c48c0008  lwc1	$f12,8(a0)
0018fdf4: 0006302b  sltu	a2,zero,a2
0018fdf8: 8c850004  lw	a1,4(a0)
0018fdfc: dfbf0000  ld	ra,0(sp)
0018fe00: 01e0202d  move	a0,t7
0018fe04: 0806d438  j	0x1b50e0
0018fe08: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0018fde0(void)`

```c
void FUN_0018fde0(undefined4 *param_1)

{
  FUN_001b50e0(param_1[2],*param_1,param_1[1],param_1[3] != 0);
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 44/44 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_04_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_04_1.cpp`)
