# Target packet 00198aa8

- Range: `00198aa8`..`00198ae0`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_00198aa8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00198aa8: 14e00006  bnez	a3,0x198ac4
00198aac: 240e03e8  li	t6,1000
00198ab0: 8c8f09b4  lw	t7,2484(a0)
00198ab4: 11e00003  beqz	t7,0x198ac4
00198ab8: 2407ffff  li	a3,-1
00198abc: 85e70002  lh	a3,2(t7)
00198ac0: 240e03e8  li	t6,1000
00198ac4: 240f000c  li	t7,12
00198ac8: 00ee7018  mult	t6,a3,t6
00198acc: 00af7818  mult	t7,a1,t7
00198ad0: 01c67021  addu	t6,t6,a2
00198ad4: 008f7821  addu	t7,a0,t7
00198ad8: 03e00008  jr	ra
00198adc: adee09e4  sw	t6,2532(t7)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00198aa8(void)`

```c
void FUN_00198aa8(int param_1,int param_2,int param_3,long param_4)

{
  if (param_4 == 0) {
    param_4 = -1;
    if (*(int *)(param_1 + 0x9b4) != 0) {
      param_4 = (long)*(short *)(*(int *)(param_1 + 0x9b4) + 2);
    }
  }
  *(int *)(param_1 + param_2 * 0xc + 0x9e4) = (int)param_4 * 1000 + param_3;
  return;
}
```

## Earlier attempts (newest first)

- 11 differing words, 64/56 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_03.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_03.cpp`)
