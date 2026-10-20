# Target packet 0018fd40

- Range: `0018fd40`..`0018fd6c`, **44 bytes = 11 instructions**. This size is the acceptance size.
- Layout name: `FUN_0018fd40`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00187018` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`, `fm_primary_orchbc_recovered_00176620.cpp`, `fm_primary_sixword_recovered_0018f2a8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0018fd40: 27bdfff0  addiu	sp,sp,-16
0018fd44: ffbf0000  sd	ra,0(sp)
0018fd48: 8c860008  lw	a2,8(a0)
0018fd4c: 8c850004  lw	a1,4(a0)
0018fd50: 8c8f0000  lw	t7,0(a0)
0018fd54: c48c0010  lwc1	$f12,16(a0)
0018fd58: 8c87000c  lw	a3,12(a0)
0018fd5c: dfbf0000  ld	ra,0(sp)
0018fd60: 01e0202d  move	a0,t7
0018fd64: 08061c06  j	0x187018
0018fd68: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0018fd40(void)`

```c
void FUN_0018fd40(undefined4 *param_1)

{
  FUN_00187018(param_1[4],*param_1,param_1[1],param_1[2],param_1[3]);
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 44/44 bytes: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_04_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_04_0.cpp`)
