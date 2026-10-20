# Target packet 0028ce38

- Range: `0028ce38`..`0028ce94`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028ce38`
- Registry names for this address: `Tz::MenuCursor::DeleteAll(...)`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0028cdb8` registry: `func_0028cdb8`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcheo_recovered_0028cdb8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028ce38: 27bdffe0  addiu	sp,sp,-32
0028ce3c: 3c0e0036  lui	t6,0x36
0028ce40: ffb00000  sd	s0,0(sp)
0028ce44: ffb10008  sd	s1,8(sp)
0028ce48: ffbf0010  sd	ra,16(sp)
0028ce4c: 8dcff404  lw	t7,-3068(t6)   ; = D_0035f404
0028ce50: 19e00009  blez	t7,0x28ce78
0028ce54: 0000802d  move	s0,zero
0028ce58: 01c0882d  move	s1,t6
0028ce5c: 0c0a336e  jal	0x28cdb8
0028ce60: 0200202d  move	a0,s0
0028ce64: 26100001  addiu	s0,s0,1
0028ce68: 8e2ff404  lw	t7,-3068(s1)
0028ce6c: 020f782a  slt	t7,s0,t7
0028ce70: 15e0fffa  bnez	t7,0x28ce5c
0028ce74: 00000000  nop
0028ce78: 3c0f0036  lui	t7,0x36
0028ce7c: dfb00000  ld	s0,0(sp)
0028ce80: ade0f410  sw	zero,-3056(t7)   ; = D_0035f410
0028ce84: dfb10008  ld	s1,8(sp)
0028ce88: dfbf0010  ld	ra,16(sp)
0028ce8c: 03e00008  jr	ra
0028ce90: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028ce38(void)`

```c
void FUN_0028ce38(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_0035f404) {
    do {
      FUN_0028cdb8(iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0035f404);
  }
  DAT_0035f410 = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
