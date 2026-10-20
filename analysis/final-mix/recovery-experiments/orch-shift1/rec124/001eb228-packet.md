# Target packet 001eb228

- Range: `001eb228`..`001eb2a0`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001eb228`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002f3d08` registry: `_Z16wtarget_002f3d08jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_queuezeta_recovered_002f3d08.cpp`
- `002f4000` registry: `func_002f4000`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_queuedelta_recovered_002f4000.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001eb228: 27bdffb0  addiu	sp,sp,-80
001eb22c: ffb00040  sd	s0,64(sp)
001eb230: 03a0202d  move	a0,sp
001eb234: ffbf0048  sd	ra,72(sp)
001eb238: 0c0bd000  jal	0x2f4000
001eb23c: 00a0802d  move	s0,a1
001eb240: 3c0f01da  lui	t7,0x1da
001eb244: c6010004  lwc1	$f1,4(s0)
001eb248: 8deee6e0  lw	t6,-6432(t7)   ; = D_01d9e6e0
001eb24c: 03a0282d  move	a1,sp
001eb250: c6020008  lwc1	$f2,8(s0)
001eb254: c5c00040  lwc1	$f0,64(t6)
001eb258: 3c0f01da  lui	t7,0x1da
001eb25c: 8de4e6e8  lw	a0,-6424(t7)   ; = D_01d9e6e8
001eb260: 46010042  mul.s	$f1,$f0,$f1
001eb264: 24840010  addiu	a0,a0,16
001eb268: 0080302d  move	a2,a0
001eb26c: 46010000  add.s	$f0,$f0,$f1
001eb270: 46001034  c.lt.s	$f2,$f0
001eb274: 45000002  bc1f	0x1eb280
001eb278: e7a00000  swc1	$f0,0(sp)
001eb27c: e7a20000  swc1	$f2,0(sp)
001eb280: c7a00000  lwc1	$f0,0(sp)
001eb284: e7a00014  swc1	$f0,20(sp)
001eb288: 0c0bcf42  jal	0x2f3d08
001eb28c: e7a00028  swc1	$f0,40(sp)
001eb290: dfb00040  ld	s0,64(sp)
001eb294: dfbf0048  ld	ra,72(sp)
001eb298: 03e00008  jr	ra
001eb29c: 27bd0050  addiu	sp,sp,80
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001eb228(void)`

```c
void FUN_001eb228(undefined8 param_1,int param_2)

{
  float fVar1;
  float afStack_50 [5];
  float fStack_3c;
  float fStack_28;
  
  FUN_002f4000(afStack_50);
  afStack_50[0] = *(float *)(param_2 + 8);
  fVar1 = *(float *)(DAT_01d9e6e0 + 0x40) +
          *(float *)(DAT_01d9e6e0 + 0x40) * *(float *)(param_2 + 4);
  if (fVar1 <= afStack_50[0]) {
    afStack_50[0] = fVar1;
  }
  fStack_3c = afStack_50[0];
  fStack_28 = afStack_50[0];
  FUN_002f3d08(DAT_01d9e6e8 + 0x10,afStack_50,DAT_01d9e6e8 + 0x10);
  return;
}
```

## Earlier attempts (newest first)

- none found
