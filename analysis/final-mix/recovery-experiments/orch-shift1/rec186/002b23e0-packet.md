# Target packet 002b23e0

- Range: `002b23e0`..`002b2428`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b23e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00276608` registry: `_ZN2Tz6Jiminy9GetCurPosEi`
- `002b2338` registry: `func_002b2338`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b23e0: 27bdfff0  addiu	sp,sp,-16
002b23e4: 0080102d  move	v0,a0
002b23e8: ffbf0000  sd	ra,0(sp)
002b23ec: 04410003  bgez	v0,0x2b23fc
002b23f0: 2404001c  li	a0,28
002b23f4: 0c09d982  jal	0x276608
002b23f8: 00000000  nop
002b23fc: 0c0ac8ce  jal	0x2b2338
002b2400: 0040202d  move	a0,v0
002b2404: 0040682d  move	t5,v0
002b2408: dfbf0000  ld	ra,0(sp)
002b240c: 240e0024  li	t6,36
002b2410: 3c0f0036  lui	t7,0x36
002b2414: 01ae6818  mult	t5,t5,t6
002b2418: 8de2f630  lw	v0,-2512(t7)   ; = D_0035f630
002b241c: 004d1021  addu	v0,v0,t5
002b2420: 03e00008  jr	ra
002b2424: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b23e0(void)`

```c
int FUN_002b23e0(long param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = FUN_00276608(0x1c);
  }
  iVar1 = FUN_002b2338(param_1);
  return DAT_0035f630 + iVar1 * 0x24;
}
```

## Earlier attempts (newest first)

- none found
