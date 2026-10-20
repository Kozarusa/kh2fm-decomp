# Target packet 001dbb38

- Range: `001dbb38`..`001dbb94`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dbb38`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00185da8` registry: `_Z16ctarget_00185da8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbg_recovered_00185da8.cpp`, `fm_primary_resume_recovered_00.cpp`, `fm_primary_transport_recovered.cpp`, `fm_primary_width_recovered_00.cpp`
- `0019c410` registry: `_ZN2YS3OBJ10is_cullingEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dbb38: 27bdfff0  addiu	sp,sp,-16
001dbb3c: ffb00000  sd	s0,0(sp)
001dbb40: ffbf0008  sd	ra,8(sp)
001dbb44: 0000802d  move	s0,zero
001dbb48: 0c06176a  jal	0x185da8
001dbb4c: 0200202d  move	a0,s0
001dbb50: 0040802d  move	s0,v0
001dbb54: 14400005  bnez	v0,0x1dbb6c
001dbb58: 0040202d  move	a0,v0
001dbb5c: dfb00000  ld	s0,0(sp)
001dbb60: dfbf0008  ld	ra,8(sp)
001dbb64: 03e00008  jr	ra
001dbb68: 27bd0010  addiu	sp,sp,16
001dbb6c: 0c067104  jal	0x19c410
001dbb70: 00000000  nop
001dbb74: 1040fff4  beqz	v0,0x1dbb48
001dbb78: 00000000  nop
001dbb7c: 8e0e0000  lw	t6,0(s0)
001dbb80: 8dcf0020  lw	t7,32(t6)
001dbb84: 01e0f809  jalr	t7
001dbb88: 0200202d  move	a0,s0
001dbb8c: 1000fff4  b	0x1dbb60
001dbb90: dfb00000  ld	s0,0(sp)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dbb38(void)`

```c
void FUN_001dbb38(void)

{
  long lVar1;
  long lVar2;
  
  lVar2 = 0;
  do {
    lVar2 = FUN_00185da8(lVar2);
    if (lVar2 == 0) {
      return;
    }
    lVar1 = FUN_0019c410(lVar2);
  } while (lVar1 == 0);
  (**(code **)(*(int *)lVar2 + 0x20))(lVar2);
  return;
}
```

## Earlier attempts (newest first)

- none found
