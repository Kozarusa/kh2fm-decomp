# Target packet 00143ae0

- Range: `00143ae0`..`00143b60`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_00143ae0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00141c18` registry: `_ZN2dk11OctCollFile13setSelectMaskEjjbb`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`
- `00141ff0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00143ae0: 27bdffd0  addiu	sp,sp,-48
00143ae4: 0000402d  move	t0,zero
00143ae8: ffb00000  sd	s0,0(sp)
00143aec: ffb40020  sd	s4,32(sp)
00143af0: ffb10008  sd	s1,8(sp)
00143af4: 3c100035  lui	s0,0x35
00143af8: ffb20010  sd	s2,16(sp)
00143afc: 0080a02d  move	s4,a0
00143b00: ffb30018  sd	s3,24(sp)
00143b04: 00a0882d  move	s1,a1
00143b08: ffbf0028  sd	ra,40(sp)
00143b0c: 00c0902d  move	s2,a2
00143b10: 00e0982d  move	s3,a3
00143b14: 8e048804  lw	a0,-30716(s0)   ; = D_00348804
00143b18: 0000282d  move	a1,zero
00143b1c: 0000302d  move	a2,zero
00143b20: 0c050706  jal	0x141c18
00143b24: 0000382d  move	a3,zero
00143b28: 8e048804  lw	a0,-30716(s0)   ; = D_00348804
00143b2c: 0280282d  move	a1,s4
00143b30: 0220302d  move	a2,s1
00143b34: 0240382d  move	a3,s2
00143b38: 0c0507fc  jal	0x141ff0
00143b3c: 0260402d  move	t0,s3
00143b40: dfb00000  ld	s0,0(sp)
00143b44: dfb10008  ld	s1,8(sp)
00143b48: dfb20010  ld	s2,16(sp)
00143b4c: dfb30018  ld	s3,24(sp)
00143b50: dfb40020  ld	s4,32(sp)
00143b54: dfbf0028  ld	ra,40(sp)
00143b58: 03e00008  jr	ra
00143b5c: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00143ae0(void)`

```c
void FUN_00143ae0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_00141c18(DAT_00348804,0,0,0,0);
  FUN_00141ff0(DAT_00348804,param_1,param_2,param_3,param_4);
  return;
}
```

## Earlier attempts (newest first)

- none found
