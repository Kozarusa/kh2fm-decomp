# Target packet 0017d8c0

- Range: `0017d8c0`..`0017d930`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_0017d8c0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0011b6a8` registry: `func_0011b6a8(void*)`
  - accepted sources that already call it (copy their declaration): `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`, `fm_primary_order_recovered_00132130.cpp`
- `0011b7b0` registry: `_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0017d8c0: 27bdffe0  addiu	sp,sp,-32
0017d8c4: ffb00000  sd	s0,0(sp)
0017d8c8: ffb10008  sd	s1,8(sp)
0017d8cc: ffb20010  sd	s2,16(sp)
0017d8d0: 00a0802d  move	s0,a1
0017d8d4: ffbf0018  sd	ra,24(sp)
0017d8d8: 0080882d  move	s1,a0
0017d8dc: 0c046daa  jal	0x11b6a8
0017d8e0: 00c0902d  move	s2,a2
0017d8e4: 0200282d  move	a1,s0
0017d8e8: 0220202d  move	a0,s1
0017d8ec: 0c046dec  jal	0x11b7b0
0017d8f0: 26300030  addiu	s0,s1,48
0017d8f4: 12120004  beq	s0,s2,0x17d908
0017d8f8: 3c0f0037  lui	t7,0x37
0017d8fc: 7a480000  lq	t0,0(s2)
0017d900: 7e080000  sq	t0,0(s0)
0017d904: 3c0f0037  lui	t7,0x37
0017d908: dfb20010  ld	s2,16(sp)
0017d90c: 25efc574  addiu	t7,t7,-14988   ; = D_0036c574
0017d910: dfbf0018  ld	ra,24(sp)
0017d914: c5e00000  lwc1	$f0,0(t7)
0017d918: 0220102d  move	v0,s1
0017d91c: dfb10008  ld	s1,8(sp)
0017d920: e600000c  swc1	$f0,12(s0)
0017d924: dfb00000  ld	s0,0(sp)
0017d928: 03e00008  jr	ra
0017d92c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0017d8c0(void)`

```c
undefined8 FUN_0017d8c0(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  FUN_0011b6a8();
  iVar4 = (int)param_1;
  FUN_0011b7b0(param_1,param_2);
  if ((undefined4 *)(iVar4 + 0x30) != param_3) {
    uVar1 = param_3[1];
    uVar2 = param_3[2];
    uVar3 = param_3[3];
    *(undefined4 *)(iVar4 + 0x30) = *param_3;
    *(undefined4 *)(iVar4 + 0x34) = uVar1;
    *(undefined4 *)(iVar4 + 0x38) = uVar2;
    *(undefined4 *)(iVar4 + 0x3c) = uVar3;
  }
  *(undefined4 *)(iVar4 + 0x3c) = DAT_0036c574;
  return param_1;
}
```

## Earlier attempts (newest first)

- none found
