# Target packet 0019eb60

- Range: `0019eb60`..`0019ebc0`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019eb60`
- Registry names for this address: `_ZN2YS4UNIT8ActivateEPc`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0015ee90` registry: `_ZN2dk3Map15setVisibleGroupEj`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019eb60: 27bdffe0  addiu	sp,sp,-32
0019eb64: ffb00000  sd	s0,0(sp)
0019eb68: ffb10008  sd	s1,8(sp)
0019eb6c: ffbf0010  sd	ra,16(sp)
0019eb70: 0000802d  move	s0,zero
0019eb74: 3c110035  lui	s1,0x35
0019eb78: de2fecc8  ld	t7,-4920(s1)   ; = D_0034ecc8
0019eb7c: 020f7816  dsrlv	t7,t7,s0
0019eb80: 31ef0001  andi	t7,t7,0x1
0019eb84: 31ef00ff  andi	t7,t7,0xff
0019eb88: 31ef00ff  andi	t7,t7,0xff
0019eb8c: 51e00004  beqzl	t7,0x19eba0
0019eb90: 26100001  addiu	s0,s0,1
0019eb94: 0c057ba4  jal	0x15ee90
0019eb98: 0200202d  move	a0,s0
0019eb9c: 26100001  addiu	s0,s0,1
0019eba0: 2a0f0040  slti	t7,s0,64
0019eba4: 55e0fff5  bnezl	t7,0x19eb7c
0019eba8: de2fecc8  ld	t7,-4920(s1)   ; = D_0034ecc8
0019ebac: dfb00000  ld	s0,0(sp)
0019ebb0: dfb10008  ld	s1,8(sp)
0019ebb4: dfbf0010  ld	ra,16(sp)
0019ebb8: 03e00008  jr	ra
0019ebbc: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019eb60(void)`

```c
void FUN_0019eb60(void)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    if ((DAT_0034ecc8 >> lVar1 & 1) != 0) {
      FUN_0015ee90(lVar1);
    }
    lVar1 = (long)((int)lVar1 + 1);
  } while (lVar1 < 0x40);
  return;
}
```

## Earlier attempts (newest first)

- none found
