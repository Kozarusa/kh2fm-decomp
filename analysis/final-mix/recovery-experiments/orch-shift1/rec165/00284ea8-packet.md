# Target packet 00284ea8

- Range: `00284ea8`..`00284eec`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_00284ea8`
- Registry names for this address: `func_00284ea8`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00103580` registry: `_ZN4MENU15GetObjAllocatorEv`
- `002bd7d8` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00284ea8: 27bdfff0  addiu	sp,sp,-16
00284eac: ffbf0008  sd	ra,8(sp)
00284eb0: ffb00000  sd	s0,0(sp)
00284eb4: 0c0af5f6  jal	0x2bd7d8
00284eb8: 3c100036  lui	s0,0x36
00284ebc: 0c040d60  jal	0x103580
00284ec0: 00000000  nop
00284ec4: 8c4e0000  lw	t6,0(v0)
00284ec8: 0040202d  move	a0,v0
00284ecc: 8dcf0004  lw	t7,4(t6)
00284ed0: 01e0f809  jalr	t7
00284ed4: 8e05f2c0  lw	a1,-3392(s0)   ; = D_0035f2c0
00284ed8: ae00f2c0  sw	zero,-3392(s0)   ; = D_0035f2c0
00284edc: dfbf0008  ld	ra,8(sp)
00284ee0: dfb00000  ld	s0,0(sp)
00284ee4: 03e00008  jr	ra
00284ee8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00284ea8(void)`

```c
void FUN_00284ea8(void)

{
  undefined8 uVar1;
  
  FUN_002bd7d8();
  uVar1 = FUN_00103580();
  (**(code **)(*(int *)uVar1 + 4))(uVar1,DAT_0035f2c0);
  DAT_0035f2c0 = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
