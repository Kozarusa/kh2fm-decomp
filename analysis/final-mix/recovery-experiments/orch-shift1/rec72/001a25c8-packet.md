# Target packet 001a25c8

- Range: `001a25c8`..`001a2618`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a25c8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a25c8: 8c8e0244  lw	t6,580(a0)
001a25cc: 51c0000c  beqzl	t6,0x1a2600
001a25d0: 948e018a  lhu	t6,394(a0)
001a25d4: 91cc000a  lbu	t4,10(t6)
001a25d8: 318d00ff  andi	t5,t4,0xff
001a25dc: 01a57821  addu	t7,t5,a1
001a25e0: 29ef0065  slti	t7,t7,101
001a25e4: 55e00004  bnezl	t7,0x1a25f8
001a25e8: 01857821  addu	t7,t4,a1
001a25ec: 240f0064  li	t7,100
001a25f0: 01ed2823  subu	a1,t7,t5
001a25f4: 01857821  addu	t7,t4,a1
001a25f8: a1cf000a  sb	t7,10(t6)
001a25fc: 948e018a  lhu	t6,394(a0)
001a2600: 948f0192  lhu	t7,402(a0)
001a2604: 01c57021  addu	t6,t6,a1
001a2608: 01e57821  addu	t7,t7,a1
001a260c: a48e018a  sh	t6,394(a0)
001a2610: 03e00008  jr	ra
001a2614: a48f0192  sh	t7,402(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a25c8(void)`

```c
void FUN_001a25c8(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  
  iVar3 = *(int *)(param_1 + 0x244);
  if (iVar3 == 0) {
    sVar2 = *(short *)(param_1 + 0x18a);
  }
  else {
    bVar1 = *(byte *)(iVar3 + 10);
    if ((int)((uint)bVar1 + param_2) < 0x65) {
      cVar4 = (char)param_2;
    }
    else {
      param_2 = 100 - (uint)bVar1;
      cVar4 = (char)param_2;
    }
    *(byte *)(iVar3 + 10) = bVar1 + cVar4;
    sVar2 = *(short *)(param_1 + 0x18a);
  }
  *(short *)(param_1 + 0x18a) = sVar2 + (short)param_2;
  *(short *)(param_1 + 0x192) = *(short *)(param_1 + 0x192) + (short)param_2;
  return;
}
```

## Earlier attempts (newest first)

- 18 differing words, 88/80 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_03.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_03.cpp`)
