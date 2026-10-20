# Target packet 0026ff30

- Range: `0026ff30`..`0026ff74`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_0026ff30`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002571e0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_twoword_recovered_0026ec70.cpp`, `fm_primary_twoword_recovered_00276410.cpp`, `fm_primary_twoword_recovered_002806c8.cpp`, `fm_scalar_extra_recovered_07.cpp`, `fm_scalar_recovered_07.cpp`
- `00257388` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_twoword_recovered_0026ec70.cpp`, `fm_primary_twoword_recovered_00276410.cpp`, `fm_primary_twoword_recovered_002806c8.cpp`, `fm_scalar_extra_recovered_07.cpp`, `fm_scalar_recovered_07.cpp`
- `00287bc0` registry: `_ZN2Tz8MenuBase7GetModeEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`
- `00287cc0` registry: `Tz::Selector::SetState(int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`, `fm_primary_oneword_recovered_00253538.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0026ff30: 27bdfff0  addiu	sp,sp,-16
0026ff34: ffbf0000  sd	ra,0(sp)
0026ff38: 0c0a1ef0  jal	0x287bc0
0026ff3c: 00000000  nop
0026ff40: 3c0f0036  lui	t7,0x36
0026ff44: 3c0e0036  lui	t6,0x36
0026ff48: a1e2f130  sb	v0,-3792(t7)   ; = D_0035f130
0026ff4c: 0000282d  move	a1,zero
0026ff50: a1c0f128  sb	zero,-3800(t6)   ; = D_0035f128
0026ff54: 0c095ce2  jal	0x257388
0026ff58: 3404846a  li	a0,0x846a
0026ff5c: 0c095c78  jal	0x2571e0
0026ff60: 24040001  li	a0,1
0026ff64: dfbf0000  ld	ra,0(sp)
0026ff68: 0000202d  move	a0,zero
0026ff6c: 080a1f30  j	0x287cc0
0026ff70: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0026ff30(void)`

```c
void FUN_0026ff30(void)

{
  DAT_0035f130 = FUN_00287bc0();
  DAT_0035f128 = 0;
  FUN_00257388(0x846a,0);
  FUN_002571e0(1);
  FUN_00287cc0(0);
  return;
}
```

## Earlier attempts (newest first)

- none found
