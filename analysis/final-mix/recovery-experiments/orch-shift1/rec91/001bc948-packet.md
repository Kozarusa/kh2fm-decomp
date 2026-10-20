# Target packet 001bc948

- Range: `001bc948`..`001bc98c`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bc948`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bc948: 8c8d0008  lw	t5,8(a0)
001bc94c: 19a0000c  blez	t5,0x1bc980
001bc950: 0000702d  move	t6,zero
001bc954: 24840011  addiu	a0,a0,17
001bc958: 908f0000  lbu	t7,0(a0)
001bc95c: 24020001  li	v0,1
001bc960: 2def0004  sltiu	t7,t7,4
001bc964: 31ef00ff  andi	t7,t7,0xff
001bc968: 15e00006  bnez	t7,0x1bc984
001bc96c: 2484000c  addiu	a0,a0,12
001bc970: 25ce0001  addiu	t6,t6,1
001bc974: 01cd782a  slt	t7,t6,t5
001bc978: 55e0fff9  bnezl	t7,0x1bc960
001bc97c: 908f0000  lbu	t7,0(a0)
001bc980: 0000102d  move	v0,zero
001bc984: 03e00008  jr	ra
001bc988: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bc948(void)`

```c
undefined4 FUN_001bc948(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(param_1 + 8) < 1) {
LAB_001bc980:
    uVar2 = 0;
  }
  else {
    pbVar3 = (byte *)(param_1 + 0x11);
    uVar2 = 1;
    bVar1 = *pbVar3;
    while (pbVar3 = pbVar3 + 0xc, 3 < bVar1) {
      iVar4 = iVar4 + 1;
      if (*(int *)(param_1 + 8) <= iVar4) goto LAB_001bc980;
      bVar1 = *pbVar3;
    }
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- none found
