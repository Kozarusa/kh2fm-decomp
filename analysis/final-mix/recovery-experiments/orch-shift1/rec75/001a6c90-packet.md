# Target packet 001a6c90

- Range: `001a6c90`..`001a6cd0`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a6c90`
- Registry names for this address: `func_001a6c90`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d59b0` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a6c90: 27bdfff0  addiu	sp,sp,-16
001a6c94: 00046942  srl	t5,a0,0x5
001a6c98: 3c0f0033  lui	t7,0x33
001a6c9c: ffbf0000  sd	ra,0(sp)
001a6ca0: 25efdec0  addiu	t7,t7,-8512   ; = D_0032dec0
001a6ca4: 000d6880  sll	t5,t5,0x2
001a6ca8: 01af6821  addu	t5,t5,t7
001a6cac: dfbf0000  ld	ra,0(sp)
001a6cb0: 8dae0000  lw	t6,0(t5)
001a6cb4: 3084001f  andi	a0,a0,0x1f
001a6cb8: 240f0001  li	t7,1
001a6cbc: 008f7804  sllv	t7,t7,a0
001a6cc0: 01cf7025  or	t6,t6,t7
001a6cc4: adae0000  sw	t6,0(t5)
001a6cc8: 0807566c  j	0x1d59b0
001a6ccc: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a6c90(void)`

```c
void FUN_001a6c90(uint param_1)

{
  *(uint *)(&DAT_0032dec0 + (param_1 >> 5) * 4) =
       *(uint *)(&DAT_0032dec0 + (param_1 >> 5) * 4) | 1 << (param_1 & 0x1f);
  FUN_001d59b0();
  return;
}
```

## Earlier attempts (newest first)

- none found
