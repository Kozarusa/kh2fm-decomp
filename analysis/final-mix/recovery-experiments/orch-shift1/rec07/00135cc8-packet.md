# Target packet 00135cc8

- Range: `00135cc8`..`00135cfc`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_00135cc8`
- Registry names for this address: `func_00135cc8`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00135cc8: 8c8d000c  lw	t5,12(a0)
00135ccc: 19a00009  blez	t5,0x135cf4
00135cd0: 0000702d  move	t6,zero
00135cd4: 8c8f0010  lw	t7,16(a0)
00135cd8: 55e50003  bnel	t7,a1,0x135ce8
00135cdc: 25ce0001  addiu	t6,t6,1
00135ce0: 03e00008  jr	ra
00135ce4: ac860010  sw	a2,16(a0)
00135ce8: 01cd782a  slt	t7,t6,t5
00135cec: 15e0fff9  bnez	t7,0x135cd4
00135cf0: 24840004  addiu	a0,a0,4
00135cf4: 03e00008  jr	ra
00135cf8: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00135cc8(void)`

```c
void FUN_00135cc8(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0xc);
  iVar2 = 0;
  if (0 < *piVar1) {
    do {
      if (*(int *)(param_1 + 0x10) == param_2) {
        *(undefined4 *)(param_1 + 0x10) = param_3;
        return;
      }
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 4;
    } while (iVar2 < *piVar1);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
