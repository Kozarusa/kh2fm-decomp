# Target packet 001eb140

- Range: `001eb140`..`001eb1b0`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001eb140`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002f3d08` registry: `_Z16wtarget_002f3d08jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_queuezeta_recovered_002f3d08.cpp`
- `002f4000` registry: `func_002f4000`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_queuedelta_recovered_002f4000.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001eb140: 27bdffb0  addiu	sp,sp,-80
001eb144: ffb00040  sd	s0,64(sp)
001eb148: 03a0202d  move	a0,sp
001eb14c: ffbf0048  sd	ra,72(sp)
001eb150: 0c0bd000  jal	0x2f4000
001eb154: 00a0802d  move	s0,a1
001eb158: 3c0f01da  lui	t7,0x1da
001eb15c: c6010004  lwc1	$f1,4(s0)
001eb160: 8deee6e0  lw	t6,-6432(t7)   ; = D_01d9e6e0
001eb164: 03a0282d  move	a1,sp
001eb168: c6020008  lwc1	$f2,8(s0)
001eb16c: c5c00044  lwc1	$f0,68(t6)
001eb170: 3c0f01da  lui	t7,0x1da
001eb174: 8de4e6e8  lw	a0,-6424(t7)   ; = D_01d9e6e8
001eb178: 46010042  mul.s	$f1,$f0,$f1
001eb17c: 24840010  addiu	a0,a0,16
001eb180: 0080302d  move	a2,a0
001eb184: 46010000  add.s	$f0,$f0,$f1
001eb188: 46001034  c.lt.s	$f2,$f0
001eb18c: 45000002  bc1f	0x1eb198
001eb190: e7a00014  swc1	$f0,20(sp)
001eb194: e7a20014  swc1	$f2,20(sp)
001eb198: 0c0bcf42  jal	0x2f3d08
001eb19c: 00000000  nop
001eb1a0: dfb00040  ld	s0,64(sp)
001eb1a4: dfbf0048  ld	ra,72(sp)
001eb1a8: 03e00008  jr	ra
001eb1ac: 27bd0050  addiu	sp,sp,80
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001eb140(void)`

```c
void FUN_001eb140(undefined8 param_1,int param_2)

{
  float fVar1;
  undefined1 auStack_50 [20];
  float fStack_3c;
  
  FUN_002f4000(auStack_50);
  fStack_3c = *(float *)(param_2 + 8);
  fVar1 = *(float *)(DAT_01d9e6e0 + 0x44) +
          *(float *)(DAT_01d9e6e0 + 0x44) * *(float *)(param_2 + 4);
  if (fVar1 <= fStack_3c) {
    fStack_3c = fVar1;
  }
  FUN_002f3d08(DAT_01d9e6e8 + 0x10,auStack_50,DAT_01d9e6e8 + 0x10);
  return;
}
```

## Earlier attempts (newest first)

- none found
