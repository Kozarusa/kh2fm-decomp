# Target packet 001aaf98

- Range: `001aaf98`..`001aafe4`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aaf98`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aaf98: 00a73821  addu	a3,a1,a3
001aaf9c: 28e77000  slti	a3,a3,28672
001aafa0: 14e0000d  bnez	a3,0x1aafd8
001aafa4: 0000102d  move	v0,zero
001aafa8: 340f9000  li	t7,0x9000
001aafac: 01e5782a  slt	t7,t7,a1
001aafb0: 55e0000a  bnezl	t7,0x1aafdc
001aafb4: 24020001  li	v0,1
001aafb8: 28cf7300  slti	t7,a2,29440
001aafbc: 55e00007  bnezl	t7,0x1aafdc
001aafc0: 24020001  li	v0,1
001aafc4: 00c87023  subu	t6,a2,t0
001aafc8: 340f8d00  li	t7,0x8d00
001aafcc: 01ee782a  slt	t7,t7,t6
001aafd0: 11e00002  beqz	t7,0x1aafdc
001aafd4: 00000000  nop
001aafd8: 24020001  li	v0,1
001aafdc: 03e00008  jr	ra
001aafe0: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aaf98(void)`

```c
undefined4 FUN_001aaf98(undefined8 param_1,long param_2,long param_3,int param_4,int param_5)

{
  if (0x6fff < (int)param_2 + param_4) {
    if (0x9000 < param_2) {
      return 1;
    }
    if (param_3 < 0x7300) {
      return 1;
    }
    if ((int)param_3 - param_5 < 0x8d01) {
      return 0;
    }
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 20 differing words, 84/76 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_03.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_03.cpp`)
