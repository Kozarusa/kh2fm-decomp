# Target packet 0016f9e8

- Range: `0016f9e8`..`0016fa54`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016f9e8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0014d430` registry: `func_0014d430`
- `001707d8` registry: none
- `003058a0` registry: `FlushCache`
  - accepted sources that already call it (copy their declaration): `fm_boundary_initializers.cpp`, `fm_primary_orchal_recovered_0014d8d0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016f9e8: 27bdffd0  addiu	sp,sp,-48
0016f9ec: ffb20010  sd	s2,16(sp)
0016f9f0: ffb30018  sd	s3,24(sp)
0016f9f4: ffb00000  sd	s0,0(sp)
0016f9f8: 24120001  li	s2,1
0016f9fc: ffb10008  sd	s1,8(sp)
0016fa00: 3c130035  lui	s3,0x35
0016fa04: ffbf0020  sd	ra,32(sp)
0016fa08: 0c0c1628  jal	0x3058a0
0016fa0c: 0000202d  move	a0,zero
0016fa10: 926fdcac  lbu	t7,-9044(s3)   ; = D_0034dcac
0016fa14: 31ef00ff  andi	t7,t7,0xff
0016fa18: 15f2000a  bne	t7,s2,0x16fa44
0016fa1c: 00000000  nop
0016fa20: 3c100035  lui	s0,0x35
0016fa24: 24110001  li	s1,1
0016fa28: 0c05c1f6  jal	0x1707d8
0016fa2c: 00000000  nop
0016fa30: a200dcac  sb	zero,-9044(s0)   ; = D_0034dcac
0016fa34: 920fdcac  lbu	t7,-9044(s0)   ; = D_0034dcac
0016fa38: 31ef00ff  andi	t7,t7,0xff
0016fa3c: 11f1fffa  beq	t7,s1,0x16fa28
0016fa40: 00000000  nop
0016fa44: 0c05350c  jal	0x14d430
0016fa48: 00000000  nop
0016fa4c: 1000ffee  b	0x16fa08
0016fa50: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016f9e8(void)`

```c
void FUN_0016f9e8(void)

{
  do {
    FlushCache(0);
    if (DAT_0034dcac == '\x01') {
      FUN_001707d8();
      DAT_0034dcac = '\0';
    }
    FUN_0014d430();
  } while( true );
}
```

## Earlier attempts (newest first)

- none found
