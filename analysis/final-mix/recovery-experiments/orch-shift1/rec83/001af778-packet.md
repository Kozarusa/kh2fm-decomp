# Target packet 001af778

- Range: `001af778`..`001af7bc`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_001af778`
- Registry names for this address: `func_001af778`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001708f8` registry: `_ZN2YS10CACHE_BUFF5AllocEPKci`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_orchaz_recovered_001708f8.cpp`, `fm_primary_orchbs_recovered_001a3a88.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_storeorder_recovered_00281f90.cpp`
- `001af7c0` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001af778: 27bdfff0  addiu	sp,sp,-16
001af77c: 3c0f0035  lui	t7,0x35
001af780: ffb00000  sd	s0,0(sp)
001af784: 2405ffff  li	a1,-1
001af788: ffbf0008  sd	ra,8(sp)
001af78c: 0080802d  move	s0,a0
001af790: 0c05c23e  jal	0x1708f8
001af794: 8de40dec  lw	a0,3564(t7)   ; = D_00350dec
001af798: 8e050030  lw	a1,48(s0)
001af79c: 0200202d  move	a0,s0
001af7a0: 0c06bdf0  jal	0x1af7c0
001af7a4: ae020004  sw	v0,4(s0)
001af7a8: ae020034  sw	v0,52(s0)
001af7ac: dfbf0008  ld	ra,8(sp)
001af7b0: dfb00000  ld	s0,0(sp)
001af7b4: 03e00008  jr	ra
001af7b8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001af778(void)`

```c
void FUN_001af778(undefined8 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_001708f8(PTR_s_obj_GAMEOVER_mset_00350dec,0xffffffffffffffff);
  iVar2 = (int)param_1;
  *(undefined4 *)(iVar2 + 4) = uVar1;
  uVar1 = FUN_001af7c0(param_1,*(undefined4 *)(iVar2 + 0x30));
  *(undefined4 *)(iVar2 + 0x34) = uVar1;
  return;
}
```

## Earlier attempts (newest first)

- 15 differing words, 76/68 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round21_001af778_v01.verification.json`
