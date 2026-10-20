# Target packet 0018e0d8

- Range: `0018e0d8`..`0018e108`, **48 bytes = 12 instructions**. This size is the acceptance size.
- Layout name: `FUN_0018e0d8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0018e0d8: 240f0003  li	t7,3
0018e0dc: 14af0002  bne	a1,t7,0x18e0e8
0018e0e0: 00a0682d  move	t5,a1
0018e0e4: 240d0004  li	t5,4
0018e0e8: 31ae00ff  andi	t6,t5,0xff
0018e0ec: a08d002c  sb	t5,44(a0)
0018e0f0: 240f0001  li	t7,1
0018e0f4: 01cf7804  sllv	t7,t7,t6
0018e0f8: 35ef0001  ori	t7,t7,0x1
0018e0fc: 000f7827  nor	t7,zero,t7
0018e100: 03e00008  jr	ra
0018e104: a08f002d  sb	t7,45(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0018e0d8(void)`

```c
void FUN_0018e0d8(int param_1,uint param_2)

{
  if (param_2 == 3) {
    param_2 = 4;
  }
  *(char *)(param_1 + 0x2c) = (char)param_2;
  *(byte *)(param_1 + 0x2d) = ~((byte)(1 << (param_2 & 0x1f)) | 1);
  return;
}
```

## Earlier attempts (newest first)

- 12 differing words, 44/48 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_02.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_02.cpp`)
