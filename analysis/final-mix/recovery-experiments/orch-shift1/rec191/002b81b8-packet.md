# Target packet 002b81b8

- Range: `002b81b8`..`002b81ec`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b81b8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b81b8: 27bdffe0  addiu	sp,sp,-32
002b81bc: ffbe0010  sd	s8,16(sp)
002b81c0: 03a0f02d  move	s8,sp
002b81c4: afc40000  sw	a0,0(s8)
002b81c8: afc50004  sw	a1,4(s8)
002b81cc: afc60008  sw	a2,8(s8)
002b81d0: afc7000c  sw	a3,12(s8)
002b81d4: 0000782d  move	t7,zero
002b81d8: 01e0102d  move	v0,t7
002b81dc: 03c0e82d  move	sp,s8
002b81e0: dfbe0010  ld	s8,16(sp)
002b81e4: 03e00008  jr	ra
002b81e8: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b81b8(void)`

```c
undefined8 FUN_002b81b8(void)

{
  return 0;
}
```

## Earlier attempts (newest first)

- 13 differing words, 8/52 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_08.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_08.cpp`)
