# Target packet 002b2d48

- Range: `002b2d48`..`002b2da4`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b2d48`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b2d48: 27bdffe0  addiu	sp,sp,-32
002b2d4c: ffb00000  sd	s0,0(sp)
002b2d50: ffb10008  sd	s1,8(sp)
002b2d54: 3c100036  lui	s0,0x36
002b2d58: ffbf0010  sd	ra,16(sp)
002b2d5c: 8e04f634  lw	a0,-2508(s0)   ; = D_0035f634
002b2d60: 0000882d  move	s1,zero
002b2d64: 0c04e75e  jal	0x139d78
002b2d68: 24844e18  addiu	a0,a0,19992
002b2d6c: 54400007  bnezl	v0,0x2b2d8c
002b2d70: 24110001  li	s1,1
002b2d74: 8e04f634  lw	a0,-2508(s0)   ; = D_0035f634
002b2d78: 0c04e75e  jal	0x139d78
002b2d7c: 24844fb0  addiu	a0,a0,20400
002b2d80: 10400003  beqz	v0,0x2b2d90
002b2d84: 0220102d  move	v0,s1
002b2d88: 24110001  li	s1,1
002b2d8c: 0220102d  move	v0,s1
002b2d90: dfb00000  ld	s0,0(sp)
002b2d94: dfb10008  ld	s1,8(sp)
002b2d98: dfbf0010  ld	ra,16(sp)
002b2d9c: 03e00008  jr	ra
002b2da0: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b2d48(void)`

```c
undefined4 FUN_002b2d48(void)

{
  long lVar1;
  
  lVar1 = FUN_00139d78(DAT_0035f634 + 0x4e18);
  if ((lVar1 == 0) && (lVar1 = FUN_00139d78(DAT_0035f634 + 0x4fb0), lVar1 == 0)) {
    return 0;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- none found
