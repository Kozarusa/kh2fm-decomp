# Target packet 00181cc0

- Range: `00181cc0`..`00181d30`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_00181cc0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00181d30` registry: `_ZNK2YS8AREADATA8SETINDEX5parseEPKNS0_4CODEES4_`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00181cc0: 948d0000  lhu	t5,0(a0)
00181cc4: 27bdfff0  addiu	sp,sp,-16
00181cc8: 00a0602d  move	t4,a1
00181ccc: ffbf0000  sd	ra,0(sp)
00181cd0: 000d7400  sll	t6,t5,0x10
00181cd4: 000e7403  sra	t6,t6,0x10
00181cd8: 240fffff  li	t7,-1
00181cdc: 11cf0011  beq	t6,t7,0x181d24
00181ce0: 0080282d  move	a1,a0
00181ce4: 240bffff  li	t3,-1
00181ce8: 84af0002  lh	t7,2(a1)
00181cec: 000d7400  sll	t6,t5,0x10
00181cf0: 000e7403  sra	t6,t6,0x10
00181cf4: 15cc0006  bne	t6,t4,0x181d10
00181cf8: 00af3021  addu	a2,a1,t7
00181cfc: dfbf0000  ld	ra,0(sp)
00181d00: 24a50004  addiu	a1,a1,4
00181d04: 0806074c  j	0x181d30
00181d08: 27bd0010  addiu	sp,sp,16
00181d0c: 00000000  nop
00181d10: 94cd0000  lhu	t5,0(a2)
00181d14: 000d7c00  sll	t7,t5,0x10
00181d18: 000f7c03  sra	t7,t7,0x10
00181d1c: 15ebfff2  bne	t7,t3,0x181ce8
00181d20: 00c0282d  move	a1,a2
00181d24: dfbf0000  ld	ra,0(sp)
00181d28: 03e00008  jr	ra
00181d2c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00181cc0(void)`

```c
void FUN_00181cc0(short *param_1,short param_2)

{
  short sVar1;
  short *psVar2;
  
  sVar1 = *param_1;
  psVar2 = param_1;
  while( true ) {
    if (sVar1 == -1) {
      return;
    }
    if (sVar1 == param_2) break;
    sVar1 = *(short *)((int)psVar2 + (int)psVar2[1]);
    psVar2 = (short *)((int)psVar2 + (int)psVar2[1]);
  }
  FUN_00181d30(param_1,psVar2 + 2);
  return;
}
```

## Earlier attempts (newest first)

- none found
