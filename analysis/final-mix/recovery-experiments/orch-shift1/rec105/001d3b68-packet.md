# Target packet 001d3b68

- Range: `001d3b68`..`001d3bbc`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d3b68`
- Registry names for this address: `_Z16u_call0_001d3b68v`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00105110` registry: `_ZN4AREA4FreeEPv`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_orchbu_recovered_001a4060.cpp`
- `001d3878` registry: `func_001d3878`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d3b68: 27bdffe0  addiu	sp,sp,-32
001d3b6c: 3c0f01d6  lui	t7,0x1d6
001d3b70: ffb00000  sd	s0,0(sp)
001d3b74: ffb10008  sd	s1,8(sp)
001d3b78: ffbf0010  sd	ra,16(sp)
001d3b7c: 8df0ba20  lw	s0,-17888(t7)   ; = D_01d5ba20
001d3b80: 5200000a  beqzl	s0,0x1d3bac
001d3b84: dfb00000  ld	s0,0(sp)
001d3b88: 12000005  beqz	s0,0x1d3ba0
001d3b8c: 8e110030  lw	s1,48(s0)
001d3b90: 0c074e1e  jal	0x1d3878
001d3b94: 0200202d  move	a0,s0
001d3b98: 0c041444  jal	0x105110
001d3b9c: 0200202d  move	a0,s0
001d3ba0: 1620fff9  bnez	s1,0x1d3b88
001d3ba4: 0220802d  move	s0,s1
001d3ba8: dfb00000  ld	s0,0(sp)
001d3bac: dfb10008  ld	s1,8(sp)
001d3bb0: dfbf0010  ld	ra,16(sp)
001d3bb4: 03e00008  jr	ra
001d3bb8: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d3b68(void)`

```c
void FUN_001d3b68(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_01d5ba20;
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x30);
    if (iVar2 != 0) {
      FUN_001d3878(iVar2);
      FUN_00105110(iVar2);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
