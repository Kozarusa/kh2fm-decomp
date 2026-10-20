# Target packet 001db8b8

- Range: `001db8b8`..`001db8f4`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001db8b8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001db8b8: 8c8d000c  lw	t5,12(a0)
001db8bc: 8c8f0014  lw	t7,20(a0)
001db8c0: 00ad2823  subu	a1,a1,t5
001db8c4: 8c8e0008  lw	t6,8(a0)
001db8c8: 00af001b  divu	zero,a1,t7
001db8cc: 51e00001  beqzl	t7,0x1db8d4
001db8d0: 000001cd  break	0x7
001db8d4: 8c8d0010  lw	t5,16(a0)
001db8d8: 000e7880  sll	t7,t6,0x2
001db8dc: 00002812  mflo	a1
001db8e0: 01ed7821  addu	t7,t7,t5
001db8e4: 25ce0001  addiu	t6,t6,1
001db8e8: ade50000  sw	a1,0(t7)
001db8ec: 03e00008  jr	ra
001db8f0: ac8e0008  sw	t6,8(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001db8b8(void)`

```c
void FUN_001db8b8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 0x14) == 0) {
    trap(7);
  }
  *(int *)(iVar1 * 4 + *(int *)(param_1 + 0x10)) =
       (param_2 - *(int *)(param_1 + 0xc)) / *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 8) = iVar1 + 1;
  return;
}
```

## Earlier attempts (newest first)

- none found
