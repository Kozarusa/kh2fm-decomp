# Target packet 001e3c18

- Range: `001e3c18`..`001e3c98`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e3c18`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e3650` registry: `func_001e3650`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001e3660` registry: `_Z13func_001e3660ji`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001e38f8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001e3a88` registry: none
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e3c18: 27bdffe0  addiu	sp,sp,-32
001e3c1c: ffbf0018  sd	ra,24(sp)
001e3c20: ffb00000  sd	s0,0(sp)
001e3c24: ffb10008  sd	s1,8(sp)
001e3c28: ffb20010  sd	s2,16(sp)
001e3c2c: 0080802d  move	s0,a0
001e3c30: 8492009c  lh	s2,156(a0)
001e3c34: 8c820088  lw	v0,136(a0)
001e3c38: 8611009e  lh	s1,158(s0)
001e3c3c: 0c078d94  jal	0x1e3650
001e3c40: 0040202d  move	a0,v0
001e3c44: 0040202d  move	a0,v0
001e3c48: 0c078d98  jal	0x1e3660
001e3c4c: 24050002  li	a1,2
001e3c50: 8e05008c  lw	a1,140(s0)
001e3c54: 0240302d  move	a2,s2
001e3c58: 0220382d  move	a3,s1
001e3c5c: 0040202d  move	a0,v0
001e3c60: 0c078e3e  jal	0x1e38f8
001e3c64: 24a500c0  addiu	a1,a1,192
001e3c68: 8e05008c  lw	a1,140(s0)
001e3c6c: 0240302d  move	a2,s2
001e3c70: 0220382d  move	a3,s1
001e3c74: 0040202d  move	a0,v0
001e3c78: 0c078ea2  jal	0x1e3a88
001e3c7c: 24a500d0  addiu	a1,a1,208
001e3c80: dfb00000  ld	s0,0(sp)
001e3c84: dfb10008  ld	s1,8(sp)
001e3c88: dfb20010  ld	s2,16(sp)
001e3c8c: dfbf0018  ld	ra,24(sp)
001e3c90: 03e00008  jr	ra
001e3c94: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e3c18(void)`

```c
void FUN_001e3c18(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined8 uVar3;
  
  uVar1 = *(undefined2 *)(param_1 + 0x9c);
  uVar2 = *(undefined2 *)(param_1 + 0x9e);
  uVar3 = FUN_001e3650(*(undefined4 *)(param_1 + 0x88));
  uVar3 = FUN_001e3660(uVar3,2);
  uVar3 = FUN_001e38f8(uVar3,*(int *)(param_1 + 0x8c) + 0xc0,uVar1,uVar2);
  FUN_001e3a88(uVar3,*(int *)(param_1 + 0x8c) + 0xd0,uVar1,uVar2);
  return;
}
```

## Earlier attempts (newest first)

- 21 differing words, 128/128 bytes: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_08_0.cpp`)
