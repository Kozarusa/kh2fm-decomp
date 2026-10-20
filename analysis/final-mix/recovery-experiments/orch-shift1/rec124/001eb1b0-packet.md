# Target packet 001eb1b0

- Range: `001eb1b0`..`001eb228`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001eb1b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002f3d08` registry: `_Z16wtarget_002f3d08jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_queuezeta_recovered_002f3d08.cpp`
- `002f4000` registry: `func_002f4000`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_queuedelta_recovered_002f4000.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001eb1b0: 27bdffb0  addiu	sp,sp,-80
001eb1b4: ffb00040  sd	s0,64(sp)
001eb1b8: 03a0202d  move	a0,sp
001eb1bc: ffbf0048  sd	ra,72(sp)
001eb1c0: 0c0bd000  jal	0x2f4000
001eb1c4: 00a0802d  move	s0,a1
001eb1c8: 3c0f01da  lui	t7,0x1da
001eb1cc: c6010004  lwc1	$f1,4(s0)
001eb1d0: 8deee6e0  lw	t6,-6432(t7)   ; = D_01d9e6e0
001eb1d4: 03a0282d  move	a1,sp
001eb1d8: c6030008  lwc1	$f3,8(s0)
001eb1dc: c5c00044  lwc1	$f0,68(t6)
001eb1e0: 3c0f01da  lui	t7,0x1da
001eb1e4: 8de4e6e8  lw	a0,-6424(t7)   ; = D_01d9e6e8
001eb1e8: 46010042  mul.s	$f1,$f0,$f1
001eb1ec: 24840010  addiu	a0,a0,16
001eb1f0: c7a20028  lwc1	$f2,40(sp)
001eb1f4: 0080302d  move	a2,a0
001eb1f8: 46010000  add.s	$f0,$f0,$f1
001eb1fc: 46001834  c.lt.s	$f3,$f0
001eb200: 45000002  bc1f	0x1eb20c
001eb204: e7a00014  swc1	$f0,20(sp)
001eb208: e7a30014  swc1	$f3,20(sp)
001eb20c: e7a20000  swc1	$f2,0(sp)
001eb210: 0c0bcf42  jal	0x2f3d08
001eb214: e7a20014  swc1	$f2,20(sp)
001eb218: dfb00040  ld	s0,64(sp)
001eb21c: dfbf0048  ld	ra,72(sp)
001eb220: 03e00008  jr	ra
001eb224: 27bd0050  addiu	sp,sp,80
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001eb1b0(void)`

```c
void FUN_001eb1b0(void)

{
  undefined4 auStack_50 [5];
  undefined4 uStack_3c;
  undefined4 uStack_28;
  
  FUN_002f4000(auStack_50);
  auStack_50[0] = uStack_28;
  uStack_3c = uStack_28;
  FUN_002f3d08(DAT_01d9e6e8 + 0x10,auStack_50,DAT_01d9e6e8 + 0x10);
  return;
}
```

## Earlier attempts (newest first)

- none found
