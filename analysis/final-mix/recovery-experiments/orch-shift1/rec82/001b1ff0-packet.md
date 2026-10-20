# Target packet 001b1ff0

- Range: `001b1ff0`..`001b2028`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b1ff0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b1ff0: 240fffff  li	t7,-1
001b1ff4: 108f000a  beq	a0,t7,0x1b2020
001b1ff8: 0000102d  move	v0,zero
001b1ffc: 3c0c01d4  lui	t4,0x1d4
001b2000: 3c0f0035  lui	t7,0x35
001b2004: 8d8e4400  lw	t6,17408(t4)   ; = D_01d44400
001b2008: 240d0002  li	t5,2
001b200c: aded0f18  sw	t5,3864(t7)   ; = D_00350f18
001b2010: 25ce0001  addiu	t6,t6,1
001b2014: 3c0f01d4  lui	t7,0x1d4
001b2018: ad8e4400  sw	t6,17408(t4)   ; = D_01d44400
001b201c: 25e24440  addiu	v0,t7,17472   ; = D_01d44440
001b2020: 03e00008  jr	ra
001b2024: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b1ff0(void)`

```c
undefined * FUN_001b1ff0(int param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 != -1) {
    DAT_00350f18 = 2;
    DAT_01d44400 = DAT_01d44400 + 1;
    puVar1 = &DAT_01d44440;
  }
  return puVar1;
}
```

## Earlier attempts (newest first)

- none found
