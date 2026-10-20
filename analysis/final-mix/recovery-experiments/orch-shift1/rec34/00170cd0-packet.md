# Target packet 00170cd0

- Range: `00170cd0`..`00170d18`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_00170cd0`
- Registry names for this address: `func_00170cd0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001688b8` registry: `_ZN2YS4FILE9IsReadingEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_loadorder_recovered.cpp`, `fm_primary_packetnext_recovered.cpp`
- `00170c50` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_loadorder_recovered.cpp`, `fm_primary_packetnext_recovered.cpp`, `fm_primary_packetorder_recovered_00172368.cpp`
- `002ba200` registry: `_ZN5SOUND13checkTransferEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_loadorder_recovered.cpp`, `fm_primary_packetnext_recovered.cpp`, `fm_primary_packetorder_recovered_00172368.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00170cd0: 27bdfff0  addiu	sp,sp,-16
00170cd4: ffbf0000  sd	ra,0(sp)
00170cd8: 0c05a22e  jal	0x1688b8
00170cdc: 00000000  nop
00170ce0: 14400006  bnez	v0,0x170cfc
00170ce4: 24020001  li	v0,1
00170ce8: 0c0ae880  jal	0x2ba200
00170cec: 00000000  nop
00170cf0: 10400005  beqz	v0,0x170d08
00170cf4: 00000000  nop
00170cf8: 24020001  li	v0,1
00170cfc: dfbf0000  ld	ra,0(sp)
00170d00: 03e00008  jr	ra
00170d04: 27bd0010  addiu	sp,sp,16
00170d08: 0c05c314  jal	0x170c50
00170d0c: 00000000  nop
00170d10: 1000fffb  b	0x170d00
00170d14: dfbf0000  ld	ra,0(sp)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00170cd0(void)`

```c
undefined8 FUN_00170cd0(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_001688b8();
  if ((lVar1 == 0) && (lVar1 = FUN_002ba200(), lVar1 == 0)) {
    uVar2 = FUN_00170c50();
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- none found
