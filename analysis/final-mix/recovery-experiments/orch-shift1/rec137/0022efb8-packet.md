# Target packet 0022efb8

- Range: `0022efb8`..`0022f018`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_0022efb8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00227d10` registry: `_ZN2sa5EVENT14entry_work_getEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`
- `002282f0` registry: `func_002282f0`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0022efb8: 27bdfff0  addiu	sp,sp,-16
0022efbc: ffb00000  sd	s0,0(sp)
0022efc0: ffbf0008  sd	ra,8(sp)
0022efc4: 0080802d  move	s0,a0
0022efc8: 0c08a0bc  jal	0x2282f0
0022efcc: 84840004  lh	a0,4(a0)
0022efd0: 5440000e  bnezl	v0,0x22f00c
0022efd4: dfb00000  ld	s0,0(sp)
0022efd8: 0c089f44  jal	0x227d10
0022efdc: 8604000c  lh	a0,12(s0)
0022efe0: 860e0004  lh	t6,4(s0)
0022efe4: ac4e000c  sw	t6,12(v0)
0022efe8: 860e000a  lh	t6,10(s0)
0022efec: 860f0004  lh	t7,4(s0)
0022eff0: 01ee7821  addu	t7,t7,t6
0022eff4: ac4f0010  sw	t7,16(v0)
0022eff8: 920e0008  lbu	t6,8(s0)
0022effc: a04e0014  sb	t6,20(v0)
0022f000: 920f0009  lbu	t7,9(s0)
0022f004: a04f0015  sb	t7,21(v0)
0022f008: dfb00000  ld	s0,0(sp)
0022f00c: dfbf0008  ld	ra,8(sp)
0022f010: 03e00008  jr	ra
0022f014: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0022efb8(void)`

```c
void FUN_0022efb8(int param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = FUN_002282f0(*(undefined2 *)(param_1 + 4));
  if (lVar1 == 0) {
    iVar2 = FUN_00227d10(*(undefined2 *)(param_1 + 0xc));
    *(int *)(iVar2 + 0xc) = (int)*(short *)(param_1 + 4);
    *(int *)(iVar2 + 0x10) = (int)*(short *)(param_1 + 4) + (int)*(short *)(param_1 + 10);
    *(undefined1 *)(iVar2 + 0x14) = *(undefined1 *)(param_1 + 8);
    *(undefined1 *)(iVar2 + 0x15) = *(undefined1 *)(param_1 + 9);
  }
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 96/96 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_09_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_09_0.cpp`)
