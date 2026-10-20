# Target packet 0019d4f8

- Range: `0019d4f8`..`0019d548`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019d4f8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00190128` registry: `func_00190128`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_delegatedbatch_recovered_00159c58.cpp`, `fm_primary_fiveword_recovered_002e8c28.cpp`, `fm_primary_floatpacket_recovered_002e8c58.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`
- `001bc688` registry: `_ZN2YS12COMMAND_SLOT5clearEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_queuebeta_recovered_0019da20.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`
- `0019d518` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019d4f8: 27bdfff0  addiu	sp,sp,-16
0019d4fc: ac800008  sw	zero,8(a0)
0019d500: ffbf0000  sd	ra,0(sp)
0019d504: ac800004  sw	zero,4(a0)
0019d508: dfbf0000  ld	ra,0(sp)
0019d50c: 08067546  j	0x19d518
0019d510: 27bd0010  addiu	sp,sp,16
0019d514: 00000000  nop
0019d518: 27bdfff0  addiu	sp,sp,-16
0019d51c: ffb00000  sd	s0,0(sp)
0019d520: ffbf0008  sd	ra,8(sp)
0019d524: 0080802d  move	s0,a0
0019d528: 24840024  addiu	a0,a0,36
0019d52c: 0c06f1a2  jal	0x1bc688
0019d530: 2610000c  addiu	s0,s0,12
0019d534: 0200202d  move	a0,s0
0019d538: dfbf0008  ld	ra,8(sp)
0019d53c: dfb00000  ld	s0,0(sp)
0019d540: 0806404a  j	0x190128
0019d544: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019d4f8(void)`

```c
void FUN_0019d4f8(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_001bc688(param_1 + 0x24);
  FUN_00190128(param_1 + 0xc);
  return;
}
```

## Earlier attempts (newest first)

- none found
