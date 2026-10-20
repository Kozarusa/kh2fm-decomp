# Target packet 001fb8b8

- Range: `001fb8b8`..`001fb924`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001fb8b8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0021fbd8` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001fb8b8: 27bdffd0  addiu	sp,sp,-48
001fb8bc: 0080702d  move	t6,a0
001fb8c0: ffbf0020  sd	ra,32(sp)
001fb8c4: 248b0010  addiu	t3,a0,16
001fb8c8: 0000282d  move	a1,zero
001fb8cc: c4800028  lwc1	$f0,40(a0)
001fb8d0: c481002c  lwc1	$f1,44(a0)
001fb8d4: 460000a4  cvt.w.s	$f2,$f0
001fb8d8: 8c8f0024  lw	t7,36(a0)
001fb8dc: 46000824  cvt.w.s	$f0,$f1
001fb8e0: 440c1000  mfc1	t4,$f2
001fb8e4: 440d0000  mfc1	t5,$f0
001fb8e8: c4800020  lwc1	$f0,32(a0)
001fb8ec: afaf0004  sw	t7,4(sp)
001fb8f0: 03a0202d  move	a0,sp
001fb8f4: e7a0000c  swc1	$f0,12(sp)
001fb8f8: 3c0f01da  lui	t7,0x1da
001fb8fc: a7ac0010  sh	t4,16(sp)
001fb900: 25efe8c0  addiu	t7,t7,-5952   ; = D_01d9e8c0
001fb904: a7ad0012  sh	t5,18(sp)
001fb908: afaf0008  sw	t7,8(sp)
001fb90c: afab0014  sw	t3,20(sp)
001fb910: 0c087ef6  jal	0x21fbd8
001fb914: afae0000  sw	t6,0(sp)
001fb918: dfbf0020  ld	ra,32(sp)
001fb91c: 03e00008  jr	ra
001fb920: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001fb8b8(void)`

```c
void FUN_001fb8b8(int param_1)

{
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  int iStack_1c;
  
  iStack_1c = param_1 + 0x10;
  uStack_2c = *(undefined4 *)(param_1 + 0x24);
  uStack_24 = *(undefined4 *)(param_1 + 0x20);
  uStack_20 = (undefined2)(int)*(float *)(param_1 + 0x28);
  uStack_1e = (undefined2)(int)*(float *)(param_1 + 0x2c);
  puStack_28 = &DAT_01d9e8c0;
  iStack_30 = param_1;
  FUN_0021fbd8(&iStack_30,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
