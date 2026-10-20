# Target packet 001afe30

- Range: `001afe30`..`001afe6c`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001afe30`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001afe30: 3c0f01c9  lui	t7,0x1c9
001afe34: 0000682d  move	t5,zero
001afe38: 25ef4090  addiu	t7,t7,16528   ; = D_01c94090
001afe3c: 25ec0004  addiu	t4,t7,4
001afe40: 8d8f0000  lw	t7,0(t4)
001afe44: 01a0102d  move	v0,t5
001afe48: 25ad0001  addiu	t5,t5,1
001afe4c: 258c000c  addiu	t4,t4,12
001afe50: 11e40004  beq	t7,a0,0x1afe64
001afe54: 29ae0003  slti	t6,t5,3
001afe58: 55c0fffa  bnezl	t6,0x1afe44
001afe5c: 8d8f0000  lw	t7,0(t4)
001afe60: 2402ffff  li	v0,-1
001afe64: 03e00008  jr	ra
001afe68: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001afe30(void)`

```c
int FUN_001afe30(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = &DAT_01c94094;
  iVar3 = DAT_01c94094;
  iVar2 = 0;
  while( true ) {
    piVar1 = piVar1 + 3;
    if (iVar3 == param_1) {
      return iVar2;
    }
    if (2 < iVar2 + 1) break;
    iVar3 = *piVar1;
    iVar2 = iVar2 + 1;
  }
  return -1;
}
```

## Earlier attempts (newest first)

- 15 differing words, 64/60 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
