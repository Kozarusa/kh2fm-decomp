# Target packet 001fcb18

- Range: `001fcb18`..`001fcb90`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001fcb18`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002f3d08` registry: `_Z16wtarget_002f3d08jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchdf_recovered_001eb0c8.cpp`, `fm_primary_orchdf_recovered_001eb140.cpp`, `fm_primary_orchdf_recovered_001eb1b0.cpp`, `fm_primary_orchdf_recovered_001eb228.cpp`, `fm_primary_queuezeta_recovered_002f3d08.cpp`
- `002f3f98` registry: `_Z16u_call4_002f3f98jjjj`
  - accepted sources that already call it (copy their declaration): `fm_fallback_vector.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001fcb18: 27bdffe0  addiu	sp,sp,-32
001fcb1c: 3c0501da  lui	a1,0x1da
001fcb20: ffbf0010  sd	ra,16(sp)
001fcb24: 24a5e840  addiu	a1,a1,-6080   ; = D_01d9e840
001fcb28: ffb00000  sd	s0,0(sp)
001fcb2c: ffb10008  sd	s1,8(sp)
001fcb30: 0080802d  move	s0,a0
001fcb34: 8ccf000c  lw	t7,12(a2)
001fcb38: 3c1101da  lui	s1,0x1da
001fcb3c: 8e24e6e8  lw	a0,-6424(s1)   ; = D_01d9e6e8
001fcb40: 8dee0004  lw	t6,4(t7)
001fcb44: 24860010  addiu	a2,a0,16
001fcb48: 020e8021  addu	s0,s0,t6
001fcb4c: 0c0bcf42  jal	0x2f3d08
001fcb50: 24840050  addiu	a0,a0,80
001fcb54: 261000a0  addiu	s0,s0,160
001fcb58: 8e25e6e8  lw	a1,-6424(s1)   ; = D_01d9e6e8
001fcb5c: 0200202d  move	a0,s0
001fcb60: 0c0bcfe6  jal	0x2f3f98
001fcb64: 24a50050  addiu	a1,a1,80
001fcb68: 8e24e6e8  lw	a0,-6424(s1)   ; = D_01d9e6e8
001fcb6c: 3c0501da  lui	a1,0x1da
001fcb70: dfb00000  ld	s0,0(sp)
001fcb74: 24a5e8c0  addiu	a1,a1,-5952   ; = D_01d9e8c0
001fcb78: 24840050  addiu	a0,a0,80
001fcb7c: dfb10008  ld	s1,8(sp)
001fcb80: dfbf0010  ld	ra,16(sp)
001fcb84: 0080302d  move	a2,a0
001fcb88: 080bcf42  j	0x2f3d08
001fcb8c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001fcb18(void)`

```c
void FUN_001fcb18(int param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_3 + 0xc) + 4);
  FUN_002f3d08(DAT_01d9e6e8 + 0x50,0x1d9e840,DAT_01d9e6e8 + 0x10);
  FUN_002f3f98(param_1 + iVar1 + 0xa0,DAT_01d9e6e8 + 0x50);
  FUN_002f3d08(DAT_01d9e6e8 + 0x50,0x1d9e8c0,DAT_01d9e6e8 + 0x50);
  return;
}
```

## Earlier attempts (newest first)

- none found
