# Target packet 00232ea0

- Range: `00232ea0`..`00232f08`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_00232ea0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00232ea0: 8cce0000  lw	t6,0(a2)
00232ea4: ac8e0000  sw	t6,0(a0)
00232ea8: 8ccf0004  lw	t7,4(a2)
00232eac: ac8f0004  sw	t7,4(a0)
00232eb0: 8cce0008  lw	t6,8(a2)
00232eb4: ac8e0008  sw	t6,8(a0)
00232eb8: 94af0008  lhu	t7,8(a1)
00232ebc: 448f0000  mtc1	t7,$f0
00232ec0: 46800020  cvt.s.w	$f0,$f0
00232ec4: 46000000  add.s	$f0,$f0,$f0
00232ec8: e4800014  swc1	$f0,20(a0)
00232ecc: 94af000a  lhu	t7,10(a1)
00232ed0: a48f0018  sh	t7,24(a0)
00232ed4: 94ae000c  lhu	t6,12(a1)
00232ed8: a48e001a  sh	t6,26(a0)
00232edc: 84ad0010  lh	t5,16(a1)
00232ee0: 240e0001  li	t6,1
00232ee4: 94af0008  lhu	t7,8(a1)
00232ee8: 01ed7823  subu	t7,t7,t5
00232eec: a08e0030  sb	t6,48(a0)
00232ef0: 448f0000  mtc1	t7,$f0
00232ef4: ac87000c  sw	a3,12(a0)
00232ef8: 46800020  cvt.s.w	$f0,$f0
00232efc: 46000000  add.s	$f0,$f0,$f0
00232f00: 03e00008  jr	ra
00232f04: e4800010  swc1	$f0,16(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00232ea0(void)`

```c
void FUN_00232ea0(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  short sVar1;
  ushort uVar2;
  float fVar3;
  
  *param_1 = *param_3;
  param_1[1] = param_3[1];
  param_1[2] = param_3[2];
  param_1[5] = (float)*(ushort *)(param_2 + 8) + (float)*(ushort *)(param_2 + 8);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 10);
  *(undefined2 *)((int)param_1 + 0x1a) = *(undefined2 *)(param_2 + 0xc);
  sVar1 = *(short *)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_2 + 8);
  *(undefined1 *)(param_1 + 0xc) = 1;
  param_1[3] = param_4;
  fVar3 = (float)(int)((uint)uVar2 - (int)sVar1);
  param_1[4] = fVar3 + fVar3;
  return;
}
```

## Earlier attempts (newest first)

- 41 differing words, 164/104 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_06.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_06.cpp`)
