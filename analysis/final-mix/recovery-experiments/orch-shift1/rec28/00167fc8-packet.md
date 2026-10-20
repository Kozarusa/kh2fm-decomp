# Target packet 00167fc8

- Range: `00167fc8`..`00168008`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_00167fc8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00167f38` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00167fc8: 27bdfff0  addiu	sp,sp,-16
00167fcc: 3c0f004f  lui	t7,0x4f
00167fd0: ffbf0000  sd	ra,0(sp)
00167fd4: 3c0b0035  lui	t3,0x35
00167fd8: 8dec5250  lw	t4,21072(t7)   ; = D_004f5250
00167fdc: 8d6dd780  lw	t5,-10368(t3)   ; = D_0034d780
00167fe0: 3c0f004f  lui	t7,0x4f
00167fe4: dfbf0000  ld	ra,0(sp)
00167fe8: 000d7080  sll	t6,t5,0x2
00167fec: 25ef5258  addiu	t7,t7,21080   ; = D_004f5258
00167ff0: 01cf7021  addu	t6,t6,t7
00167ff4: 25ad0001  addiu	t5,t5,1
00167ff8: adcc0000  sw	t4,0(t6)
00167ffc: ad6dd780  sw	t5,-10368(t3)   ; = D_0034d780
00168000: 08059fce  j	0x167f38
00168004: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00167fc8(void)`

```c
void FUN_00167fc8(void)

{
  int iVar1;
  
  iVar1 = DAT_0034d780 * 4;
  DAT_0034d780 = DAT_0034d780 + 1;
  *(undefined4 *)(&DAT_004f5258 + iVar1) = DAT_004f5250;
  FUN_00167f38();
  return;
}
```

## Earlier attempts (newest first)

- none found
