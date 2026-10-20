# Target packet 001abdf0

- Range: `001abdf0`..`001abe48`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001abdf0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001abb78` registry: `func_001abb78`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`
- `00239bf8` registry: `_Z16wtarget_00239bf8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001abdf0: 0080602d  move	t4,a0
001abdf4: 27bdfff0  addiu	sp,sp,-16
001abdf8: ad850000  sw	a1,0(t4)
001abdfc: 00a0702d  move	t6,a1
001abe00: ffbf0000  sd	ra,0(sp)
001abe04: 24840004  addiu	a0,a0,4
001abe08: 24050041  li	a1,65
001abe0c: 240f0001  li	t7,1
001abe10: 11cf000a  beq	t6,t7,0x1abe3c
001abe14: 29cd0002  slti	t5,t6,2
001abe18: 15a00004  bnez	t5,0x1abe2c
001abe1c: dfbf0000  ld	ra,0(sp)
001abe20: 240f0002  li	t7,2
001abe24: 51cf0003  beql	t6,t7,0x1abe34
001abe28: 2584015c  addiu	a0,t4,348
001abe2c: 03e00008  jr	ra
001abe30: 27bd0010  addiu	sp,sp,16
001abe34: 0806aede  j	0x1abb78
001abe38: 27bd0010  addiu	sp,sp,16
001abe3c: dfbf0000  ld	ra,0(sp)
001abe40: 0808e6fe  j	0x239bf8
001abe44: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001abdf0(void)`

```c
void FUN_001abdf0(int *param_1,int param_2)

{
  *param_1 = param_2;
  if (param_2 == 1) {
    FUN_00239bf8(param_1 + 1,0x41);
    return;
  }
  if ((1 < param_2) && (param_2 == 2)) {
    FUN_001abb78(param_1 + 0x57);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- 19 differing words, 84/88 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_1.cpp`)
