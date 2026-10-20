# Target packet 001c8b48

- Range: `001c8b48`..`001c8ba4`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c8b48`
- Registry names for this address: `_ZN2YS6SUMMON11IsTinkExistEv`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c8ab0` registry: `_ZN2YS6SUMMON7GetModeEv`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`
- `001d6d00` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c8b48: 27bdffe0  addiu	sp,sp,-32
001c8b4c: 24040132  li	a0,306
001c8b50: ffb00000  sd	s0,0(sp)
001c8b54: ffb10008  sd	s1,8(sp)
001c8b58: ffbf0010  sd	ra,16(sp)
001c8b5c: 0c075b40  jal	0x1d6d00
001c8b60: 0000882d  move	s1,zero
001c8b64: 0c0722ac  jal	0x1c8ab0
001c8b68: 0040802d  move	s0,v0
001c8b6c: 10400007  beqz	v0,0x1c8b8c
001c8b70: 3c0f0033  lui	t7,0x33
001c8b74: 25efbb30  addiu	t7,t7,-17616   ; = D_0032bb30
001c8b78: 91ee3525  lbu	t6,13605(t7)
001c8b7c: 15d00004  bne	t6,s0,0x1c8b90
001c8b80: 0220102d  move	v0,s1
001c8b84: 91ef3527  lbu	t7,13607(t7)
001c8b88: 000f882b  sltu	s1,zero,t7
001c8b8c: 0220102d  move	v0,s1
001c8b90: dfb00000  ld	s0,0(sp)
001c8b94: dfb10008  ld	s1,8(sp)
001c8b98: dfbf0010  ld	ra,16(sp)
001c8b9c: 03e00008  jr	ra
001c8ba0: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c8b48(void)`

```c
bool FUN_001c8b48(void)

{
  bool bVar1;
  ulong uVar2;
  long lVar3;
  
  bVar1 = false;
  uVar2 = FUN_001d6d00(0x132);
  lVar3 = FUN_001c8ab0();
  if ((lVar3 != 0) && (bVar1 = false, DAT_0032f050._5_1_ == uVar2)) {
    bVar1 = DAT_0032f050._7_1_ != '\0';
  }
  return bVar1;
}
```

## Earlier attempts (newest first)

- none found
