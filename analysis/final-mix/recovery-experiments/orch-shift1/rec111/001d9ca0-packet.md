# Target packet 001d9ca0

- Range: `001d9ca0`..`001d9ce0`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d9ca0`
- Registry names for this address: `_Z16wtarget_001d9ca0jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d9a18` registry: `_Z16wtarget_001d9a18jjjj`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d9ca0: 27bdfff0  addiu	sp,sp,-16
001d9ca4: 340fffff  li	t7,0xffff
001d9ca8: ffbf0000  sd	ra,0(sp)
001d9cac: 14af000a  bne	a1,t7,0x1d9cd8
001d9cb0: dfbf0000  ld	ra,0(sp)
001d9cb4: 240f0001  li	t7,1
001d9cb8: 148f0007  bne	a0,t7,0x1d9cd8
001d9cbc: 3c0401d6  lui	a0,0x1d6
001d9cc0: dfbf0000  ld	ra,0(sp)
001d9cc4: 2405ffff  li	a1,-1
001d9cc8: 2484baa0  addiu	a0,a0,-17760   ; = D_01d5baa0
001d9ccc: 08076686  j	0x1d9a18
001d9cd0: 27bd0010  addiu	sp,sp,16
001d9cd4: 00000000  nop
001d9cd8: 03e00008  jr	ra
001d9cdc: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d9ca0(void)`

```c
void FUN_001d9ca0(int param_1,long param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    FUN_001d9a18(0x1d5baa0,0xffffffffffffffff);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
