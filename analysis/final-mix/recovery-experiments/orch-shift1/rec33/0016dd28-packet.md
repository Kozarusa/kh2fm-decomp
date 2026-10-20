# Target packet 0016dd28

- Range: `0016dd28`..`0016dda8`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016dd28`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00312db8` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016dd28: 27bdffe0  addiu	sp,sp,-32
0016dd2c: 3c0e0035  lui	t6,0x35
0016dd30: ffb00000  sd	s0,0(sp)
0016dd34: 3c0f0001  lui	t7,0x1
0016dd38: ffbf0010  sd	ra,16(sp)
0016dd3c: 35ef0dcd  ori	t7,t7,0xdcd
0016dd40: 8dd0d8a8  lw	s0,-10072(t6)   ; = D_0034d8a8
0016dd44: ffb10008  sd	s1,8(sp)
0016dd48: 020f8018  mult	s0,s0,t7
0016dd4c: 9c850000  lwu	a1,0(a0)
0016dd50: 0080882d  move	s1,a0
0016dd54: 24a4ffff  addiu	a0,a1,-1
0016dd58: add0d8a8  sw	s0,-10072(t6)   ; = D_0034d8a8
0016dd5c: 0004203c  dsll32	a0,a0,0x0
0016dd60: 240f0001  li	t7,1
0016dd64: 0004203e  dsrl32	a0,a0,0x0
0016dd68: 000f783c  dsll32	t7,t7,0x0
0016dd6c: 0010803c  dsll32	s0,s0,0x0
0016dd70: 008f202d  daddu	a0,a0,t7
0016dd74: 0c0c4b6e  jal	0x312db8
0016dd78: 0010803e  dsrl32	s0,s0,0x0
0016dd7c: 0200202d  move	a0,s0
0016dd80: 0c0c4b6e  jal	0x312db8
0016dd84: 0040282d  move	a1,v0
0016dd88: 0002103c  dsll32	v0,v0,0x0
0016dd8c: dfb00000  ld	s0,0(sp)
0016dd90: 0002103f  dsra32	v0,v0,0x0
0016dd94: dfbf0010  ld	ra,16(sp)
0016dd98: ae220000  sw	v0,0(s1)
0016dd9c: dfb10008  ld	s1,8(sp)
0016dda0: 03e00008  jr	ra
0016dda4: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016dd28(void)`

```c
void FUN_0016dd28(int *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = DAT_0034d8a8 * 0x10dcd;
  DAT_0034d8a8 = iVar1;
  uVar2 = FUN_00312db8((ulong)(*param_1 - 1) + 0x100000000);
  iVar1 = FUN_00312db8(iVar1,uVar2);
  *param_1 = iVar1;
  return;
}
```

## Earlier attempts (newest first)

- none found
