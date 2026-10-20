# Target packet 00202ba0

- Range: `00202ba0`..`00202c1c`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_00202ba0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00202ba0: 46006024  cvt.w.s	$f0,$f12
00202ba4: 3c0e0036  lui	t6,0x36
00202ba8: 25ce90f0  addiu	t6,t6,-28432   ; = D_003590f0
00202bac: 440f0000  mfc1	t7,$f0
00202bb0: 448f0000  mtc1	t7,$f0
00202bb4: 46800020  cvt.s.w	$f0,$f0
00202bb8: 000f7900  sll	t7,t7,0x4
00202bbc: 00cf3021  addu	a2,a2,t7
00202bc0: 00af2821  addu	a1,a1,t7
00202bc4: 46006301  sub.s	$f12,$f12,$f0
00202bc8: e5cc0008  swc1	$f12,8(t6)
00202bcc: d8a10000  lqc2	vf1,0(a1)
00202bd0: d8a20010  lqc2	vf2,16(a1)
00202bd4: d8c30000  lqc2	vf3,0(a2)
00202bd8: d8c40010  lqc2	vf4,16(a2)
00202bdc: d9c50000  lqc2	vf5,0(t6)
00202be0: 4be322ac  vsub.wxyz	vf10,vf4,vf3
00202be4: 4be51ad9  vmuly.wxyz	vf11,vf3,vf5y
00202be8: 4be51b18  vmulx.wxyz	vf12,vf3,vf5x
00202bec: 4be1136c  vsub.wxyz	vf13,vf2,vf1
00202bf0: 4be5529a  vmulz.wxyz	vf10,vf10,vf5z
00202bf4: 4be45ae8  vadd.wxyz	vf11,vf11,vf4
00202bf8: 4bec52a8  vadd.wxyz	vf10,vf10,vf12
00202bfc: 4beb6b6c  vsub.wxyz	vf13,vf13,vf11
00202c00: 4be5529a  vmulz.wxyz	vf10,vf10,vf5z
00202c04: 4bed52a8  vadd.wxyz	vf10,vf10,vf13
00202c08: 4be5529a  vmulz.wxyz	vf10,vf10,vf5z
00202c0c: 4be152a8  vadd.wxyz	vf10,vf10,vf1
00202c10: f88a0000  sqc2	vf10,0(a0)
00202c14: 03e00008  jr	ra
00202c18: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00202ba0(void)`

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00202ba0(float param_1,undefined1 (*param_2) [16],int param_3,int param_4)

{
  undefined1 (*pauVar1) [16];
  undefined1 (*pauVar2) [16];
  int iVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  
  iVar3 = (int)param_1 * 0x10;
  pauVar2 = (undefined1 (*) [16])(param_4 + iVar3);
  pauVar1 = (undefined1 (*) [16])(param_3 + iVar3);
  DAT_003590f8 = param_1 - (float)(int)param_1;
  auVar4 = _lqc2(*pauVar1);
  auVar5 = _lqc2(pauVar1[1]);
  auVar6 = _lqc2(*pauVar2);
  auVar7 = _lqc2(pauVar2[1]);
  auVar8._8_4_ = DAT_003590f8;
  auVar8._0_8_ = _DAT_003590f0;
  auVar8._12_4_ = uRam003590fc;
  auVar8 = _lqc2(auVar8);
  auVar9 = _vsub(auVar7,auVar6);
  auVar10 = _vmulbc(auVar6,auVar8);
  auVar11 = _vmulbc(auVar6,auVar8);
  auVar12 = _vsub(auVar5,auVar4);
  auVar5 = _vmulbc(auVar9,auVar8);
  auVar6 = _vadd(auVar10,auVar7);
  auVar5 = _vadd(auVar5,auVar11);
  auVar6 = _vsub(auVar12,auVar6);
  auVar5 = _vmulbc(auVar5,auVar8);
  auVar5 = _vadd(auVar5,auVar6);
  auVar8 = _vmulbc(auVar5,auVar8);
  auVar8 = _vadd(auVar8,auVar4);
  auVar8 = _sqc2(auVar8);
  *param_2 = auVar8;
  return;
}
```

## Earlier attempts (newest first)

- none found
