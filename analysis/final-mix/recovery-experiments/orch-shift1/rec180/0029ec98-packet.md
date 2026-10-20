# Target packet 0029ec98

- Range: `0029ec98`..`0029ecf0`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_0029ec98`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0029ec98: 3c0e0037  lui	t6,0x37
0029ec9c: 0000102d  move	v0,zero
0029eca0: 95cf4aa8  lhu	t7,19112(t6)   ; = D_00374aa8
0029eca4: 11e00010  beqz	t7,0x29ece8
0029eca8: 0000602d  move	t4,zero
0029ecac: 25cb4aa8  addiu	t3,t6,19112   ; = D_00374aa8
0029ecb0: 0000682d  move	t5,zero
0029ecb4: 01ab7821  addu	t7,t5,t3
0029ecb8: 95ee0000  lhu	t6,0(t7)
0029ecbc: 55c40004  bnel	t6,a0,0x29ecd0
0029ecc0: 258c0001  addiu	t4,t4,1
0029ecc4: 03e00008  jr	ra
0029ecc8: 24020001  li	v0,1
0029eccc: 00000000  nop
0029ecd0: 000c7840  sll	t7,t4,0x1
0029ecd4: 01e0682d  move	t5,t7
0029ecd8: 01eb7021  addu	t6,t7,t3
0029ecdc: 95cf0000  lhu	t7,0(t6)
0029ece0: 15e0fff5  bnez	t7,0x29ecb8
0029ece4: 01ab7821  addu	t7,t5,t3
0029ece8: 03e00008  jr	ra
0029ecec: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0029ec98(void)`

```c
undefined4 FUN_0029ec98(ulong param_1)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = 0;
  if (DAT_00374aa8 != 0) {
    puVar2 = (ushort *)&DAT_00374aa8;
    do {
      if (*puVar2 == param_1) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      puVar2 = (ushort *)(&DAT_00374aa8 + iVar1);
    } while ((&DAT_00374aa8)[iVar1] != 0);
  }
  return 0;
}
```

## Earlier attempts (newest first)

- none found
