# Target packet 001cf998

- Range: `001cf998`..`001cf9dc`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_001cf998`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001d87b8` registry: `_ZN2YS7MISSION8GetCountEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`, `fm_primary_sixwordnext_recovered_001d7a50.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001cf998: 27bdfff0  addiu	sp,sp,-16
001cf99c: ffb00000  sd	s0,0(sp)
001cf9a0: ffbf0008  sd	ra,8(sp)
001cf9a4: 0c06ed28  jal	0x1bb4a0
001cf9a8: 0000802d  move	s0,zero
001cf9ac: 10400005  beqz	v0,0x1cf9c4
001cf9b0: 24040001  li	a0,1
001cf9b4: 0c0761ee  jal	0x1d87b8
001cf9b8: 00000000  nop
001cf9bc: 18400003  blez	v0,0x1cf9cc
001cf9c0: 0200102d  move	v0,s0
001cf9c4: 24100001  li	s0,1
001cf9c8: 0200102d  move	v0,s0
001cf9cc: dfbf0008  ld	ra,8(sp)
001cf9d0: dfb00000  ld	s0,0(sp)
001cf9d4: 03e00008  jr	ra
001cf9d8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001cf998(void)`

```c
undefined4 FUN_001cf998(void)

{
  long lVar1;
  
  lVar1 = FUN_001bb4a0();
  if ((lVar1 != 0) && (lVar1 = FUN_001d87b8(1), lVar1 < 1)) {
    return 0;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 14 differing words, 72/68 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.cpp`)
- 13 differing words, 56/68 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round21_001cf998_v02.verification.json`
- 13 differing words, 56/68 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round21_001cf998_v01.verification.json`
