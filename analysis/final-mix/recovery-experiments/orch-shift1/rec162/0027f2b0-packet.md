# Target packet 0027f2b0

- Range: `0027f2b0`..`0027f2f8`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_0027f2b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `0028acc8` registry: `Tz::Select::isCreated(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcheb_recovered_002519d0.cpp`, `fm_primary_orchec_recovered_002576d0.cpp`, `fm_primary_orchee_recovered_00262290.cpp`, `fm_primary_orchef_recovered_002656c0.cpp`, `fm_primary_orcheg_recovered_00269ef8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0027f2b0: 27bdfff0  addiu	sp,sp,-16
0027f2b4: 3c0f0036  lui	t7,0x36
0027f2b8: ffbf0000  sd	ra,0(sp)
0027f2bc: 0c04e75e  jal	0x139d78
0027f2c0: 8de4f250  lw	a0,-3504(t7)   ; = D_0035f250
0027f2c4: 1440000a  bnez	v0,0x27f2f0
0027f2c8: dfbf0000  ld	ra,0(sp)
0027f2cc: 3c0f0036  lui	t7,0x36
0027f2d0: 0c04e75e  jal	0x139d78
0027f2d4: 8de4f258  lw	a0,-3496(t7)   ; = D_0035f258
0027f2d8: 14400005  bnez	v0,0x27f2f0
0027f2dc: dfbf0000  ld	ra,0(sp)
0027f2e0: 3c0f0036  lui	t7,0x36
0027f2e4: 0c0a2b32  jal	0x28acc8
0027f2e8: 8de4f254  lw	a0,-3500(t7)   ; = D_0035f254
0027f2ec: dfbf0000  ld	ra,0(sp)
0027f2f0: 03e00008  jr	ra
0027f2f4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0027f2b0(void)`

```c
void FUN_0027f2b0(void)

{
  long lVar1;
  
  lVar1 = FUN_00139d78(DAT_0035f250);
  if ((lVar1 == 0) && (lVar1 = FUN_00139d78(DAT_0035f258), lVar1 == 0)) {
    FUN_0028acc8(DAT_0035f254);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
