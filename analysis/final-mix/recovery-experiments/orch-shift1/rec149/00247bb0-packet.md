# Target packet 00247bb0

- Range: `00247bb0`..`00247c1c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_00247bb0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00247bb0: 27bdffe0  addiu	sp,sp,-32
00247bb4: ffb00000  sd	s0,0(sp)
00247bb8: ffb10008  sd	s1,8(sp)
00247bbc: ffb20010  sd	s2,16(sp)
00247bc0: 0000802d  move	s0,zero
00247bc4: ffbf0018  sd	ra,24(sp)
00247bc8: 24110003  li	s1,3
00247bcc: 3c120036  lui	s2,0x36
00247bd0: 8e44ed34  lw	a0,-4812(s2)   ; = D_0035ed34
00247bd4: 0c04e75e  jal	0x139d78
00247bd8: 00902021  addu	a0,a0,s0
00247bdc: 10400006  beqz	v0,0x247bf8
00247be0: 8e44ed34  lw	a0,-4812(s2)   ; = D_0035ed34
00247be4: 02042021  addu	a0,s0,a0
00247be8: 8c8e0000  lw	t6,0(a0)
00247bec: 8dcf0014  lw	t7,20(t6)
00247bf0: 01e0f809  jalr	t7
00247bf4: 00000000  nop
00247bf8: 2631ffff  addiu	s1,s1,-1
00247bfc: 0621fff4  bgez	s1,0x247bd0
00247c00: 26100198  addiu	s0,s0,408
00247c04: dfb00000  ld	s0,0(sp)
00247c08: dfb10008  ld	s1,8(sp)
00247c0c: dfb20010  ld	s2,16(sp)
00247c10: dfbf0018  ld	ra,24(sp)
00247c14: 03e00008  jr	ra
00247c18: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00247bb0(void)`

```c
void FUN_00247bb0(void)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 3;
  do {
    lVar1 = FUN_00139d78(DAT_0035ed34 + iVar2);
    if (lVar1 != 0) {
      (**(code **)(*(int *)(iVar2 + DAT_0035ed34) + 0x14))();
    }
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + 0x198;
  } while (-1 < iVar3);
  return;
}
```

## Earlier attempts (newest first)

- none found
