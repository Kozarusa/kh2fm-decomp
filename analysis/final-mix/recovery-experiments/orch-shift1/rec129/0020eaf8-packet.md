# Target packet 0020eaf8

- Range: `0020eaf8`..`0020eb6c`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_0020eaf8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0020eaf8: 3c0a0036  lui	t2,0x36
0020eafc: 8d4b9780  lw	t3,-26752(t2)   ; = D_00359780
0020eb00: 296f001f  slti	t7,t3,31
0020eb04: 11e00016  beqz	t7,0x20eb60
0020eb08: 000b6080  sll	t4,t3,0x2
0020eb0c: 3c0f0036  lui	t7,0x36
0020eb10: 3c0e0036  lui	t6,0x36
0020eb14: 8ded9808  lw	t5,-26616(t7)   ; = D_00359808
0020eb18: 25c99788  addiu	t1,t6,-26744   ; = D_00359788
0020eb1c: 01896021  addu	t4,t4,t1
0020eb20: 3c0f0036  lui	t7,0x36
0020eb24: 8d8e0000  lw	t6,0(t4)
0020eb28: 25ef9810  addiu	t7,t7,-26608   ; = D_00359810
0020eb2c: 000d6880  sll	t5,t5,0x2
0020eb30: 01af6821  addu	t5,t5,t7
0020eb34: 01c42021  addu	a0,t6,a0
0020eb38: 8daf0000  lw	t7,0(t5)
0020eb3c: 01e4782a  slt	t7,t7,a0
0020eb40: 15e00007  bnez	t7,0x20eb60
0020eb44: 01c0102d  move	v0,t6
0020eb48: 256b0001  addiu	t3,t3,1
0020eb4c: 000b7880  sll	t7,t3,0x2
0020eb50: ad4b9780  sw	t3,-26752(t2)   ; = D_00359780
0020eb54: 01e97821  addu	t7,t7,t1
0020eb58: 03e00008  jr	ra
0020eb5c: ade40000  sw	a0,0(t7)
0020eb60: ac000000  sw	zero,0(zero)
0020eb64: 03e00008  jr	ra
0020eb68: 0000102d  move	v0,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0020eaf8(void)`

```c
int FUN_0020eaf8(int param_1)

{
  undefined4 *in_zero_lo;
  int *piVar1;
  
  if (DAT_00359780 < 0x1f) {
    piVar1 = &DAT_00359788 + DAT_00359780;
    param_1 = *piVar1 + param_1;
    if (param_1 <= (int)(&DAT_00359810)[DAT_00359808]) {
      DAT_00359780 = DAT_00359780 + 1;
      (&DAT_00359788)[DAT_00359780] = param_1;
      return *piVar1;
    }
  }
  *in_zero_lo = 0;
  return 0;
}
```

## Earlier attempts (newest first)

- none found
