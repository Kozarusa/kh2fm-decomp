# Target packet 001a6ae8

- Range: `001a6ae8`..`001a6b58`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a6ae8`
- Registry names for this address: `_Z16u_tail0_001a6ae8v`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00105110` registry: `_ZN4AREA4FreeEPv`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_orchbu_recovered_001a4060.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a6ae8: 27bdffe0  addiu	sp,sp,-32
001a6aec: 3c0e01c7  lui	t6,0x1c7
001a6af0: ffb10008  sd	s1,8(sp)
001a6af4: ffb00000  sd	s0,0(sp)
001a6af8: ffb20010  sd	s2,16(sp)
001a6afc: ffbf0018  sd	ra,24(sp)
001a6b00: 8dcfcb70  lw	t7,-13456(t6)   ; = D_01c6cb70
001a6b04: 19e0000c  blez	t7,0x1a6b38
001a6b08: 0000882d  move	s1,zero
001a6b0c: 3c0f01c7  lui	t7,0x1c7
001a6b10: 01c0902d  move	s2,t6
001a6b14: 25efcb30  addiu	t7,t7,-13520   ; = D_01c6cb30
001a6b18: 25f00004  addiu	s0,t7,4
001a6b1c: 8e040000  lw	a0,0(s0)
001a6b20: 0c041444  jal	0x105110
001a6b24: 26310001  addiu	s1,s1,1
001a6b28: 8e4fcb70  lw	t7,-13456(s2)
001a6b2c: 022f782a  slt	t7,s1,t7
001a6b30: 15e0fffa  bnez	t7,0x1a6b1c
001a6b34: 26100008  addiu	s0,s0,8
001a6b38: 3c0f01c7  lui	t7,0x1c7
001a6b3c: dfb00000  ld	s0,0(sp)
001a6b40: ade0cb70  sw	zero,-13456(t7)   ; = D_01c6cb70
001a6b44: dfb10008  ld	s1,8(sp)
001a6b48: dfb20010  ld	s2,16(sp)
001a6b4c: dfbf0018  ld	ra,24(sp)
001a6b50: 03e00008  jr	ra
001a6b54: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a6ae8(void)`

```c
void FUN_001a6ae8(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_01c6cb70) {
    puVar1 = &DAT_01c6cb34;
    do {
      iVar2 = iVar2 + 1;
      FUN_00105110(*puVar1);
      puVar1 = puVar1 + 2;
    } while (iVar2 < DAT_01c6cb70);
  }
  DAT_01c6cb70 = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
