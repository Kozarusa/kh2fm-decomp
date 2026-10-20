# Target packet 00180ef0

- Range: `00180ef0`..`00180f28`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_00180ef0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00180ef0: 0000682d  move	t5,zero
00180ef4: 3c0c0200  lui	t4,0x200
00180ef8: 55a00002  bnezl	t5,0x180f04
00180efc: 8dae002c  lw	t6,44(t5)
00180f00: 8c8e018c  lw	t6,396(a0)
00180f04: 15c00004  bnez	t6,0x180f18
00180f08: 01c0682d  move	t5,t6
00180f0c: ac80018c  sw	zero,396(a0)
00180f10: 03e00008  jr	ra
00180f14: ac800190  sw	zero,400(a0)
00180f18: 8dcf0008  lw	t7,8(t6)
00180f1c: 01ec7825  or	t7,t7,t4
00180f20: 1000fff5  b	0x180ef8
00180f24: adcf0008  sw	t7,8(t6)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00180ef0(void)`

```c
void FUN_00180ef0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x18c);
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x2c);
    }
    if (iVar1 == 0) break;
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 0x2000000;
  }
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 400) = 0;
  return;
}
```

## Earlier attempts (newest first)

- 13 differing words, 52/56 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_02.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_02.cpp`)
