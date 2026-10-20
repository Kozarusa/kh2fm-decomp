# Target packet 0015eaf8

- Range: `0015eaf8`..`0015eb68`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015eaf8`
- Registry names for this address: `_Z16wtarget_0015eaf8jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0014c050` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015eaf8: 27bdffe0  addiu	sp,sp,-32
0015eafc: 340fffff  li	t7,0xffff
0015eb00: ffb00000  sd	s0,0(sp)
0015eb04: ffb10008  sd	s1,8(sp)
0015eb08: ffbf0010  sd	ra,16(sp)
0015eb0c: 00a0802d  move	s0,a1
0015eb10: 14af0008  bne	a1,t7,0x15eb34
0015eb14: 0080882d  move	s1,a0
0015eb18: 240f0001  li	t7,1
0015eb1c: 148f0005  bne	a0,t7,0x15eb34
0015eb20: 340fffff  li	t7,0xffff
0015eb24: 3c04004f  lui	a0,0x4f
0015eb28: 0c053014  jal	0x14c050
0015eb2c: 24843820  addiu	a0,a0,14368   ; = D_004f3820
0015eb30: 340fffff  li	t7,0xffff
0015eb34: 160f0008  bne	s0,t7,0x15eb58
0015eb38: dfb00000  ld	s0,0(sp)
0015eb3c: 16200007  bnez	s1,0x15eb5c
0015eb40: dfb10008  ld	s1,8(sp)
0015eb44: 3c0f0035  lui	t7,0x35
0015eb48: 3c0e004f  lui	t6,0x4f
0015eb4c: 25ef8698  addiu	t7,t7,-31080   ; = D_00348698
0015eb50: adcf3820  sw	t7,14368(t6)   ; = D_004f3820
0015eb54: dfb00000  ld	s0,0(sp)
0015eb58: dfb10008  ld	s1,8(sp)
0015eb5c: dfbf0010  ld	ra,16(sp)
0015eb60: 03e00008  jr	ra
0015eb64: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015eaf8(void)`

```c
void FUN_0015eaf8(int param_1,long param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    FUN_0014c050(0x4f3820);
  }
  if ((param_2 == 0xffff) && (param_1 == 0)) {
    DAT_004f3820 = &PTR_LAB_00348698;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
