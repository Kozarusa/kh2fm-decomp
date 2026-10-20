# Target packet 001a80c8

- Range: `001a80c8`..`001a810c`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a80c8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a80c8: 3c0f01c7  lui	t7,0x1c7
001a80cc: 0000682d  move	t5,zero
001a80d0: 8deecb90  lw	t6,-13424(t7)   ; = D_01c6cb90
001a80d4: 8dcc0004  lw	t4,4(t6)
001a80d8: 19800009  blez	t4,0x1a8100
001a80dc: 25ce0008  addiu	t6,t6,8
001a80e0: 95cf0000  lhu	t7,0(t6)
001a80e4: 01c0102d  move	v0,t6
001a80e8: 11e40006  beq	t7,a0,0x1a8104
001a80ec: 25ce0018  addiu	t6,t6,24
001a80f0: 25ad0001  addiu	t5,t5,1
001a80f4: 01ac782a  slt	t7,t5,t4
001a80f8: 55e0fffa  bnezl	t7,0x1a80e4
001a80fc: 95cf0000  lhu	t7,0(t6)
001a8100: 0000102d  move	v0,zero
001a8104: 03e00008  jr	ra
001a8108: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a80c8(void)`

```c
ushort * FUN_001a80c8(ulong param_1)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  
  iVar2 = 0;
  if (*(int *)(DAT_01c6cb90 + 4) < 1) {
LAB_001a8100:
    puVar3 = (ushort *)0x0;
  }
  else {
    uVar1 = *(ushort *)(DAT_01c6cb90 + 8);
    puVar3 = (ushort *)(DAT_01c6cb90 + 8);
    while (uVar1 != param_1) {
      iVar2 = iVar2 + 1;
      if (*(int *)(DAT_01c6cb90 + 4) <= iVar2) goto LAB_001a8100;
      uVar1 = puVar3[0xc];
      puVar3 = puVar3 + 0xc;
    }
  }
  return puVar3;
}
```

## Earlier attempts (newest first)

- none found
