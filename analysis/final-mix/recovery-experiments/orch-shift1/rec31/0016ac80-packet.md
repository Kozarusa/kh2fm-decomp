# Target packet 0016ac80

- Range: `0016ac80`..`0016acdc`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016ac80`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016abf8` registry: `_ZN2YS3OBJ12start_effectEiii`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_twowordfresh_recovered_00149ec0.cpp`, `fm_scalar_extra_recovered_01.cpp`, `fm_scalar_recovered_01.cpp`, `fm_width_recovered_01.cpp`
- `001dc5f8` registry: `_ZN3ryj6EFFECT3posEv`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016ac80: 27bdffe0  addiu	sp,sp,-32
0016ac84: ffb10008  sd	s1,8(sp)
0016ac88: ffb00000  sd	s0,0(sp)
0016ac8c: 00c0882d  move	s1,a2
0016ac90: ffbf0010  sd	ra,16(sp)
0016ac94: 00e0302d  move	a2,a3
0016ac98: 0c05aafe  jal	0x16abf8
0016ac9c: 0100382d  move	a3,t0
0016aca0: 0040802d  move	s0,v0
0016aca4: 10400007  beqz	v0,0x16acc4
0016aca8: 0040202d  move	a0,v0
0016acac: 0c07717e  jal	0x1dc5f8
0016acb0: 00000000  nop
0016acb4: 50510004  beql	v0,s1,0x16acc8
0016acb8: 0200102d  move	v0,s0
0016acbc: 7a280000  lq	t0,0(s1)
0016acc0: 7c480000  sq	t0,0(v0)
0016acc4: 0200102d  move	v0,s0
0016acc8: dfb10008  ld	s1,8(sp)
0016accc: dfb00000  ld	s0,0(sp)
0016acd0: dfbf0010  ld	ra,16(sp)
0016acd4: 03e00008  jr	ra
0016acd8: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016ac80(void)`

```c
long FUN_0016ac80(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined4 *puVar1;
  long lVar2;
  long lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  lVar2 = FUN_0016abf8(param_1,param_2,param_4,param_5);
  if ((lVar2 != 0) && (lVar3 = FUN_001dc5f8(lVar2), lVar3 != param_3)) {
    puVar7 = (undefined4 *)param_3;
    uVar4 = puVar7[1];
    uVar5 = puVar7[2];
    uVar6 = puVar7[3];
    puVar1 = (undefined4 *)lVar3;
    *puVar1 = *puVar7;
    puVar1[1] = uVar4;
    puVar1[2] = uVar5;
    puVar1[3] = uVar6;
  }
  return lVar2;
}
```

## Earlier attempts (newest first)

- none found
