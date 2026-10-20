# Target packet 001bdcd0

- Range: `001bdcd0`..`001bdd20`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bdcd0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001819c0` registry: `func_001819c0`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`
- `001bd590` registry: `_ZN2YS14PLAYER_COMMAND15is_override_topEv`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bdcd0: 27bdffe0  addiu	sp,sp,-32
001bdcd4: ffb00000  sd	s0,0(sp)
001bdcd8: ffb10008  sd	s1,8(sp)
001bdcdc: ffbf0010  sd	ra,16(sp)
001bdce0: 0080802d  move	s0,a0
001bdce4: 0c060670  jal	0x1819c0
001bdce8: 0000882d  move	s1,zero
001bdcec: 10400005  beqz	v0,0x1bdd04
001bdcf0: 0200202d  move	a0,s0
001bdcf4: 0c06f564  jal	0x1bd590
001bdcf8: 00000000  nop
001bdcfc: 10400003  beqz	v0,0x1bdd0c
001bdd00: 0220102d  move	v0,s1
001bdd04: 24110001  li	s1,1
001bdd08: 0220102d  move	v0,s1
001bdd0c: dfb00000  ld	s0,0(sp)
001bdd10: dfb10008  ld	s1,8(sp)
001bdd14: dfbf0010  ld	ra,16(sp)
001bdd18: 03e00008  jr	ra
001bdd1c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bdcd0(void)`

```c
undefined4 FUN_001bdcd0(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = FUN_001819c0();
  if ((lVar1 != 0) && (lVar1 = FUN_001bd590(param_1), lVar1 == 0)) {
    return 0;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 13 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_0.cpp`)
- 9 differing words, 72/80 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round25_001bdcd0_v01.verification.json`
