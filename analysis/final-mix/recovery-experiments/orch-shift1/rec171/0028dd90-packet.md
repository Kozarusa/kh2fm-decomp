# Target packet 0028dd90

- Range: `0028dd90`..`0028ddd4`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028dd90`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028dd90: 240f000a  li	t7,10
0028dd94: 0000102d  move	v0,zero
0028dd98: 008f001a  div	zero,a0,t7
0028dd9c: 51e00001  beqzl	t7,0x28dda4
0028dda0: 000001cd  break	0x7
0028dda4: 00007010  mfhi	t6
0028dda8: 240f0001  li	t7,1
0028ddac: 11cf0007  beq	t6,t7,0x28ddcc
0028ddb0: 29cd0002  slti	t5,t6,2
0028ddb4: 15a00003  bnez	t5,0x28ddc4
0028ddb8: 240f0002  li	t7,2
0028ddbc: 51cf0001  beql	t6,t7,0x28ddc4
0028ddc0: 24020001  li	v0,1
0028ddc4: 03e00008  jr	ra
0028ddc8: 00000000  nop
0028ddcc: 03e00008  jr	ra
0028ddd0: 24020002  li	v0,2
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028dd90(void)`

```c
/* WARNING: Removing unreachable block (ram,0x0028dd9c) */

undefined4 FUN_0028dd90(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  param_1 = param_1 % 10;
  if (param_1 == 1) {
    return 2;
  }
  if ((1 < param_1) && (param_1 == 2)) {
    uVar1 = 1;
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- none found
