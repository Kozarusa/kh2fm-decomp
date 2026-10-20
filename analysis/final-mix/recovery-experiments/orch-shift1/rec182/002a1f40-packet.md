# Target packet 002a1f40

- Range: `002a1f40`..`002a1f7c`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_002a1f40`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00276c50` registry: `Tz::JmReport::DrawMessage(unsigned int, unsigned int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_storeorder_recovered_00281f90.cpp`, `fm_primary_width_recovered_02.cpp`, `fm_scalar_recovered_07.cpp`
- `00287bc0` registry: `_ZN2Tz8MenuBase7GetModeEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002a1f40: 27bdfff0  addiu	sp,sp,-16
002a1f44: ffbf0000  sd	ra,0(sp)
002a1f48: 0c0a1ef0  jal	0x287bc0
002a1f4c: 00000000  nop
002a1f50: 240f0006  li	t7,6
002a1f54: 144f0007  bne	v0,t7,0x2a1f74
002a1f58: 3c0f0037  lui	t7,0x37
002a1f5c: 3c0f0037  lui	t7,0x37
002a1f60: 8de44b44  lw	a0,19268(t7)   ; = D_00374b44
002a1f64: dfbf0000  ld	ra,0(sp)
002a1f68: 0000282d  move	a1,zero
002a1f6c: 0809db14  j	0x276c50
002a1f70: 27bd0010  addiu	sp,sp,16
002a1f74: 1000fffb  b	0x2a1f64
002a1f78: 8de44b48  lw	a0,19272(t7)   ; = D_00374b48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002a1f40(void)`

```c
void FUN_002a1f40(void)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_00287bc0();
  uVar1 = DAT_00374b48;
  if (lVar2 == 6) {
    uVar1 = DAT_00374b44;
  }
  FUN_00276c50(uVar1,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
