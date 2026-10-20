# Target packet 002aacd8

- Range: `002aacd8`..`002aad58`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_002aacd8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002aacd8: 04810014  bgez	a0,0x2aad2c
002aacdc: 3c0f0036  lui	t7,0x36
002aace0: 0000602d  move	t4,zero
002aace4: 8deef610  lw	t6,-2544(t7)   ; = D_0035f610
002aace8: 240a0001  li	t2,1
002aacec: 25cb0094  addiu	t3,t6,148
002aacf0: 000c7942  srl	t7,t4,0x5
002aacf4: 318d001f  andi	t5,t4,0x1f
002aacf8: 000f7880  sll	t7,t7,0x2
002aacfc: 01aa6804  sllv	t5,t2,t5
002aad00: 01eb7821  addu	t7,t7,t3
002aad04: 258c0001  addiu	t4,t4,1
002aad08: 8dee0000  lw	t6,0(t7)
002aad0c: 01cd7024  and	t6,t6,t5
002aad10: 000e102b  sltu	v0,zero,t6
002aad14: 14400003  bnez	v0,0x2aad24
002aad18: 298f00c0  slti	t7,t4,192
002aad1c: 55e0fff5  bnezl	t7,0x2aacf4
002aad20: 000c7942  srl	t7,t4,0x5
002aad24: 03e00008  jr	ra
002aad28: 00000000  nop
002aad2c: 00046942  srl	t5,a0,0x5
002aad30: 8decf610  lw	t4,-2544(t7)
002aad34: 000d6880  sll	t5,t5,0x2
002aad38: 308b001f  andi	t3,a0,0x1f
002aad3c: 240e0001  li	t6,1
002aad40: 018d6021  addu	t4,t4,t5
002aad44: 016e7004  sllv	t6,t6,t3
002aad48: 8d8f0094  lw	t7,148(t4)
002aad4c: 01ee7824  and	t7,t7,t6
002aad50: 03e00008  jr	ra
002aad54: 000f102b  sltu	v0,zero,t7
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002aacd8(void)`

```c
bool FUN_002aacd8(long param_1)

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
      bVar1 = (*(uint *)(uVar4 * 4 + DAT_0035f610 + 0x94) & 1 << uVar3) != 0;
      if ((bVar1) || (0xbf < (int)uVar2)) break;
      uVar4 = uVar2 >> 5;
    }
    return bVar1;
  }
  return (*(uint *)(DAT_0035f610 + ((uint)param_1 >> 5) * 4 + 0x94) & 1 << ((uint)param_1 & 0x1f))
         != 0;
}
```

## Earlier attempts (newest first)

- none found
