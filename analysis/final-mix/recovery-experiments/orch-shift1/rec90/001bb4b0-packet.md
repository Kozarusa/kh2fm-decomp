# Target packet 001bb4b0

- Range: `001bb4b0`..`001bb4ec`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bb4b0`
- Registry names for this address: `func_001bb4b0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bb4b0: 27bdfff0  addiu	sp,sp,-16
001bb4b4: ffbf0000  sd	ra,0(sp)
001bb4b8: 0c06ed28  jal	0x1bb4a0
001bb4bc: 00000000  nop
001bb4c0: 10400006  beqz	v0,0x1bb4dc
001bb4c4: 0000702d  move	t6,zero
001bb4c8: 3c0f01d5  lui	t7,0x1d5
001bb4cc: 8ded9320  lw	t5,-27872(t7)   ; = D_01d49320
001bb4d0: 8dae0004  lw	t6,4(t5)
001bb4d4: 31ce0004  andi	t6,t6,0x4
001bb4d8: 2dce0001  sltiu	t6,t6,1
001bb4dc: dfbf0000  ld	ra,0(sp)
001bb4e0: 01c0102d  move	v0,t6
001bb4e4: 03e00008  jr	ra
001bb4e8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bb4b0(void)`

```c
bool FUN_001bb4b0(void)

{
  long lVar1;
  bool bVar2;
  
  lVar1 = FUN_001bb4a0();
  bVar2 = false;
  if (lVar1 != 0) {
    bVar2 = (*(uint *)(DAT_01d49320 + 4) & 4) == 0;
  }
  return bVar2;
}
```

## Earlier attempts (newest first)

- 6 differing words, 60/60 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round17_001bb4b0_v03.verification.json`
- 8 differing words, 64/60 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round17_001bb4b0_v02.verification.json`
- 6 differing words, 60/60 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round17_001bb4b0_v01.verification.json`
