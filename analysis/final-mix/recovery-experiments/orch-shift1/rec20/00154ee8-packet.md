# Target packet 00154ee8

- Range: `00154ee8`..`00154f30`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_00154ee8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00154ee8: 8c8e0018  lw	t6,24(a0)
00154eec: 24020043  li	v0,67
00154ef0: 240f0001  li	t7,1
00154ef4: 11cf0006  beq	t6,t7,0x154f10
00154ef8: 29cd0002  slti	t5,t6,2
00154efc: 51a00008  beqzl	t5,0x154f20
00154f00: 240f0002  li	t7,2
00154f04: 11c00004  beqz	t6,0x154f18
00154f08: 00000000  nop
00154f0c: 24020048  li	v0,72
00154f10: 03e00008  jr	ra
00154f14: 00000000  nop
00154f18: 03e00008  jr	ra
00154f1c: 24020048  li	v0,72
00154f20: 55cffffb  bnel	t6,t7,0x154f10
00154f24: 24020048  li	v0,72
00154f28: 1000fffb  b	0x154f18
00154f2c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00154ee8(void)`

```c
undefined4 FUN_00154ee8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  uVar2 = 0x43;
  if (iVar1 != 1) {
    if (iVar1 < 2) {
      if (iVar1 == 0) {
        return 0x48;
      }
      uVar2 = 0x48;
    }
    else {
      if (iVar1 == 2) {
        return 0x48;
      }
      uVar2 = 0x48;
    }
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- none found
