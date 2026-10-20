# Target packet 001ca448

- Range: `001ca448`..`001ca494`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ca448`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ca448: 8c8e0154  lw	t6,340(a0)
001ca44c: 240f002c  li	t7,44
001ca450: 11cf0007  beq	t6,t7,0x1ca470
001ca454: 29cd002d  slti	t5,t6,45
001ca458: 11a00007  beqz	t5,0x1ca478
001ca45c: 240f0010  li	t7,16
001ca460: 11cf0003  beq	t6,t7,0x1ca470
001ca464: 00000000  nop
001ca468: 03e00008  jr	ra
001ca46c: 24020001  li	v0,1
001ca470: 03e00008  jr	ra
001ca474: 0000102d  move	v0,zero
001ca478: 240f00a1  li	t7,161
001ca47c: 15cffffa  bne	t6,t7,0x1ca468
001ca480: 00000000  nop
001ca484: 8c8f0588  lw	t7,1416(a0)
001ca488: 31ef0080  andi	t7,t7,0x80
001ca48c: 03e00008  jr	ra
001ca490: 2de20001  sltiu	v0,t7,1
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ca448(void)`

```c
bool FUN_001ca448(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x154);
  if (iVar1 == 0x2c) {
    return false;
  }
  if (iVar1 < 0x2d) {
    if (iVar1 == 0x10) {
      return false;
    }
  }
  else if (iVar1 == 0xa1) {
    return (*(uint *)(param_1 + 0x588) & 0x80) == 0;
  }
  return true;
}
```

## Earlier attempts (newest first)

- none found
