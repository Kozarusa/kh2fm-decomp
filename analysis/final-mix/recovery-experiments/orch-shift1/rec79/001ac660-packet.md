# Target packet 001ac660

- Range: `001ac660`..`001ac6a0`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ac660`
- Registry names for this address: `func_001ac660`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00105110` registry: `_ZN4AREA4FreeEPv`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_orchbu_recovered_001a4060.cpp`
- `0031fe00` registry: `func_0031fe00`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ac660: 27bdfff0  addiu	sp,sp,-16
001ac664: 3c0f0035  lui	t7,0x35
001ac668: ffb00000  sd	s0,0(sp)
001ac66c: 25ef0c50  addiu	t7,t7,3152   ; = D_00350c50
001ac670: ac8f0000  sw	t7,0(a0)
001ac674: 0080802d  move	s0,a0
001ac678: ffbf0008  sd	ra,8(sp)
001ac67c: 3c0401c7  lui	a0,0x1c7
001ac680: 0200282d  move	a1,s0
001ac684: 0c0c7f80  jal	0x31fe00
001ac688: 2484ced0  addiu	a0,a0,-12592   ; = D_01c6ced0
001ac68c: 0200202d  move	a0,s0
001ac690: dfbf0008  ld	ra,8(sp)
001ac694: dfb00000  ld	s0,0(sp)
001ac698: 08041444  j	0x105110
001ac69c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ac660(void)`

```c
void FUN_001ac660(undefined8 param_1)

{
  *(undefined4 *)param_1 = &PTR_LAB_00350c50;
  FUN_0031fe00(0x1c6ced0,param_1);
  FUN_00105110(param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
