# Target packet 001d21c0

- Range: `001d21c0`..`001d2210`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d21c0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d2180` registry: `func_001d2180`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d21c0: 27bdfff0  addiu	sp,sp,-16
001d21c4: 44801000  mtc1	zero,$f2
001d21c8: ffbf0000  sd	ra,0(sp)
001d21cc: c481003c  lwc1	$f1,60(a0)
001d21d0: 46011034  c.lt.s	$f2,$f1
001d21d4: 4500000c  bc1f	0x1d2208
001d21d8: 3c0f0035  lui	t7,0x35
001d21dc: c5e09e10  lwc1	$f0,-25072(t7)   ; = D_00349e10
001d21e0: 46000801  sub.s	$f0,$f1,$f0
001d21e4: 46020036  c.le.s	$f0,$f2
001d21e8: 45000007  bc1f	0x1d2208
001d21ec: e480003c  swc1	$f0,60(a0)
001d21f0: 0c074860  jal	0x1d2180
001d21f4: 00000000  nop
001d21f8: 0000102d  move	v0,zero
001d21fc: dfbf0000  ld	ra,0(sp)
001d2200: 03e00008  jr	ra
001d2204: 27bd0010  addiu	sp,sp,16
001d2208: 1000fffc  b	0x1d21fc
001d220c: 24020001  li	v0,1
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d21c0(void)`

```c
undefined4 FUN_001d21c0(int param_1)

{
  undefined4 uVar1;
  float fVar2;
  
  if ((*(float *)(param_1 + 0x3c) <= 0.0) ||
     (fVar2 = *(float *)(param_1 + 0x3c) - DAT_00349e10, *(float *)(param_1 + 0x3c) = fVar2,
     0.0 < fVar2)) {
    uVar1 = 1;
  }
  else {
    FUN_001d2180();
    uVar1 = 0;
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- none found
