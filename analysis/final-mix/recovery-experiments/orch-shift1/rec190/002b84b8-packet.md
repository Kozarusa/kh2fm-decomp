# Target packet 002b84b8

- Range: `002b84b8`..`002b8534`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b84b8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `003094b8` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b84b8: 27bdffd0  addiu	sp,sp,-48
002b84bc: ffbe0020  sd	s8,32(sp)
002b84c0: ffbf0028  sd	ra,40(sp)
002b84c4: 03a0f02d  move	s8,sp
002b84c8: 00000000  nop
002b84cc: afa00000  sw	zero,0(sp)
002b84d0: 3c0401e2  lui	a0,0x1e2
002b84d4: 24842040  addiu	a0,a0,8256   ; = D_01e22040
002b84d8: 24050004  li	a1,4
002b84dc: 0000302d  move	a2,zero
002b84e0: 3c0701e2  lui	a3,0x1e2
002b84e4: 24e71f40  addiu	a3,a3,8000   ; = D_01e21f40
002b84e8: 24080100  li	t0,256
002b84ec: 3c0901e2  lui	t1,0x1e2
002b84f0: 25291f40  addiu	t1,t1,8000   ; = D_01e21f40
002b84f4: 240a0100  li	t2,256
002b84f8: 0c0c252e  jal	0x3094b8
002b84fc: 0000582d  move	t3,zero
002b8500: 0040782d  move	t7,v0
002b8504: afcf0010  sw	t7,16(s8)
002b8508: 8fcf0010  lw	t7,16(s8)
002b850c: 15e0ffef  bnez	t7,0x2b84cc
002b8510: 00000000  nop
002b8514: 3c0f01e2  lui	t7,0x1e2
002b8518: 8def1f40  lw	t7,8000(t7)   ; = D_01e21f40
002b851c: 01e0102d  move	v0,t7
002b8520: 03c0e82d  move	sp,s8
002b8524: dfbe0020  ld	s8,32(sp)
002b8528: dfbf0028  ld	ra,40(sp)
002b852c: 03e00008  jr	ra
002b8530: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b84b8(void)`

```c
undefined4 FUN_002b84b8(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_003094b8(0x1e22040,4,0,0x1e21f40,0x100,0x1e21f40,0x100,0);
  } while (iVar1 != 0);
  return DAT_01e21f40;
}
```

## Earlier attempts (newest first)

- none found
