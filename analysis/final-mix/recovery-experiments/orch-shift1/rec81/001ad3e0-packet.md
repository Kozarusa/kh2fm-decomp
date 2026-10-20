# Target packet 001ad3e0

- Range: `001ad3e0`..`001ad430`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ad3e0`
- Registry names for this address: `func_001ad3e0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001ac310` registry: `func_001ac310`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`
- `001acdc0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ad3e0: 27bdfff0  addiu	sp,sp,-16
001ad3e4: 240901b0  li	t1,432
001ad3e8: ffb00000  sd	s0,0(sp)
001ad3ec: ffbf0008  sd	ra,8(sp)
001ad3f0: 0080802d  move	s0,a0
001ad3f4: 8c87005c  lw	a3,92(a0)
001ad3f8: 26100b6c  addiu	s0,s0,2924
001ad3fc: 8c880060  lw	t0,96(a0)
001ad400: 8c850004  lw	a1,4(a0)
001ad404: 00073842  srl	a3,a3,0x1
001ad408: 8c860008  lw	a2,8(a0)
001ad40c: 00084042  srl	t0,t0,0x1
001ad410: 00a73821  addu	a3,a1,a3
001ad414: 0c06b370  jal	0x1acdc0
001ad418: 00c84021  addu	t0,a2,t0
001ad41c: 0200202d  move	a0,s0
001ad420: dfbf0008  ld	ra,8(sp)
001ad424: dfb00000  ld	s0,0(sp)
001ad428: 0806b0c4  j	0x1ac310
001ad42c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ad3e0(void)`

```c
void FUN_001ad3e0(int param_1)

{
  FUN_001acdc0();
  FUN_001ac310(param_1 + 0xb6c);
  return;
}
```

## Earlier attempts (newest first)

- 18 differing words, 48/80 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_1.cpp`)
