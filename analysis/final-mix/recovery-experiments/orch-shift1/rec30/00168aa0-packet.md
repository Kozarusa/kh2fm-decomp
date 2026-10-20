# Target packet 00168aa0

- Range: `00168aa0`..`00168ad8`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_00168aa0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00168aa0: 8c8f0004  lw	t7,4(a0)
00168aa4: 19e0000a  blez	t7,0x168ad0
00168aa8: 0000102d  move	v0,zero
00168aac: 24840010  addiu	a0,a0,16
00168ab0: 01e0682d  move	t5,t7
00168ab4: 948f0000  lhu	t7,0(a0)
00168ab8: 244e0001  addiu	t6,v0,1
00168abc: 25adffff  addiu	t5,t5,-1
00168ac0: 01e57826  xor	t7,t7,a1
00168ac4: 24840010  addiu	a0,a0,16
00168ac8: 15a0fffa  bnez	t5,0x168ab4
00168acc: 01cf100a  movz	v0,t6,t7
00168ad0: 03e00008  jr	ra
00168ad4: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00168aa0(void)`

```c
int FUN_00168aa0(ushort *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 2);
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      param_1 = param_1 + 8;
      iVar2 = iVar2 + -1;
      if (*param_1 == param_2) {
        iVar1 = iVar1 + 1;
      }
    } while (iVar2 != 0);
  }
  return iVar1;
}
```

## Earlier attempts (newest first)

- none found
