# Target packet 00182ab0

- Range: `00182ab0`..`00182b14`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_00182ab0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00182910` registry: `func_00182910`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00182ab0: 27bdffe0  addiu	sp,sp,-32
00182ab4: 3c0e0035  lui	t6,0x35
00182ab8: ffb10008  sd	s1,8(sp)
00182abc: ffb00000  sd	s0,0(sp)
00182ac0: ffb20010  sd	s2,16(sp)
00182ac4: ffbf0018  sd	ra,24(sp)
00182ac8: 8dcfed00  lw	t7,-4864(t6)   ; = D_0034ed00
00182acc: 19e0000b  blez	t7,0x182afc
00182ad0: 0000882d  move	s1,zero
00182ad4: 3c0f01c6  lui	t7,0x1c6
00182ad8: 01c0902d  move	s2,t6
00182adc: 25f00588  addiu	s0,t7,1416   ; = D_01c60588
00182ae0: 0200202d  move	a0,s0
00182ae4: 0c060a44  jal	0x182910
00182ae8: 26310001  addiu	s1,s1,1
00182aec: 8e4fed00  lw	t7,-4864(s2)
00182af0: 022f782a  slt	t7,s1,t7
00182af4: 15e0fffa  bnez	t7,0x182ae0
00182af8: 2610000c  addiu	s0,s0,12
00182afc: dfb00000  ld	s0,0(sp)
00182b00: dfb10008  ld	s1,8(sp)
00182b04: dfb20010  ld	s2,16(sp)
00182b08: dfbf0018  ld	ra,24(sp)
00182b0c: 03e00008  jr	ra
00182b10: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00182ab0(void)`

```c
void FUN_00182ab0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_0034ed00) {
    puVar1 = &DAT_01c60588;
    do {
      iVar2 = iVar2 + 1;
      FUN_00182910(puVar1);
      puVar1 = puVar1 + 3;
    } while (iVar2 < DAT_0034ed00);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
