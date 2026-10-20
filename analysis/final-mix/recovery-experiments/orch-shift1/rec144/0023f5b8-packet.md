# Target packet 0023f5b8

- Range: `0023f5b8`..`0023f614`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_0023f5b8`
- Registry names for this address: `func_0023f5b8(int)`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `00192048` registry: `_Z16u_tail4_00192048jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0023f5b8: 27bdffe0  addiu	sp,sp,-32
0023f5bc: ffb00000  sd	s0,0(sp)
0023f5c0: ffb10008  sd	s1,8(sp)
0023f5c4: ffb20010  sd	s2,16(sp)
0023f5c8: 00a0802d  move	s0,a1
0023f5cc: ffbf0018  sd	ra,24(sp)
0023f5d0: 0c04e75e  jal	0x139d78
0023f5d4: 0080882d  move	s1,a0
0023f5d8: 06020009  bltzl	s0,0x23f600
0023f5dc: dfb00000  ld	s0,0(sp)
0023f5e0: 8e2f0024  lw	t7,36(s1)
0023f5e4: 520f0006  beql	s0,t7,0x23f600
0023f5e8: dfb00000  ld	s0,0(sp)
0023f5ec: 0c064812  jal	0x192048
0023f5f0: 0200202d  move	a0,s0
0023f5f4: ae220020  sw	v0,32(s1)
0023f5f8: ae300024  sw	s0,36(s1)
0023f5fc: dfb00000  ld	s0,0(sp)
0023f600: dfb10008  ld	s1,8(sp)
0023f604: dfb20010  ld	s2,16(sp)
0023f608: dfbf0018  ld	ra,24(sp)
0023f60c: 03e00008  jr	ra
0023f610: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0023f5b8(void)`

```c
void FUN_0023f5b8(int param_1,int param_2)

{
  undefined4 uVar1;
  
  FUN_00139d78();
  if ((-1 < param_2) && (param_2 != *(int *)(param_1 + 0x24))) {
    uVar1 = FUN_00192048(param_2);
    *(undefined4 *)(param_1 + 0x20) = uVar1;
    *(int *)(param_1 + 0x24) = param_2;
  }
  return;
}
```

## Earlier attempts (newest first)

- 17 differing words, 92/92 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_06.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_06.cpp`)
