# Target packet 0015ee10

- Range: `0015ee10`..`0015ee8c`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015ee10`
- Registry names for this address: `_ZN2dk3Map12setHideGroupEj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00143060` registry: `func_00143060`
- `001538d8` registry: none
- `0015c4a0` registry: `func_0015c4a0`
- `001de3d8` registry: `func_001de3d8`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015ee10: 27bdfff0  addiu	sp,sp,-16
0015ee14: 3c0e0035  lui	t6,0x35
0015ee18: ffbf0008  sd	ra,8(sp)
0015ee1c: 240f0001  li	t7,1
0015ee20: ffb00000  sd	s0,0(sp)
0015ee24: 008f7814  dsllv	t7,t7,a0
0015ee28: 000f7827  nor	t7,zero,t7
0015ee2c: ddcdc710  ld	t5,-14576(t6)   ; = D_0034c710
0015ee30: 0080802d  move	s0,a0
0015ee34: 01ed7824  and	t7,t7,t5
0015ee38: 0c050c18  jal	0x143060
0015ee3c: fdcfc710  sd	t7,-14576(t6)   ; = D_0034c710
0015ee40: 0c054e36  jal	0x1538d8
0015ee44: 320400ff  andi	a0,s0,0xff
0015ee48: 0c057128  jal	0x15c4a0
0015ee4c: 0200202d  move	a0,s0
0015ee50: 3c0f0035  lui	t7,0x35
0015ee54: 3c040035  lui	a0,0x35
0015ee58: 91eec70c  lbu	t6,-14580(t7)   ; = D_0034c70c
0015ee5c: 2484c6f0  addiu	a0,a0,-14608   ; = D_0034c6f0
0015ee60: 240f0001  li	t7,1
0015ee64: 15cf0005  bne	t6,t7,0x15ee7c
0015ee68: 0200282d  move	a1,s0
0015ee6c: dfb00000  ld	s0,0(sp)
0015ee70: dfbf0008  ld	ra,8(sp)
0015ee74: 080778f6  j	0x1de3d8
0015ee78: 27bd0010  addiu	sp,sp,16
0015ee7c: dfb00000  ld	s0,0(sp)
0015ee80: dfbf0008  ld	ra,8(sp)
0015ee84: 03e00008  jr	ra
0015ee88: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015ee10(void)`

```c
void FUN_0015ee10(ulong param_1)

{
  DAT_0034c710 = ~(1L << param_1) & DAT_0034c710;
  FUN_00143060();
  FUN_001538d8(param_1 & 0xff);
  FUN_0015c4a0(param_1);
  if (DAT_0034c70c == '\x01') {
    FUN_001de3d8(0x34c6f0,param_1);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
