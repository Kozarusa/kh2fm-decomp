# Target packet 0028ae28

- Range: `0028ae28`..`0028ae98`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028ae28`
- Registry names for this address: `Tz::Select::IsSeqDone(...)`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `0028ac98` registry: `func_0028ac98`
  - accepted sources that already call it (copy their declaration): `fm_primary_queueepsilon_recovered_0028ac98.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028ae28: 27bdffe0  addiu	sp,sp,-32
0028ae2c: ffbf0018  sd	ra,24(sp)
0028ae30: ffb00000  sd	s0,0(sp)
0028ae34: ffb10008  sd	s1,8(sp)
0028ae38: ffb20010  sd	s2,16(sp)
0028ae3c: 00058080  sll	s0,a1,0x2
0028ae40: 0080882d  move	s1,a0
0028ae44: 8c8f0028  lw	t7,40(a0)
0028ae48: 00a0902d  move	s2,a1
0028ae4c: 020f7821  addu	t7,s0,t7
0028ae50: 0c04e75e  jal	0x139d78
0028ae54: 8de40000  lw	a0,0(t7)
0028ae58: 0220202d  move	a0,s1
0028ae5c: 0c0a2b26  jal	0x28ac98
0028ae60: 0240282d  move	a1,s2
0028ae64: 8e2e0028  lw	t6,40(s1)
0028ae68: 844d0004  lh	t5,4(v0)
0028ae6c: 020e8021  addu	s0,s0,t6
0028ae70: dfb10008  ld	s1,8(sp)
0028ae74: 8e0f0000  lw	t7,0(s0)
0028ae78: dfb20010  ld	s2,16(sp)
0028ae7c: 8de20184  lw	v0,388(t7)
0028ae80: dfb00000  ld	s0,0(sp)
0028ae84: 004d1026  xor	v0,v0,t5
0028ae88: dfbf0018  ld	ra,24(sp)
0028ae8c: 2c420001  sltiu	v0,v0,1
0028ae90: 03e00008  jr	ra
0028ae94: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028ae28(void)`

```c
bool FUN_0028ae28(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_2 * 4;
  FUN_00139d78(*(undefined4 *)(iVar2 + *(int *)((int)param_1 + 0x28)));
  iVar1 = FUN_0028ac98(param_1,param_2);
  return (long)*(int *)(*(int *)(iVar2 + *(int *)((int)param_1 + 0x28)) + 0x184) ==
         (long)*(short *)(iVar1 + 4);
}
```

## Earlier attempts (newest first)

- none found
