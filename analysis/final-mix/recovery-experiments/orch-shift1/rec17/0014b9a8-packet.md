# Target packet 0014b9a8

- Range: `0014b9a8`..`0014ba1c`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_0014b9a8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b7e68` registry: none
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`, `fm_primary_twowordfresh_recovered_00149ec0.cpp`
- `001b7f30` registry: `func_001b7f30`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`, `fm_primary_twowordfresh_recovered_00149ec0.cpp`
- `001b80d8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`, `fm_primary_twowordfresh_recovered_00149ec0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0014b9a8: 27bdffe0  addiu	sp,sp,-32
0014b9ac: 24050020  li	a1,32
0014b9b0: ffb00010  sd	s0,16(sp)
0014b9b4: ffbf0018  sd	ra,24(sp)
0014b9b8: 0080802d  move	s0,a0
0014b9bc: afa00008  sw	zero,8(sp)
0014b9c0: afa00004  sw	zero,4(sp)
0014b9c4: 03a0202d  move	a0,sp
0014b9c8: 0c06df9a  jal	0x1b7e68
0014b9cc: afa00000  sw	zero,0(sp)
0014b9d0: 03a0602d  move	t4,sp
0014b9d4: 240d0001  li	t5,1
0014b9d8: 8d8f0008  lw	t7,8(t4)
0014b9dc: 25adffff  addiu	t5,t5,-1
0014b9e0: 7a0e0000  lq	t6,0(s0)
0014b9e4: 7dee0000  sq	t6,0(t7)
0014b9e8: 26100010  addiu	s0,s0,16
0014b9ec: 8d8f0008  lw	t7,8(t4)
0014b9f0: 25ef0010  addiu	t7,t7,16
0014b9f4: 05a1fff8  bgez	t5,0x14b9d8
0014b9f8: ad8f0008  sw	t7,8(t4)
0014b9fc: 0c06e036  jal	0x1b80d8
0014ba00: 03a0202d  move	a0,sp
0014ba04: 0c06dfcc  jal	0x1b7f30
0014ba08: 03a0202d  move	a0,sp
0014ba0c: dfb00010  ld	s0,16(sp)
0014ba10: dfbf0018  ld	ra,24(sp)
0014ba14: 03e00008  jr	ra
0014ba18: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0014b9a8(void)`

```c
void FUN_0014b9a8(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 *puStack_18;
  
  puStack_18 = (undefined4 *)0x0;
  uStack_1c = 0;
  uStack_20 = 0;
  FUN_001b7e68(&uStack_20,0x20);
  iVar1 = 1;
  do {
    iVar1 = iVar1 + -1;
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    *puStack_18 = *param_1;
    puStack_18[1] = uVar2;
    puStack_18[2] = uVar3;
    puStack_18[3] = uVar4;
    param_1 = param_1 + 4;
    puStack_18 = puStack_18 + 4;
  } while (-1 < iVar1);
  FUN_001b80d8(&uStack_20);
  FUN_001b7f30(&uStack_20);
  return;
}
```

## Earlier attempts (newest first)

- none found
