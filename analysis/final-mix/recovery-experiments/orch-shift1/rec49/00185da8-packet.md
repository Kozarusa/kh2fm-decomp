# Target packet 00185da8

- Range: `00185da8`..`00185ddc`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_00185da8`
- Registry names for this address: `_Z16ctarget_00185da8jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b9bc8` registry: `_Z16ctarget_001b9bc8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00185da8: 27bdfff0  addiu	sp,sp,-16
00185dac: ffbf0000  sd	ra,0(sp)
00185db0: 0c06e6f2  jal	0x1b9bc8
00185db4: 00000000  nop
00185db8: 10400005  beqz	v0,0x185dd0
00185dbc: 0040202d  move	a0,v0
00185dc0: 8c4f0588  lw	t7,1416(v0)
00185dc4: 31ef0010  andi	t7,t7,0x10
00185dc8: 11e0fff9  beqz	t7,0x185db0
00185dcc: 00000000  nop
00185dd0: dfbf0000  ld	ra,0(sp)
00185dd4: 03e00008  jr	ra
00185dd8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00185da8(void)`

```c
void FUN_00185da8(long param_1)

{
  do {
    param_1 = FUN_001b9bc8(param_1);
    if (param_1 == 0) {
      return;
    }
  } while ((*(uint *)((int)param_1 + 0x588) & 0x10) == 0);
  return;
}
```

## Earlier attempts (newest first)

- 10 differing words, 52/52 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_03_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_03_0.cpp`)
- 4 differing words, 48/52 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round13_00185da8_v02.verification.json`
- 10 differing words, 52/52 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round13_00185da8_v01.verification.json`
