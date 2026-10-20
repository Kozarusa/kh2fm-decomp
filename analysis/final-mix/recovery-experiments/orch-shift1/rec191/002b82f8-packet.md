# Target packet 002b82f8

- Range: `002b82f8`..`002b8374`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b82f8`
- Registry names for this address: `func_002b82f8(void*)`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `003094b8` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b82f8: 27bdffd0  addiu	sp,sp,-48
002b82fc: ffbe0020  sd	s8,32(sp)
002b8300: ffbf0028  sd	ra,40(sp)
002b8304: 03a0f02d  move	s8,sp
002b8308: 00000000  nop
002b830c: afa00000  sw	zero,0(sp)
002b8310: 3c0401e2  lui	a0,0x1e2
002b8314: 24842040  addiu	a0,a0,8256   ; = D_01e22040
002b8318: 24050002  li	a1,2
002b831c: 0000302d  move	a2,zero
002b8320: 3c0701e2  lui	a3,0x1e2
002b8324: 24e71f40  addiu	a3,a3,8000   ; = D_01e21f40
002b8328: 24080100  li	t0,256
002b832c: 3c0901e2  lui	t1,0x1e2
002b8330: 25291f40  addiu	t1,t1,8000   ; = D_01e21f40
002b8334: 240a0100  li	t2,256
002b8338: 0c0c252e  jal	0x3094b8
002b833c: 0000582d  move	t3,zero
002b8340: 0040782d  move	t7,v0
002b8344: afcf0010  sw	t7,16(s8)
002b8348: 8fcf0010  lw	t7,16(s8)
002b834c: 15e0ffef  bnez	t7,0x2b830c
002b8350: 00000000  nop
002b8354: 3c0f01e2  lui	t7,0x1e2
002b8358: 8def1f40  lw	t7,8000(t7)   ; = D_01e21f40
002b835c: 01e0102d  move	v0,t7
002b8360: 03c0e82d  move	sp,s8
002b8364: dfbe0020  ld	s8,32(sp)
002b8368: dfbf0028  ld	ra,40(sp)
002b836c: 03e00008  jr	ra
002b8370: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b82f8(void)`

```c
undefined4 FUN_002b82f8(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_003094b8(0x1e22040,2,0,0x1e21f40,0x100,0x1e21f40,0x100,0);
  } while (iVar1 != 0);
  return DAT_01e21f40;
}
```

## Earlier attempts (newest first)

- none found
