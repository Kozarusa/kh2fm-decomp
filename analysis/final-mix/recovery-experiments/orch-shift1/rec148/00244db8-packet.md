# Target packet 00244db8

- Range: `00244db8`..`00244e24`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_00244db8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00244db8: 27bdffe0  addiu	sp,sp,-32
00244dbc: ffb00000  sd	s0,0(sp)
00244dc0: ffb10008  sd	s1,8(sp)
00244dc4: ffb20010  sd	s2,16(sp)
00244dc8: 0000802d  move	s0,zero
00244dcc: ffbf0018  sd	ra,24(sp)
00244dd0: 24110001  li	s1,1
00244dd4: 3c120036  lui	s2,0x36
00244dd8: 8e44ed04  lw	a0,-4860(s2)   ; = D_0035ed04
00244ddc: 0c04e75e  jal	0x139d78
00244de0: 00902021  addu	a0,a0,s0
00244de4: 10400006  beqz	v0,0x244e00
00244de8: 8e44ed04  lw	a0,-4860(s2)   ; = D_0035ed04
00244dec: 02042021  addu	a0,s0,a0
00244df0: 8c8e0000  lw	t6,0(a0)
00244df4: 8dcf0014  lw	t7,20(t6)
00244df8: 01e0f809  jalr	t7
00244dfc: 00000000  nop
00244e00: 2631ffff  addiu	s1,s1,-1
00244e04: 0621fff4  bgez	s1,0x244dd8
00244e08: 26100198  addiu	s0,s0,408
00244e0c: dfb00000  ld	s0,0(sp)
00244e10: dfb10008  ld	s1,8(sp)
00244e14: dfb20010  ld	s2,16(sp)
00244e18: dfbf0018  ld	ra,24(sp)
00244e1c: 03e00008  jr	ra
00244e20: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00244db8(void)`

```c
void FUN_00244db8(void)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 1;
  do {
    lVar1 = FUN_00139d78(DAT_0035ed04 + iVar2);
    if (lVar1 != 0) {
      (**(code **)(*(int *)(iVar2 + DAT_0035ed04) + 0x14))();
    }
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + 0x198;
  } while (-1 < iVar3);
  return;
}
```

## Earlier attempts (newest first)

- none found
