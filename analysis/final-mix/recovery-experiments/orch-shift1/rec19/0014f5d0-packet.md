# Target packet 0014f5d0

- Range: `0014f5d0`..`0014f648`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_0014f5d0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `00150b68` registry: `_ZN2dk18INFORMATION_WINDOW5closeEv`
- `00150bc0` registry: `_ZN2dk18INFORMATION_WINDOW8isCreateEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_globalargument_recovered_0014f578.cpp`
- `00150be0` registry: `_ZN2dk18INFORMATION_WINDOW10getMessageEv`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0014f5d0: 27bdffe0  addiu	sp,sp,-32
0014f5d4: ffb00000  sd	s0,0(sp)
0014f5d8: ffb10008  sd	s1,8(sp)
0014f5dc: ffbf0010  sd	ra,16(sp)
0014f5e0: 3c100035  lui	s0,0x35
0014f5e4: 0080882d  move	s1,a0
0014f5e8: 0c0542f0  jal	0x150bc0
0014f5ec: 8e04a42c  lw	a0,-23508(s0)   ; = D_0034a42c
0014f5f0: 50400011  beqzl	v0,0x14f638
0014f5f4: dfb00000  ld	s0,0(sp)
0014f5f8: 12200005  beqz	s1,0x14f610
0014f5fc: 00000000  nop
0014f600: 0c0542f8  jal	0x150be0
0014f604: 8e04a42c  lw	a0,-23508(s0)
0014f608: 5451000b  bnel	v0,s1,0x14f638
0014f60c: dfb00000  ld	s0,0(sp)
0014f610: 0c04e75e  jal	0x139d78
0014f614: 8e04a42c  lw	a0,-23508(s0)
0014f618: 50400007  beqzl	v0,0x14f638
0014f61c: dfb00000  ld	s0,0(sp)
0014f620: 8e04a42c  lw	a0,-23508(s0)
0014f624: dfb10008  ld	s1,8(sp)
0014f628: dfb00000  ld	s0,0(sp)
0014f62c: dfbf0010  ld	ra,16(sp)
0014f630: 080542da  j	0x150b68
0014f634: 27bd0020  addiu	sp,sp,32
0014f638: dfb10008  ld	s1,8(sp)
0014f63c: dfbf0010  ld	ra,16(sp)
0014f640: 03e00008  jr	ra
0014f644: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0014f5d0(void)`

```c
void FUN_0014f5d0(long param_1)

{
  long lVar1;
  
  lVar1 = FUN_00150bc0(DAT_0034a42c);
  if ((lVar1 != 0) &&
     (((param_1 == 0 || (lVar1 = FUN_00150be0(DAT_0034a42c), lVar1 == param_1)) &&
      (lVar1 = FUN_00139d78(DAT_0034a42c), lVar1 != 0)))) {
    FUN_00150b68(DAT_0034a42c);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
