# Target packet 001c9ab8

- Range: `001c9ab8`..`001c9b34`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c9ab8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0017df58` registry: `_ZN2YS6FRIEND3GetEi`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`
- `0017e3b8` registry: `_ZN2YS6FRIEND20can_summon_sacrificeEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`
- `0019ba60` registry: `_Z16ctarget_0019ba60jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`
- `001bc010` registry: `func_001bc010`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchck_recovered_001bc010.cpp`, `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c9ab8: 27bdffe0  addiu	sp,sp,-32
001c9abc: ffb00000  sd	s0,0(sp)
001c9ac0: ffb10008  sd	s1,8(sp)
001c9ac4: ffbf0010  sd	ra,16(sp)
001c9ac8: 0c06f004  jal	0x1bc010
001c9acc: 00000000  nop
001c9ad0: 14400010  bnez	v0,0x1c9b14
001c9ad4: 240f0001  li	t7,1
001c9ad8: 0000882d  move	s1,zero
001c9adc: 0c05f7d6  jal	0x17df58
001c9ae0: 0220202d  move	a0,s1
001c9ae4: 26310001  addiu	s1,s1,1
001c9ae8: 0040802d  move	s0,v0
001c9aec: 0c066e98  jal	0x19ba60
001c9af0: 0040202d  move	a0,v0
001c9af4: 1040000d  beqz	v0,0x1c9b2c
001c9af8: 0200202d  move	a0,s0
001c9afc: 0c05f8ee  jal	0x17e3b8
001c9b00: 00000000  nop
001c9b04: 10400009  beqz	v0,0x1c9b2c
001c9b08: 2a2f0002  slti	t7,s1,2
001c9b0c: 15e0fff3  bnez	t7,0x1c9adc
001c9b10: 240f0001  li	t7,1
001c9b14: dfb00000  ld	s0,0(sp)
001c9b18: 01e0102d  move	v0,t7
001c9b1c: dfb10008  ld	s1,8(sp)
001c9b20: dfbf0010  ld	ra,16(sp)
001c9b24: 03e00008  jr	ra
001c9b28: 27bd0020  addiu	sp,sp,32
001c9b2c: 1000fff9  b	0x1c9b14
001c9b30: 0000782d  move	t7,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c9ab8(void)`

```c
undefined4 FUN_001c9ab8(void)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  
  lVar1 = FUN_001bc010();
  if (lVar1 == 0) {
    iVar3 = 0;
    do {
      uVar2 = FUN_0017df58(iVar3);
      iVar3 = iVar3 + 1;
      lVar1 = FUN_0019ba60(uVar2);
      if (lVar1 == 0) {
        return 0;
      }
      lVar1 = FUN_0017e3b8(uVar2);
      if (lVar1 == 0) {
        return 0;
      }
    } while (iVar3 < 2);
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 18 differing words, 128/124 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_00_all_narrow32.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_00_all_narrow32.cpp`)
