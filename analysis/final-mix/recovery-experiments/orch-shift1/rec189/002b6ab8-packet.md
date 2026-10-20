# Target packet 002b6ab8

- Range: `002b6ab8`..`002b6adc`, **36 bytes = 9 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b6ab8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b6ab8: 27bdfff0  addiu	sp,sp,-16
002b6abc: ffbe0000  sd	s8,0(sp)
002b6ac0: 03a0f02d  move	s8,sp
002b6ac4: 0000782d  move	t7,zero
002b6ac8: 01e0102d  move	v0,t7
002b6acc: 03c0e82d  move	sp,s8
002b6ad0: dfbe0000  ld	s8,0(sp)
002b6ad4: 03e00008  jr	ra
002b6ad8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b6ab8(void)`

```c
undefined8 FUN_002b6ab8(void)

{
  return 0;
}
```

## Earlier attempts (newest first)

- 8 differing words, 20/36 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round8_002b6ab8_v02.verification.json`
- 8 differing words, 20/36 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round8_002b6ab8_v01.verification.json`
