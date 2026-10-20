# Target packet 001bba88

- Range: `001bba88`..`001bbabc`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bba88`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001bba30` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bba88: 27bdfff0  addiu	sp,sp,-16
001bba8c: ffbf0000  sd	ra,0(sp)
001bba90: 0c06ed28  jal	0x1bb4a0
001bba94: 00000000  nop
001bba98: 10400006  beqz	v0,0x1bbab4
001bba9c: 3c0f01d5  lui	t7,0x1d5
001bbaa0: 0c06ee8c  jal	0x1bba30
001bbaa4: 8de49320  lw	a0,-27872(t7)   ; = D_01d49320
001bbaa8: dfbf0000  ld	ra,0(sp)
001bbaac: 03e00008  jr	ra
001bbab0: 27bd0010  addiu	sp,sp,16
001bbab4: 1000fffc  b	0x1bbaa8
001bbab8: 0000102d  move	v0,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bba88(void)`

```c
undefined8 FUN_001bba88(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_001bb4a0();
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_001bba30(DAT_01d49320);
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- 3 differing words, 44/52 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round13_001bba88_v02.verification.json`
- 10 differing words, 56/52 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round13_001bba88_v01.verification.json`
