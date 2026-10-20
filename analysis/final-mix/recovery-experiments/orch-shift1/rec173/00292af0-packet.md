# Target packet 00292af0

- Range: `00292af0`..`00292b40`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_00292af0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00292af0: 3c0f0036  lui	t7,0x36
00292af4: 0000682d  move	t5,zero
00292af8: 85eff4e0  lh	t7,-2848(t7)   ; = D_0035f4e0
00292afc: 19e0000e  blez	t7,0x292b38
00292b00: 0000102d  move	v0,zero
00292b04: 01e0602d  move	t4,t7
00292b08: 3c0f0036  lui	t7,0x36
00292b0c: 8deef4dc  lw	t6,-2852(t7)   ; = D_0035f4dc
00292b10: 95cf0000  lhu	t7,0(t6)
00292b14: 15e40004  bne	t7,a0,0x292b28
00292b18: 25ce0004  addiu	t6,t6,4
00292b1c: 03e00008  jr	ra
00292b20: 24020001  li	v0,1
00292b24: 00000000  nop
00292b28: 25ad0001  addiu	t5,t5,1
00292b2c: 01ac782a  slt	t7,t5,t4
00292b30: 55e0fff8  bnezl	t7,0x292b14
00292b34: 95cf0000  lhu	t7,0(t6)
00292b38: 03e00008  jr	ra
00292b3c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00292af0(void)`

```c
undefined4 FUN_00292af0(ulong param_1)

{
  ushort uVar1;
  long lVar2;
  ushort *puVar3;
  
  lVar2 = 0;
  if (0 < (long)DAT_0035f4e0) {
    uVar1 = *DAT_0035f4dc;
    puVar3 = DAT_0035f4dc;
    while( true ) {
      puVar3 = puVar3 + 2;
      if (uVar1 == param_1) {
        return 1;
      }
      lVar2 = (long)((int)lVar2 + 1);
      if (DAT_0035f4e0 <= lVar2) break;
      uVar1 = *puVar3;
    }
  }
  return 0;
}
```

## Earlier attempts (newest first)

- none found
