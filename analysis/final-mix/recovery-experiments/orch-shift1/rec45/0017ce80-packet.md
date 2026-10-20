# Target packet 0017ce80

- Range: `0017ce80`..`0017cf00`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0017ce80`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0017ce10` registry: `_ZN2YS4MATH9FixRadianEf`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0017ce80: 27bdffe0  addiu	sp,sp,-32
0017ce84: e7b60010  swc1	$f22,16(sp)
0017ce88: e7b40008  swc1	$f20,8(sp)
0017ce8c: 46006586  mov.s	$f22,$f12
0017ce90: ffbf0000  sd	ra,0(sp)
0017ce94: 460c6d01  sub.s	$f20,$f13,$f12
0017ce98: e7b5000c  swc1	$f21,12(sp)
0017ce9c: 46007546  mov.s	$f21,$f14
0017cea0: 0c05f384  jal	0x17ce10
0017cea4: 4600a306  mov.s	$f12,$f20
0017cea8: 4600a847  neg.s	$f1,$f21
0017ceac: 46010034  c.lt.s	$f0,$f1
0017ceb0: 45000008  bc1f	0x17ced4
0017ceb4: 4600a306  mov.s	$f12,$f20
0017ceb8: 4615b301  sub.s	$f12,$f22,$f21
0017cebc: dfbf0000  ld	ra,0(sp)
0017cec0: c7b60010  lwc1	$f22,16(sp)
0017cec4: c7b5000c  lwc1	$f21,12(sp)
0017cec8: c7b40008  lwc1	$f20,8(sp)
0017cecc: 0805f384  j	0x17ce10
0017ced0: 27bd0020  addiu	sp,sp,32
0017ced4: 0c05f384  jal	0x17ce10
0017ced8: 00000000  nop
0017cedc: 4600a834  c.lt.s	$f21,$f0
0017cee0: 45000003  bc1f	0x17cef0
0017cee4: 4600a306  mov.s	$f12,$f20
0017cee8: 1000fff4  b	0x17cebc
0017ceec: 4615b300  add.s	$f12,$f22,$f21
0017cef0: 0c05f384  jal	0x17ce10
0017cef4: 00000000  nop
0017cef8: 1000fff0  b	0x17cebc
0017cefc: 4600b300  add.s	$f12,$f22,$f0
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0017ce80(void)`

```c
void FUN_0017ce80(float param_1,float param_2,float param_3)

{
  float fVar1;
  
  param_2 = param_2 - param_1;
  fVar1 = (float)FUN_0017ce10(param_2);
  if (fVar1 < -param_3) {
    param_1 = param_1 - param_3;
  }
  else {
    fVar1 = (float)FUN_0017ce10(param_2);
    if (param_3 < fVar1) {
      param_1 = param_1 + param_3;
    }
    else {
      fVar1 = (float)FUN_0017ce10(param_2);
      param_1 = param_1 + fVar1;
    }
  }
  FUN_0017ce10(param_1);
  return;
}
```

## Earlier attempts (newest first)

- 28 differing words, 136/128 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_03_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_03_0.cpp`)
