# Target packet 0028ae98

- Range: `0028ae98`..`0028af14`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028ae98`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `0028ac98` registry: `func_0028ac98`
  - accepted sources that already call it (copy their declaration): `fm_primary_queueepsilon_recovered_0028ac98.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028ae98: 27bdffe0  addiu	sp,sp,-32
0028ae9c: ffb00000  sd	s0,0(sp)
0028aea0: ffb10008  sd	s1,8(sp)
0028aea4: ffb20010  sd	s2,16(sp)
0028aea8: 0080802d  move	s0,a0
0028aeac: ffbf0018  sd	ra,24(sp)
0028aeb0: 00a0882d  move	s1,a1
0028aeb4: 00059080  sll	s2,a1,0x2
0028aeb8: 8c8f0028  lw	t7,40(a0)
0028aebc: 024f7821  addu	t7,s2,t7
0028aec0: 8dee0000  lw	t6,0(t7)
0028aec4: 11c00003  beqz	t6,0x28aed4
0028aec8: 01c0202d  move	a0,t6
0028aecc: 0c04e75e  jal	0x139d78
0028aed0: 00000000  nop
0028aed4: 0220282d  move	a1,s1
0028aed8: 0c0a2b26  jal	0x28ac98
0028aedc: 0200202d  move	a0,s0
0028aee0: 8e0f0028  lw	t7,40(s0)
0028aee4: 844d0006  lh	t5,6(v0)
0028aee8: 024f7821  addu	t7,s2,t7
0028aeec: dfb00000  ld	s0,0(sp)
0028aef0: 8dee0000  lw	t6,0(t7)
0028aef4: dfb10008  ld	s1,8(sp)
0028aef8: 8dc20184  lw	v0,388(t6)
0028aefc: dfb20010  ld	s2,16(sp)
0028af00: 004d1026  xor	v0,v0,t5
0028af04: dfbf0018  ld	ra,24(sp)
0028af08: 2c420001  sltiu	v0,v0,1
0028af0c: 03e00008  jr	ra
0028af10: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028ae98(void)`

```c
bool FUN_0028ae98(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_2 * 4;
  iVar1 = *(int *)(iVar2 + *(int *)((int)param_1 + 0x28));
  if (iVar1 != 0) {
    FUN_00139d78(iVar1);
  }
  iVar1 = FUN_0028ac98(param_1,param_2);
  return (long)*(int *)(*(int *)(iVar2 + *(int *)((int)param_1 + 0x28)) + 0x184) ==
         (long)*(short *)(iVar1 + 6);
}
```

## Earlier attempts (newest first)

- none found
