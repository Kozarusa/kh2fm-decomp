# Target packet 00152ab8

- Range: `00152ab8`..`00152ae8`, **48 bytes = 12 instructions**. This size is the acceptance size.
- Layout name: `FUN_00152ab8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00152508` registry: `func_00152508`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_loadorder_recovered.cpp`, `fm_primary_packetnext_recovered.cpp`, `fm_primary_packetorder_recovered_00172368.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00152ab8: 27bdfff0  addiu	sp,sp,-16
00152abc: ac8801b8  sw	t0,440(a0)
00152ac0: ffbf0000  sd	ra,0(sp)
00152ac4: 0080782d  move	t7,a0
00152ac8: ac8a01c0  sw	t2,448(a0)
00152acc: 0160402d  move	t0,t3
00152ad0: ac8901bc  sw	t1,444(a0)
00152ad4: 2405006c  li	a1,108
00152ad8: ade601b4  sw	a2,436(t7)
00152adc: dfbf0000  ld	ra,0(sp)
00152ae0: 08054942  j	0x152508
00152ae4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00152ab8(void)`

```c
void FUN_00152ab8(int param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined8 param_8)

{
  *(undefined4 *)(param_1 + 0x1b8) = param_5;
  *(undefined4 *)(param_1 + 0x1c0) = param_7;
  *(undefined4 *)(param_1 + 0x1bc) = param_6;
  *(undefined4 *)(param_1 + 0x1b4) = param_3;
  FUN_00152508(param_1,0x6c,param_3,param_4,param_8);
  return;
}
```

## Earlier attempts (newest first)

- none found
