# Target packet 0013efe8

- Range: `0013efe8`..`0013f020`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_0013efe8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102788` registry: `_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0013efe8: 27bdfff0  addiu	sp,sp,-16
0013efec: 3c0f0035  lui	t7,0x35
0013eff0: ffbf0000  sd	ra,0(sp)
0013eff4: 3c0e0033  lui	t6,0x33
0013eff8: a1e08700  sb	zero,-30976(t7)   ; = D_00348700
0013effc: 3c060004  lui	a2,0x4
0013f000: 8dc4b96c  lw	a0,-18068(t6)   ; = D_0032b96c
0013f004: 3c070014  lui	a3,0x14
0013f008: dfbf0000  ld	ra,0(sp)
0013f00c: 24e7ef90  addiu	a3,a3,-4208   ; = D_0013ef90
0013f010: 0000282d  move	a1,zero
0013f014: 34c693e0  ori	a2,a2,0x93e0
0013f018: 080409e2  j	0x102788
0013f01c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0013efe8(void)`

```c
void FUN_0013efe8(void)

{
  DAT_00348700 = 0;
  FUN_00102788(DAT_0032b96c,0,300000,0x13ef90);
  return;
}
```

## Earlier attempts (newest first)

- none found
