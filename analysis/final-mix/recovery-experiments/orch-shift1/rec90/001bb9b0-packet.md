# Target packet 001bb9b0

- Range: `001bb9b0`..`001bb9f0`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bb9b0`
- Registry names for this address: `func_001bb9b0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bb9b0: 27bdfff0  addiu	sp,sp,-16
001bb9b4: ffbf0000  sd	ra,0(sp)
001bb9b8: 0c06ed28  jal	0x1bb4a0
001bb9bc: 00000000  nop
001bb9c0: 10400007  beqz	v0,0x1bb9e0
001bb9c4: 0000782d  move	t7,zero
001bb9c8: 3c0f01d5  lui	t7,0x1d5
001bb9cc: 8dee9320  lw	t6,-27872(t7)   ; = D_01d49320
001bb9d0: 8dcd0008  lw	t5,8(t6)
001bb9d4: 95af0004  lhu	t7,4(t5)
001bb9d8: 000f7902  srl	t7,t7,0x4
001bb9dc: 31ef0001  andi	t7,t7,0x1
001bb9e0: dfbf0000  ld	ra,0(sp)
001bb9e4: 01e0102d  move	v0,t7
001bb9e8: 03e00008  jr	ra
001bb9ec: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bb9b0(void)`

```c
ushort FUN_001bb9b0(void)

{
  long lVar1;
  ushort uVar2;
  
  lVar1 = FUN_001bb4a0();
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = *(ushort *)(*(int *)(DAT_01d49320 + 8) + 4) >> 4 & 1;
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- 6 differing words, 68/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bb9b0_v07.verification.json`
- 10 differing words, 72/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bb9b0_v06.verification.json`
- 6 differing words, 68/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bb9b0_v05.verification.json`
- 9 differing words, 72/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bb9b0_v04.verification.json`
- 6 differing words, 68/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bb9b0_v03.verification.json`
- 6 differing words, 68/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bb9b0_v02.verification.json`
- 10 differing words, 72/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bb9b0_v01.verification.json`
