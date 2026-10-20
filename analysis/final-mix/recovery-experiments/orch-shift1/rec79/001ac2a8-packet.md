# Target packet 001ac2a8

- Range: `001ac2a8`..`001ac30c`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ac2a8`
- Registry names for this address: `_Z16wtarget_001ac2a8jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00239bf8` registry: `_Z16wtarget_00239bf8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ac2a8: 27bdffd0  addiu	sp,sp,-48
001ac2ac: ffb00000  sd	s0,0(sp)
001ac2b0: ffb10008  sd	s1,8(sp)
001ac2b4: ffb20010  sd	s2,16(sp)
001ac2b8: 0080802d  move	s0,a0
001ac2bc: ffb30018  sd	s3,24(sp)
001ac2c0: 00a0882d  move	s1,a1
001ac2c4: ffbf0020  sd	ra,32(sp)
001ac2c8: 2484000c  addiu	a0,a0,12
001ac2cc: 24a50001  addiu	a1,a1,1
001ac2d0: 00c0982d  move	s3,a2
001ac2d4: 12200003  beqz	s1,0x1ac2e4
001ac2d8: 00e0902d  move	s2,a3
001ac2dc: 0c08e6fe  jal	0x239bf8
001ac2e0: 00000000  nop
001ac2e4: ae120008  sw	s2,8(s0)
001ac2e8: ae110000  sw	s1,0(s0)
001ac2ec: ae130004  sw	s3,4(s0)
001ac2f0: dfb10008  ld	s1,8(sp)
001ac2f4: dfb00000  ld	s0,0(sp)
001ac2f8: dfb20010  ld	s2,16(sp)
001ac2fc: dfb30018  ld	s3,24(sp)
001ac300: dfbf0020  ld	ra,32(sp)
001ac304: 03e00008  jr	ra
001ac308: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ac2a8(void)`

```c
void FUN_001ac2a8(int *param_1,long param_2,int param_3,int param_4)

{
  if (param_2 != 0) {
    FUN_00239bf8(param_1 + 3,(int)param_2 + 1);
  }
  param_1[2] = param_4;
  *param_1 = (int)param_2;
  param_1[1] = param_3;
  return;
}
```

## Earlier attempts (newest first)

- 7 differing words, 100/100 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.cpp`)
