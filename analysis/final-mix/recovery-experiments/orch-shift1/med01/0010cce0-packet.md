# Target packet 0010cce0

- Range: `0010cce0`..`0010cd30`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_0010cce0`
- Registry names for this address: none
- Queue: state `leased`, queue `medium-register-and-branch`, attempts 3, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\eight-hour-20261011\\0010cce0-medium-blocker.md", "sha256": "b163c99498eefaf6a58d0146f22206eab4043456752bef1bf695238dc00e3ca8", "hypothesis": "Focused source family still differs in native scheduling, register allocation or branch layout; see immutable probe census."}`

## Callees

- `00112d28` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`, `fm_primary_order_recovered_00132130.cpp`
- `001b9bc8` registry: `_Z16ctarget_001b9bc8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0010cce0: 27bdfff0  addiu	sp,sp,-16
0010cce4: ffb00000  sd	s0,0(sp)
0010cce8: ffbf0008  sd	ra,8(sp)
0010ccec: 0080802d  move	s0,a0
0010ccf0: 0c06e6f2  jal	0x1b9bc8
0010ccf4: 0200202d  move	a0,s0
0010ccf8: 0040802d  move	s0,v0
0010ccfc: 14400006  bnez	v0,0x10cd18
0010cd00: 0040202d  move	a0,v0
0010cd04: 0200102d  move	v0,s0
0010cd08: dfbf0008  ld	ra,8(sp)
0010cd0c: dfb00000  ld	s0,0(sp)
0010cd10: 03e00008  jr	ra
0010cd14: 27bd0010  addiu	sp,sp,16
0010cd18: 0c044b4a  jal	0x112d28
0010cd1c: 00000000  nop
0010cd20: 1440fff9  bnez	v0,0x10cd08
0010cd24: 0200102d  move	v0,s0
0010cd28: 1000fff1  b	0x10ccf0
0010cd2c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0010cce0(void)`

```c
long FUN_0010cce0(long param_1)

{
  long lVar1;
  
  do {
    param_1 = FUN_001b9bc8(param_1);
    if (param_1 == 0) {
      return 0;
    }
    lVar1 = FUN_00112d28(param_1);
  } while (lVar1 == 0);
  return param_1;
}
```

## Earlier attempts (newest first)

- 13 differing words, 76/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0010cce0_node_return_lifetime_v3_2.verification.json`
- 13 differing words, 76/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0010cce0_node_return_lifetime_v3_1.verification.json`
- 12 differing words, 72/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0010cce0_node_return_lifetime_v2_0.verification.json`
- 13 differing words, 76/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0010cce0_medium_scalar_v1_1.verification.json`
- 13 differing words, 76/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0010cce0_medium_scalar_v1_0.verification.json`
- report: `analysis/final-mix/recovery-experiments/eight-hour-20261011/0010cce0-medium-blocker.md`
