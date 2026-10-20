# Target packet 001b58b8

- Range: `001b58b8`..`001b58ec`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b58b8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016cfa0` registry: `func_0016cfa0`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b58b8: 27bdfff0  addiu	sp,sp,-16
001b58bc: 3c0f01d5  lui	t7,0x1d5
001b58c0: ffbf0000  sd	ra,0(sp)
001b58c4: 0080682d  move	t5,a0
001b58c8: 8dee8cb0  lw	t6,-29520(t7)   ; = D_01d48cb0
001b58cc: 00a0382d  move	a3,a1
001b58d0: 00c0402d  move	t0,a2
001b58d4: dfbf0000  ld	ra,0(sp)
001b58d8: 8dc40034  lw	a0,52(t6)
001b58dc: 01a0302d  move	a2,t5
001b58e0: 0000282d  move	a1,zero
001b58e4: 0805b3e8  j	0x16cfa0
001b58e8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b58b8(void)`

```c
void FUN_001b58b8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_0016cfa0(*(undefined4 *)(DAT_01d48cb0 + 0x34),0,param_1,param_2,param_3);
  return;
}
```

## Earlier attempts (newest first)

- none found
