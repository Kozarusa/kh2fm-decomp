# Target packet 0023fcd0

- Range: `0023fcd0`..`0023fd30`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_0023fcd0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002fdd68` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0023fcd0: 27bdffe0  addiu	sp,sp,-32
0023fcd4: 3c0e0036  lui	t6,0x36
0023fcd8: ffb10008  sd	s1,8(sp)
0023fcdc: ffbf0010  sd	ra,16(sp)
0023fce0: ffb00000  sd	s0,0(sp)
0023fce4: 3c110036  lui	s1,0x36
0023fce8: 8e2febec  lw	t7,-5140(s1)   ; = D_0035ebec
0023fcec: 8dd0ebf0  lw	s0,-5136(t6)   ; = D_0035ebf0
0023fcf0: 000f78c0  sll	t7,t7,0x3
0023fcf4: 020f8021  addu	s0,s0,t7
0023fcf8: 8e05fff8  lw	a1,-8(s0)
0023fcfc: 0c0bf75a  jal	0x2fdd68
0023fd00: 8e06fffc  lw	a2,-4(s0)
0023fd04: 8e2eebec  lw	t6,-5140(s1)   ; = D_0035ebec
0023fd08: 3c0f0036  lui	t7,0x36
0023fd0c: 8e0dfff8  lw	t5,-8(s0)
0023fd10: 25ceffff  addiu	t6,t6,-1
0023fd14: dfbf0010  ld	ra,16(sp)
0023fd18: ae2eebec  sw	t6,-5140(s1)   ; = D_0035ebec
0023fd1c: adedebe8  sw	t5,-5144(t7)   ; = D_0035ebe8
0023fd20: dfb00000  ld	s0,0(sp)
0023fd24: dfb10008  ld	s1,8(sp)
0023fd28: 03e00008  jr	ra
0023fd2c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0023fcd0(void)`

```c
void FUN_0023fcd0(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = DAT_0035ebf0 + DAT_0035ebec * 8;
  FUN_002fdd68(param_1,*(undefined4 *)(iVar1 + -8),*(undefined4 *)(iVar1 + -4));
  DAT_0035ebec = DAT_0035ebec + -1;
  DAT_0035ebe8 = *(undefined4 *)(iVar1 + -8);
  return;
}
```

## Earlier attempts (newest first)

- none found
