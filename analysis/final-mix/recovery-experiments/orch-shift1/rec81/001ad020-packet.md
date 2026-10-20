# Target packet 001ad020

- Range: `001ad020`..`001ad098`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ad020`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00239bf8` registry: `_Z16wtarget_00239bf8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ad020: 27bdffe0  addiu	sp,sp,-32
001ad024: 24e7000a  addiu	a3,a3,10
001ad028: ffb00000  sd	s0,0(sp)
001ad02c: ffb10008  sd	s1,8(sp)
001ad030: ffb20010  sd	s2,16(sp)
001ad034: 24100158  li	s0,344
001ad038: ffbf0018  sd	ra,24(sp)
001ad03c: 00c0882d  move	s1,a2
001ad040: 00a0902d  move	s2,a1
001ad044: 26318d00  addiu	s1,s1,-29440
001ad048: 8c8f0b68  lw	t7,2920(a0)
001ad04c: 00e0282d  move	a1,a3
001ad050: 26529000  addiu	s2,s2,-28672
001ad054: 00118903  sra	s1,s1,0x4
001ad058: 01f08018  mult	s0,t7,s0
001ad05c: 00129103  sra	s2,s2,0x4
001ad060: 25ef0001  addiu	t7,t7,1
001ad064: 00908021  addu	s0,a0,s0
001ad068: ac8f0b68  sw	t7,2920(a0)
001ad06c: 26100608  addiu	s0,s0,1544
001ad070: 0c08e6fe  jal	0x239bf8
001ad074: 0200202d  move	a0,s0
001ad078: ae11014c  sw	s1,332(s0)
001ad07c: ae120148  sw	s2,328(s0)
001ad080: dfb10008  ld	s1,8(sp)
001ad084: dfb00000  ld	s0,0(sp)
001ad088: dfb20010  ld	s2,16(sp)
001ad08c: dfbf0018  ld	ra,24(sp)
001ad090: 03e00008  jr	ra
001ad094: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ad020(void)`

```c
void FUN_001ad020(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = param_1 + *(int *)(param_1 + 0xb68) * 0x158;
  *(int *)(param_1 + 0xb68) = *(int *)(param_1 + 0xb68) + 1;
  FUN_00239bf8(iVar1 + 0x608,param_4 + 10);
  *(int *)(iVar1 + 0x754) = param_3 + -0x7300 >> 4;
  *(int *)(iVar1 + 0x750) = param_2 + -0x7000 >> 4;
  return;
}
```

## Earlier attempts (newest first)

- 17 differing words, 116/120 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_0.cpp`)
