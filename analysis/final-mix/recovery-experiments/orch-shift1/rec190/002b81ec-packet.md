# Target packet 002b81ec

- Range: `002b81ec`..`002b8214`, **40 bytes = 10 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b81ec`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b81ec: 27bdffe0  addiu	sp,sp,-32
002b81f0: ffbe0010  sd	s8,16(sp)
002b81f4: 03a0f02d  move	s8,sp
002b81f8: afc40000  sw	a0,0(s8)
002b81fc: 0000782d  move	t7,zero
002b8200: 01e0102d  move	v0,t7
002b8204: 03c0e82d  move	sp,s8
002b8208: dfbe0010  ld	s8,16(sp)
002b820c: 03e00008  jr	ra
002b8210: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b81ec(void)`

```c
undefined8 FUN_002b81ec(void)

{
  return 0;
}
```

## Earlier attempts (newest first)

- 10 differing words, 20/40 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round10_002b81ec_v01.verification.json`
