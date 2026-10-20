# Target packet 001aff90

- Range: `001aff90`..`001affe0`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aff90`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aff90: 3c0f01c9  lui	t7,0x1c9
001aff94: 0000682d  move	t5,zero
001aff98: 8dee40b4  lw	t6,16564(t7)   ; = D_01c940b4
001aff9c: 8dcf0004  lw	t7,4(t6)
001affa0: 19e0000c  blez	t7,0x1affd4
001affa4: 25ce0008  addiu	t6,t6,8
001affa8: 01e0602d  move	t4,t7
001affac: 91cf0000  lbu	t7,0(t6)
001affb0: 55e40005  bnel	t7,a0,0x1affc8
001affb4: 25ad0001  addiu	t5,t5,1
001affb8: 91cf0001  lbu	t7,1(t6)
001affbc: 11e50006  beq	t7,a1,0x1affd8
001affc0: 01c0102d  move	v0,t6
001affc4: 25ad0001  addiu	t5,t5,1
001affc8: 01ac782a  slt	t7,t5,t4
001affcc: 15e0fff7  bnez	t7,0x1affac
001affd0: 25ce000e  addiu	t6,t6,14
001affd4: 0000102d  move	v0,zero
001affd8: 03e00008  jr	ra
001affdc: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aff90(void)`

```c
byte * FUN_001aff90(ulong param_1,ulong param_2)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0;
  pbVar2 = (byte *)(DAT_01c940b4 + 8);
  if (0 < *(int *)(DAT_01c940b4 + 4)) {
    do {
      if ((*pbVar2 == param_1) && (pbVar2[1] == param_2)) {
        return pbVar2;
      }
      iVar1 = iVar1 + 1;
      pbVar2 = pbVar2 + 0xe;
    } while (iVar1 < *(int *)(DAT_01c940b4 + 4));
  }
  return (byte *)0x0;
}
```

## Earlier attempts (newest first)

- none found
