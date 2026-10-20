# Target packet 0015def8

- Range: `0015def8`..`0015df68`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015def8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0031dd50` registry: `func_0031dd50`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015def8: 27bdffe0  addiu	sp,sp,-32
0015defc: 3c0f0035  lui	t7,0x35
0015df00: ffbf0010  sd	ra,16(sp)
0015df04: 03e0302d  move	a2,ra
0015df08: ffb00000  sd	s0,0(sp)
0015df0c: 24051340  li	a1,4928
0015df10: ffb10008  sd	s1,8(sp)
0015df14: 8de4b278  lw	a0,-19848(t7)   ; = D_0034b278
0015df18: 8c8f0000  lw	t7,0(a0)
0015df1c: 8de20000  lw	v0,0(t7)
0015df20: 0040f809  jalr	v0
0015df24: 3c110035  lui	s1,0x35
0015df28: 0040802d  move	s0,v0
0015df2c: 0c0c7754  jal	0x31dd50
0015df30: 0040202d  move	a0,v0
0015df34: ae30b244  sw	s0,-19900(s1)   ; = D_0034b244
0015df38: 8e0f0000  lw	t7,0(s0)
0015df3c: 8dee0000  lw	t6,0(t7)
0015df40: 01c0f809  jalr	t6
0015df44: 0200202d  move	a0,s0
0015df48: 8e2db244  lw	t5,-19900(s1)   ; = D_0034b244
0015df4c: 240f0001  li	t7,1
0015df50: dfb00000  ld	s0,0(sp)
0015df54: a1af0004  sb	t7,4(t5)
0015df58: dfb10008  ld	s1,8(sp)
0015df5c: dfbf0010  ld	ra,16(sp)
0015df60: 03e00008  jr	ra
0015df64: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015def8(void)`

```c
void FUN_0015def8(void)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)*DAT_0034b278)(DAT_0034b278,0x1340);
  FUN_0031dd50(uVar1);
  DAT_0034b244 = (undefined4 *)uVar1;
  (**(code **)*DAT_0034b244)(uVar1);
  *(undefined1 *)(DAT_0034b244 + 1) = 1;
  return;
}
```

## Earlier attempts (newest first)

- none found
