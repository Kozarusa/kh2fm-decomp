# Target packet 001d1f38

- Range: `001d1f38`..`001d1fa8`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d1f38`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d1678` registry: `func_001d1678`
  - accepted sources that already call it (copy their declaration): `fm_fallback_helpers.cpp`
- `001d16e8` registry: `_ZN2YS9MISSION2D9set_imageEN2dk9INFO_BASE5ALIGNEi`
- `001d19e8` registry: `_ZN2YS13MISSION_COUNT4initEi`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d1f38: 27bdfff0  addiu	sp,sp,-16
001d1f3c: ac800004  sw	zero,4(a0)
001d1f40: 3c0f0035  lui	t7,0x35
001d1f44: ffb00000  sd	s0,0(sp)
001d1f48: 25ef25c8  addiu	t7,t7,9672   ; = D_003525c8
001d1f4c: ffbf0008  sd	ra,8(sp)
001d1f50: ac8f0000  sw	t7,0(a0)
001d1f54: 0080802d  move	s0,a0
001d1f58: ac800008  sw	zero,8(a0)
001d1f5c: 2405ffff  li	a1,-1
001d1f60: 0c07459e  jal	0x1d1678
001d1f64: ac80000c  sw	zero,12(a0)
001d1f68: 3c0f0035  lui	t7,0x35
001d1f6c: ae000030  sw	zero,48(s0)
001d1f70: 25ef25e8  addiu	t7,t7,9704   ; = D_003525e8
001d1f74: 0200202d  move	a0,s0
001d1f78: ae0f0000  sw	t7,0(s0)
001d1f7c: 0c07467a  jal	0x1d19e8
001d1f80: 2405ffff  li	a1,-1
001d1f84: ae00002c  sw	zero,44(s0)
001d1f88: 0200202d  move	a0,s0
001d1f8c: ae000038  sw	zero,56(s0)
001d1f90: 0000282d  move	a1,zero
001d1f94: dfbf0008  ld	ra,8(sp)
001d1f98: 2406000c  li	a2,12
001d1f9c: dfb00000  ld	s0,0(sp)
001d1fa0: 080745ba  j	0x1d16e8
001d1fa4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d1f38(void)`

```c
void FUN_001d1f38(undefined8 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  puVar1[1] = 0;
  *puVar1 = &PTR_FUN_003525c8;
  puVar1[2] = 0;
  puVar1[3] = 0;
  FUN_001d1678(param_1,0xffffffffffffffff);
  puVar1[0xc] = 0;
  *puVar1 = &PTR_FUN_003525e8;
  FUN_001d19e8(param_1,0xffffffffffffffff);
  puVar1[0xb] = 0;
  puVar1[0xe] = 0;
  FUN_001d16e8(param_1,0,0xc);
  return;
}
```

## Earlier attempts (newest first)

- none found
