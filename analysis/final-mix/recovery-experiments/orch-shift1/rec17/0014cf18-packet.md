# Target packet 0014cf18

- Range: `0014cf18`..`0014cf80`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_0014cf18`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0014ca48` registry: `func_0014ca48`
- `0014ccb8` registry: none
- `0014d4e8` registry: `func_0014d4e8`
- `003058d0` registry: `iFlushCache`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0014cf18: 27bdfff0  addiu	sp,sp,-16
0014cf1c: ffbf0000  sd	ra,0(sp)
0014cf20: 0c05332e  jal	0x14ccb8
0014cf24: 00000000  nop
0014cf28: 0c053292  jal	0x14ca48
0014cf2c: 00000000  nop
0014cf30: 3c0d0035  lui	t5,0x35
0014cf34: 3c0c0035  lui	t4,0x35
0014cf38: 8daf9e04  lw	t7,-25084(t5)   ; = D_00349e04
0014cf3c: 25ef0001  addiu	t7,t7,1
0014cf40: adaf9e04  sw	t7,-25084(t5)   ; = D_00349e04
0014cf44: 8d8e9e08  lw	t6,-25080(t4)   ; = D_00349e08
0014cf48: 25ce0001  addiu	t6,t6,1
0014cf4c: ad8e9e08  sw	t6,-25080(t4)   ; = D_00349e08
0014cf50: 0c05353a  jal	0x14d4e8
0014cf54: 00000000  nop
0014cf58: 0c0c1634  jal	0x3058d0
0014cf5c: 0000202d  move	a0,zero
0014cf60: 0c0c1634  jal	0x3058d0
0014cf64: 24040002  li	a0,2
0014cf68: 0000000f  sync
0014cf6c: 42000038  ei
0014cf70: dfbf0000  ld	ra,0(sp)
0014cf74: 0000102d  move	v0,zero
0014cf78: 03e00008  jr	ra
0014cf7c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0014cf18(void)`

```c
undefined8 FUN_0014cf18(void)

{
  FUN_0014ccb8();
  FUN_0014ca48();
  DAT_00349e04 = DAT_00349e04 + 1;
  DAT_00349e08 = DAT_00349e08 + 1;
  FUN_0014d4e8();
  iFlushCache(0);
  iFlushCache(2);
  SYNC(0);
  EI();
  return 0;
}
```

## Earlier attempts (newest first)

- none found
