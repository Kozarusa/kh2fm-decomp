# Target packet 001d8f38

- Range: `001d8f38`..`001d8fa4`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d8f38`
- Registry names for this address: `_ZN2YS7MISSION14IsGaugeWarningEi`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001bbcb0` registry: `_ZN2YS7MISSION10GetCurrentEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d8f38: 27bdfff0  addiu	sp,sp,-16
001d8f3c: ffb00000  sd	s0,0(sp)
001d8f40: ffbf0008  sd	ra,8(sp)
001d8f44: 0c06ed28  jal	0x1bb4a0
001d8f48: 0080802d  move	s0,a0
001d8f4c: 10400011  beqz	v0,0x1d8f94
001d8f50: 0000102d  move	v0,zero
001d8f54: 0c06ef2c  jal	0x1bbcb0
001d8f58: 00000000  nop
001d8f5c: 240f0034  li	t7,52
001d8f60: 020f8018  mult	s0,s0,t7
001d8f64: 00501021  addu	v0,v0,s0
001d8f68: 8c4f019c  lw	t7,412(v0)
001d8f6c: 31ef0001  andi	t7,t7,0x1
001d8f70: 31ef00ff  andi	t7,t7,0xff
001d8f74: 11e00007  beqz	t7,0x1d8f94
001d8f78: 0000102d  move	v0,zero
001d8f7c: 0c06ef2c  jal	0x1bbcb0
001d8f80: 00000000  nop
001d8f84: 00501021  addu	v0,v0,s0
001d8f88: 8c4f019c  lw	t7,412(v0)
001d8f8c: 31ef0008  andi	t7,t7,0x8
001d8f90: 000f102b  sltu	v0,zero,t7
001d8f94: dfb00000  ld	s0,0(sp)
001d8f98: dfbf0008  ld	ra,8(sp)
001d8f9c: 03e00008  jr	ra
001d8fa0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d8f38(void)`

```c
bool FUN_001d8f38(int param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = FUN_001bb4a0();
  bVar1 = false;
  if (lVar3 != 0) {
    iVar2 = FUN_001bbcb0();
    bVar1 = false;
    if ((*(uint *)(iVar2 + param_1 * 0x34 + 0x19c) & 1) != 0) {
      iVar2 = FUN_001bbcb0();
      bVar1 = (*(uint *)(iVar2 + param_1 * 0x34 + 0x19c) & 8) != 0;
    }
  }
  return bVar1;
}
```

## Earlier attempts (newest first)

- 29 differing words, 120/108 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_07_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_07_1.cpp`)
