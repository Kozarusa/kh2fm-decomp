# Target packet 001e03b0

- Range: `001e03b0`..`001e0400`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e03b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e03d8` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e03b0: 27bdfff0  addiu	sp,sp,-16
001e03b4: ffbf0000  sd	ra,0(sp)
001e03b8: dfbf0000  ld	ra,0(sp)
001e03bc: 080780f6  j	0x1e03d8
001e03c0: 27bd0010  addiu	sp,sp,16
001e03c4: 00000000  nop
001e03c8: 03e00008  jr	ra
001e03cc: 00000000  nop
001e03d0: 03e00008  jr	ra
001e03d4: 00000000  nop
001e03d8: ac800020  sw	zero,32(a0)
001e03dc: ac800000  sw	zero,0(a0)
001e03e0: ac800008  sw	zero,8(a0)
001e03e4: ac800004  sw	zero,4(a0)
001e03e8: ac800010  sw	zero,16(a0)
001e03ec: ac80000c  sw	zero,12(a0)
001e03f0: ac800014  sw	zero,20(a0)
001e03f4: ac800018  sw	zero,24(a0)
001e03f8: 03e00008  jr	ra
001e03fc: ac80001c  sw	zero,28(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e03b0(void)`

```c
void FUN_001e03b0(undefined4 *param_1)

{
  param_1[8] = 0;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
