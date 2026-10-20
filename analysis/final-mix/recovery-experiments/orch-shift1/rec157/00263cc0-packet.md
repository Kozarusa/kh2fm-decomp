# Target packet 00263cc0

- Range: `00263cc0`..`00263d24`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_00263cc0`
- Registry names for this address: `func_00263cc0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `00263d28` registry: `_ZN2Tz9CMenuHelp5LeaveEv`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00263cc0: 27bdfff0  addiu	sp,sp,-16
00263cc4: ffb00000  sd	s0,0(sp)
00263cc8: ffbf0008  sd	ra,8(sp)
00263ccc: 3c100036  lui	s0,0x36
00263cd0: 8e0ff0dc  lw	t7,-3876(s0)   ; = D_0035f0dc
00263cd4: 11e0000f  beqz	t7,0x263d14
00263cd8: 0000102d  move	v0,zero
00263cdc: 3c0f0036  lui	t7,0x36
00263ce0: 0c04e75e  jal	0x139d78
00263ce4: 8de4f0c0  lw	a0,-3904(t7)   ; = D_0035f0c0
00263ce8: 14400008  bnez	v0,0x263d0c
00263cec: 3c0f0036  lui	t7,0x36
00263cf0: 0c04e75e  jal	0x139d78
00263cf4: 8e04f0dc  lw	a0,-3876(s0)   ; = D_0035f0dc
00263cf8: 10400004  beqz	v0,0x263d0c
00263cfc: 3c0f0036  lui	t7,0x36
00263d00: 0c098f4a  jal	0x263d28
00263d04: 00000000  nop
00263d08: 3c0f0036  lui	t7,0x36
00263d0c: 0c04e75e  jal	0x139d78
00263d10: 8de4f0dc  lw	a0,-3876(t7)   ; = D_0035f0dc
00263d14: dfb00000  ld	s0,0(sp)
00263d18: dfbf0008  ld	ra,8(sp)
00263d1c: 03e00008  jr	ra
00263d20: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00263cc0(void)`

```c
undefined8 FUN_00263cc0(void)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = 0;
  if (DAT_0035f0dc != 0) {
    lVar2 = FUN_00139d78(DAT_0035f0c0);
    if ((lVar2 == 0) && (lVar2 = FUN_00139d78(DAT_0035f0dc), lVar2 != 0)) {
      FUN_00263d28();
    }
    uVar1 = FUN_00139d78(DAT_0035f0dc);
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- none found
