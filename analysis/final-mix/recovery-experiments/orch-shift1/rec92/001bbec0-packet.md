# Target packet 001bbec0

- Range: `001bbec0`..`001bbf00`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bbec0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001bbcb0` registry: `_ZN2YS7MISSION10GetCurrentEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bbec0: 27bdfff0  addiu	sp,sp,-16
001bbec4: ffbf0000  sd	ra,0(sp)
001bbec8: 0c06ed28  jal	0x1bb4a0
001bbecc: 00000000  nop
001bbed0: 10400007  beqz	v0,0x1bbef0
001bbed4: 0000782d  move	t7,zero
001bbed8: 0c06ef2c  jal	0x1bbcb0
001bbedc: 00000000  nop
001bbee0: 8c4e0008  lw	t6,8(v0)
001bbee4: 95cf0004  lhu	t7,4(t6)
001bbee8: 000f7ac2  srl	t7,t7,0xb
001bbeec: 31ef0001  andi	t7,t7,0x1
001bbef0: dfbf0000  ld	ra,0(sp)
001bbef4: 01e0102d  move	v0,t7
001bbef8: 03e00008  jr	ra
001bbefc: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bbec0(void)`

```c
ushort FUN_001bbec0(void)

{
  int iVar1;
  long lVar2;
  ushort uVar3;
  
  lVar2 = FUN_001bb4a0();
  uVar3 = 0;
  if (lVar2 != 0) {
    iVar1 = FUN_001bbcb0();
    uVar3 = *(ushort *)(*(int *)(iVar1 + 8) + 4) >> 0xb & 1;
  }
  return uVar3;
}
```

## Earlier attempts (newest first)

- 6 differing words, 68/64 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_06_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_06_0.cpp`)
- 11 differing words, 68/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bbec0_v07.verification.json`
- 13 differing words, 80/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bbec0_v06.verification.json`
- 13 differing words, 76/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bbec0_v05.verification.json`
- 14 differing words, 80/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bbec0_v04.verification.json`
- 13 differing words, 76/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001bbec0_v01.verification.json`
