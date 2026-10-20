# Target packet 001abe80

- Range: `001abe80`..`001abf00`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_001abe80`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001abbf0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`
- `001ac728` registry: `_ZN2YS11MESSAGEDRAW9next_pageEv`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`
- `002ba2e8` registry: `_ZN5SOUND12systemSePlayEii`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001abe80: 27bdfff0  addiu	sp,sp,-16
001abe84: 240f0001  li	t7,1
001abe88: ffb00000  sd	s0,0(sp)
001abe8c: ffbf0008  sd	ra,8(sp)
001abe90: 00a0802d  move	s0,a1
001abe94: 8c8e0000  lw	t6,0(a0)
001abe98: 11cf000d  beq	t6,t7,0x1abed0
001abe9c: 29cd0002  slti	t5,t6,2
001abea0: 15a00005  bnez	t5,0x1abeb8
001abea4: dfb00000  ld	s0,0(sp)
001abea8: 240f0002  li	t7,2
001abeac: 51cf0005  beql	t6,t7,0x1abec4
001abeb0: 2484015c  addiu	a0,a0,348
001abeb4: dfb00000  ld	s0,0(sp)
001abeb8: dfbf0008  ld	ra,8(sp)
001abebc: 03e00008  jr	ra
001abec0: 27bd0010  addiu	sp,sp,16
001abec4: dfbf0008  ld	ra,8(sp)
001abec8: 0806aefc  j	0x1abbf0
001abecc: 27bd0010  addiu	sp,sp,16
001abed0: dccf0008  ld	t7,8(a2)
001abed4: 31ef040c  andi	t7,t7,0x40c
001abed8: 51e0fff7  beqzl	t7,0x1abeb8
001abedc: dfb00000  ld	s0,0(sp)
001abee0: 24040018  li	a0,24
001abee4: 0c0ae8ba  jal	0x2ba2e8
001abee8: 0000282d  move	a1,zero
001abeec: 0200202d  move	a0,s0
001abef0: dfbf0008  ld	ra,8(sp)
001abef4: dfb00000  ld	s0,0(sp)
001abef8: 0806b1ca  j	0x1ac728
001abefc: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001abe80(void)`

```c
void FUN_001abe80(int *param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 1) {
    if ((*(ulong *)(param_3 + 8) & 0x40c) != 0) {
      FUN_002ba2e8(0x18,0);
      FUN_001ac728(param_2);
      return;
    }
  }
  else if ((1 < iVar1) && (iVar1 == 2)) {
    FUN_001abbf0(param_1 + 0x57);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- 27 differing words, 120/128 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.cpp`)
