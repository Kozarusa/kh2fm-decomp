# Target packet 00143dd0

- Range: `00143dd0`..`00143e50`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_00143dd0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00141c18` registry: `_ZN2dk11OctCollFile13setSelectMaskEjjbb`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`, `fm_primary_orchah_recovered_00143a48.cpp`, `fm_primary_orchah_recovered_00143ae0.cpp`
- `00141ff0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`, `fm_primary_orchah_recovered_00143a48.cpp`, `fm_primary_orchah_recovered_00143ae0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00143dd0: 27bdffd0  addiu	sp,sp,-48
00143dd4: ffb00000  sd	s0,0(sp)
00143dd8: ffb30018  sd	s3,24(sp)
00143ddc: ffb40020  sd	s4,32(sp)
00143de0: 3c100035  lui	s0,0x35
00143de4: ffb10008  sd	s1,8(sp)
00143de8: 00c0982d  move	s3,a2
00143dec: ffb20010  sd	s2,16(sp)
00143df0: 0080a02d  move	s4,a0
00143df4: ffbf0028  sd	ra,40(sp)
00143df8: 0100882d  move	s1,t0
00143dfc: 00a0902d  move	s2,a1
00143e00: 8e048804  lw	a0,-30716(s0)   ; = D_00348804
00143e04: 00e0302d  move	a2,a3
00143e08: 2405000f  li	a1,15
00143e0c: 0000382d  move	a3,zero
00143e10: 0c050706  jal	0x141c18
00143e14: 0000402d  move	t0,zero
00143e18: 8e048804  lw	a0,-30716(s0)   ; = D_00348804
00143e1c: 0280282d  move	a1,s4
00143e20: 0240302d  move	a2,s2
00143e24: 0260382d  move	a3,s3
00143e28: 0c0507fc  jal	0x141ff0
00143e2c: 0220402d  move	t0,s1
00143e30: dfb00000  ld	s0,0(sp)
00143e34: dfb10008  ld	s1,8(sp)
00143e38: dfb20010  ld	s2,16(sp)
00143e3c: dfb30018  ld	s3,24(sp)
00143e40: dfb40020  ld	s4,32(sp)
00143e44: dfbf0028  ld	ra,40(sp)
00143e48: 03e00008  jr	ra
00143e4c: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00143dd0(void)`

```c
void FUN_00143dd0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  FUN_00141c18(DAT_00348804,0xf,param_4,0,0);
  FUN_00141ff0(DAT_00348804,param_1,param_2,param_3,param_5);
  return;
}
```

## Earlier attempts (newest first)

- none found
