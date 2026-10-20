# Target packet 001e35f0

- Range: `001e35f0`..`001e3650`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e35f0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e35f0: 908e00a8  lbu	t6,168(a0)
001e35f4: 2dcf000d  sltiu	t7,t6,13
001e35f8: 11e00011  beqz	t7,0x1e3640
001e35fc: 000e7880  sll	t7,t6,0x2
001e3600: 3c0e0037  lui	t6,0x37
001e3604: 25ceeb28  addiu	t6,t6,-5336   ; = D_0036eb28
001e3608: 01ee7821  addu	t7,t7,t6
001e360c: 8ded0000  lw	t5,0(t7)
001e3610: 01a00008  jr	t5
001e3614: 00000000  nop
001e3618: 03e00008  jr	ra
001e361c: 24020001  li	v0,1
001e3620: 03e00008  jr	ra
001e3624: 24020002  li	v0,2
001e3628: 03e00008  jr	ra
001e362c: 24020003  li	v0,3
001e3630: 03e00008  jr	ra
001e3634: 24020004  li	v0,4
001e3638: 03e00008  jr	ra
001e363c: 24020005  li	v0,5
001e3640: 03e00008  jr	ra
001e3644: 0000102d  move	v0,zero
001e3648: 03e00008  jr	ra
001e364c: 24020006  li	v0,6
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e35f0(void)`

```c
undefined4 FUN_001e35f0(int param_1)

{
  switch(*(undefined1 *)(param_1 + 0xa8)) {
  default:
    return 0;
  case 2:
    return 1;
  case 4:
    return 2;
  case 6:
    return 3;
  case 8:
    return 4;
  case 10:
    return 5;
  case 0xc:
    return 6;
  }
}
```

## Earlier attempts (newest first)

- none found
