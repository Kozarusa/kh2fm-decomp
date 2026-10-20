# Target packet 001ad9c8

- Range: `001ad9c8`..`001ada34`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ad9c8`
- Registry names for this address: `func_001ad9c8`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ad9c8: 44801800  mtc1	zero,$f3
001ad9cc: c4820004  lwc1	$f2,4(a0)
001ad9d0: 46031032  c.eq.s	$f2,$f3
001ad9d4: 4501000c  bc1t	0x1ada08
001ad9d8: 0000102d  move	v0,zero
001ad9dc: 3c0f0035  lui	t7,0x35
001ad9e0: c4810000  lwc1	$f1,0(a0)
001ad9e4: c5e09e10  lwc1	$f0,-25072(t7)   ; = D_00349e10
001ad9e8: 46001002  mul.s	$f0,$f2,$f0
001ad9ec: 46000800  add.s	$f0,$f1,$f0
001ad9f0: 46030036  c.le.s	$f0,$f3
001ad9f4: 45000006  bc1f	0x1ada10
001ad9f8: e4800000  swc1	$f0,0(a0)
001ad9fc: e4830004  swc1	$f3,4(a0)
001ada00: e4830000  swc1	$f3,0(a0)
001ada04: 24020001  li	v0,1
001ada08: 03e00008  jr	ra
001ada0c: 00000000  nop
001ada10: 3c0f0037  lui	t7,0x37
001ada14: 25efd7a4  addiu	t7,t7,-10332   ; = D_0036d7a4
001ada18: c5e10000  lwc1	$f1,0(t7)
001ada1c: 46000836  c.le.s	$f1,$f0
001ada20: 4502fff9  bc1fl	0x1ada08
001ada24: 24020001  li	v0,1
001ada28: e4830004  swc1	$f3,4(a0)
001ada2c: 1000fff5  b	0x1ada04
001ada30: e4810000  swc1	$f1,0(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ad9c8(void)`

```c
undefined4 FUN_001ad9c8(float *param_1)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  
  uVar2 = 0;
  if (param_1[1] != 0.0) {
    fVar3 = *param_1 + param_1[1] * DAT_00349e10;
    *param_1 = fVar3;
    fVar1 = DAT_0036d7a4;
    if (fVar3 <= 0.0) {
      param_1[1] = 0.0;
      *param_1 = 0.0;
    }
    else {
      if (fVar3 < DAT_0036d7a4) {
        return 1;
      }
      param_1[1] = 0.0;
      *param_1 = fVar1;
    }
    uVar2 = 1;
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- 50 differing words, 200/108 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
