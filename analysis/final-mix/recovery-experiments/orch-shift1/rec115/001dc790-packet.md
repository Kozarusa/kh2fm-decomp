# Target packet 001dc790

- Range: `001dc790`..`001dc7e4`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dc790`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001dc738` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dc790: 27bdffe0  addiu	sp,sp,-32
001dc794: ffb00000  sd	s0,0(sp)
001dc798: ffb10008  sd	s1,8(sp)
001dc79c: ffbf0010  sd	ra,16(sp)
001dc7a0: 0080802d  move	s0,a0
001dc7a4: 0c0771ce  jal	0x1dc738
001dc7a8: 0000882d  move	s1,zero
001dc7ac: 54400007  bnezl	v0,0x1dc7cc
001dc7b0: 24110001  li	s1,1
001dc7b4: 8e0e0008  lw	t6,8(s0)
001dc7b8: 3c0f0020  lui	t7,0x20
001dc7bc: 01cf7024  and	t6,t6,t7
001dc7c0: 11c00003  beqz	t6,0x1dc7d0
001dc7c4: 0220102d  move	v0,s1
001dc7c8: 24110001  li	s1,1
001dc7cc: 0220102d  move	v0,s1
001dc7d0: dfb00000  ld	s0,0(sp)
001dc7d4: dfb10008  ld	s1,8(sp)
001dc7d8: dfbf0010  ld	ra,16(sp)
001dc7dc: 03e00008  jr	ra
001dc7e0: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dc790(void)`

```c
undefined4 FUN_001dc790(int param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_001dc738();
  if ((lVar2 != 0) || (uVar1 = 0, (*(uint *)(param_1 + 8) & 0x200000) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- 15 differing words, 80/84 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.cpp`)
