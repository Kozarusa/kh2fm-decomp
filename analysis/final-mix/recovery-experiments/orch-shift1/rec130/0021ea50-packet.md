# Target packet 0021ea50

- Range: `0021ea50`..`0021ead0`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0021ea50`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0021ea50: 00057882  srl	t7,a1,0x2
0021ea54: 3c0e0036  lui	t6,0x36
0021ea58: 25ce9a20  addiu	t6,t6,-26080   ; = D_00359a20
0021ea5c: 31ef3ffc  andi	t7,t7,0x3ffc
0021ea60: 01ee7821  addu	t7,t7,t6
0021ea64: 24a54000  addiu	a1,a1,16384
0021ea68: c5e20000  lwc1	$f2,0(t7)
0021ea6c: 00052882  srl	a1,a1,0x2
0021ea70: 30a53ffc  andi	a1,a1,0x3ffc
0021ea74: 3c0f0037  lui	t7,0x37
0021ea78: 46001047  neg.s	$f1,$f2
0021ea7c: 00ae2821  addu	a1,a1,t6
0021ea80: 25ef0b4c  addiu	t7,t7,2892   ; = D_00370b4c
0021ea84: c4a00000  lwc1	$f0,0(a1)
0021ea88: c5e30000  lwc1	$f3,0(t7)
0021ea8c: e4800028  swc1	$f0,40(a0)
0021ea90: e483003c  swc1	$f3,60(a0)
0021ea94: e4810008  swc1	$f1,8(a0)
0021ea98: e4800000  swc1	$f0,0(a0)
0021ea9c: ac800010  sw	zero,16(a0)
0021eaa0: e4820020  swc1	$f2,32(a0)
0021eaa4: ac800030  sw	zero,48(a0)
0021eaa8: ac800004  sw	zero,4(a0)
0021eaac: e4830014  swc1	$f3,20(a0)
0021eab0: ac800024  sw	zero,36(a0)
0021eab4: ac800034  sw	zero,52(a0)
0021eab8: ac800018  sw	zero,24(a0)
0021eabc: ac800038  sw	zero,56(a0)
0021eac0: ac80000c  sw	zero,12(a0)
0021eac4: ac80001c  sw	zero,28(a0)
0021eac8: 03e00008  jr	ra
0021eacc: ac80002c  sw	zero,44(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0021ea50(void)`

```c
void FUN_0021ea50(undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  
  uVar1 = DAT_00370b4c;
  fVar3 = *(float *)(&DAT_00359a20 + (param_2 >> 2 & 0x3ffc));
  uVar2 = *(undefined4 *)(&DAT_00359a20 + (param_2 + 0x4000 >> 2 & 0x3ffc));
  param_1[10] = uVar2;
  param_1[0xf] = uVar1;
  param_1[2] = -fVar3;
  *param_1 = uVar2;
  param_1[4] = 0;
  param_1[8] = fVar3;
  param_1[0xc] = 0;
  param_1[1] = 0;
  param_1[5] = uVar1;
  param_1[9] = 0;
  param_1[0xd] = 0;
  param_1[6] = 0;
  param_1[0xe] = 0;
  param_1[3] = 0;
  param_1[7] = 0;
  param_1[0xb] = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
