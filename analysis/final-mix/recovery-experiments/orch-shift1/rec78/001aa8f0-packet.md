# Target packet 001aa8f0

- Range: `001aa8f0`..`001aa93c`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aa8f0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001ab260` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aa8f0: 27bdfff0  addiu	sp,sp,-16
001aa8f4: 00a0702d  move	t6,a1
001aa8f8: ffbf0000  sd	ra,0(sp)
001aa8fc: 0080782d  move	t7,a0
001aa900: 24850040  addiu	a1,a0,64
001aa904: 00c0682d  move	t5,a2
001aa908: c48d0028  lwc1	$f13,40(a0)
001aa90c: 00e0602d  move	t4,a3
001aa910: 0100482d  move	t1,t0
001aa914: 8dea0038  lw	t2,56(t7)
001aa918: 8c840000  lw	a0,0(a0)
001aa91c: 01c0302d  move	a2,t6
001aa920: c5ec0024  lwc1	$f12,36(t7)
001aa924: 01a0382d  move	a3,t5
001aa928: 0c06ac98  jal	0x1ab260
001aa92c: 0180402d  move	t0,t4
001aa930: dfbf0000  ld	ra,0(sp)
001aa934: 03e00008  jr	ra
001aa938: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aa8f0(void)`

```c
void FUN_001aa8f0(undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  FUN_001ab260(param_1[9],param_1[10],*param_1,param_1 + 0x10,param_2,param_3,param_4,param_5,
               param_1[0xe]);
  return;
}
```

## Earlier attempts (newest first)

- 19 differing words, 68/76 bytes: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_05_0.cpp`)
