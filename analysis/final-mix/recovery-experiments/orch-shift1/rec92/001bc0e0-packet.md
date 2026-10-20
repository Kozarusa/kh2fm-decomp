# Target packet 001bc0e0

- Range: `001bc0e0`..`001bc12c`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bc0e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001bbcb0` registry: `_ZN2YS7MISSION10GetCurrentEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bc0e0: 27bdfff0  addiu	sp,sp,-16
001bc0e4: ffb00000  sd	s0,0(sp)
001bc0e8: ffbf0008  sd	ra,8(sp)
001bc0ec: 0c06ed28  jal	0x1bb4a0
001bc0f0: 0000802d  move	s0,zero
001bc0f4: 50400008  beqzl	v0,0x1bc118
001bc0f8: 24100001  li	s0,1
001bc0fc: 0c06ef2c  jal	0x1bbcb0
001bc100: 00000000  nop
001bc104: 8c4f0004  lw	t7,4(v0)
001bc108: 31ef0010  andi	t7,t7,0x10
001bc10c: 15e00003  bnez	t7,0x1bc11c
001bc110: 0200102d  move	v0,s0
001bc114: 24100001  li	s0,1
001bc118: 0200102d  move	v0,s0
001bc11c: dfbf0008  ld	ra,8(sp)
001bc120: dfb00000  ld	s0,0(sp)
001bc124: 03e00008  jr	ra
001bc128: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bc0e0(void)`

```c
undefined4 FUN_001bc0e0(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_001bb4a0();
  if ((lVar2 != 0) && (iVar1 = FUN_001bbcb0(), (*(uint *)(iVar1 + 4) & 0x10) != 0)) {
    return 0;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 16 differing words, 76/76 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_04.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_04.cpp`)
