# Target packet 0017f3d8

- Range: `0017f3d8`..`0017f42c`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_0017f3d8`
- Registry names for this address: `_Z16wtarget_0017f3d8jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0017f3d8: 8c8c003c  lw	t4,60(a0)
0017f3dc: 240e0014  li	t6,20
0017f3e0: 248a003c  addiu	t2,a0,60
0017f3e4: 258d0001  addiu	t5,t4,1
0017f3e8: 258f0004  addiu	t7,t4,4
0017f3ec: 29ab0000  slti	t3,t5,0
0017f3f0: 018e6018  mult	t4,t4,t6
0017f3f4: 01ab780a  movz	t7,t5,t3
0017f3f8: 000f7883  sra	t7,t7,0x2
0017f3fc: 000f7880  sll	t7,t7,0x2
0017f400: 01af6823  subu	t5,t5,t7
0017f404: 014c5021  addu	t2,t2,t4
0017f408: ac8d003c  sw	t5,60(a0)
0017f40c: 254f0008  addiu	t7,t2,8
0017f410: 01e0102d  move	v0,t7
0017f414: e5ec0004  swc1	$f12,4(t7)
0017f418: e5ed0008  swc1	$f13,8(t7)
0017f41c: ade6000c  sw	a2,12(t7)
0017f420: ad450008  sw	a1,8(t2)
0017f424: 03e00008  jr	ra
0017f428: ad400018  sw	zero,24(t2)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0017f3d8(void)`

```c
int FUN_0017f3d8(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_3 + 0x3c);
  iVar2 = iVar1 + 1;
  iVar3 = iVar1 + 4;
  if (-1 < iVar2) {
    iVar3 = iVar2;
  }
  iVar1 = param_3 + 0x3c + iVar1 * 0x14;
  *(int *)(param_3 + 0x3c) = iVar2 + (iVar3 >> 2) * -4;
  *(undefined4 *)(iVar1 + 0xc) = param_1;
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  *(undefined4 *)(iVar1 + 0x14) = param_5;
  *(undefined4 *)(iVar1 + 8) = param_4;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return iVar1 + 8;
}
```

## Earlier attempts (newest first)

- 20 differing words, 80/84 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_02.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_02.cpp`)
