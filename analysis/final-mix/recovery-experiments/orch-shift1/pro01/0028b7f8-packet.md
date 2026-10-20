# Target packet 0028b7f8

- Range: `0028b7f8`..`0028b830`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028b7f8`
- Registry names for this address: `func_0028b7f8`
- Queue: state `leased`, queue `address-prologue-scheduling`, attempts 3, priority 1
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\eight-hour-20261011\\0028b7f8-object-report.md", "sha256": "b0e5fd1a4e6c4944b160e30d526e03f5c98db9f9b29e3a84217491e4950dd7fd", "hypothesis": "Explicit original object argument is supported but retains save/store swap; investigate joint address and prologue scheduling without repeating typed profiles."}`

## Callees

- `0023f820` registry: `func_0023f820`
- `0028b8a0` registry: `func_0028b8a0`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028b7f8: 27bdfff0  addiu	sp,sp,-16
0028b7fc: 3c0f0036  lui	t7,0x36
0028b800: 25eff3a0  addiu	t7,t7,-3168   ; = D_0035f3a0
0028b804: ffb00000  sd	s0,0(sp)
0028b808: ffbf0008  sd	ra,8(sp)
0028b80c: ac8f0000  sw	t7,0(a0)
0028b810: 0c0a2e28  jal	0x28b8a0
0028b814: 0080802d  move	s0,a0
0028b818: 0c08fe08  jal	0x23f820
0028b81c: 0200202d  move	a0,s0
0028b820: dfb00000  ld	s0,0(sp)
0028b824: dfbf0008  ld	ra,8(sp)
0028b828: 03e00008  jr	ra
0028b82c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028b7f8(void)`

```c
void FUN_0028b7f8(undefined8 param_1)

{
  *(undefined4 *)param_1 = &PTR_FUN_0035f3a0;
  FUN_0028b8a0();
  FUN_0023f820(param_1);
  return;
}
```

## Earlier attempts (newest first)

- 2 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0028b7f8_object_voidpointer_1.verification.json`
- 2 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0028b7f8_object_voidpointer_0.verification.json`
- 2 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0028b7f8_object_u32_1.verification.json`
- 2 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0028b7f8_object_u32_0.verification.json`
- 2 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-b/recovery_b_0028b7f8_8aba2384_tablestoreprecise.verification.json`
- 4 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-b/recovery_b_0028b7f8_8aba2384_tablestorememory.verification.json`
- 4 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-b/recovery_b_0028b7f8_8aba2384_tablemarker.verification.json`
- 2 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-b/recovery_b_0028b7f8_8aba2384_pointerstore.verification.json`
- 6 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/fm_primary_linkorder_v1_0028b7f8.verification.json`
- 6 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/fm_primary_destructors_v1_0028b7f8_2.verification.json`
- 2 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/fm_primary_destructors_v1_0028b7f8_1.verification.json`
- 4 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round15_0028b7f8_v05.verification.json`
- 4 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round15_0028b7f8_v04.verification.json`
- 6 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round15_0028b7f8_v03.verification.json`
- 2 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round15_0028b7f8_v02.verification.json`
- report: `analysis/final-mix/recovery-experiments/eight-hour-20261011/0028b7f8-object-report.md`
- report: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-b/0028b7f8-blocked.md`
