# Target packet 002aa2f8

- Range: `002aa2f8`..`002aa378`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_002aa2f8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002aa2f8: 04810014  bgez	a0,0x2aa34c
002aa2fc: 3c0f0036  lui	t7,0x36
002aa300: 0000602d  move	t4,zero
002aa304: 8deef610  lw	t6,-2544(t7)   ; = D_0035f610
002aa308: 240a0001  li	t2,1
002aa30c: 25cb013c  addiu	t3,t6,316
002aa310: 000c7942  srl	t7,t4,0x5
002aa314: 318d001f  andi	t5,t4,0x1f
002aa318: 000f7880  sll	t7,t7,0x2
002aa31c: 01aa6804  sllv	t5,t2,t5
002aa320: 01eb7821  addu	t7,t7,t3
002aa324: 258c0001  addiu	t4,t4,1
002aa328: 8dee0000  lw	t6,0(t7)
002aa32c: 01cd7024  and	t6,t6,t5
002aa330: 000e102b  sltu	v0,zero,t6
002aa334: 14400003  bnez	v0,0x2aa344
002aa338: 298f000d  slti	t7,t4,13
002aa33c: 55e0fff5  bnezl	t7,0x2aa314
002aa340: 000c7942  srl	t7,t4,0x5
002aa344: 03e00008  jr	ra
002aa348: 00000000  nop
002aa34c: 00046942  srl	t5,a0,0x5
002aa350: 8decf610  lw	t4,-2544(t7)
002aa354: 000d6880  sll	t5,t5,0x2
002aa358: 308b001f  andi	t3,a0,0x1f
002aa35c: 240e0001  li	t6,1
002aa360: 018d6021  addu	t4,t4,t5
002aa364: 016e7004  sllv	t6,t6,t3
002aa368: 8d8f013c  lw	t7,316(t4)
002aa36c: 01ee7824  and	t7,t7,t6
002aa370: 03e00008  jr	ra
002aa374: 000f102b  sltu	v0,zero,t7
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002aa2f8(void)`

```c
bool FUN_002aa2f8(long param_1)

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
      bVar1 = (*(uint *)(uVar4 * 4 + DAT_0035f610 + 0x13c) & 1 << uVar3) != 0;
      if ((bVar1) || (0xc < (int)uVar2)) break;
      uVar4 = uVar2 >> 5;
    }
    return bVar1;
  }
  return (*(uint *)(DAT_0035f610 + ((uint)param_1 >> 5) * 4 + 0x13c) & 1 << ((uint)param_1 & 0x1f))
         != 0;
}
```

## Earlier attempts (newest first)

- none found
