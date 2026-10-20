# Target packet 0017ce10

- Range: `0017ce10`..`0017ce80`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_0017ce10`
- Registry names for this address: `_ZN2YS4MATH9FixRadianEf`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002f8b00` registry: `func_002f8b00`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0017ce10: 44800000  mtc1	zero,$f0
0017ce14: 27bdfff0  addiu	sp,sp,-16
0017ce18: ffbf0000  sd	ra,0(sp)
0017ce1c: 460c0034  c.lt.s	$f0,$f12
0017ce20: e7b40008  swc1	$f20,8(sp)
0017ce24: 4500000d  bc1f	0x17ce5c
0017ce28: 3c0f0037  lui	t7,0x37
0017ce2c: 25efc544  addiu	t7,t7,-15036   ; = D_0036c544
0017ce30: c5f40000  lwc1	$f20,0(t7)
0017ce34: 3c0f0037  lui	t7,0x37
0017ce38: 46146300  add.s	$f12,$f12,$f20
0017ce3c: 25efc548  addiu	t7,t7,-15032   ; = D_0036c548
0017ce40: 0c0be2c0  jal	0x2f8b00
0017ce44: c5ed0000  lwc1	$f13,0(t7)
0017ce48: 46140001  sub.s	$f0,$f0,$f20
0017ce4c: dfbf0000  ld	ra,0(sp)
0017ce50: c7b40008  lwc1	$f20,8(sp)
0017ce54: 03e00008  jr	ra
0017ce58: 27bd0010  addiu	sp,sp,16
0017ce5c: 25efc544  addiu	t7,t7,-15036
0017ce60: c5f40000  lwc1	$f20,0(t7)
0017ce64: 3c0f0037  lui	t7,0x37
0017ce68: 460ca301  sub.s	$f12,$f20,$f12
0017ce6c: 25efc548  addiu	t7,t7,-15032   ; = D_0036c548
0017ce70: 0c0be2c0  jal	0x2f8b00
0017ce74: c5ed0000  lwc1	$f13,0(t7)
0017ce78: 1000fff4  b	0x17ce4c
0017ce7c: 4600a001  sub.s	$f0,$f20,$f0
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0017ce10(void)`

```c
float FUN_0017ce10(float param_1)

{
  float fVar1;
  float fVar2;
  
  fVar2 = DAT_0036c544;
  if (0.0 < param_1) {
    fVar1 = (float)FUN_002f8b00(param_1 + DAT_0036c544,DAT_0036c548);
    fVar2 = fVar1 - fVar2;
  }
  else {
    fVar1 = (float)FUN_002f8b00(DAT_0036c544 - param_1,DAT_0036c548);
    fVar2 = fVar2 - fVar1;
  }
  return fVar2;
}
```

## Earlier attempts (newest first)

- none found
