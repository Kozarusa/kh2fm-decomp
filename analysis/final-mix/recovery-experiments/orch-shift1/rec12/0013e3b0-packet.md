# Target packet 0013e3b0

- Range: `0013e3b0`..`0013e410`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_0013e3b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001391a8` registry: `func_001391a8`
  - accepted sources that already call it (copy their declaration): `fm_copy_helpers.cpp`, `fm_global_recovered_02.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`
- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0013e3b0: 27bdffd0  addiu	sp,sp,-48
0013e3b4: ffb00010  sd	s0,16(sp)
0013e3b8: ffb10018  sd	s1,24(sp)
0013e3bc: 00a0802d  move	s0,a1
0013e3c0: ffbf0020  sd	ra,32(sp)
0013e3c4: 78a80000  lq	t0,0(a1)
0013e3c8: 7fa80000  sq	t0,0(sp)
0013e3cc: 249101c0  addiu	s1,a0,448
0013e3d0: 0c04e46a  jal	0x1391a8
0013e3d4: 03a0282d  move	a1,sp
0013e3d8: 0c04e75e  jal	0x139d78
0013e3dc: 0220202d  move	a0,s1
0013e3e0: 50400007  beqzl	v0,0x13e400
0013e3e4: dfb00010  ld	s0,16(sp)
0013e3e8: 7a080000  lq	t0,0(s0)
0013e3ec: 7fa80000  sq	t0,0(sp)
0013e3f0: 0220202d  move	a0,s1
0013e3f4: 0c04e46a  jal	0x1391a8
0013e3f8: 03a0282d  move	a1,sp
0013e3fc: dfb00010  ld	s0,16(sp)
0013e400: dfb10018  ld	s1,24(sp)
0013e404: dfbf0020  ld	ra,32(sp)
0013e408: 03e00008  jr	ra
0013e40c: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0013e3b0(void)`

```c
void FUN_0013e3b0(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  int iVar2;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_30 = *param_2;
  uStack_2c = param_2[1];
  uStack_28 = param_2[2];
  uStack_24 = param_2[3];
  iVar2 = (int)param_1 + 0x1c0;
  FUN_001391a8(param_1,&uStack_30);
  lVar1 = FUN_00139d78(iVar2);
  if (lVar1 != 0) {
    uStack_30 = *param_2;
    uStack_2c = param_2[1];
    uStack_28 = param_2[2];
    uStack_24 = param_2[3];
    FUN_001391a8(iVar2,&uStack_30);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
