# Target packet 0019ebc0

- Range: `0019ebc0`..`0019ec20`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019ebc0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0015ee10` registry: `_ZN2dk3Map12setHideGroupEj`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchas_recovered_0015ee10.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019ebc0: 27bdffe0  addiu	sp,sp,-32
0019ebc4: ffb00000  sd	s0,0(sp)
0019ebc8: ffb10008  sd	s1,8(sp)
0019ebcc: ffbf0010  sd	ra,16(sp)
0019ebd0: 0000802d  move	s0,zero
0019ebd4: 3c110035  lui	s1,0x35
0019ebd8: de2fecc8  ld	t7,-4920(s1)   ; = D_0034ecc8
0019ebdc: 020f7816  dsrlv	t7,t7,s0
0019ebe0: 31ef0001  andi	t7,t7,0x1
0019ebe4: 31ef00ff  andi	t7,t7,0xff
0019ebe8: 31ef00ff  andi	t7,t7,0xff
0019ebec: 51e00004  beqzl	t7,0x19ec00
0019ebf0: 26100001  addiu	s0,s0,1
0019ebf4: 0c057b84  jal	0x15ee10
0019ebf8: 0200202d  move	a0,s0
0019ebfc: 26100001  addiu	s0,s0,1
0019ec00: 2a0f0040  slti	t7,s0,64
0019ec04: 55e0fff5  bnezl	t7,0x19ebdc
0019ec08: de2fecc8  ld	t7,-4920(s1)   ; = D_0034ecc8
0019ec0c: dfb00000  ld	s0,0(sp)
0019ec10: dfb10008  ld	s1,8(sp)
0019ec14: dfbf0010  ld	ra,16(sp)
0019ec18: 03e00008  jr	ra
0019ec1c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019ebc0(void)`

```c
void FUN_0019ebc0(void)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    if ((DAT_0034ecc8 >> lVar1 & 1) != 0) {
      FUN_0015ee10(lVar1);
    }
    lVar1 = (long)((int)lVar1 + 1);
  } while (lVar1 < 0x40);
  return;
}
```

## Earlier attempts (newest first)

- none found
