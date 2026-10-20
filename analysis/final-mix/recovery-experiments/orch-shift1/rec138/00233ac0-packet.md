# Target packet 00233ac0

- Range: `00233ac0`..`00233b1c`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_00233ac0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00313bc0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_scalar_extra_recovered_11.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00233ac0: 27bdfff0  addiu	sp,sp,-16
00233ac4: 00047842  srl	t7,a0,0x1
00233ac8: 308e0001  andi	t6,a0,0x1
00233acc: ffbf0000  sd	ra,0(sp)
00233ad0: 0480000e  bltz	a0,0x233b0c
00233ad4: 01cf7025  or	t6,t6,t7
00233ad8: 44840000  mtc1	a0,$f0
00233adc: 46800020  cvt.s.w	$f0,$f0
00233ae0: 3c0f0037  lui	t7,0x37
00233ae4: 25ef13b0  addiu	t7,t7,5040   ; = D_003713b0
00233ae8: c5ec0000  lwc1	$f12,0(t7)
00233aec: 00000000  nop
00233af0: 00000000  nop
00233af4: 460c0303  div.s	$f12,$f0,$f12
00233af8: 0c0c4ef0  jal	0x313bc0
00233afc: 00000000  nop
00233b00: dfbf0000  ld	ra,0(sp)
00233b04: 03e00008  jr	ra
00233b08: 27bd0010  addiu	sp,sp,16
00233b0c: 448e0000  mtc1	t6,$f0
00233b10: 46800020  cvt.s.w	$f0,$f0
00233b14: 1000fff2  b	0x233ae0
00233b18: 46000000  add.s	$f0,$f0,$f0
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00233ac0(void)`

```c
void FUN_00233ac0(ulong param_1)

{
  float fVar1;
  
  if ((long)param_1 < 0) {
    fVar1 = (float)(param_1 & 0xffffffff);
  }
  else {
    fVar1 = (float)(int)param_1;
  }
  FUN_00313bc0(fVar1 / DAT_003713b0);
  return;
}
```

## Earlier attempts (newest first)

- none found
