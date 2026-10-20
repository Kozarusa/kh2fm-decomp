# Target packet 0016bb38

- Range: `0016bb38`..`0016bba8`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016bb38`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b9bc8` registry: `_Z16ctarget_001b9bc8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016bb38: 27bdffe0  addiu	sp,sp,-32
0016bb3c: ffb00000  sd	s0,0(sp)
0016bb40: ffb10008  sd	s1,8(sp)
0016bb44: ffb20010  sd	s2,16(sp)
0016bb48: 0000802d  move	s0,zero
0016bb4c: ffbf0018  sd	ra,24(sp)
0016bb50: 00a0882d  move	s1,a1
0016bb54: 0080902d  move	s2,a0
0016bb58: 0c06e6f2  jal	0x1b9bc8
0016bb5c: 0200202d  move	a0,s0
0016bb60: 0040802d  move	s0,v0
0016bb64: 0040202d  move	a0,v0
0016bb68: 0240282d  move	a1,s2
0016bb6c: 14400008  bnez	v0,0x16bb90
0016bb70: 0220302d  move	a2,s1
0016bb74: dfb00000  ld	s0,0(sp)
0016bb78: dfb10008  ld	s1,8(sp)
0016bb7c: dfb20010  ld	s2,16(sp)
0016bb80: dfbf0018  ld	ra,24(sp)
0016bb84: 03e00008  jr	ra
0016bb88: 27bd0020  addiu	sp,sp,32
0016bb8c: 00000000  nop
0016bb90: 8e0f0000  lw	t7,0(s0)
0016bb94: 8dee0034  lw	t6,52(t7)
0016bb98: 01c0f809  jalr	t6
0016bb9c: 00000000  nop
0016bba0: 1000ffed  b	0x16bb58
0016bba4: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016bb38(void)`

```c
void FUN_0016bb38(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = 0;
  while (lVar1 = FUN_001b9bc8(lVar1), lVar1 != 0) {
    (**(code **)(*(int *)lVar1 + 0x34))(lVar1,param_1,param_2);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
