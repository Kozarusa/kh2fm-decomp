# Target packet 001d5d20

- Range: `001d5d20`..`001d5d80`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d5d20`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d5b78` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d5d20: 27bdfff0  addiu	sp,sp,-16
001d5d24: 0000202d  move	a0,zero
001d5d28: ffbf0000  sd	ra,0(sp)
001d5d2c: 0c0756de  jal	0x1d5b78
001d5d30: 24050001  li	a1,1
001d5d34: 3c0f0033  lui	t7,0x33
001d5d38: 0040682d  move	t5,v0
001d5d3c: 25efbb30  addiu	t7,t7,-17616   ; = D_0032bb30
001d5d40: 240e0001  li	t6,1
001d5d44: 91ec3526  lbu	t4,13606(t7)
001d5d48: 01cc702a  slt	t6,t6,t4
001d5d4c: 11c00009  beqz	t6,0x1d5d74
001d5d50: 8de236e4  lw	v0,14052(t7)
001d5d54: 258effff  addiu	t6,t4,-1
001d5d58: 8daf0004  lw	t7,4(t5)
001d5d5c: 25ceffff  addiu	t6,t6,-1
001d5d60: 004f1021  addu	v0,v0,t7
001d5d64: 00000000  nop
001d5d68: 00000000  nop
001d5d6c: 15c0fffa  bnez	t6,0x1d5d58
001d5d70: 25ad0008  addiu	t5,t5,8
001d5d74: dfbf0000  ld	ra,0(sp)
001d5d78: 03e00008  jr	ra
001d5d7c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d5d20(void)`

```c
int FUN_001d5d20(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_001d5b78(0,1);
  iVar2 = DAT_0032f214;
  if (1 < DAT_0032f050._6_1_) {
    iVar3 = DAT_0032f050._6_1_ - 1;
    do {
      iVar3 = iVar3 + -1;
      iVar2 = iVar2 + *(int *)(iVar1 + 4);
      iVar1 = iVar1 + 8;
    } while (iVar3 != 0);
  }
  return iVar2;
}
```

## Earlier attempts (newest first)

- none found
