# Target packet 001aa310

- Range: `001aa310`..`001aa388`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aa310`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00192fb8` registry: `func_00192fb8`
- `001ab820` registry: `func_001ab820`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aa310: 27bdffe0  addiu	sp,sp,-32
001aa314: 8ca40000  lw	a0,0(a1)
001aa318: ffb00000  sd	s0,0(sp)
001aa31c: ffb10008  sd	s1,8(sp)
001aa320: ffbf0010  sd	ra,16(sp)
001aa324: 00a0802d  move	s0,a1
001aa328: e7b40018  swc1	$f20,24(sp)
001aa32c: 00c0882d  move	s1,a2
001aa330: 0c06ae08  jal	0x1ab820
001aa334: 26100020  addiu	s0,s0,32
001aa338: 4482a000  mtc1	v0,$f20
001aa33c: 0200202d  move	a0,s0
001aa340: 0c064bee  jal	0x192fb8
001aa344: 4680a520  cvt.s.w	$f20,$f20
001aa348: 3c0f0037  lui	t7,0x37
001aa34c: dfb00000  ld	s0,0(sp)
001aa350: 25efd6a4  addiu	t7,t7,-10588   ; = D_0036d6a4
001aa354: dfbf0010  ld	ra,16(sp)
001aa358: 4600a502  mul.s	$f20,$f20,$f0
001aa35c: c5e00000  lwc1	$f0,0(t7)
001aa360: 4600a500  add.s	$f20,$f20,$f0
001aa364: 4600a024  cvt.w.s	$f0,$f20
001aa368: 440f0000  mfc1	t7,$f0
001aa36c: c7b40018  lwc1	$f20,24(sp)
001aa370: 000f7900  sll	t7,t7,0x4
001aa374: 022f8821  addu	s1,s1,t7
001aa378: 0220102d  move	v0,s1
001aa37c: dfb10008  ld	s1,8(sp)
001aa380: 03e00008  jr	ra
001aa384: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aa310(void)`

```c
int FUN_001aa310(undefined8 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  float fVar2;
  
  iVar1 = FUN_001ab820(*param_2);
  fVar2 = (float)FUN_00192fb8(param_2 + 8);
  return param_3 + (int)((float)iVar1 * fVar2 + DAT_0036d6a4) * 0x10;
}
```

## Earlier attempts (newest first)

- none found
