# Target packet 001dcc60

- Range: `001dcc60`..`001dccc8`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dcc60`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c8ab0` registry: `_ZN2YS6SUMMON7GetModeEv`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`
- `001dcd38` registry: `func_001dcd38`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dcc60: 27bdffe0  addiu	sp,sp,-32
001dcc64: ffb10008  sd	s1,8(sp)
001dcc68: ffb00000  sd	s0,0(sp)
001dcc6c: ffb20010  sd	s2,16(sp)
001dcc70: 0080882d  move	s1,a0
001dcc74: ffbf0018  sd	ra,24(sp)
001dcc78: 24100001  li	s0,1
001dcc7c: 0c07734e  jal	0x1dcd38
001dcc80: 0000902d  move	s2,zero
001dcc84: 50500006  beql	v0,s0,0x1dcca0
001dcc88: 8e2f0008  lw	t7,8(s1)
001dcc8c: 0c0722ac  jal	0x1c8ab0
001dcc90: 00000000  nop
001dcc94: 10500006  beq	v0,s0,0x1dccb0
001dcc98: 0240102d  move	v0,s2
001dcc9c: 8e2f0008  lw	t7,8(s1)
001dcca0: 3c0e0080  lui	t6,0x80
001dcca4: 01ee7824  and	t7,t7,t6
001dcca8: 2df20001  sltiu	s2,t7,1
001dccac: 0240102d  move	v0,s2
001dccb0: dfb00000  ld	s0,0(sp)
001dccb4: dfb10008  ld	s1,8(sp)
001dccb8: dfb20010  ld	s2,16(sp)
001dccbc: dfbf0018  ld	ra,24(sp)
001dccc0: 03e00008  jr	ra
001dccc4: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dcc60(void)`

```c
bool FUN_001dcc60(int param_1)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = FUN_001dcd38();
  if (lVar2 == 1) {
    uVar1 = *(uint *)(param_1 + 8);
  }
  else {
    lVar2 = FUN_001c8ab0();
    if (lVar2 == 1) {
      return false;
    }
    uVar1 = *(uint *)(param_1 + 8);
  }
  return (uVar1 & 0x800000) == 0;
}
```

## Earlier attempts (newest first)

- none found
