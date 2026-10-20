# Target packet 0020ebd8

- Range: `0020ebd8`..`0020ec18`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_0020ebd8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0020ebd8: 3c0b0036  lui	t3,0x36
0020ebdc: 8d6c9780  lw	t4,-26752(t3)   ; = D_00359780
0020ebe0: 1980000b  blez	t4,0x20ec10
0020ebe4: 000c7080  sll	t6,t4,0x2
0020ebe8: 3c0f0036  lui	t7,0x36
0020ebec: 25ef9788  addiu	t7,t7,-26744   ; = D_00359788
0020ebf0: 01cf7821  addu	t7,t6,t7
0020ebf4: 8dedfffc  lw	t5,-4(t7)
0020ebf8: 8dee0000  lw	t6,0(t7)
0020ebfc: 01cd7023  subu	t6,t6,t5
0020ec00: 15c40003  bne	t6,a0,0x20ec10
0020ec04: 258fffff  addiu	t7,t4,-1
0020ec08: 03e00008  jr	ra
0020ec0c: ad6f9780  sw	t7,-26752(t3)   ; = D_00359780
0020ec10: 03e00008  jr	ra
0020ec14: ac000000  sw	zero,0(zero)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0020ebd8(void)`

```c
void FUN_0020ebd8(int param_1)

{
  undefined4 *in_zero_lo;
  
  if ((0 < DAT_00359780) &&
     ((&DAT_00359788)[DAT_00359780] - *(int *)(&DAT_00359784 + DAT_00359780 * 4) == param_1)) {
    DAT_00359780 = DAT_00359780 + -1;
    return;
  }
  *in_zero_lo = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
