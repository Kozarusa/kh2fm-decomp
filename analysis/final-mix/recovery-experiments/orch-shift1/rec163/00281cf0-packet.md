# Target packet 00281cf0

- Range: `00281cf0`..`00281d38`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_00281cf0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00281b30` registry: `Tz::CmItem::FadeOutHelp()`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00281cf0: 27bdfff0  addiu	sp,sp,-16
00281cf4: 3c0f0037  lui	t7,0x37
00281cf8: ffb00000  sd	s0,0(sp)
00281cfc: 25ef41a4  addiu	t7,t7,16804   ; = D_003741a4
00281d00: ffbf0008  sd	ra,8(sp)
00281d04: 3c0e0036  lui	t6,0x36
00281d08: a1c0f298  sb	zero,-3432(t6)   ; = D_0035f298
00281d0c: 0080802d  move	s0,a0
00281d10: c5e00000  lwc1	$f0,0(t7)
00281d14: 3c0f0036  lui	t7,0x36
00281d18: 0c0a06cc  jal	0x281b30
00281d1c: e5e0f294  swc1	$f0,-3436(t7)   ; = D_0035f294
00281d20: 3c0f0036  lui	t7,0x36
00281d24: dfbf0008  ld	ra,8(sp)
00281d28: a5f0f280  sh	s0,-3456(t7)   ; = D_0035f280
00281d2c: dfb00000  ld	s0,0(sp)
00281d30: 03e00008  jr	ra
00281d34: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00281cf0(void)`

```c
void FUN_00281cf0(undefined2 param_1)

{
  DAT_0035f298 = 0;
  DAT_0035f294 = DAT_003741a4;
  FUN_00281b30();
  DAT_0035f280 = param_1;
  return;
}
```

## Earlier attempts (newest first)

- none found
