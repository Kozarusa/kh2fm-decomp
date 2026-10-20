# Target packet 001bffd8

- Range: `001bffd8`..`001c0054`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bffd8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bffd8: 3c0f01d5  lui	t7,0x1d5
001bffdc: 0000502d  move	t2,zero
001bffe0: 25e79328  addiu	a3,t7,-27864   ; = D_01d49328
001bffe4: 3c0901d5  lui	t1,0x1d5
001bffe8: 240b00ff  li	t3,255
001bffec: 24080001  li	t0,1
001bfff0: 8d2f9348  lw	t7,-27832(t1)   ; = D_01d49348
001bfff4: 51600001  beqzl	t3,0x1bfffc
001bfff8: 000001cd  break	0x7
001bfffc: 25ef0001  addiu	t7,t7,1
001c0000: 01eb001a  div	zero,t7,t3
001c0004: 00007010  mfhi	t6
001c0008: 25c20001  addiu	v0,t6,1
001c000c: ad2e9348  sw	t6,-27832(t1)   ; = D_01d49348
001c0010: 00027942  srl	t7,v0,0x5
001c0014: 304e001f  andi	t6,v0,0x1f
001c0018: 000f7880  sll	t7,t7,0x2
001c001c: 01c86804  sllv	t5,t0,t6
001c0020: 01e76021  addu	t4,t7,a3
001c0024: 8d8e0000  lw	t6,0(t4)
001c0028: 01cd7824  and	t7,t6,t5
001c002c: 55e00004  bnezl	t7,0x1c0040
001c0030: 254a0001  addiu	t2,t2,1
001c0034: 01cd7825  or	t7,t6,t5
001c0038: 03e00008  jr	ra
001c003c: ad8f0000  sw	t7,0(t4)
001c0040: 294f0100  slti	t7,t2,256
001c0044: 55e0ffeb  bnezl	t7,0x1bfff4
001c0048: 8d2f9348  lw	t7,-27832(t1)   ; = D_01d49348
001c004c: 03e00008  jr	ra
001c0050: 0000102d  move	v0,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bffd8(void)`

```c
/* WARNING: Removing unreachable block (ram,0x001bfff4) */

uint FUN_001bffd8(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0;
  do {
    DAT_01d49348 = (DAT_01d49348 + 1) % 0xff;
    uVar2 = DAT_01d49348 + 1;
    uVar4 = 1 << (uVar2 & 0x1f);
    uVar1 = (&DAT_01d49328)[uVar2 >> 5];
    if ((uVar1 & uVar4) == 0) {
      (&DAT_01d49328)[uVar2 >> 5] = uVar1 | uVar4;
      return uVar2;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  return 0;
}
```

## Earlier attempts (newest first)

- none found
