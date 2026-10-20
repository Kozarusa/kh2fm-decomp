# Target packet 0020e7a8

- Range: `0020e7a8`..`0020e7fc`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_0020e7a8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0020e7a8: 7c800000  sq	zero,0(a0)
0020e7ac: 3c0f2000  lui	t7,0x2000
0020e7b0: 24a5ffff  addiu	a1,a1,-1
0020e7b4: 00af2825  or	a1,a1,t7
0020e7b8: ac850000  sw	a1,0(a0)
0020e7bc: 0006782a  slt	t7,zero,a2
0020e7c0: 3c0e01db  lui	t6,0x1db
0020e7c4: 000f300a  movz	a2,zero,t7
0020e7c8: 25cec450  addiu	t6,t6,-15280   ; = D_01dac450
0020e7cc: 28cd0010  slti	t5,a2,16
0020e7d0: 240f000f  li	t7,15
0020e7d4: 01ed300a  movz	a2,t7,t5
0020e7d8: 00063100  sll	a2,a2,0x4
0020e7dc: 00ce7021  addu	t6,a2,t6
0020e7e0: 8dcf0008  lw	t7,8(t6)
0020e7e4: 8ded0004  lw	t5,4(t7)
0020e7e8: ade40004  sw	a0,4(t7)
0020e7ec: ac8d0004  sw	t5,4(a0)
0020e7f0: adc40008  sw	a0,8(t6)
0020e7f4: 03e00008  jr	ra
0020e7f8: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0020e7a8(void)`

```c
void FUN_0020e7a8(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint in_zero_lo;
  uint in_zero_hi;
  uint in_zero_udw;
  uint in_register_0000000c;
  
  *param_1 = in_zero_lo;
  param_1[1] = in_zero_hi;
  param_1[2] = in_zero_udw;
  param_1[3] = in_register_0000000c;
  *param_1 = param_2 - 1U | 0x20000000;
  if (param_3 < 1) {
    param_3 = 0;
  }
  if (0xf < param_3) {
    param_3 = 0xf;
  }
  uVar1 = *(uint *)((&DAT_01dac458)[param_3 * 4] + 4);
  *(uint **)((&DAT_01dac458)[param_3 * 4] + 4) = param_1;
  param_1[1] = uVar1;
  (&DAT_01dac458)[param_3 * 4] = param_1;
  return;
}
```

## Earlier attempts (newest first)

- none found
