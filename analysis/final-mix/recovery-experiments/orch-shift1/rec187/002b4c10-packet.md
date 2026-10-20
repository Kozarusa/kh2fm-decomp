# Target packet 002b4c10

- Range: `002b4c10`..`002b4c84`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b4c10`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00234570` registry: `_ZN2YI5MCARD14EntryInfoMCardEiPv`
- `00240ba0` registry: `_ZN2Tz5MCard7GetSlotEv`
- `00287d20` registry: `_ZN2Tz8MenuBase8SetPhaseEi`
- `0028f4d8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_queueomega_recovered_0025a1d0.cpp`, `fm_primary_twoword_recovered_002367a0.cpp`, `fm_scalar_extra_recovered_06.cpp`, `fm_scalar_recovered_06.cpp`
- `002b4dd0` registry: none
- `002b5108` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b4c10: 27bdfff0  addiu	sp,sp,-16
002b4c14: ffbf0008  sd	ra,8(sp)
002b4c18: ffb00000  sd	s0,0(sp)
002b4c1c: 0c0902e8  jal	0x240ba0
002b4c20: 00000000  nop
002b4c24: 0040802d  move	s0,v0
002b4c28: 0c0ad374  jal	0x2b4dd0
002b4c2c: 2404ffff  li	a0,-1
002b4c30: 0200282d  move	a1,s0
002b4c34: 0c0ad442  jal	0x2b5108
002b4c38: 34048a89  li	a0,0x8a89
002b4c3c: 3c0f0036  lui	t7,0x36
002b4c40: 240e0024  li	t6,36
002b4c44: 8dedf6cc  lw	t5,-2356(t7)   ; = D_0035f6cc
002b4c48: 020e7018  mult	t6,s0,t6
002b4c4c: 0000302d  move	a2,zero
002b4c50: 24040001  li	a0,1
002b4c54: 8daf0000  lw	t7,0(t5)
002b4c58: 01cf7021  addu	t6,t6,t7
002b4c5c: 0c0a3d36  jal	0x28f4d8
002b4c60: 95c50012  lhu	a1,18(t6)
002b4c64: 0c0a1f48  jal	0x287d20
002b4c68: 0000202d  move	a0,zero
002b4c6c: 0200202d  move	a0,s0
002b4c70: dfbf0008  ld	ra,8(sp)
002b4c74: dfb00000  ld	s0,0(sp)
002b4c78: 0000282d  move	a1,zero
002b4c7c: 0808d15c  j	0x234570
002b4c80: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b4c10(void)`

```c
void FUN_002b4c10(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00240ba0();
  FUN_002b4dd0(0xffffffffffffffff);
  FUN_002b5108(0x8a89,uVar1);
  FUN_0028f4d8(1,*(undefined2 *)((int)uVar1 * 0x24 + *DAT_0035f6cc + 0x12),0);
  FUN_00287d20(0);
  FUN_00234570(uVar1,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
