# Target packet 001fb6c8

- Range: `001fb6c8`..`001fb71c`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001fb6c8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0021f620` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001fb6c8: 27bdffd0  addiu	sp,sp,-48
001fb6cc: 0080702d  move	t6,a0
001fb6d0: ffbf0020  sd	ra,32(sp)
001fb6d4: 248d0030  addiu	t5,a0,48
001fb6d8: 0000282d  move	a1,zero
001fb6dc: c4800040  lwc1	$f0,64(a0)
001fb6e0: 8c8f0048  lw	t7,72(a0)
001fb6e4: c4810044  lwc1	$f1,68(a0)
001fb6e8: afaf0004  sw	t7,4(sp)
001fb6ec: 03a0202d  move	a0,sp
001fb6f0: e7a00010  swc1	$f0,16(sp)
001fb6f4: 3c0f01da  lui	t7,0x1da
001fb6f8: e7a1000c  swc1	$f1,12(sp)
001fb6fc: 25efe8c0  addiu	t7,t7,-5952   ; = D_01d9e8c0
001fb700: afad0014  sw	t5,20(sp)
001fb704: afaf0008  sw	t7,8(sp)
001fb708: 0c087d88  jal	0x21f620
001fb70c: afae0000  sw	t6,0(sp)
001fb710: dfbf0020  ld	ra,32(sp)
001fb714: 03e00008  jr	ra
001fb718: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001fb6c8(void)`

```c
void FUN_001fb6c8(int param_1)

{
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  
  iStack_1c = param_1 + 0x30;
  uStack_20 = *(undefined4 *)(param_1 + 0x40);
  uStack_2c = *(undefined4 *)(param_1 + 0x48);
  uStack_24 = *(undefined4 *)(param_1 + 0x44);
  puStack_28 = &DAT_01d9e8c0;
  iStack_30 = param_1;
  FUN_0021f620(&iStack_30,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
