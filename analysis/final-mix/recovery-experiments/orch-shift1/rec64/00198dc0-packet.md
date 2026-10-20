# Target packet 00198dc0

- Range: `00198dc0`..`00198e40`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_00198dc0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0019ef70` registry: `_ZN2YS6JUMPER5clearEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`, `fm_primary_sixword_recovered_0018f2a8.cpp`, `fm_primary_sixword_recovered_0018f2d0.cpp`
- `0031cc28` registry: `_Z13func_0031cc28Pv`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourword_recovered_00174e10.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00198dc0: 0080782d  move	t7,a0
00198dc4: 240effff  li	t6,-1
00198dc8: 340dffff  li	t5,0xffff
00198dcc: ac8e0000  sw	t6,0(a0)
00198dd0: ac8e0004  sw	t6,4(a0)
00198dd4: 248c0038  addiu	t4,a0,56
00198dd8: ac8d0008  sw	t5,8(a0)
00198ddc: 27bdfff0  addiu	sp,sp,-16
00198de0: ac8e000c  sw	t6,12(a0)
00198de4: 248b003c  addiu	t3,a0,60
00198de8: ade00010  sw	zero,16(t7)
00198dec: adee0014  sw	t6,20(t7)
00198df0: 24840054  addiu	a0,a0,84
00198df4: ade00018  sw	zero,24(t7)
00198df8: ade0001c  sw	zero,28(t7)
00198dfc: a5e0002e  sh	zero,46(t7)
00198e00: a1e00030  sb	zero,48(t7)
00198e04: a1ed0038  sb	t5,56(t7)
00198e08: a18e0002  sb	t6,2(t4)
00198e0c: a18e0001  sb	t6,1(t4)
00198e10: ffb00000  sd	s0,0(sp)
00198e14: ffbf0008  sd	ra,8(sp)
00198e18: a56e0004  sh	t6,4(t3)
00198e1c: 25f00034  addiu	s0,t7,52
00198e20: a5ed003c  sh	t5,60(t7)
00198e24: 0c0c730a  jal	0x31cc28
00198e28: a56e0002  sh	t6,2(t3)
00198e2c: 0200202d  move	a0,s0
00198e30: dfbf0008  ld	ra,8(sp)
00198e34: dfb00000  ld	s0,0(sp)
00198e38: 08067bdc  j	0x19ef70
00198e3c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00198dc0(void)`

```c
void FUN_00198dc0(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffff;
  param_1[3] = 0xffffffff;
  param_1[4] = 0;
  param_1[5] = 0xffffffff;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined2 *)((int)param_1 + 0x2e) = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 0xe) = 0xff;
  *(undefined1 *)((int)param_1 + 0x3a) = 0xff;
  *(undefined1 *)((int)param_1 + 0x39) = 0xff;
  *(undefined2 *)(param_1 + 0x10) = 0xffff;
  *(undefined2 *)(param_1 + 0xf) = 0xffff;
  *(undefined2 *)((int)param_1 + 0x3e) = 0xffff;
  FUN_0031cc28(param_1 + 0x15);
  FUN_0019ef70(param_1 + 0xd);
  return;
}
```

## Earlier attempts (newest first)

- 30 differing words, 124/128 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_04_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_04_1.cpp`)
