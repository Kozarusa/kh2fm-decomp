# Target packet 002b8a70

- Range: `002b8a70`..`002b8ac0`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b8a70`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002b78ec` registry: `_Z16wtarget_002b78ecjjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_queuelambdaprime_recovered_002b78ec.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_storeorder_recovered_00281f90.cpp`, `fm_primary_width_recovered_02.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b8a70: 27bdffe0  addiu	sp,sp,-32
002b8a74: ffbe0010  sd	s8,16(sp)
002b8a78: ffbf0018  sd	ra,24(sp)
002b8a7c: 03a0f02d  move	s8,sp
002b8a80: afc40000  sw	a0,0(s8)
002b8a84: 8fce0000  lw	t6,0(s8)
002b8a88: 340f8000  li	t7,0x8000
002b8a8c: 01cf7821  addu	t7,t6,t7
002b8a90: 0c0ade3b  jal	0x2b78ec
002b8a94: 01e0202d  move	a0,t7
002b8a98: 8fce0000  lw	t6,0(s8)
002b8a9c: 3c0f0004  lui	t7,0x4
002b8aa0: 35ef8000  ori	t7,t7,0x8000
002b8aa4: 01cf7821  addu	t7,t6,t7
002b8aa8: ade00000  sw	zero,0(t7)
002b8aac: 03c0e82d  move	sp,s8
002b8ab0: dfbe0010  ld	s8,16(sp)
002b8ab4: dfbf0018  ld	ra,24(sp)
002b8ab8: 03e00008  jr	ra
002b8abc: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b8a70(void)`

```c
void FUN_002b8a70(int param_1)

{
  FUN_002b78ec(param_1 + 0x8000);
  *(undefined4 *)(param_1 + 0x48000) = 0;
  return;
}
```

## Earlier attempts (newest first)

- 20 differing words, 60/80 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_01_all.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_01_all.cpp`)
