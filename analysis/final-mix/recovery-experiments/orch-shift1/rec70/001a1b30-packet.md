# Target packet 001a1b30

- Range: `001a1b30`..`001a1b68`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a1b30`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a1b30: 908f01b1  lbu	t7,433(a0)
001a1b34: 908d01b2  lbu	t5,434(a0)
001a1b38: 31ee00ff  andi	t6,t7,0xff
001a1b3c: 01c0782d  move	t7,t6
001a1b40: 01c57023  subu	t6,t6,a1
001a1b44: 01e5602a  slt	t4,t7,a1
001a1b48: 11ed0003  beq	t7,t5,0x1a1b58
001a1b4c: 29cb0000  slti	t3,t6,0
001a1b50: 51800003  beqzl	t4,0x1a1b60
001a1b54: 000b700b  movn	t6,zero,t3
001a1b58: a08001b0  sb	zero,432(a0)
001a1b5c: 000b700b  movn	t6,zero,t3
001a1b60: 03e00008  jr	ra
001a1b64: a08e01b1  sb	t6,433(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a1b30(void)`

```c
void FUN_001a1b30(int param_1,long param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 0x1b1);
  iVar2 = (uint)bVar1 - (int)param_2;
  if (((ulong)bVar1 == (ulong)*(byte *)(param_1 + 0x1b2)) || ((long)(ulong)bVar1 < param_2)) {
    *(undefined1 *)(param_1 + 0x1b0) = 0;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
  }
  else if (iVar2 < 0) {
    iVar2 = 0;
  }
  *(char *)(param_1 + 0x1b1) = (char)iVar2;
  return;
}
```

## Earlier attempts (newest first)

- 16 differing words, 68/56 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_03.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_03.cpp`)
