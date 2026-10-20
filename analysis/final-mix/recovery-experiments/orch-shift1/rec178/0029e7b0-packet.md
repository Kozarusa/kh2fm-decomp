# Target packet 0029e7b0

- Range: `0029e7b0`..`0029e808`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_0029e7b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0029e7b0: 3c0e0037  lui	t6,0x37
0029e7b4: 2402ffff  li	v0,-1
0029e7b8: 85cf4a08  lh	t7,18952(t6)   ; = D_00374a08
0029e7bc: 19e00010  blez	t7,0x29e800
0029e7c0: 0000602d  move	t4,zero
0029e7c4: 25cb4a08  addiu	t3,t6,18952   ; = D_00374a08
0029e7c8: 0000682d  move	t5,zero
0029e7cc: 01ab7021  addu	t6,t5,t3
0029e7d0: 85cf0000  lh	t7,0(t6)
0029e7d4: 55e40004  bnel	t7,a0,0x29e7e8
0029e7d8: 258c0001  addiu	t4,t4,1
0029e7dc: 03e00008  jr	ra
0029e7e0: 85c20002  lh	v0,2(t6)
0029e7e4: 00000000  nop
0029e7e8: 000c7880  sll	t7,t4,0x2
0029e7ec: 01e0682d  move	t5,t7
0029e7f0: 01eb7021  addu	t6,t7,t3
0029e7f4: 85cf0000  lh	t7,0(t6)
0029e7f8: 1de0fff5  bgtz	t7,0x29e7d0
0029e7fc: 01ab7021  addu	t6,t5,t3
0029e800: 03e00008  jr	ra
0029e804: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0029e7b0(void)`

```c
short FUN_0029e7b0(short param_1)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (0 < DAT_00374a08) {
    psVar2 = &DAT_00374a08;
    do {
      if (*psVar2 == param_1) {
        return psVar2[1];
      }
      iVar1 = iVar1 + 1;
      psVar2 = &DAT_00374a08 + iVar1 * 2;
    } while (0 < (&DAT_00374a08)[iVar1 * 2]);
  }
  return -1;
}
```

## Earlier attempts (newest first)

- none found
