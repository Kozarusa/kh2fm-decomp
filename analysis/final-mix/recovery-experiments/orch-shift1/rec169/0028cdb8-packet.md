# Target packet 0028cdb8

- Range: `0028cdb8`..`0028ce34`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028cdb8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028cdb8: 27bdffe0  addiu	sp,sp,-32
0028cdbc: 240f0198  li	t7,408
0028cdc0: ffb00000  sd	s0,0(sp)
0028cdc4: ffb10008  sd	s1,8(sp)
0028cdc8: 008f8018  mult	s0,a0,t7
0028cdcc: ffb20010  sd	s2,16(sp)
0028cdd0: 3c110036  lui	s1,0x36
0028cdd4: ffbf0018  sd	ra,24(sp)
0028cdd8: 0080902d  move	s2,a0
0028cddc: 8e24f3fc  lw	a0,-3076(s1)   ; = D_0035f3fc
0028cde0: 0c04e75e  jal	0x139d78
0028cde4: 00902021  addu	a0,a0,s0
0028cde8: 1040000c  beqz	v0,0x28ce1c
0028cdec: 8e24f3fc  lw	a0,-3076(s1)   ; = D_0035f3fc
0028cdf0: 02042021  addu	a0,s0,a0
0028cdf4: 8c8e0000  lw	t6,0(a0)
0028cdf8: 8dcf0014  lw	t7,20(t6)
0028cdfc: 01e0f809  jalr	t7
0028ce00: 00000000  nop
0028ce04: 3c0d0036  lui	t5,0x36
0028ce08: 240f0001  li	t7,1
0028ce0c: 8daef410  lw	t6,-3056(t5)   ; = D_0035f410
0028ce10: 024f7804  sllv	t7,t7,s2
0028ce14: 01cf7025  or	t6,t6,t7
0028ce18: adaef410  sw	t6,-3056(t5)   ; = D_0035f410
0028ce1c: dfb00000  ld	s0,0(sp)
0028ce20: dfb10008  ld	s1,8(sp)
0028ce24: dfb20010  ld	s2,16(sp)
0028ce28: dfbf0018  ld	ra,24(sp)
0028ce2c: 03e00008  jr	ra
0028ce30: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028cdb8(void)`

```c
void FUN_0028cdb8(uint param_1)

{
  long lVar1;
  
  lVar1 = FUN_00139d78(DAT_0035f3fc + param_1 * 0x198);
  if (lVar1 != 0) {
    (**(code **)(*(int *)(param_1 * 0x198 + DAT_0035f3fc) + 0x14))();
    DAT_0035f410 = DAT_0035f410 | 1 << (param_1 & 0x1f);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
