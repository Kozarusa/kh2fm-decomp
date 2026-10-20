# Target packet 001fb508

- Range: `001fb508`..`001fb554`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_001fb508`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0021fa28` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001fb508: 27bdffd0  addiu	sp,sp,-48
001fb50c: 0080702d  move	t6,a0
001fb510: ffbf0020  sd	ra,32(sp)
001fb514: 248d0010  addiu	t5,a0,16
001fb518: 0000282d  move	a1,zero
001fb51c: 8c8f0024  lw	t7,36(a0)
001fb520: c4800020  lwc1	$f0,32(a0)
001fb524: afaf0004  sw	t7,4(sp)
001fb528: 03a0202d  move	a0,sp
001fb52c: e7a0000c  swc1	$f0,12(sp)
001fb530: 3c0f01da  lui	t7,0x1da
001fb534: afad0010  sw	t5,16(sp)
001fb538: 25efe8c0  addiu	t7,t7,-5952   ; = D_01d9e8c0
001fb53c: afae0000  sw	t6,0(sp)
001fb540: 0c087e8a  jal	0x21fa28
001fb544: afaf0008  sw	t7,8(sp)
001fb548: dfbf0020  ld	ra,32(sp)
001fb54c: 03e00008  jr	ra
001fb550: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001fb508(void)`

```c
void FUN_001fb508(int param_1)

{
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  int iStack_20;
  
  iStack_20 = param_1 + 0x10;
  uStack_2c = *(undefined4 *)(param_1 + 0x24);
  uStack_24 = *(undefined4 *)(param_1 + 0x20);
  puStack_28 = &DAT_01d9e8c0;
  iStack_30 = param_1;
  FUN_0021fa28(&iStack_30,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
