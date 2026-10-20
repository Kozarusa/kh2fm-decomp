# Target packet 002a9ce8

- Range: `002a9ce8`..`002a9d2c`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_002a9ce8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00103570` registry: `Tz::LoadDataGetSystem()`
- `001063c0` registry: `Tz::LoadDataAlloc(unsigned int, unsigned int)`
- `00319a60` registry: `func_00319a60`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`, `fm_primary_twowordfresh_recovered_00319a60.cpp`, `fm_scalar_extra_recovered_11.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002a9ce8: 27bdfff0  addiu	sp,sp,-16
002a9cec: ffbf0008  sd	ra,8(sp)
002a9cf0: ffb00000  sd	s0,0(sp)
002a9cf4: 0c040d5c  jal	0x103570
002a9cf8: 00000000  nop
002a9cfc: 0040282d  move	a1,v0
002a9d00: 0c0418f0  jal	0x1063c0
002a9d04: 24040968  li	a0,2408
002a9d08: 0040802d  move	s0,v0
002a9d0c: 0c0c6698  jal	0x319a60
002a9d10: 0040202d  move	a0,v0
002a9d14: 3c0f0036  lui	t7,0x36
002a9d18: dfbf0008  ld	ra,8(sp)
002a9d1c: adf0f610  sw	s0,-2544(t7)   ; = D_0035f610
002a9d20: dfb00000  ld	s0,0(sp)
002a9d24: 03e00008  jr	ra
002a9d28: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002a9ce8(void)`

```c
void FUN_002a9ce8(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00103570();
  uVar1 = FUN_001063c0(0x968,uVar1);
  FUN_00319a60(uVar1);
  DAT_0035f610 = (int)uVar1;
  return;
}
```

## Earlier attempts (newest first)

- 15 differing words, 60/68 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round22_002a9ce8_v01.verification.json`
