# Target packet 0019f8c0

- Range: `0019f8c0`..`0019f8f4`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019f8c0`
- Registry names for this address: none
- Queue: state `leased`, queue `branch-layout`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec70\\0019f8c0-BLOCKED.md", "sha256": "a617cb476e2cc6a0be64e95d15b22543037b44d1d9b662df8d5fbb2db50254f3", "hypothesis": "On v4 early-return shape, separate sum variable or asm barrier to avoid movz; original is bnez with addu in delay slot then move v0,zero"}`

## Callees

- `0019f7d0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019f8c0: 27bdfff0  addiu	sp,sp,-16
0019f8c4: ffbf0000  sd	ra,0(sp)
0019f8c8: 0c067df4  jal	0x19f7d0
0019f8cc: 00000000  nop
0019f8d0: 50400005  beqzl	v0,0x19f8e8
0019f8d4: 0000102d  move	v0,zero
0019f8d8: 944f0002  lhu	t7,2(v0)
0019f8dc: 15e00002  bnez	t7,0x19f8e8
0019f8e0: 004f1021  addu	v0,v0,t7
0019f8e4: 0000102d  move	v0,zero
0019f8e8: dfbf0000  ld	ra,0(sp)
0019f8ec: 03e00008  jr	ra
0019f8f0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019f8c0(void)`

```c
int FUN_0019f8c0(void)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = FUN_0019f7d0();
  if (lVar3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar1 = *(ushort *)((int)lVar3 + 2);
    iVar2 = (int)lVar3 + (uint)uVar1;
    if (uVar1 == 0) {
      iVar2 = 0;
    }
  }
  return iVar2;
}
```

## Earlier attempts (newest first)

- 6 differing words, 52/52 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.cpp`)
- 7 differing words, 48/52 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec70/orch1_rec70_0019f8c0_v4.verification.json`
- 8 differing words, 56/52 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec70/orch1_rec70_0019f8c0_v3.verification.json`
- 7 differing words, 52/52 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec70/orch1_rec70_0019f8c0_v2.verification.json`
- 6 differing words, 52/52 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec70/orch1_rec70_0019f8c0_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec70/0019f8c0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec70/0019f8c0-packet.md`
