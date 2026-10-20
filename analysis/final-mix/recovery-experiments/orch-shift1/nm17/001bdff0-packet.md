# Target packet 001bdff0

- Range: `001bdff0`..`001be05c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bdff0`
- Registry names for this address: none
- Queue: state `leased`, queue `prologue-epilogue`, attempts 3, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\nm14\\001bdff0-BLOCKED.md", "sha256": "784a6a8fb5522f15551348975c79fb179e3d6812b279493222363ef87946247d", "hypothesis": "C11 memory-clobber cursor guard scheduling; accepted callee declaration normalization; next opus WP"}`

## Callees

- `001a67b0` registry: `_ZN2YS5MAGIC10GetCommandEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_resume_recovered_00.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`
- `001b8e88` registry: `_Z16u_call4_001b8e88jjjj`
  - accepted sources that already call it (copy their declaration): `fm_fallback_small.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bdff0: 27bdffe0  addiu	sp,sp,-32
001bdff4: 3c0f0033  lui	t7,0x33
001bdff8: ffb00000  sd	s0,0(sp)
001bdffc: 25efbb30  addiu	t7,t7,-17616   ; = D_0032bb30
001be000: ffb10008  sd	s1,8(sp)
001be004: ffb20010  sd	s2,16(sp)
001be008: 25f036f0  addiu	s0,t7,14064
001be00c: ffbf0018  sd	ra,24(sp)
001be010: 24110003  li	s1,3
001be014: 24120002  li	s2,2
001be018: 0c06e3a2  jal	0x1b8e88
001be01c: 96040008  lhu	a0,8(s0)
001be020: 944f0002  lhu	t7,2(v0)
001be024: 55f20005  bnel	t7,s2,0x1be03c
001be028: 2631ffff  addiu	s1,s1,-1
001be02c: 0c0699ec  jal	0x1a67b0
001be030: 84440004  lh	a0,4(v0)
001be034: a6020008  sh	v0,8(s0)
001be038: 2631ffff  addiu	s1,s1,-1
001be03c: 0621fff6  bgez	s1,0x1be018
001be040: 26100002  addiu	s0,s0,2
001be044: dfb00000  ld	s0,0(sp)
001be048: dfb10008  ld	s1,8(sp)
001be04c: dfb20010  ld	s2,16(sp)
001be050: dfbf0018  ld	ra,24(sp)
001be054: 03e00008  jr	ra
001be058: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bdff0(void)`

```c
void FUN_001bdff0(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0x32f220;
  iVar4 = 3;
  do {
    iVar2 = FUN_001b8e88(*(undefined2 *)(iVar3 + 8));
    if (*(short *)(iVar2 + 2) == 2) {
      uVar1 = FUN_001a67b0(*(undefined2 *)(iVar2 + 4));
      *(undefined2 *)(iVar3 + 8) = uVar1;
    }
    iVar4 = iVar4 + -1;
    iVar3 = iVar3 + 2;
  } while (-1 < iVar4);
  return;
}
```

## Earlier attempts (newest first)

- 26 differing words, 104/108 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_00_all.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_00_all.cpp`)
- 2 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm14/orch1_nm14_001bdff0_v4.verification.json`
- 7 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm14/orch1_nm14_001bdff0_v3.verification.json`
- 2 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm14/orch1_nm14_001bdff0_v2.verification.json`
- 2 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm14/orch1_nm14_001bdff0_v1.verification.json`
- 2 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec93/orch1_rec93_001bdff0_v8.verification.json`
- 2 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec93/orch1_rec93_001bdff0_v7.verification.json`
- 2 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec93/orch1_rec93_001bdff0_v6.verification.json`
- 2 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec93/orch1_rec93_001bdff0_v5.verification.json`
- 4 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec93/orch1_rec93_001bdff0_v4.verification.json`
- 4 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec93/orch1_rec93_001bdff0_v3.verification.json`
- 4 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec93/orch1_rec93_001bdff0_v2.verification.json`
- 24 differing words, 104/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec93/orch1_rec93_001bdff0_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/nm14/001bdff0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/nm14/001bdff0-packet.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec93/001bdff0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec93/001bdff0-packet.md`
