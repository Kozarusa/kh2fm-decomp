# Target packet 001fb720

- Range: `001fb720`..`001fb78c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001fb720`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001fa950` registry: `func_001fa950`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001fb720: 27bdffe0  addiu	sp,sp,-32
001fb724: ffb00000  sd	s0,0(sp)
001fb728: ffb10008  sd	s1,8(sp)
001fb72c: ffb20010  sd	s2,16(sp)
001fb730: 0080802d  move	s0,a0
001fb734: ffbf0018  sd	ra,24(sp)
001fb738: 00a0882d  move	s1,a1
001fb73c: 8cce000c  lw	t6,12(a2)
001fb740: 8dcf0000  lw	t7,0(t6)
001fb744: 008f7821  addu	t7,a0,t7
001fb748: 0c07ea54  jal	0x1fa950
001fb74c: 25f200a0  addiu	s2,t7,160
001fb750: 8e0e000c  lw	t6,12(s0)
001fb754: 8e2f0000  lw	t7,0(s1)
001fb758: 15ee0007  bne	t7,t6,0x1fb778
001fb75c: dfb00000  ld	s0,0(sp)
001fb760: c620000c  lwc1	$f0,12(s1)
001fb764: e6400044  swc1	$f0,68(s2)
001fb768: 962f0014  lhu	t7,20(s1)
001fb76c: 448f0000  mtc1	t7,$f0
001fb770: 46800020  cvt.s.w	$f0,$f0
001fb774: e6400040  swc1	$f0,64(s2)
001fb778: dfb10008  ld	s1,8(sp)
001fb77c: dfb20010  ld	s2,16(sp)
001fb780: dfbf0018  ld	ra,24(sp)
001fb784: 03e00008  jr	ra
001fb788: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001fb720(void)`

```c
void FUN_001fb720(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_1 + **(int **)(param_3 + 0xc);
  FUN_001fa950();
  if (*param_2 == *(int *)(param_1 + 0xc)) {
    *(int *)(iVar1 + 0xe4) = param_2[3];
    *(float *)(iVar1 + 0xe0) = (float)*(ushort *)(param_2 + 5);
  }
  return;
}
```

## Earlier attempts (newest first)

- 18 differing words, 104/108 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.cpp`)
