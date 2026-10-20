# Target packet 001aa8a8

- Range: `001aa8a8`..`001aa8f0`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aa8a8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001aafe8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_scalar_extra_recovered_03.cpp`, `fm_scalar_recovered_03.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aa8a8: 27bdfff0  addiu	sp,sp,-16
001aa8ac: 00a0702d  move	t6,a1
001aa8b0: ffbf0000  sd	ra,0(sp)
001aa8b4: 0080782d  move	t7,a0
001aa8b8: 24850040  addiu	a1,a0,64
001aa8bc: 00c0682d  move	t5,a2
001aa8c0: c48d0028  lwc1	$f13,40(a0)
001aa8c4: 00e0602d  move	t4,a3
001aa8c8: 0100482d  move	t1,t0
001aa8cc: c5ec0024  lwc1	$f12,36(t7)
001aa8d0: 8c840000  lw	a0,0(a0)
001aa8d4: 01c0302d  move	a2,t6
001aa8d8: 01a0382d  move	a3,t5
001aa8dc: 0c06abfa  jal	0x1aafe8
001aa8e0: 0180402d  move	t0,t4
001aa8e4: dfbf0000  ld	ra,0(sp)
001aa8e8: 03e00008  jr	ra
001aa8ec: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aa8a8(void)`

```c
void FUN_001aa8a8(undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  FUN_001aafe8(param_1[9],param_1[10],*param_1,param_1 + 0x10,param_2,param_3,param_4,param_5);
  return;
}
```

## Earlier attempts (newest first)

- 16 differing words, 60/72 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_03.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_03.cpp`)
