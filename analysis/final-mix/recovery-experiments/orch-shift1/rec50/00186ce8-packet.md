# Target packet 00186ce8

- Range: `00186ce8`..`00186d14`, **44 bytes = 11 instructions**. This size is the acceptance size.
- Layout name: `FUN_00186ce8`
- Registry names for this address: `_Z16ctarget_00186ce8jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00186ce8: 8c8f0140  lw	t7,320(a0)
00186cec: 0000102d  move	v0,zero
00186cf0: 11e00006  beqz	t7,0x186d0c
00186cf4: 24840140  addiu	a0,a0,320
00186cf8: 8c8e0014  lw	t6,20(a0)
00186cfc: 29cf000a  slti	t7,t6,10
00186d00: 29ce0028  slti	t6,t6,40
00186d04: 39ef0000  xori	t7,t7,0x0
00186d08: 01cf100a  movz	v0,t6,t7
00186d0c: 03e00008  jr	ra
00186d10: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00186ce8(void)`

```c
bool FUN_00186ce8(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(int *)(param_1 + 0x140) != 0) && (9 < *(int *)(param_1 + 0x154))) {
    bVar1 = *(int *)(param_1 + 0x154) < 0x28;
  }
  return bVar1;
}
```

## Earlier attempts (newest first)

- 10 differing words, 36/44 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_02.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_02.cpp`)
