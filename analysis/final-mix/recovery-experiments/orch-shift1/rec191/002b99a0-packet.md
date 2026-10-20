# Target packet 002b99a0

- Range: `002b99a0`..`002b99c8`, **40 bytes = 10 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b99a0`
- Registry names for this address: `_Z16ctarget_002b99a0jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b99a0: 27bdfff0  addiu	sp,sp,-16
002b99a4: ffbe0000  sd	s8,0(sp)
002b99a8: 03a0f02d  move	s8,sp
002b99ac: 3c0f01e3  lui	t7,0x1e3
002b99b0: 8defa3c0  lw	t7,-23616(t7)   ; = D_01e2a3c0
002b99b4: 01e0102d  move	v0,t7
002b99b8: 03c0e82d  move	sp,s8
002b99bc: dfbe0000  ld	s8,0(sp)
002b99c0: 03e00008  jr	ra
002b99c4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b99a0(void)`

```c
undefined4 FUN_002b99a0(void)

{
  return DAT_01e2a3c0;
}
```

## Earlier attempts (newest first)

- 9 differing words, 24/40 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round7_002b99a0_v03.verification.json`
- 10 differing words, 12/40 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round7_002b99a0_v02.verification.json`
- 10 differing words, 12/40 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round7_002b99a0_v01.verification.json`
