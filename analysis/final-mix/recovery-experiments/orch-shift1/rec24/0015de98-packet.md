# Target packet 0015de98

- Range: `0015de98`..`0015def4`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015de98`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0031dd50` registry: `func_0031dd50`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015de98: 27bdfff0  addiu	sp,sp,-16
0015de9c: 3c0f0035  lui	t7,0x35
0015dea0: ffbf0008  sd	ra,8(sp)
0015dea4: 03e0302d  move	a2,ra
0015dea8: ffb00000  sd	s0,0(sp)
0015deac: 8de4b278  lw	a0,-19848(t7)   ; = D_0034b278
0015deb0: 8c8f0000  lw	t7,0(a0)
0015deb4: 8de20000  lw	v0,0(t7)
0015deb8: 0040f809  jalr	v0
0015debc: 24051340  li	a1,4928
0015dec0: 0040802d  move	s0,v0
0015dec4: 0c0c7754  jal	0x31dd50
0015dec8: 0040202d  move	a0,v0
0015decc: 3c0f0035  lui	t7,0x35
0015ded0: adf0b240  sw	s0,-19904(t7)   ; = D_0034b240
0015ded4: 8e0f0000  lw	t7,0(s0)
0015ded8: 8dee0000  lw	t6,0(t7)
0015dedc: 01c0f809  jalr	t6
0015dee0: 0200202d  move	a0,s0
0015dee4: dfb00000  ld	s0,0(sp)
0015dee8: dfbf0008  ld	ra,8(sp)
0015deec: 03e00008  jr	ra
0015def0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015de98(void)`

```c
void FUN_0015de98(void)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)*DAT_0034b278)(DAT_0034b278,0x1340);
  FUN_0031dd50(uVar1);
  DAT_0034b240 = (undefined4 *)uVar1;
  (**(code **)*DAT_0034b240)(uVar1);
  return;
}
```

## Earlier attempts (newest first)

- none found
