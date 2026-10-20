# Target packet 0018caf8

- Range: `0018caf8`..`0018cb30`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_0018caf8`
- Registry names for this address: `_ZNK2YS6DAMAGE9is_normalEv`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0018caf8: 908e0027  lbu	t6,39(a0)
0018cafc: 2dcf0011  sltiu	t7,t6,17
0018cb00: 11e00009  beqz	t7,0x18cb28
0018cb04: 000e7880  sll	t7,t6,0x2
0018cb08: 3c0e0037  lui	t6,0x37
0018cb0c: 25cecc74  addiu	t6,t6,-13196   ; = D_0036cc74
0018cb10: 01ee7821  addu	t7,t7,t6
0018cb14: 8ded0000  lw	t5,0(t7)
0018cb18: 01a00008  jr	t5
0018cb1c: 00000000  nop
0018cb20: 03e00008  jr	ra
0018cb24: 24020001  li	v0,1
0018cb28: 03e00008  jr	ra
0018cb2c: 0000102d  move	v0,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0018caf8(void)`

```c
undefined4 FUN_0018caf8(int param_1)

{
  switch(*(undefined1 *)(param_1 + 0x27)) {
  case 0:
  case 1:
  case 3:
  case 4:
  case 6:
  case 7:
  case 0xf:
  case 0x10:
    return 1;
  default:
    return 0;
  }
}
```

## Earlier attempts (newest first)

- none found
