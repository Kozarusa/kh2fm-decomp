# Target packet 001bf6a8

- Range: `001bf6a8`..`001bf710`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bf6a8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b9bc8` registry: `_Z16ctarget_001b9bc8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bf6a8: 27bdffe0  addiu	sp,sp,-32
001bf6ac: ffb00000  sd	s0,0(sp)
001bf6b0: ffb10008  sd	s1,8(sp)
001bf6b4: ffbf0010  sd	ra,16(sp)
001bf6b8: 0000802d  move	s0,zero
001bf6bc: 3c110004  lui	s1,0x4
001bf6c0: 0c06e6f2  jal	0x1b9bc8
001bf6c4: 0200202d  move	a0,s0
001bf6c8: 0040802d  move	s0,v0
001bf6cc: 14400006  bnez	v0,0x1bf6e8
001bf6d0: 0040202d  move	a0,v0
001bf6d4: dfb00000  ld	s0,0(sp)
001bf6d8: dfb10008  ld	s1,8(sp)
001bf6dc: dfbf0010  ld	ra,16(sp)
001bf6e0: 03e00008  jr	ra
001bf6e4: 27bd0020  addiu	sp,sp,32
001bf6e8: 8e0f0588  lw	t7,1416(s0)
001bf6ec: 01f17824  and	t7,t7,s1
001bf6f0: 11e0fff3  beqz	t7,0x1bf6c0
001bf6f4: 00000000  nop
001bf6f8: 8e0f0000  lw	t7,0(s0)
001bf6fc: 8dee0028  lw	t6,40(t7)
001bf700: 01c0f809  jalr	t6
001bf704: 00000000  nop
001bf708: 1000ffed  b	0x1bf6c0
001bf70c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bf6a8(void)`

```c
void FUN_001bf6a8(void)

{
  long lVar1;
  
  lVar1 = 0;
  while (lVar1 = FUN_001b9bc8(lVar1), lVar1 != 0) {
    if ((((int *)lVar1)[0x162] & 0x40000U) != 0) {
      (**(code **)(*(int *)lVar1 + 0x28))(lVar1);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
