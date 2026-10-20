# Target packet 001aae28

- Range: `001aae28`..`001aae64`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aae28`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aae28: 8faf0010  lw	t7,16(sp)
001aae2c: 27ae0000  addiu	t6,sp,0
001aae30: ac850000  sw	a1,0(a0)
001aae34: ac8f0018  sw	t7,24(a0)
001aae38: ac860004  sw	a2,4(a0)
001aae3c: ac870008  sw	a3,8(a0)
001aae40: ac88000c  sw	t0,12(a0)
001aae44: a0890010  sb	t1,16(a0)
001aae48: a08a0011  sb	t2,17(a0)
001aae4c: a08b0012  sb	t3,18(a0)
001aae50: 8dcf0000  lw	t7,0(t6)
001aae54: 8fae0008  lw	t6,8(sp)
001aae58: a08f0013  sb	t7,19(a0)
001aae5c: 03e00008  jr	ra
001aae60: ac8e0014  sw	t6,20(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aae28(void)`

```c
void FUN_001aae28(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                 undefined1 param_9,undefined4 param_10,undefined4 param_11)

{
  *param_1 = param_2;
  param_1[6] = param_11;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  *(undefined1 *)(param_1 + 4) = param_6;
  *(undefined1 *)((int)param_1 + 0x11) = param_7;
  *(undefined1 *)((int)param_1 + 0x12) = param_8;
  *(undefined1 *)((int)param_1 + 0x13) = param_9;
  param_1[5] = param_10;
  return;
}
```

## Earlier attempts (newest first)

- 18 differing words, 72/60 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_03.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_03.cpp`)
