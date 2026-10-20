# Target packet 002b6ab8

- Range: `002b6ab8`..`002b6adc`, **36 bytes = 9 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b6ab8`
- Registry names for this address: none
- Queue: state `leased`, queue `prologue-epilogue`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec189\\002b6ab8-BLOCKED.md", "sha256": "fc086917d275fa2b07e4994e7c03c4540c9e3976f413041b283b67453b88bf76", "hypothesis": "C19 explicit frame restoration before the epilogue, copied from accepted 002b6b84, while preserving the guarded t7 and v0 transports."}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b6ab8: 27bdfff0  addiu	sp,sp,-16
002b6abc: ffbe0000  sd	s8,0(sp)
002b6ac0: 03a0f02d  move	s8,sp
002b6ac4: 0000782d  move	t7,zero
002b6ac8: 01e0102d  move	v0,t7
002b6acc: 03c0e82d  move	sp,s8
002b6ad0: dfbe0000  ld	s8,0(sp)
002b6ad4: 03e00008  jr	ra
002b6ad8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b6ab8(void)`

```c
undefined8 FUN_002b6ab8(void)

{
  return 0;
}
```

## Earlier attempts (newest first)

- 5 differing words, 32/36 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec189/orch1_rec189_002b6ab8_v7.verification.json`
- 5 differing words, 32/36 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec189/orch1_rec189_002b6ab8_v6.verification.json`
- 5 differing words, 32/36 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec189/orch1_rec189_002b6ab8_v5.verification.json`
- 6 differing words, 28/36 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec189/orch1_rec189_002b6ab8_v4.verification.json`
- 6 differing words, 28/36 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec189/orch1_rec189_002b6ab8_v3.verification.json`
- 9 differing words, 8/36 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec189/orch1_rec189_002b6ab8_v2.verification.json`
- 9 differing words, 8/36 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec189/orch1_rec189_002b6ab8_v1.verification.json`
- 8 differing words, 20/36 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round8_002b6ab8_v02.verification.json`
- 8 differing words, 20/36 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round8_002b6ab8_v01.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec189/002b6ab8-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec189/002b6ab8-packet.md`
