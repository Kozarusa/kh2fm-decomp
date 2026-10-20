# Target packet 00173ce8

- Range: `00173ce8`..`00173d68`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_00173ce8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016b0e0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_scalar_extra_recovered_12.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00173ce8: 27bdffa0  addiu	sp,sp,-96
00173cec: ffb00050  sd	s0,80(sp)
00173cf0: 03a0302d  move	a2,sp
00173cf4: ffbf0058  sd	ra,88(sp)
00173cf8: 0080802d  move	s0,a0
00173cfc: 8c8f0000  lw	t7,0(a0)
00173d00: 8c850004  lw	a1,4(a0)
00173d04: 0c05ac38  jal	0x16b0e0
00173d08: 8de40004  lw	a0,4(t7)
00173d0c: 8e0e0008  lw	t6,8(s0)
00173d10: 27ad0040  addiu	t5,sp,64
00173d14: d9c50000  lqc2	vf5,0(t6)
00173d18: dba10000  lqc2	vf1,0(sp)
00173d1c: dba20010  lqc2	vf2,16(sp)
00173d20: dba30020  lqc2	vf3,32(sp)
00173d24: dba40030  lqc2	vf4,48(sp)
00173d28: 4be509bc  vmulax.wxyz	ACC,vf1,vf5x
00173d2c: 4be510bd  vmadday.wxyz	ACC,vf2,vf5y
00173d30: 4be518be  vmaddaz.wxyz	ACC,vf3,vf5z
00173d34: 4be5214b  vmaddw.wxyz	vf5,vf4,vf5w
00173d38: f9a50000  sqc2	vf5,0(t5)
00173d3c: 3c0f01c6  lui	t7,0x1c6
00173d40: 25eff480  addiu	t7,t7,-2944   ; = D_01c5f480
00173d44: 51af0004  beql	t5,t7,0x173d58
00173d48: ae0f0000  sw	t7,0(s0)
00173d4c: 79a80000  lq	t0,0(t5)
00173d50: 7de80000  sq	t0,0(t7)
00173d54: ae0f0000  sw	t7,0(s0)
00173d58: dfbf0058  ld	ra,88(sp)
00173d5c: dfb00050  ld	s0,80(sp)
00173d60: 03e00008  jr	ra
00173d64: 27bd0060  addiu	sp,sp,96
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00173ce8(void)`

```c
void FUN_00173ce8(int *param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  FUN_0016b0e0(*(undefined4 *)(*param_1 + 4),param_1[1],auStack_60);
  auVar5 = _lqc2(*(undefined1 (*) [16])param_1[2]);
  auVar1 = _lqc2(auStack_60);
  auVar2 = _lqc2(auStack_50);
  auVar3 = _lqc2(auStack_40);
  auVar4 = _lqc2(auStack_30);
  _vmulabc(auVar1,auVar5);
  _vmaddabc(auVar2,auVar5);
  _vmaddabc(auVar3,auVar5);
  auVar1 = _vmaddbc(auVar4,auVar5);
  auVar1 = _sqc2(auVar1);
  if ((undefined4 *)&stack0x00000000 == &DAT_01c5f4a0) {
    *param_1 = (int)&DAT_01c5f480;
  }
  else {
    uStack_20 = auVar1._0_4_;
    DAT_01c5f480 = uStack_20;
    uStack_1c = auVar1._4_4_;
    DAT_01c5f484 = uStack_1c;
    uStack_18 = auVar1._8_4_;
    DAT_01c5f488 = uStack_18;
    uStack_14 = auVar1._12_4_;
    DAT_01c5f48c = uStack_14;
    *param_1 = (int)&DAT_01c5f480;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
