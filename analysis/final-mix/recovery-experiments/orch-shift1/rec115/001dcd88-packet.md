# Target packet 001dcd88

- Range: `001dcd88`..`001dcdb8`, **48 bytes = 12 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dcd88`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00168388` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_freshhelpers_recovered_001367e0.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dcd88: 27bdfff0  addiu	sp,sp,-16
001dcd8c: 3c0f0035  lui	t7,0x35
001dcd90: ffbf0000  sd	ra,0(sp)
001dcd94: 3c0501d6  lui	a1,0x1d6
001dcd98: 8de42aec  lw	a0,10988(t7)   ; = D_00352aec
001dcd9c: 3c06001e  lui	a2,0x1e
001dcda0: dfbf0000  ld	ra,0(sp)
001dcda4: 24a5bb40  addiu	a1,a1,-17600   ; = D_01d5bb40
001dcda8: 24c6cd68  addiu	a2,a2,-12952   ; = D_001dcd68
001dcdac: 0000382d  move	a3,zero
001dcdb0: 0805a0e2  j	0x168388
001dcdb4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dcd88(void)`

```c
void FUN_001dcd88(void)

{
  FUN_00168388(PTR_s_effect_texcommon_dpd_0036e7c7_1_00352aec,0x1d5bb40,0x1dcd68,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
