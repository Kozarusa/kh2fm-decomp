# Target packet 001b1bb8

- Range: `001b1bb8`..`001b1be0`, **40 bytes = 10 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b1bb8`
- Registry names for this address: none
- Queue: state `leased`, queue `byte-prologue-scheduling`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\eight-hour-20261011\\001b1bb8-byte-forwarding-report.md", "sha256": "a2944d53985fdffcf621cb065d4168e15372b9c14c81a02add23f58da27b44ab", "hypothesis": "Float/object forwarding is now explicit and child exact; coordinate native prologue timing with byte-store order. Avoid repeated cursor markers or byte-formal profiles."}`

## Callees

- `001b1be0` registry: `func_001b1be0`
  - accepted sources that already call it (copy their declaration): `fm_fallback_small.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_queuexi_recovered_001b1be0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b1bb8: 27bdfff0  addiu	sp,sp,-16
001b1bbc: a0850014  sb	a1,20(a0)
001b1bc0: ffbf0000  sd	ra,0(sp)
001b1bc4: 248f0014  addiu	t7,a0,20
001b1bc8: a1e80003  sb	t0,3(t7)
001b1bcc: a1e60001  sb	a2,1(t7)
001b1bd0: a1e70002  sb	a3,2(t7)
001b1bd4: dfbf0000  ld	ra,0(sp)
001b1bd8: 0806c6f8  j	0x1b1be0
001b1bdc: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b1bb8(void)`

```c
void FUN_001b1bb8(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5)

{
  *(undefined1 *)(param_1 + 0x14) = param_2;
  *(undefined1 *)(param_1 + 0x17) = param_5;
  *(undefined1 *)(param_1 + 0x15) = param_3;
  *(undefined1 *)(param_1 + 0x16) = param_4;
  FUN_001b1be0();
  return;
}
```

## Earlier attempts (newest first)

- 13 differing words, 56/40 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001b1bb8_v5_u8_ordered.verification.json`
- 12 differing words, 56/40 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001b1bb8_v5_u8_baseline.verification.json`
- 4 differing words, 40/40 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001b1bb8_v4_precise_first.verification.json`
- 4 differing words, 40/40 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001b1bb8_v4_volatile_first.verification.json`
- 4 differing words, 40/40 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001b1bb8_v3_cursor_order_1.verification.json`
- 4 differing words, 40/40 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001b1bb8_v3_cursor_order_0.verification.json`
- 7 differing words, 40/40 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001b1bb8_v2_volatile_cursor.verification.json`
- 3 differing words, 40/40 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001b1bb8_float_forward_1.verification.json`
- 8 differing words, 36/40 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_001b1bb8_float_forward_0.verification.json`
- report: `analysis/final-mix/recovery-experiments/eight-hour-20261011/001b1bb8-byte-forwarding-report.md`
