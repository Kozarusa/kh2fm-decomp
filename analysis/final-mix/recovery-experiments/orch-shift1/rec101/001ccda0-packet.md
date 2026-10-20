# Target packet 001ccda0

- Range: `001ccda0`..`001ccdec`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ccda0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00186078` registry: `func_00186078`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbg_recovered_00186078.cpp`, `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`, `fm_scalar_extra_recovered_12.cpp`
- `001c16f0` registry: `_ZN2YS10MASSEFFECT7MANAGER4eachEPS0_`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbu_recovered_001a5a48.cpp`, `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`
- `001c6ee8` registry: `_ZN2YS10MASSEFFECT7MANAGER10exec_zsortEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`, `fm_scalar_recovered_04.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ccda0: 27bdfff0  addiu	sp,sp,-16
001ccda4: ffb00000  sd	s0,0(sp)
001ccda8: ffbf0008  sd	ra,8(sp)
001ccdac: 0c071bba  jal	0x1c6ee8
001ccdb0: 0080802d  move	s0,a0
001ccdb4: 0000102d  move	v0,zero
001ccdb8: 8e0409f4  lw	a0,2548(s0)
001ccdbc: 0c0705bc  jal	0x1c16f0
001ccdc0: 0040282d  move	a1,v0
001ccdc4: 5440fffd  bnezl	v0,0x1ccdbc
001ccdc8: 8e0409f4  lw	a0,2548(s0)
001ccdcc: 0000102d  move	v0,zero
001ccdd0: 0c06181e  jal	0x186078
001ccdd4: 0040202d  move	a0,v0
001ccdd8: 1440fffd  bnez	v0,0x1ccdd0
001ccddc: dfbf0008  ld	ra,8(sp)
001ccde0: dfb00000  ld	s0,0(sp)
001ccde4: 03e00008  jr	ra
001ccde8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ccda0(void)`

```c
void FUN_001ccda0(int param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  FUN_001c6ee8();
  lVar2 = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x9f4);
  while (lVar2 = FUN_001c16f0(uVar1,lVar2), lVar2 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x9f4);
  }
  lVar2 = 0;
  do {
    lVar2 = FUN_00186078(lVar2);
  } while (lVar2 != 0);
  return;
}
```

## Earlier attempts (newest first)

- 10 differing words, 72/76 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_00_all.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_00_all.cpp`)
