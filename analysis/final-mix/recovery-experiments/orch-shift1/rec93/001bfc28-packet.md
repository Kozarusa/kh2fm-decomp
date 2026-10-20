# Target packet 001bfc28

- Range: `001bfc28`..`001bfca0`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bfc28`
- Registry names for this address: `_Z17ttarget0_001bfc28v`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b9bc8` registry: `_Z16ctarget_001b9bc8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`
- `001bf378` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bfc28: 27bdffe0  addiu	sp,sp,-32
001bfc2c: 3c0f0035  lui	t7,0x35
001bfc30: ffb00000  sd	s0,0(sp)
001bfc34: ffb20010  sd	s2,16(sp)
001bfc38: ffb10008  sd	s1,8(sp)
001bfc3c: 0000802d  move	s0,zero
001bfc40: ffbf0018  sd	ra,24(sp)
001bfc44: 3c120004  lui	s2,0x4
001bfc48: 8df1e948  lw	s1,-5816(t7)   ; = D_0034e948
001bfc4c: 0c06e6f2  jal	0x1b9bc8
001bfc50: 0200202d  move	a0,s0
001bfc54: 0040802d  move	s0,v0
001bfc58: 0040202d  move	a0,v0
001bfc5c: 14400008  bnez	v0,0x1bfc80
001bfc60: 0220282d  move	a1,s1
001bfc64: dfb00000  ld	s0,0(sp)
001bfc68: dfb10008  ld	s1,8(sp)
001bfc6c: dfb20010  ld	s2,16(sp)
001bfc70: dfbf0018  ld	ra,24(sp)
001bfc74: 03e00008  jr	ra
001bfc78: 27bd0020  addiu	sp,sp,32
001bfc7c: 00000000  nop
001bfc80: 8e0f0588  lw	t7,1416(s0)
001bfc84: 01f27824  and	t7,t7,s2
001bfc88: 11e0fff0  beqz	t7,0x1bfc4c
001bfc8c: 00000000  nop
001bfc90: 0c06fcde  jal	0x1bf378
001bfc94: 00000000  nop
001bfc98: 1000ffec  b	0x1bfc4c
001bfc9c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bfc28(void)`

```c
void FUN_001bfc28(void)

{
  undefined4 uVar1;
  long lVar2;
  
  uVar1 = DAT_0034e948;
  lVar2 = 0;
  while (lVar2 = FUN_001b9bc8(lVar2), lVar2 != 0) {
    if ((*(uint *)((int)lVar2 + 0x588) & 0x40000) != 0) {
      FUN_001bf378(lVar2,uVar1);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
