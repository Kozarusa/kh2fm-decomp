# Target packet 0017edf0

- Range: `0017edf0`..`0017ee68`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_0017edf0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001a97b8` registry: `_ZNK2YS9MOTIONSET9is_playerEv`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_fourword_recovered_00174e10.cpp`, `fm_primary_oneword_recovered_0017dfc8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0017edf0: 27bdffe0  addiu	sp,sp,-32
0017edf4: ffb00000  sd	s0,0(sp)
0017edf8: ffb10008  sd	s1,8(sp)
0017edfc: ffbf0010  sd	ra,16(sp)
0017ee00: 0080802d  move	s0,a0
0017ee04: 04a00004  bltz	a1,0x17ee18
0017ee08: 00a0882d  move	s1,a1
0017ee0c: 8c8f0000  lw	t7,0(a0)
0017ee10: 55e00008  bnezl	t7,0x17ee34
0017ee14: 8c8f0004  lw	t7,4(a0)
0017ee18: 0000782d  move	t7,zero
0017ee1c: dfb00000  ld	s0,0(sp)
0017ee20: 01e0102d  move	v0,t7
0017ee24: dfb10008  ld	s1,8(sp)
0017ee28: dfbf0010  ld	ra,16(sp)
0017ee2c: 03e00008  jr	ra
0017ee30: 27bd0020  addiu	sp,sp,32
0017ee34: 11e00005  beqz	t7,0x17ee4c
0017ee38: 01e0202d  move	a0,t7
0017ee3c: 0c06a5ee  jal	0x1a97b8
0017ee40: 00000000  nop
0017ee44: 1440fff5  bnez	v0,0x17ee1c
0017ee48: 0040782d  move	t7,v0
0017ee4c: 8e040000  lw	a0,0(s0)
0017ee50: 0220282d  move	a1,s1
0017ee54: dfb10008  ld	s1,8(sp)
0017ee58: dfb00000  ld	s0,0(sp)
0017ee5c: dfbf0010  ld	ra,16(sp)
0017ee60: 0806a5ee  j	0x1a97b8
0017ee64: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0017edf0(void)`

```c
long FUN_0017edf0(int *param_1,long param_2)

{
  long lVar1;
  
  if ((param_2 < 0) || (*param_1 == 0)) {
    lVar1 = 0;
  }
  else if ((param_1[1] == 0) || (lVar1 = FUN_001a97b8(param_1[1]), lVar1 == 0)) {
    lVar1 = FUN_001a97b8(*param_1,param_2);
    return lVar1;
  }
  return lVar1;
}
```

## Earlier attempts (newest first)

- 20 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_03_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_03_0.cpp`)
