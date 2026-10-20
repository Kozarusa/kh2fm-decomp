# Target packet 001d69d0

- Range: `001d69d0`..`001d6a28`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d69d0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0013dde8` registry: `func_0013dde8`
- `0019ca20` registry: `_ZN2YS6LOCKON12reset_playerEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbq_recovered_0019c8d0.cpp`, `fm_primary_orchbq_recovered_0019c920.cpp`
- `001befa8` registry: `func_001befa8`
  - accepted sources that already call it (copy their declaration): `fm_primary_width_recovered_00.cpp`
- `001d6a28` registry: `_ZN2dk5GAUGE7destroyEi`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d69d0: 27bdfff0  addiu	sp,sp,-16
001d69d4: ffb00000  sd	s0,0(sp)
001d69d8: ffbf0008  sd	ra,8(sp)
001d69dc: 0c075a8a  jal	0x1d6a28
001d69e0: 0080802d  move	s0,a0
001d69e4: 0c067288  jal	0x19ca20
001d69e8: 26040ac0  addiu	a0,s0,2752
001d69ec: 8e0e0af4  lw	t6,2804(s0)
001d69f0: 8dcf048c  lw	t7,1164(t6)
001d69f4: 11e00003  beqz	t7,0x1d6a04
001d69f8: 0000202d  move	a0,zero
001d69fc: 0c04f77a  jal	0x13dde8
001d6a00: 00000000  nop
001d6a04: 0c06fbea  jal	0x1befa8
001d6a08: 0200202d  move	a0,s0
001d6a0c: ae000af4  sw	zero,2804(s0)
001d6a10: 3c0f0035  lui	t7,0x35
001d6a14: dfbf0008  ld	ra,8(sp)
001d6a18: ade027e0  sw	zero,10208(t7)   ; = D_003527e0
001d6a1c: dfb00000  ld	s0,0(sp)
001d6a20: 03e00008  jr	ra
001d6a24: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d69d0(void)`

```c
void FUN_001d69d0(undefined8 param_1)

{
  int iVar1;
  
  FUN_001d6a28();
  iVar1 = (int)param_1;
  FUN_0019ca20(iVar1 + 0xac0);
  if (*(int *)(*(int *)(iVar1 + 0xaf4) + 0x48c) != 0) {
    FUN_0013dde8(0);
  }
  FUN_001befa8(param_1);
  *(undefined4 *)(iVar1 + 0xaf4) = 0;
  DAT_003527e0 = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
