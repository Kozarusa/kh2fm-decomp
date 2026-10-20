# Target packet 0017fef0

- Range: `0017fef0`..`0017ff68`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_0017fef0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0017ce10` registry: `_ZN2YS4MATH9FixRadianEf`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`
- `0017fe10` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0017fef0: 27bdffc0  addiu	sp,sp,-64
0017fef4: ffb00020  sd	s0,32(sp)
0017fef8: ffb10028  sd	s1,40(sp)
0017fefc: 0080802d  move	s0,a0
0017ff00: ffbf0030  sd	ra,48(sp)
0017ff04: 03a0202d  move	a0,sp
0017ff08: 0c05ff84  jal	0x17fe10
0017ff0c: 0200282d  move	a1,s0
0017ff10: 261100a0  addiu	s1,s0,160
0017ff14: 27af0010  addiu	t7,sp,16
0017ff18: 260e00b0  addiu	t6,s0,176
0017ff1c: dba10000  lqc2	vf1,0(sp)
0017ff20: da220000  lqc2	vf2,0(s1)
0017ff24: 4be2086c  vsub.wxyz	vf1,vf1,vf2
0017ff28: f9e10000  sqc2	vf1,0(t7)
0017ff2c: d9c10000  lqc2	vf1,0(t6)
0017ff30: d9e20000  lqc2	vf2,0(t7)
0017ff34: 4be20868  vadd.wxyz	vf1,vf1,vf2
0017ff38: f9c10000  sqc2	vf1,0(t6)
0017ff3c: 0c05f384  jal	0x17ce10
0017ff40: c60c00bc  lwc1	$f12,188(s0)
0017ff44: 123d0003  beq	s1,sp,0x17ff54
0017ff48: e60000bc  swc1	$f0,188(s0)
0017ff4c: 7ba80000  lq	t0,0(sp)
0017ff50: 7e280000  sq	t0,0(s1)
0017ff54: dfb00020  ld	s0,32(sp)
0017ff58: dfb10028  ld	s1,40(sp)
0017ff5c: dfbf0030  ld	ra,48(sp)
0017ff60: 03e00008  jr	ra
0017ff64: 27bd0040  addiu	sp,sp,64
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0017fef0(void)`

```c
void FUN_0017fef0(undefined8 param_1)

{
  int iVar1;
  undefined1 (*pauVar2) [16];
  undefined4 uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined4 auStack_40 [4];
  undefined1 auStack_30 [16];
  
  FUN_0017fe10(auStack_40,param_1);
  iVar1 = (int)param_1;
  pauVar2 = (undefined1 (*) [16])(iVar1 + 0xa0);
  auVar4._4_4_ = auStack_40[1];
  auVar4._0_4_ = auStack_40[0];
  auVar4._8_4_ = auStack_40[2];
  auVar4._12_4_ = auStack_40[3];
  auVar4 = _lqc2(auVar4);
  auVar5 = _lqc2(*pauVar2);
  auVar4 = _vsub(auVar4,auVar5);
  auStack_30 = _sqc2(auVar4);
  auVar4 = _lqc2(*(undefined1 (*) [16])(iVar1 + 0xb0));
  auVar5 = _lqc2(auStack_30);
  auVar4 = _vadd(auVar4,auVar5);
  auVar4 = _sqc2(auVar4);
  *(undefined1 (*) [16])(iVar1 + 0xb0) = auVar4;
  uVar3 = FUN_0017ce10(*(undefined4 *)(iVar1 + 0xbc));
  *(undefined4 *)(iVar1 + 0xbc) = uVar3;
  if (pauVar2 != (undefined1 (*) [16])auStack_40) {
    *(undefined4 *)*pauVar2 = auStack_40[0];
    *(undefined4 *)(iVar1 + 0xa4) = auStack_40[1];
    *(undefined4 *)(iVar1 + 0xa8) = auStack_40[2];
    *(undefined4 *)(iVar1 + 0xac) = auStack_40[3];
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
