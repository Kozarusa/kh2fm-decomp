# Target packet 001bd618

- Range: `001bd618`..`001bd668`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bd618`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002ba2e8` registry: `_ZN5SOUND12systemSePlayEii`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bd618: 27bdfff0  addiu	sp,sp,-16
001bd61c: 30a500ff  andi	a1,a1,0xff
001bd620: ffbf0000  sd	ra,0(sp)
001bd624: 248d09e8  addiu	t5,a0,2536
001bd628: 8c8e08c0  lw	t6,2240(a0)
001bd62c: adc00000  sw	zero,0(t6)
001bd630: 8c8f08c0  lw	t7,2240(a0)
001bd634: 15ed000a  bne	t7,t5,0x1bd660
001bd638: 25eefffc  addiu	t6,t7,-4
001bd63c: ac8008c0  sw	zero,2240(a0)
001bd640: 10a00005  beqz	a1,0x1bd658
001bd644: dfbf0000  ld	ra,0(sp)
001bd648: 24040004  li	a0,4
001bd64c: 0000282d  move	a1,zero
001bd650: 080ae8ba  j	0x2ba2e8
001bd654: 27bd0010  addiu	sp,sp,16
001bd658: 03e00008  jr	ra
001bd65c: 27bd0010  addiu	sp,sp,16
001bd660: 1000fff7  b	0x1bd640
001bd664: ac8e08c0  sw	t6,2240(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bd618(void)`

```c
void FUN_001bd618(int param_1,char param_2)

{
  **(undefined4 **)(param_1 + 0x8c0) = 0;
  if (*(int *)(param_1 + 0x8c0) == param_1 + 0x9e8) {
    *(undefined4 *)(param_1 + 0x8c0) = 0;
  }
  else {
    *(int *)(param_1 + 0x8c0) = *(int *)(param_1 + 0x8c0) + -4;
  }
  if (param_2 != '\0') {
    FUN_002ba2e8(4,0);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_0.cpp`)
