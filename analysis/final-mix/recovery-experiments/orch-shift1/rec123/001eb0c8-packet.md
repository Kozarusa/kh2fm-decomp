# Target packet 001eb0c8

- Range: `001eb0c8`..`001eb13c`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_001eb0c8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002f3d08` registry: `_Z16wtarget_002f3d08jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_queuezeta_recovered_002f3d08.cpp`
- `002f4000` registry: `func_002f4000`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_queuedelta_recovered_002f4000.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001eb0c8: 27bdffb0  addiu	sp,sp,-80
001eb0cc: ffb00040  sd	s0,64(sp)
001eb0d0: 03a0202d  move	a0,sp
001eb0d4: ffbf0048  sd	ra,72(sp)
001eb0d8: 0c0bd000  jal	0x2f4000
001eb0dc: 00a0802d  move	s0,a1
001eb0e0: 3c0f01da  lui	t7,0x1da
001eb0e4: c6010004  lwc1	$f1,4(s0)
001eb0e8: 8deee6e0  lw	t6,-6432(t7)   ; = D_01d9e6e0
001eb0ec: 03a0282d  move	a1,sp
001eb0f0: c6020008  lwc1	$f2,8(s0)
001eb0f4: c5c00040  lwc1	$f0,64(t6)
001eb0f8: 3c0f01da  lui	t7,0x1da
001eb0fc: 8de4e6e8  lw	a0,-6424(t7)   ; = D_01d9e6e8
001eb100: 46010042  mul.s	$f1,$f0,$f1
001eb104: 24840010  addiu	a0,a0,16
001eb108: 0080302d  move	a2,a0
001eb10c: 46010000  add.s	$f0,$f0,$f1
001eb110: 46001034  c.lt.s	$f2,$f0
001eb114: 45000002  bc1f	0x1eb120
001eb118: e7a00000  swc1	$f0,0(sp)
001eb11c: e7a20000  swc1	$f2,0(sp)
001eb120: c7a00000  lwc1	$f0,0(sp)
001eb124: 0c0bcf42  jal	0x2f3d08
001eb128: e7a00028  swc1	$f0,40(sp)
001eb12c: dfb00040  ld	s0,64(sp)
001eb130: dfbf0048  ld	ra,72(sp)
001eb134: 03e00008  jr	ra
001eb138: 27bd0050  addiu	sp,sp,80
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001eb0c8(void)`

```c
void FUN_001eb0c8(undefined8 param_1,int param_2)

{
  float fVar1;
  float afStack_50 [10];
  float fStack_28;
  
  FUN_002f4000(afStack_50);
  afStack_50[0] = *(float *)(param_2 + 8);
  fVar1 = *(float *)(DAT_01d9e6e0 + 0x40) +
          *(float *)(DAT_01d9e6e0 + 0x40) * *(float *)(param_2 + 4);
  if (fVar1 <= afStack_50[0]) {
    afStack_50[0] = fVar1;
  }
  fStack_28 = afStack_50[0];
  FUN_002f3d08(DAT_01d9e6e8 + 0x10,afStack_50,DAT_01d9e6e8 + 0x10);
  return;
}
```

## Earlier attempts (newest first)

- none found
