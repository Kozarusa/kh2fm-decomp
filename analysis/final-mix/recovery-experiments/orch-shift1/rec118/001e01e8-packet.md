# Target packet 001e01e8

- Range: `001e01e8`..`001e0230`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e01e8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e01e8: 8c8d000c  lw	t5,12(a0)
001e01ec: 11a0000e  beqz	t5,0x1e0228
001e01f0: 00000000  nop
001e01f4: 8dae0044  lw	t6,68(t5)
001e01f8: 8dcf0010  lw	t7,16(t6)
001e01fc: 31ef0200  andi	t7,t7,0x200
001e0200: 15e00004  bnez	t7,0x1e0214
001e0204: 00000000  nop
001e0208: 8daf0048  lw	t7,72(t5)
001e020c: 51e50001  beql	t7,a1,0x1e0214
001e0210: ada60048  sw	a2,72(t5)
001e0214: 55a00002  bnezl	t5,0x1e0220
001e0218: 8daf0060  lw	t7,96(t5)
001e021c: 8c8f000c  lw	t7,12(a0)
001e0220: 15e0fff4  bnez	t7,0x1e01f4
001e0224: 01e0682d  move	t5,t7
001e0228: 03e00008  jr	ra
001e022c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e01e8(void)`

```c
void FUN_001e01e8(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  while (iVar1 != 0) {
    if (((*(uint *)(*(int *)(iVar1 + 0x44) + 0x10) & 0x200) == 0) &&
       (*(int *)(iVar1 + 0x48) == param_2)) {
      *(undefined4 *)(iVar1 + 0x48) = param_3;
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x60);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 4 differing words, 72/72 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_05.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_05.cpp`)
