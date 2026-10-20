# Target packet 002b740c

- Range: `002b740c`..`002b7440`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b740c`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b740c: 27bdffe0  addiu	sp,sp,-32
002b7410: ffbe0010  sd	s8,16(sp)
002b7414: 03a0f02d  move	s8,sp
002b7418: afc40000  sw	a0,0(s8)
002b741c: afc50004  sw	a1,4(s8)
002b7420: afc60008  sw	a2,8(s8)
002b7424: afc7000c  sw	a3,12(s8)
002b7428: 0000782d  move	t7,zero
002b742c: 01e0102d  move	v0,t7
002b7430: 03c0e82d  move	sp,s8
002b7434: dfbe0010  ld	s8,16(sp)
002b7438: 03e00008  jr	ra
002b743c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b740c(void)`

```c
undefined8 FUN_002b740c(void)

{
  return 0;
}
```

## Earlier attempts (newest first)

- 13 differing words, 8/52 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_08.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_08.cpp`)
