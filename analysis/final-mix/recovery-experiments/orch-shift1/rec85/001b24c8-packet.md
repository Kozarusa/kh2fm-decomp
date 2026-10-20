# Target packet 001b24c8

- Range: `001b24c8`..`001b251c`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b24c8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00105110` registry: `_ZN4AREA4FreeEPv`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_orchbu_recovered_001a4060.cpp`
- `001b2488` registry: `func_001b2488`
  - accepted sources that already call it (copy their declaration): `fm_primary_twoword_recovered_001b2488.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b24c8: 27bdffe0  addiu	sp,sp,-32
001b24cc: 3c0f01d5  lui	t7,0x1d5
001b24d0: ffb00000  sd	s0,0(sp)
001b24d4: ffb10008  sd	s1,8(sp)
001b24d8: ffbf0010  sd	ra,16(sp)
001b24dc: 8df08c80  lw	s0,-29568(t7)   ; = D_01d48c80
001b24e0: 5200000a  beqzl	s0,0x1b250c
001b24e4: dfb00000  ld	s0,0(sp)
001b24e8: 12000005  beqz	s0,0x1b2500
001b24ec: 8e110018  lw	s1,24(s0)
001b24f0: 0c06c922  jal	0x1b2488
001b24f4: 0200202d  move	a0,s0
001b24f8: 0c041444  jal	0x105110
001b24fc: 0200202d  move	a0,s0
001b2500: 1620fff9  bnez	s1,0x1b24e8
001b2504: 0220802d  move	s0,s1
001b2508: dfb00000  ld	s0,0(sp)
001b250c: dfb10008  ld	s1,8(sp)
001b2510: dfbf0010  ld	ra,16(sp)
001b2514: 03e00008  jr	ra
001b2518: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b24c8(void)`

```c
void FUN_001b24c8(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_01d48c80;
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x18);
    if (iVar2 != 0) {
      FUN_001b2488(iVar2);
      FUN_00105110(iVar2);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
