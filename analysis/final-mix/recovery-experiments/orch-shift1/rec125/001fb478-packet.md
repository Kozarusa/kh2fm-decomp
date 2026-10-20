# Target packet 001fb478

- Range: `001fb478`..`001fb4dc`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_001fb478`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0021f5d8` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001fb478: 27bdfff0  addiu	sp,sp,-16
001fb47c: 8caf000c  lw	t7,12(a1)
001fb480: ffb00000  sd	s0,0(sp)
001fb484: ffbf0008  sd	ra,8(sp)
001fb488: 8dee0000  lw	t6,0(t7)
001fb48c: 008e8021  addu	s0,a0,t6
001fb490: 261000a0  addiu	s0,s0,160
001fb494: 0c087d76  jal	0x21f5d8
001fb498: 0200202d  move	a0,s0
001fb49c: ae00009c  sw	zero,156(s0)
001fb4a0: 3c0e0036  lui	t6,0x36
001fb4a4: ae0000a8  sw	zero,168(s0)
001fb4a8: 240f0002  li	t7,2
001fb4ac: dfbf0008  ld	ra,8(sp)
001fb4b0: 91cd90b0  lbu	t5,-28496(t6)   ; = D_003590b0
001fb4b4: a20f008d  sb	t7,141(s0)
001fb4b8: a20d008c  sb	t5,140(s0)
001fb4bc: a20000c1  sb	zero,193(s0)
001fb4c0: a20000c0  sb	zero,192(s0)
001fb4c4: 91cf90b0  lbu	t7,-28496(t6)   ; = D_003590b0
001fb4c8: dfb00000  ld	s0,0(sp)
001fb4cc: 25ef0001  addiu	t7,t7,1
001fb4d0: a1cf90b0  sb	t7,-28496(t6)   ; = D_003590b0
001fb4d4: 03e00008  jr	ra
001fb4d8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001fb478(void)`

```c
void FUN_001fb478(int param_1,int param_2)

{
  char cVar1;
  
  param_1 = param_1 + **(int **)(param_2 + 0xc);
  FUN_0021f5d8(param_1 + 0xa0);
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  cVar1 = DAT_003590b0;
  *(undefined1 *)(param_1 + 0x12d) = 2;
  *(char *)(param_1 + 300) = cVar1;
  *(undefined1 *)(param_1 + 0x161) = 0;
  *(undefined1 *)(param_1 + 0x160) = 0;
  DAT_003590b0 = DAT_003590b0 + '\x01';
  return;
}
```

## Earlier attempts (newest first)

- none found
