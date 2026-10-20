# Target packet 002ab100

- Range: `002ab100`..`002ab180`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_002ab100`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002ab100: 04810014  bgez	a0,0x2ab154
002ab104: 3c0f0036  lui	t7,0x36
002ab108: 0000602d  move	t4,zero
002ab10c: 8deef610  lw	t6,-2544(t7)   ; = D_0035f610
002ab110: 240a0001  li	t2,1
002ab114: 25cb0088  addiu	t3,t6,136
002ab118: 000c7942  srl	t7,t4,0x5
002ab11c: 318d001f  andi	t5,t4,0x1f
002ab120: 000f7880  sll	t7,t7,0x2
002ab124: 01aa6804  sllv	t5,t2,t5
002ab128: 01eb7821  addu	t7,t7,t3
002ab12c: 258c0001  addiu	t4,t4,1
002ab130: 8dee0000  lw	t6,0(t7)
002ab134: 01cd7024  and	t6,t6,t5
002ab138: 000e102b  sltu	v0,zero,t6
002ab13c: 14400003  bnez	v0,0x2ab14c
002ab140: 298f0060  slti	t7,t4,96
002ab144: 55e0fff5  bnezl	t7,0x2ab11c
002ab148: 000c7942  srl	t7,t4,0x5
002ab14c: 03e00008  jr	ra
002ab150: 00000000  nop
002ab154: 00046942  srl	t5,a0,0x5
002ab158: 8decf610  lw	t4,-2544(t7)
002ab15c: 000d6880  sll	t5,t5,0x2
002ab160: 308b001f  andi	t3,a0,0x1f
002ab164: 240e0001  li	t6,1
002ab168: 018d6021  addu	t4,t4,t5
002ab16c: 016e7004  sllv	t6,t6,t3
002ab170: 8d8f0088  lw	t7,136(t4)
002ab174: 01ee7824  and	t7,t7,t6
002ab178: 03e00008  jr	ra
002ab17c: 000f102b  sltu	v0,zero,t7
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002ab100(void)`

```c
bool FUN_002ab100(long param_1)

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
      bVar1 = (*(uint *)(uVar4 * 4 + DAT_0035f610 + 0x88) & 1 << uVar3) != 0;
      if ((bVar1) || (0x5f < (int)uVar2)) break;
      uVar4 = uVar2 >> 5;
    }
    return bVar1;
  }
  return (*(uint *)(DAT_0035f610 + ((uint)param_1 >> 5) * 4 + 0x88) & 1 << ((uint)param_1 & 0x1f))
         != 0;
}
```

## Earlier attempts (newest first)

- none found
