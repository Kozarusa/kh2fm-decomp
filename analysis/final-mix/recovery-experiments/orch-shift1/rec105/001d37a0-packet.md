# Target packet 001d37a0

- Range: `001d37a0`..`001d3810`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d37a0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d37a0: 78a80000  lq	t0,0(a1)
001d37a4: 7c880000  sq	t0,0(a0)
001d37a8: 3c0f0037  lui	t7,0x37
001d37ac: e48c0020  swc1	$f12,32(a0)
001d37b0: 25efe430  addiu	t7,t7,-7120   ; = D_0036e430
001d37b4: ac800010  sw	zero,16(a0)
001d37b8: c5e00000  lwc1	$f0,0(t7)
001d37bc: 3c0d01d6  lui	t5,0x1d6
001d37c0: ac800014  sw	zero,20(a0)
001d37c4: 25aeba20  addiu	t6,t5,-17888   ; = D_01d5ba20
001d37c8: 3c0f0037  lui	t7,0x37
001d37cc: e4800028  swc1	$f0,40(a0)
001d37d0: 25efe434  addiu	t7,t7,-7116   ; = D_0036e434
001d37d4: e48c0018  swc1	$f12,24(a0)
001d37d8: c5e10000  lwc1	$f1,0(t7)
001d37dc: e48c001c  swc1	$f12,28(a0)
001d37e0: e481002c  swc1	$f1,44(a0)
001d37e4: ac800024  sw	zero,36(a0)
001d37e8: 8dcf0004  lw	t7,4(t6)
001d37ec: 55e00005  bnezl	t7,0x1d3804
001d37f0: ade40030  sw	a0,48(t7)
001d37f4: adc40004  sw	a0,4(t6)
001d37f8: ada4ba20  sw	a0,-17888(t5)   ; = D_01d5ba20
001d37fc: 03e00008  jr	ra
001d3800: ac800030  sw	zero,48(a0)
001d3804: ac800030  sw	zero,48(a0)
001d3808: 03e00008  jr	ra
001d380c: adc40004  sw	a0,4(t6)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d37a0(void)`

```c
void FUN_001d37a0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  *param_2 = *param_3;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  param_2[8] = param_1;
  param_2[4] = 0;
  uVar1 = DAT_0036e430;
  param_2[5] = 0;
  param_2[10] = uVar1;
  param_2[6] = param_1;
  uVar1 = DAT_0036e434;
  param_2[7] = param_1;
  param_2[0xb] = uVar1;
  param_2[9] = 0;
  if (DAT_01d5ba24 != (undefined4 *)0x0) {
    *(undefined4 **)((int)DAT_01d5ba24 + 0x30) = param_2;
    param_2[0xc] = 0;
    DAT_01d5ba24 = param_2;
    return;
  }
  DAT_01d5ba20 = param_2;
  DAT_01d5ba24 = param_2;
  param_2[0xc] = 0;
  return;
}
```

## Earlier attempts (newest first)

- 42 differing words, 168/112 bytes: `analysis/final-mix/recovery-experiments/fm_float_roles_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_float_roles_01_0.cpp`)
