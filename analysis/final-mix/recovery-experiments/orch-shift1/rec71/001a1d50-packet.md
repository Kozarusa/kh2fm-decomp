# Target packet 001a1d50

- Range: `001a1d50`..`001a1db8`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a1d50`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001a1db8` registry: `func_001a1db8`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_queuexi_recovered_001a1db8.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a1d50: 44800000  mtc1	zero,$f0
001a1d54: 27bdfff0  addiu	sp,sp,-16
001a1d58: c48101c0  lwc1	$f1,448(a0)
001a1d5c: ffbf0000  sd	ra,0(sp)
001a1d60: 46010034  c.lt.s	$f0,$f1
001a1d64: 45000011  bc1f	0x1a1dac
001a1d68: 46000086  mov.s	$f2,$f0
001a1d6c: c48001bc  lwc1	$f0,444(a0)
001a1d70: 460c0000  add.s	$f0,$f0,$f12
001a1d74: 46020034  c.lt.s	$f0,$f2
001a1d78: 45030006  bc1tl	0x1a1d94
001a1d7c: 44800000  mtc1	zero,$f0
001a1d80: 46000834  c.lt.s	$f1,$f0
001a1d84: 45010002  bc1t	0x1a1d90
001a1d88: 46000886  mov.s	$f2,$f1
001a1d8c: 46000086  mov.s	$f2,$f0
001a1d90: 44800000  mtc1	zero,$f0
001a1d94: 46001032  c.eq.s	$f2,$f0
001a1d98: 45000004  bc1f	0x1a1dac
001a1d9c: e48201bc  swc1	$f2,444(a0)
001a1da0: dfbf0000  ld	ra,0(sp)
001a1da4: 0806876e  j	0x1a1db8
001a1da8: 27bd0010  addiu	sp,sp,16
001a1dac: dfbf0000  ld	ra,0(sp)
001a1db0: 03e00008  jr	ra
001a1db4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a1d50(void)`

```c
void FUN_001a1d50(float param_1,int param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_2 + 0x1c0);
  fVar2 = 0.0;
  if (0.0 < fVar1) {
    param_1 = *(float *)(param_2 + 0x1bc) + param_1;
    if ((0.0 <= param_1) && (fVar2 = param_1, fVar1 < param_1)) {
      fVar2 = fVar1;
    }
    *(float *)(param_2 + 0x1bc) = fVar2;
    if (fVar2 == 0.0) {
      FUN_001a1db8();
      return;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 50 differing words, 200/104 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.cpp`)
