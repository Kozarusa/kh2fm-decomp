# Target packet 001d5b78

- Range: `001d5b78`..`001d5bb8`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d5b78`
- Registry names for this address: none
- Queue: state `leased`, queue `prologue-load-scheduling`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\001d5b78-REPORT.md", "sha256": "2204b2db5c645fd129d89d444bb1fb3a9eefdb4a9dbb6cac2df82f9bf010780c", "hypothesis": "Constrain loaded global through t6 register output after sll without function-entry barrier"}`

## Callees

- `002fd248` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_callbackfamily_recovered_001b8800.cpp`, `fm_primary_callbackfamily_recovered_001c0c38.cpp`, `fm_primary_callbackfamily_recovered_001c10f8.cpp`, `fm_primary_callbackfamily_recovered_001d22a8.cpp`, `fm_primary_callbackfamily_recovered_001d23e0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d5b78: 27bdfff0  addiu	sp,sp,-16
001d5b7c: 3c0f01d6  lui	t7,0x1d6
001d5b80: ffbf0000  sd	ra,0(sp)
001d5b84: 00042100  sll	a0,a0,0x4
001d5b88: 8deeba70  lw	t6,-17808(t7)   ; = D_01d5ba70
001d5b8c: 00852025  or	a0,a0,a1
001d5b90: 3c080032  lui	t0,0x32
001d5b94: 24070008  li	a3,8
001d5b98: 8dc60004  lw	a2,4(t6)
001d5b9c: 250817a0  addiu	t0,t0,6048   ; = D_003217a0
001d5ba0: 25ce0008  addiu	t6,t6,8
001d5ba4: 0c0bf492  jal	0x2fd248
001d5ba8: 01c0282d  move	a1,t6
001d5bac: dfbf0000  ld	ra,0(sp)
001d5bb0: 03e00008  jr	ra
001d5bb4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d5b78(void)`

```c
void FUN_001d5b78(int param_1,uint param_2)

{
  FUN_002fd248(param_1 << 4 | param_2,DAT_01d5ba70 + 8,*(undefined4 *)(DAT_01d5ba70 + 4),8,0x3217a0)
  ;
  return;
}
```

## Earlier attempts (newest first)

- 9 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-a/recovery_a_001d5b78_fc79ca3d_v7.verification.json`
- 9 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-a/recovery_a_001d5b78_fc79ca3d_v6.verification.json`
- 9 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-a/recovery_a_001d5b78_fc79ca3d_v5.verification.json`
- 14 differing words, 72/64 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-a/recovery_a_001d5b78_fc79ca3d_v4.verification.json`
- 9 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-a/recovery_a_001d5b78_fc79ca3d_v3.verification.json`
- 2 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-a/recovery_a_001d5b78_fc79ca3d_v2.verification.json`
- 2 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-a/recovery_a_001d5b78_fc79ca3d_v1.verification.json`
- 8 differing words, 60/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001d5b78_v01.verification.json`
- report: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-a/001d5b78-REPORT.md`
