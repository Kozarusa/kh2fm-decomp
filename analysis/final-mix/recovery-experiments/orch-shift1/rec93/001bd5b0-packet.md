# Target packet 001bd5b0

- Range: `001bd5b0`..`001bd614`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bd5b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002ba2e8` registry: `_ZN5SOUND12systemSePlayEii`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bd5b0: 27bdfff0  addiu	sp,sp,-16
001bd5b4: 248d09e8  addiu	t5,a0,2536
001bd5b8: ffbf0000  sd	ra,0(sp)
001bd5bc: 30c600ff  andi	a2,a2,0xff
001bd5c0: 8c8f08c0  lw	t7,2240(a0)
001bd5c4: 15e00011  bnez	t7,0x1bd60c
001bd5c8: 25ee0004  addiu	t6,t7,4
001bd5cc: ac8d08c0  sw	t5,2240(a0)
001bd5d0: 240e0074  li	t6,116
001bd5d4: 8c8f08c0  lw	t7,2240(a0)
001bd5d8: 00ae7018  mult	t6,a1,t6
001bd5dc: 008e7021  addu	t6,a0,t6
001bd5e0: 25ce0024  addiu	t6,t6,36
001bd5e4: 10c00006  beqz	a2,0x1bd600
001bd5e8: adee0000  sw	t6,0(t7)
001bd5ec: dfbf0000  ld	ra,0(sp)
001bd5f0: 24040003  li	a0,3
001bd5f4: 0000282d  move	a1,zero
001bd5f8: 080ae8ba  j	0x2ba2e8
001bd5fc: 27bd0010  addiu	sp,sp,16
001bd600: dfbf0000  ld	ra,0(sp)
001bd604: 03e00008  jr	ra
001bd608: 27bd0010  addiu	sp,sp,16
001bd60c: 1000fff0  b	0x1bd5d0
001bd610: ac8e08c0  sw	t6,2240(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bd5b0(void)`

```c
void FUN_001bd5b0(int param_1,int param_2,char param_3)

{
  if (*(int *)(param_1 + 0x8c0) == 0) {
    *(int *)(param_1 + 0x8c0) = param_1 + 0x9e8;
  }
  else {
    *(int *)(param_1 + 0x8c0) = *(int *)(param_1 + 0x8c0) + 4;
  }
  **(int **)(param_1 + 0x8c0) = param_1 + param_2 * 0x74 + 0x24;
  if (param_3 != '\0') {
    FUN_002ba2e8(3,0);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- 22 differing words, 96/100 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_1.cpp`)
