# Target packet 00227cd8

- Range: `00227cd8`..`00227d10`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_00227cd8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00227cd8: 3c0f0036  lui	t7,0x36
00227cdc: 0000682d  move	t5,zero
00227ce0: 8deedcfc  lw	t6,-8964(t7)   ; = D_0035dcfc
00227ce4: 8dcf0000  lw	t7,0(t6)
00227ce8: 01c0102d  move	v0,t6
00227cec: 11e40006  beq	t7,a0,0x227d08
00227cf0: 25ce0028  addiu	t6,t6,40
00227cf4: 25ad0001  addiu	t5,t5,1
00227cf8: 29af0060  slti	t7,t5,96
00227cfc: 55e0fffa  bnezl	t7,0x227ce8
00227d00: 8dcf0000  lw	t7,0(t6)
00227d04: 0000102d  move	v0,zero
00227d08: 03e00008  jr	ra
00227d0c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00227cd8(void)`

```c
int * FUN_00227cd8(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = *DAT_0035dcfc;
  piVar1 = DAT_0035dcfc;
  while( true ) {
    if (iVar3 == param_1) {
      return piVar1;
    }
    iVar2 = iVar2 + 1;
    if (0x5f < iVar2) break;
    iVar3 = piVar1[10];
    piVar1 = piVar1 + 10;
  }
  return (int *)0x0;
}
```

## Earlier attempts (newest first)

- none found
