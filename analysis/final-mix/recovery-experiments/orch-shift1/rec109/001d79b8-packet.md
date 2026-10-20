# Target packet 001d79b8

- Range: `001d79b8`..`001d7a08`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d79b8`
- Registry names for this address: `func_001d79b8`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d7b10` registry: `func_001d7b10`
  - accepted sources that already call it (copy their declaration): `fm_primary_argument_recovered.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d79b8: 27bdfff0  addiu	sp,sp,-16
001d79bc: 0000502d  move	t2,zero
001d79c0: ffbf0000  sd	ra,0(sp)
001d79c4: 0000582d  move	t3,zero
001d79c8: 248d0004  addiu	t5,a0,4
001d79cc: 8daf0000  lw	t7,0(t5)
001d79d0: 11e5000b  beq	t7,a1,0x1d7a00
001d79d4: 39ec0000  xori	t4,t7,0x0
001d79d8: 256b0001  addiu	t3,t3,1
001d79dc: 01ac500a  movz	t2,t5,t4
001d79e0: 296f0004  slti	t7,t3,4
001d79e4: 15e0fff9  bnez	t7,0x1d79cc
001d79e8: 25ad0008  addiu	t5,t5,8
001d79ec: e54c0004  swc1	$f12,4(t2)
001d79f0: ad450000  sw	a1,0(t2)
001d79f4: dfbf0000  ld	ra,0(sp)
001d79f8: 08075ec4  j	0x1d7b10
001d79fc: 27bd0010  addiu	sp,sp,16
001d7a00: 1000fffa  b	0x1d79ec
001d7a04: 01a0502d  move	t2,t5
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d79b8(void)`

```c
void FUN_001d79b8(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)0x0;
  iVar3 = 0;
  piVar4 = (int *)(param_2 + 4);
  do {
    piVar2 = piVar4;
    if (*piVar4 == param_3) break;
    iVar3 = iVar3 + 1;
    if (*piVar4 == 0) {
      piVar1 = piVar4;
    }
    piVar4 = piVar4 + 2;
    piVar2 = piVar1;
  } while (iVar3 < 4);
  piVar2[1] = param_1;
  *piVar2 = param_3;
  FUN_001d7b10();
  return;
}
```

## Earlier attempts (newest first)

- 18 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_1.cpp`)
