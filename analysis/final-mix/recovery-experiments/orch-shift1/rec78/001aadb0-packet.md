# Target packet 001aadb0

- Range: `001aadb0`..`001aade4`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aadb0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002362b0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_more_recovered.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`
- `002367c8` registry: `func_002367c8`
  - accepted sources that already call it (copy their declaration): `fm_more_recovered.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_conditionfinish_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aadb0: 27bdfff0  addiu	sp,sp,-16
001aadb4: 0080282d  move	a1,a0
001aadb8: ffb00000  sd	s0,0(sp)
001aadbc: ffbf0008  sd	ra,8(sp)
001aadc0: 3c1001c7  lui	s0,0x1c7
001aadc4: 2610cd20  addiu	s0,s0,-13024   ; = D_01c6cd20
001aadc8: 0c08d8ac  jal	0x2362b0
001aadcc: 0200202d  move	a0,s0
001aadd0: 0200202d  move	a0,s0
001aadd4: dfbf0008  ld	ra,8(sp)
001aadd8: dfb00000  ld	s0,0(sp)
001aaddc: 0808d9f2  j	0x2367c8
001aade0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aadb0(void)`

```c
void FUN_001aadb0(undefined8 param_1)

{
  FUN_002362b0(0x1c6cd20,param_1);
  FUN_002367c8(0x1c6cd20);
  return;
}
```

## Earlier attempts (newest first)

- 11 differing words, 52/52 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.cpp`)
