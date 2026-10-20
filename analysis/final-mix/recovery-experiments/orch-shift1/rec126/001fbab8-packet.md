# Target packet 001fbab8

- Range: `001fbab8`..`001fbb1c`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_001fbab8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0021fe40` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001fbab8: 27bdffd0  addiu	sp,sp,-48
001fbabc: 0080702d  move	t6,a0
001fbac0: ffbf0020  sd	ra,32(sp)
001fbac4: 248b0010  addiu	t3,a0,16
001fbac8: 0000282d  move	a1,zero
001fbacc: c4800028  lwc1	$f0,40(a0)
001fbad0: 8c8f0024  lw	t7,36(a0)
001fbad4: 46000064  cvt.w.s	$f1,$f0
001fbad8: 948d002c  lhu	t5,44(a0)
001fbadc: 440c0800  mfc1	t4,$f1
001fbae0: c4810020  lwc1	$f1,32(a0)
001fbae4: afaf0004  sw	t7,4(sp)
001fbae8: 03a0202d  move	a0,sp
001fbaec: e7a1000c  swc1	$f1,12(sp)
001fbaf0: 3c0f01da  lui	t7,0x1da
001fbaf4: a7ac0010  sh	t4,16(sp)
001fbaf8: 25efe8c0  addiu	t7,t7,-5952   ; = D_01d9e8c0
001fbafc: a7ad0012  sh	t5,18(sp)
001fbb00: afaf0008  sw	t7,8(sp)
001fbb04: afab0014  sw	t3,20(sp)
001fbb08: 0c087f90  jal	0x21fe40
001fbb0c: afae0000  sw	t6,0(sp)
001fbb10: dfbf0020  ld	ra,32(sp)
001fbb14: 03e00008  jr	ra
001fbb18: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001fbab8(void)`

```c
void FUN_001fbab8(int param_1)

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
  uStack_1e = *(undefined2 *)(param_1 + 0x2c);
  uStack_24 = *(undefined4 *)(param_1 + 0x20);
  uStack_20 = (undefined2)(int)*(float *)(param_1 + 0x28);
  puStack_28 = &DAT_01d9e8c0;
  iStack_30 = param_1;
  FUN_0021fe40(&iStack_30,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
