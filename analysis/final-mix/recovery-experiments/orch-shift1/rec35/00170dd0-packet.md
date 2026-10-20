# Target packet 00170dd0

- Range: `00170dd0`..`00170e18`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_00170dd0`
- Registry names for this address: `func_00170dd0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102448` registry: `Tz::TaskYield(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_freshhelpers_recovered_001367e0.cpp`, `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_threeword_recovered_002a01c8.cpp`, `fm_primary_threeword_recovered_002a6368.cpp`
- `00170cd0` registry: `func_00170cd0`
  - accepted sources that already call it (copy their declaration): `fm_primary_freshhelpers_recovered_001367e0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00170dd0: 27bdfff0  addiu	sp,sp,-16
00170dd4: ffb00000  sd	s0,0(sp)
00170dd8: ffbf0008  sd	ra,8(sp)
00170ddc: 0080802d  move	s0,a0
00170de0: 0c05c334  jal	0x170cd0
00170de4: 00000000  nop
00170de8: 0200202d  move	a0,s0
00170dec: 14400006  bnez	v0,0x170e08
00170df0: 0000282d  move	a1,zero
00170df4: dfb00000  ld	s0,0(sp)
00170df8: dfbf0008  ld	ra,8(sp)
00170dfc: 03e00008  jr	ra
00170e00: 27bd0010  addiu	sp,sp,16
00170e04: 00000000  nop
00170e08: 0c040912  jal	0x102448
00170e0c: 00000000  nop
00170e10: 1000fff3  b	0x170de0
00170e14: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00170dd0(void)`

```c
void FUN_00170dd0(undefined8 param_1)

{
  long lVar1;
  
  while (lVar1 = FUN_00170cd0(), lVar1 != 0) {
    FUN_00102448(param_1,0);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
