# Target packet 001c2ce8

- Range: `001c2ce8`..`001c2d34`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c2ce8`
- Registry names for this address: none
- Queue: state `leased`, queue `store-order`, attempts 6, priority 1
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\lay01\\001c2ce8-BLOCKED.md", "sha256": "87083b73e17fe8f525ada3a82c3b01bdcd06cfa5f3b82a6198daaf49a49b6f09", "hypothesis": "write the table store through a base the alias analysis cannot separate from the mode field (second pointer view or asm-opaque pointer copy used only for the table store) so the stores get an output dependence while the v1 load order and registers stay."}`

## Callees

- `001d7cd0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_queuedeltaprime_recovered_00185b00.cpp`, `fm_primary_queuedeltaprime_recovered_00185b70.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c2ce8: 27bdfff0  addiu	sp,sp,-16
001c2cec: ffb00000  sd	s0,0(sp)
001c2cf0: ffbf0008  sd	ra,8(sp)
001c2cf4: 0c075f34  jal	0x1d7cd0
001c2cf8: 0080802d  move	s0,a0
001c2cfc: 8e0d0588  lw	t5,1416(s0)
001c2d00: 3c0f0020  lui	t7,0x20
001c2d04: 8e0e0abc  lw	t6,2748(s0)
001c2d08: 01af6825  or	t5,t5,t7
001c2d0c: dfbf0008  ld	ra,8(sp)
001c2d10: 3c0f0035  lui	t7,0x35
001c2d14: ae0d0588  sw	t5,1416(s0)
001c2d18: 35ce0004  ori	t6,t6,0x4
001c2d1c: 25ef1468  addiu	t7,t7,5224   ; = D_00351468
001c2d20: ae0f0000  sw	t7,0(s0)
001c2d24: ae0e0abc  sw	t6,2748(s0)
001c2d28: dfb00000  ld	s0,0(sp)
001c2d2c: 03e00008  jr	ra
001c2d30: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c2ce8(void)`

```c
void FUN_001c2ce8(undefined4 *param_1)

{
  FUN_001d7cd0();
  param_1[0x162] = param_1[0x162] | 0x200000;
  *param_1 = &PTR_LAB_00351468;
  param_1[0x2af] = param_1[0x2af] | 4;
  return;
}
```

## Earlier attempts (newest first)

- 7 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/lay01/orch1_lay01_001c2ce8_v4.verification.json`
- 2 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/lay01/orch1_lay01_001c2ce8_v3.verification.json`
- 7 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/lay01/orch1_lay01_001c2ce8_v2.verification.json`
- 2 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/lay01/orch1_lay01_001c2ce8_v1.verification.json`
- 11 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_v4_precise_memory_order_1.verification.json`
- 11 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_v4_precise_memory_order_0.verification.json`
- 11 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_v3_precise_mode_store_1.verification.json`
- 12 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_v3_precise_mode_store_0.verification.json`
- 8 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_v2_final_mode_dependency_1.verification.json`
- 11 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_v2_final_mode_dependency_0.verification.json`
- 2 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_revisit_store_order_2.verification.json`
- 10 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_revisit_store_order_1.verification.json`
- 10 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_revisit_store_order_0.verification.json`
- 11 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_memory_barrier.verification.json`
- 2 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001c2ce8_flag_volatile.verification.json`
- report: `analysis/final-mix/recovery-experiments/eight-hour-20261011/001c2ce8-extended-constructor-report.md`
- report: `analysis/final-mix/recovery-experiments/eight-hour-20261011/001c2ce8-object-report.md`
- report: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/001c2ce8-REPORT.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/lay01/001c2ce8-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/lay01/001c2ce8-packet.md`
