# Target packet 001abba8

- Range: `001abba8`..`001abbf0`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_001abba8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0023acd8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`
- `0023ade0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001abba8: 27bdffe0  addiu	sp,sp,-32
001abbac: ffb00000  sd	s0,0(sp)
001abbb0: ffb10008  sd	s1,8(sp)
001abbb4: 24900014  addiu	s0,a0,20
001abbb8: ffbf0010  sd	ra,16(sp)
001abbbc: 0080882d  move	s1,a0
001abbc0: 0c08eb36  jal	0x23acd8
001abbc4: 0200202d  move	a0,s0
001abbc8: 8e2e0010  lw	t6,16(s1)
001abbcc: 0200202d  move	a0,s0
001abbd0: 8e2f000c  lw	t7,12(s1)
001abbd4: dfbf0010  ld	ra,16(sp)
001abbd8: ae0e014c  sw	t6,332(s0)
001abbdc: ae0f0148  sw	t7,328(s0)
001abbe0: dfb10008  ld	s1,8(sp)
001abbe4: dfb00000  ld	s0,0(sp)
001abbe8: 0808eb78  j	0x23ade0
001abbec: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001abba8(void)`

```c
void FUN_001abba8(int param_1)

{
  FUN_0023acd8(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(param_1 + 0xc);
  FUN_0023ade0(param_1 + 0x14);
  return;
}
```

## Earlier attempts (newest first)

- 11 differing words, 72/72 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_0.cpp`)
