# Target packet 0013d1d0

- Range: `0013d1d0`..`0013d208`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_0013d1d0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139598` registry: `_ZN2dk5Obj2D9localHideEv`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0013d1d0: 27bdfff0  addiu	sp,sp,-16
0013d1d4: ffbf0000  sd	ra,0(sp)
0013d1d8: 8c8f029c  lw	t7,668(a0)
0013d1dc: 11e00008  beqz	t7,0x13d200
0013d1e0: dfbf0000  ld	ra,0(sp)
0013d1e4: 8def0020  lw	t7,32(t7)
0013d1e8: 31ef0008  andi	t7,t7,0x8
0013d1ec: 11e00004  beqz	t7,0x13d200
0013d1f0: 24840104  addiu	a0,a0,260
0013d1f4: 0804e566  j	0x139598
0013d1f8: 27bd0010  addiu	sp,sp,16
0013d1fc: 00000000  nop
0013d200: 03e00008  jr	ra
0013d204: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0013d1d0(void)`

```c
void FUN_0013d1d0(int param_1)

{
  if ((*(int *)(param_1 + 0x29c) != 0) && ((*(uint *)(*(int *)(param_1 + 0x29c) + 0x20) & 8) != 0))
  {
    FUN_00139598(param_1 + 0x104);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
