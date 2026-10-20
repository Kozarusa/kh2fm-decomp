# Target packet 0021e9d0

- Range: `0021e9d0`..`0021ea50`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0021e9d0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0021e9d0: 00057882  srl	t7,a1,0x2
0021e9d4: 3c0e0036  lui	t6,0x36
0021e9d8: 25ce9a20  addiu	t6,t6,-26080   ; = D_00359a20
0021e9dc: 31ef3ffc  andi	t7,t7,0x3ffc
0021e9e0: 01ee7821  addu	t7,t7,t6
0021e9e4: 24a54000  addiu	a1,a1,16384
0021e9e8: c5e10000  lwc1	$f1,0(t7)
0021e9ec: 00052882  srl	a1,a1,0x2
0021e9f0: 30a53ffc  andi	a1,a1,0x3ffc
0021e9f4: 3c0f0037  lui	t7,0x37
0021e9f8: 46000807  neg.s	$f0,$f1
0021e9fc: 00ae2821  addu	a1,a1,t6
0021ea00: 25ef0b48  addiu	t7,t7,2888   ; = D_00370b48
0021ea04: c4a30000  lwc1	$f3,0(a1)
0021ea08: c5e20000  lwc1	$f2,0(t7)
0021ea0c: e4810018  swc1	$f1,24(a0)
0021ea10: e482003c  swc1	$f2,60(a0)
0021ea14: e4800024  swc1	$f0,36(a0)
0021ea18: e4830028  swc1	$f3,40(a0)
0021ea1c: e4820000  swc1	$f2,0(a0)
0021ea20: ac800010  sw	zero,16(a0)
0021ea24: ac800020  sw	zero,32(a0)
0021ea28: ac800030  sw	zero,48(a0)
0021ea2c: ac800004  sw	zero,4(a0)
0021ea30: e4830014  swc1	$f3,20(a0)
0021ea34: ac800034  sw	zero,52(a0)
0021ea38: ac800008  sw	zero,8(a0)
0021ea3c: ac800038  sw	zero,56(a0)
0021ea40: ac80000c  sw	zero,12(a0)
0021ea44: ac80001c  sw	zero,28(a0)
0021ea48: 03e00008  jr	ra
0021ea4c: ac80002c  sw	zero,44(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0021e9d0(void)`

```c
void FUN_0021e9d0(undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_00370b48;
  fVar2 = *(float *)(&DAT_00359a20 + (param_2 >> 2 & 0x3ffc));
  uVar3 = *(undefined4 *)(&DAT_00359a20 + (param_2 + 0x4000 >> 2 & 0x3ffc));
  param_1[6] = fVar2;
  param_1[0xf] = uVar1;
  param_1[9] = -fVar2;
  param_1[10] = uVar3;
  *param_1 = uVar1;
  param_1[4] = 0;
  param_1[8] = 0;
  param_1[0xc] = 0;
  param_1[1] = 0;
  param_1[5] = uVar3;
  param_1[0xd] = 0;
  param_1[2] = 0;
  param_1[0xe] = 0;
  param_1[3] = 0;
  param_1[7] = 0;
  param_1[0xb] = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
