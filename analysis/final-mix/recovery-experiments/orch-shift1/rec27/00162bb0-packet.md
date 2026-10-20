# Target packet 00162bb0

- Range: `00162bb0`..`00162c24`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_00162bb0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00162560` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00162bb0: 27bdffd0  addiu	sp,sp,-48
00162bb4: c4e00000  lwc1	$f0,0(a3)
00162bb8: ffbf0020  sd	ra,32(sp)
00162bbc: 0100682d  move	t5,t0
00162bc0: 27ae0010  addiu	t6,sp,16
00162bc4: d8c10000  lqc2	vf1,0(a2)
00162bc8: 44080000  mfc1	t0,$f0
00162bcc: 48a81000  qmtc2	t0,vf2
00162bd0: 4bc20858  vmulx.xyz	vf1,vf1,vf2x
00162bd4: f9c10000  sqc2	vf1,0(t6)
00162bd8: 13ae0003  beq	sp,t6,0x162be8
00162bdc: 00000000  nop
00162be0: 79c80000  lq	t0,0(t6)
00162be4: 7fa80000  sq	t0,0(sp)
00162be8: d8810000  lqc2	vf1,0(a0)
00162bec: dba20000  lqc2	vf2,0(sp)
00162bf0: 4be2086c  vsub.wxyz	vf1,vf1,vf2
00162bf4: f9c10000  sqc2	vf1,0(t6)
00162bf8: 11ae0004  beq	t5,t6,0x162c0c
00162bfc: 00a0202d  move	a0,a1
00162c00: 79c80000  lq	t0,0(t6)
00162c04: 7da80000  sq	t0,0(t5)
00162c08: 00a0202d  move	a0,a1
00162c0c: 0c058958  jal	0x162560
00162c10: 01a0282d  move	a1,t5
00162c14: dfbf0020  ld	ra,32(sp)
00162c18: 0002102b  sltu	v0,zero,v0
00162c1c: 03e00008  jr	ra
00162c20: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00162bb0(void)`

```c
bool FUN_00162bb0(undefined1 (*param_1) [16],undefined8 param_2,undefined1 (*param_3) [16],
                 undefined4 *param_4,undefined4 *param_5)

{
  long lVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [16];
  
  auVar2 = _lqc2(*param_3);
  auVar3 = _qmtc2(*param_4);
  auVar2 = _vmulbc(auVar2,auVar3);
  auVar2 = _sqc2(auVar2);
  if (&uStack_30 != (undefined4 *)auStack_20) {
    auStack_20._8_4_ = auVar2._8_4_;
    auStack_20._12_4_ = auVar2._12_4_;
    uStack_30 = auVar2._0_4_;
    uStack_2c = auVar2._4_4_;
    uStack_28 = auStack_20._8_4_;
    uStack_24 = auStack_20._12_4_;
  }
  auVar3 = _lqc2(*param_1);
  auVar2._4_4_ = uStack_2c;
  auVar2._0_4_ = uStack_30;
  auVar2._8_4_ = uStack_28;
  auVar2._12_4_ = uStack_24;
  auVar2 = _lqc2(auVar2);
  auVar2 = _vsub(auVar3,auVar2);
  auStack_20 = _sqc2(auVar2);
  if (param_5 != (undefined4 *)auStack_20) {
    *param_5 = auStack_20._0_4_;
    param_5[1] = auStack_20._4_4_;
    param_5[2] = auStack_20._8_4_;
    param_5[3] = auStack_20._12_4_;
  }
  lVar1 = FUN_00162560(param_2,param_5);
  return lVar1 != 0;
}
```

## Earlier attempts (newest first)

- none found
