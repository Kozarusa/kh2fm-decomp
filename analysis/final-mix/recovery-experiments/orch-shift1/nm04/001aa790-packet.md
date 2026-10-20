# Target packet 001aa790

- Range: `001aa790`..`001aa7ec`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aa790`
- Registry names for this address: none
- Queue: state `leased`, queue `store-order`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec77\\001aa790-BLOCKED.md", "sha256": "4e19cd45fadd0861cba34eab668648b45e1d62e2c8707a1aadb93a93063cf6d2", "hypothesis": "ld ra must follow the two inner stores: try struct member writes, register-bound inner pointer (\\), or inline object+16 in the final call"}`

## Callees

- `00192f78` registry: `func_00192f78`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`
- `001ab750` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aa790: 27bdfff0  addiu	sp,sp,-16
001aa794: ac850000  sw	a1,0(a0)
001aa798: ffb00000  sd	s0,0(sp)
001aa79c: 3c0f6000  lui	t7,0x6000
001aa7a0: ac8f0014  sw	t7,20(a0)
001aa7a4: 0080802d  move	s0,a0
001aa7a8: ffbf0008  sd	ra,8(sp)
001aa7ac: ae000004  sw	zero,4(s0)
001aa7b0: 0c064bde  jal	0x192f78
001aa7b4: 24840020  addiu	a0,a0,32
001aa7b8: ae000038  sw	zero,56(s0)
001aa7bc: 260f0040  addiu	t7,s0,64
001aa7c0: ae00003c  sw	zero,60(s0)
001aa7c4: 01e0282d  move	a1,t7
001aa7c8: ae000040  sw	zero,64(s0)
001aa7cc: ade00008  sw	zero,8(t7)
001aa7d0: ade00004  sw	zero,4(t7)
001aa7d4: dfbf0008  ld	ra,8(sp)
001aa7d8: ae00004c  sw	zero,76(s0)
001aa7dc: 8e040000  lw	a0,0(s0)
001aa7e0: dfb00000  ld	s0,0(sp)
001aa7e4: 0806add4  j	0x1ab750
001aa7e8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aa790(void)`

```c
void FUN_001aa790(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[5] = 0x60000000;
  param_1[1] = 0;
  FUN_00192f78(param_1 + 8);
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  FUN_001ab750(*param_1,param_1 + 0x10);
  return;
}
```

## Earlier attempts (newest first)

- 10 differing words, 92/92 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.cpp`)
- 3 differing words, 92/92 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec77/orch1_rec77_001aa790_v4.verification.json`
- 3 differing words, 92/92 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec77/orch1_rec77_001aa790_v3.verification.json`
- 8 differing words, 88/92 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec77/orch1_rec77_001aa790_v2.verification.json`
- 3 differing words, 92/92 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec77/orch1_rec77_001aa790_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec77/001aa790-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec77/001aa790-packet.md`
