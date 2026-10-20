# Target packet 00105de0

- Range: `00105de0`..`00105e48`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_00105de0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102080` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_002e8c28.cpp`, `fm_primary_floatpacket_recovered_002e8c58.cpp`, `fm_primary_oneword_recovered_002ef1b8.cpp`, `fm_primary_order_recovered_002ffc08.cpp`, `fm_primary_sixword_recovered_002f0948.cpp`
- `00103b38` registry: `_ZN4MENU9isRunningEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`, `fm_primary_oneword_recovered_00253538.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00105de0: 27bdfff0  addiu	sp,sp,-16
00105de4: ffb00000  sd	s0,0(sp)
00105de8: ffbf0008  sd	ra,8(sp)
00105dec: 0c040ece  jal	0x103b38
00105df0: 0080802d  move	s0,a0
00105df4: 54400011  bnezl	v0,0x105e3c
00105df8: dfb00000  ld	s0,0(sp)
00105dfc: 3c0e0033  lui	t6,0x33
00105e00: 8dcfb984  lw	t7,-18044(t6)   ; = D_0032b984
00105e04: 39ef0002  xori	t7,t7,0x2
00105e08: 51e0000c  beqzl	t7,0x105e3c
00105e0c: dfb00000  ld	s0,0(sp)
00105e10: 3c0e0034  lui	t6,0x34
00105e14: dfbf0008  ld	ra,8(sp)
00105e18: add0cbac  sw	s0,-13396(t6)   ; = D_0033cbac
00105e1c: 240d0001  li	t5,1
00105e20: 3c0f0034  lui	t7,0x34
00105e24: 3c040034  lui	a0,0x34
00105e28: a1edcbb0  sb	t5,-13392(t7)   ; = D_0033cbb0
00105e2c: 2484cb80  addiu	a0,a0,-13440   ; = D_0033cb80
00105e30: dfb00000  ld	s0,0(sp)
00105e34: 08040820  j	0x102080
00105e38: 27bd0010  addiu	sp,sp,16
00105e3c: dfbf0008  ld	ra,8(sp)
00105e40: 03e00008  jr	ra
00105e44: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00105de0(void)`

```c
void FUN_00105de0(undefined4 param_1)

{
  long lVar1;
  
  lVar1 = FUN_00103b38();
  if ((lVar1 == 0) && (DAT_0032b984 != 2)) {
    DAT_0033cbb0 = 1;
    DAT_0033cbac = param_1;
    FUN_00102080(0x33cb80);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
