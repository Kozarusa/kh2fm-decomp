# Target packet 0029ec40

- Range: `0029ec40`..`0029ec98`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_0029ec40`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0029ec40: 3c0e0037  lui	t6,0x37
0029ec44: 0000102d  move	v0,zero
0029ec48: 95cf4aa0  lhu	t7,19104(t6)   ; = D_00374aa0
0029ec4c: 11e00010  beqz	t7,0x29ec90
0029ec50: 0000602d  move	t4,zero
0029ec54: 25cb4aa0  addiu	t3,t6,19104   ; = D_00374aa0
0029ec58: 0000682d  move	t5,zero
0029ec5c: 01ab7821  addu	t7,t5,t3
0029ec60: 95ee0000  lhu	t6,0(t7)
0029ec64: 55c40004  bnel	t6,a0,0x29ec78
0029ec68: 258c0001  addiu	t4,t4,1
0029ec6c: 03e00008  jr	ra
0029ec70: 24020001  li	v0,1
0029ec74: 00000000  nop
0029ec78: 000c7840  sll	t7,t4,0x1
0029ec7c: 01e0682d  move	t5,t7
0029ec80: 01eb7021  addu	t6,t7,t3
0029ec84: 95cf0000  lhu	t7,0(t6)
0029ec88: 15e0fff5  bnez	t7,0x29ec60
0029ec8c: 01ab7821  addu	t7,t5,t3
0029ec90: 03e00008  jr	ra
0029ec94: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0029ec40(void)`

```c
undefined4 FUN_0029ec40(ulong param_1)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = 0;
  if (DAT_00374aa0 != 0) {
    puVar2 = (ushort *)&DAT_00374aa0;
    do {
      if (*puVar2 == param_1) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      puVar2 = (ushort *)(&DAT_00374aa0 + iVar1);
    } while ((&DAT_00374aa0)[iVar1] != 0);
  }
  return 0;
}
```

## Earlier attempts (newest first)

- none found
