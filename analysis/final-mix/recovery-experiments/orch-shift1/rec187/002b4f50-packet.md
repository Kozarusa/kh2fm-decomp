# Target packet 002b4f50

- Range: `002b4f50`..`002b4fb4`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b4f50`
- Registry names for this address: `func_002b4f50`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `0028abe0` registry: `Tz::Select::Destroy(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcheg_recovered_00269ef8.cpp`
- `0028acc8` registry: `Tz::Select::isCreated(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcheb_recovered_002519d0.cpp`, `fm_primary_orchec_recovered_002576d0.cpp`, `fm_primary_orchee_recovered_00262290.cpp`, `fm_primary_orchef_recovered_002656c0.cpp`, `fm_primary_orcheg_recovered_00269ef8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b4f50: 27bdfff0  addiu	sp,sp,-16
002b4f54: ffb00000  sd	s0,0(sp)
002b4f58: ffbf0008  sd	ra,8(sp)
002b4f5c: 3c100036  lui	s0,0x36
002b4f60: 0c04e75e  jal	0x139d78
002b4f64: 8e04f654  lw	a0,-2476(s0)   ; = D_0035f654
002b4f68: 10400005  beqz	v0,0x2b4f80
002b4f6c: 8e0ff654  lw	t7,-2476(s0)   ; = D_0035f654
002b4f70: 8dee0000  lw	t6,0(t7)
002b4f74: 8dcd0014  lw	t5,20(t6)
002b4f78: 01a0f809  jalr	t5
002b4f7c: 01e0202d  move	a0,t7
002b4f80: 3c100036  lui	s0,0x36
002b4f84: 0c0a2b32  jal	0x28acc8
002b4f88: 8e04f650  lw	a0,-2480(s0)   ; = D_0035f650
002b4f8c: 10400004  beqz	v0,0x2b4fa0
002b4f90: 3c0f0036  lui	t7,0x36
002b4f94: 0c0a2af8  jal	0x28abe0
002b4f98: 8e04f650  lw	a0,-2480(s0)   ; = D_0035f650
002b4f9c: 3c0f0036  lui	t7,0x36
002b4fa0: dfb00000  ld	s0,0(sp)
002b4fa4: a1e0f6d0  sb	zero,-2352(t7)   ; = D_0035f6d0
002b4fa8: dfbf0008  ld	ra,8(sp)
002b4fac: 03e00008  jr	ra
002b4fb0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b4f50(void)`

```c
void FUN_002b4f50(void)

{
  long lVar1;
  
  lVar1 = FUN_00139d78(DAT_0035f654);
  if (lVar1 != 0) {
    (**(code **)(*DAT_0035f654 + 0x14))(DAT_0035f654);
  }
  lVar1 = FUN_0028acc8(DAT_0035f650);
  if (lVar1 != 0) {
    FUN_0028abe0(DAT_0035f650);
  }
  DAT_0035f6d0 = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
