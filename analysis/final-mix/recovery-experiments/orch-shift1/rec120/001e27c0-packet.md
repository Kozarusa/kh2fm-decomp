# Target packet 001e27c0

- Range: `001e27c0`..`001e27f4`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e27c0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e17b8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e27c0: 27bdfff0  addiu	sp,sp,-16
001e27c4: ac800dc0  sw	zero,3520(a0)
001e27c8: ffbf0000  sd	ra,0(sp)
001e27cc: 240effff  li	t6,-1
001e27d0: ac8e0e00  sw	t6,3584(a0)
001e27d4: ac800dc4  sw	zero,3524(a0)
001e27d8: ac800dcc  sw	zero,3532(a0)
001e27dc: ac800dd0  sw	zero,3536(a0)
001e27e0: ac800de4  sw	zero,3556(a0)
001e27e4: ac800dec  sw	zero,3564(a0)
001e27e8: dfbf0000  ld	ra,0(sp)
001e27ec: 080785ee  j	0x1e17b8
001e27f0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e27c0(void)`

```c
void FUN_001e27c0(int param_1)

{
  *(undefined4 *)(param_1 + 0xdc0) = 0;
  *(undefined4 *)(param_1 + 0xe00) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xdc4) = 0;
  *(undefined4 *)(param_1 + 0xdcc) = 0;
  *(undefined4 *)(param_1 + 0xdd0) = 0;
  *(undefined4 *)(param_1 + 0xde4) = 0;
  *(undefined4 *)(param_1 + 0xdec) = 0;
  FUN_001e17b8();
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 52/52 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.cpp`)
