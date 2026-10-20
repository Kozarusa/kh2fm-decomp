# Target packet 002adf60

- Range: `002adf60`..`002adfcc`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_002adf60`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002adf60: 3c0f0036  lui	t7,0x36
002adf64: 24020001  li	v0,1
002adf68: 8deef620  lw	t6,-2528(t7)   ; = D_0035f620
002adf6c: 0000602d  move	t4,zero
002adf70: 240a0001  li	t2,1
002adf74: 25cb0140  addiu	t3,t6,320
002adf78: 04800004  bltz	a0,0x2adf8c
002adf7c: 000c7942  srl	t7,t4,0x5
002adf80: 548c000d  bnel	a0,t4,0x2adfb8
002adf84: 258c0001  addiu	t4,t4,1
002adf88: 000c7942  srl	t7,t4,0x5
002adf8c: 318d001f  andi	t5,t4,0x1f
002adf90: 000f7880  sll	t7,t7,0x2
002adf94: 01aa6804  sllv	t5,t2,t5
002adf98: 01eb7821  addu	t7,t7,t3
002adf9c: 8dee0000  lw	t6,0(t7)
002adfa0: 01cd7024  and	t6,t6,t5
002adfa4: 55c00004  bnezl	t6,0x2adfb8
002adfa8: 258c0001  addiu	t4,t4,1
002adfac: 03e00008  jr	ra
002adfb0: 0000102d  move	v0,zero
002adfb4: 00000000  nop
002adfb8: 298f0004  slti	t7,t4,4
002adfbc: 15e0ffee  bnez	t7,0x2adf78
002adfc0: 00000000  nop
002adfc4: 03e00008  jr	ra
002adfc8: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002adf60(void)`

```c
undefined4 FUN_002adf60(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((-1 < (int)param_1 && (param_1 != uVar1)) ||
         ((*(uint *)((uVar1 >> 5) * 4 + DAT_0035f620 + 0x140) & 1 << (uVar1 & 0x1f)) != 0))) {
    uVar1 = uVar1 + 1;
    if (3 < (int)uVar1) {
      return 1;
    }
  }
  return 0;
}
```

## Earlier attempts (newest first)

- none found
