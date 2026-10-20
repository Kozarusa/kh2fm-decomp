# Target packet 001cf560

- Range: `001cf560`..`001cf5b0`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001cf560`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001ca448` registry: `func_001ca448`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`, `fm_primary_orchco_recovered_001ca448.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001cf560: 27bdffe0  addiu	sp,sp,-32
001cf564: ffb00000  sd	s0,0(sp)
001cf568: ffb10008  sd	s1,8(sp)
001cf56c: ffbf0010  sd	ra,16(sp)
001cf570: 0080802d  move	s0,a0
001cf574: 0c072912  jal	0x1ca448
001cf578: 0000882d  move	s1,zero
001cf57c: 54400006  bnezl	v0,0x1cf598
001cf580: 24110001  li	s1,1
001cf584: 8e0e0154  lw	t6,340(s0)
001cf588: 240f002c  li	t7,44
001cf58c: 15cf0003  bne	t6,t7,0x1cf59c
001cf590: 0220102d  move	v0,s1
001cf594: 24110001  li	s1,1
001cf598: 0220102d  move	v0,s1
001cf59c: dfb00000  ld	s0,0(sp)
001cf5a0: dfb10008  ld	s1,8(sp)
001cf5a4: dfbf0010  ld	ra,16(sp)
001cf5a8: 03e00008  jr	ra
001cf5ac: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001cf560(void)`

```c
undefined4 FUN_001cf560(int param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_001ca448();
  if ((lVar2 != 0) || (uVar1 = 0, *(int *)(param_1 + 0x154) == 0x2c)) {
    uVar1 = 1;
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- 18 differing words, 72/80 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.cpp`)
