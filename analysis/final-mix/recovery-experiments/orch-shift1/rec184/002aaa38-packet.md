# Target packet 002aaa38

- Range: `002aaa38`..`002aaab8`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_002aaa38`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002aaa38: 04810014  bgez	a0,0x2aaa8c
002aaa3c: 3c0f0036  lui	t7,0x36
002aaa40: 0000602d  move	t4,zero
002aaa44: 8deef610  lw	t6,-2544(t7)   ; = D_0035f610
002aaa48: 240a0001  li	t2,1
002aaa4c: 25cb0084  addiu	t3,t6,132
002aaa50: 000c7942  srl	t7,t4,0x5
002aaa54: 318d001f  andi	t5,t4,0x1f
002aaa58: 000f7880  sll	t7,t7,0x2
002aaa5c: 01aa6804  sllv	t5,t2,t5
002aaa60: 01eb7821  addu	t7,t7,t3
002aaa64: 258c0001  addiu	t4,t4,1
002aaa68: 8dee0000  lw	t6,0(t7)
002aaa6c: 01cd7024  and	t6,t6,t5
002aaa70: 000e102b  sltu	v0,zero,t6
002aaa74: 14400003  bnez	v0,0x2aaa84
002aaa78: 298f0020  slti	t7,t4,32
002aaa7c: 55e0fff5  bnezl	t7,0x2aaa54
002aaa80: 000c7942  srl	t7,t4,0x5
002aaa84: 03e00008  jr	ra
002aaa88: 00000000  nop
002aaa8c: 00046942  srl	t5,a0,0x5
002aaa90: 8decf610  lw	t4,-2544(t7)
002aaa94: 000d6880  sll	t5,t5,0x2
002aaa98: 308b001f  andi	t3,a0,0x1f
002aaa9c: 240e0001  li	t6,1
002aaaa0: 018d6021  addu	t4,t4,t5
002aaaa4: 016e7004  sllv	t6,t6,t3
002aaaa8: 8d8f0084  lw	t7,132(t4)
002aaaac: 01ee7824  and	t7,t7,t6
002aaab0: 03e00008  jr	ra
002aaab4: 000f102b  sltu	v0,zero,t7
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002aaa38(void)`

```c
bool FUN_002aaa38(long param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 < 0) {
    uVar2 = 0;
    uVar4 = 0;
    while( true ) {
      uVar3 = uVar2 & 0x1f;
      uVar2 = uVar2 + 1;
      bVar1 = (*(uint *)(uVar4 * 4 + DAT_0035f610 + 0x84) & 1 << uVar3) != 0;
      if ((bVar1) || (0x1f < (int)uVar2)) break;
      uVar4 = uVar2 >> 5;
    }
    return bVar1;
  }
  return (*(uint *)(DAT_0035f610 + ((uint)param_1 >> 5) * 4 + 0x84) & 1 << ((uint)param_1 & 0x1f))
         != 0;
}
```

## Earlier attempts (newest first)

- none found
