# Target packet 001dd2b8

- Range: `001dd2b8`..`001dd320`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dd2b8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00106a18` registry: `func_00106a18`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`, `fm_primary_packetorder_recovered_002e8038.cpp`
- `00106a60` registry: `func_00106a60`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`
- `001dd320` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dd2b8: 27bdfff0  addiu	sp,sp,-16
001dd2bc: 3c0f0035  lui	t7,0x35
001dd2c0: ffb00000  sd	s0,0(sp)
001dd2c4: ffbf0008  sd	ra,8(sp)
001dd2c8: 91ee2af1  lbu	t6,10993(t7)   ; = D_00352af1
001dd2cc: 15c00011  bnez	t6,0x1dd314
001dd2d0: dfb00000  ld	s0,0(sp)
001dd2d4: 3c0f0035  lui	t7,0x35
001dd2d8: 91ee2af0  lbu	t6,10992(t7)   ; = D_00352af0
001dd2dc: 11c0000e  beqz	t6,0x1dd318
001dd2e0: dfbf0008  ld	ra,8(sp)
001dd2e4: 0c041a86  jal	0x106a18
001dd2e8: 0000202d  move	a0,zero
001dd2ec: 0040802d  move	s0,v0
001dd2f0: 0c041a98  jal	0x106a60
001dd2f4: 0000202d  move	a0,zero
001dd2f8: 0200202d  move	a0,s0
001dd2fc: dfbf0008  ld	ra,8(sp)
001dd300: dfb00000  ld	s0,0(sp)
001dd304: 0040282d  move	a1,v0
001dd308: 24060001  li	a2,1
001dd30c: 080774c8  j	0x1dd320
001dd310: 27bd0010  addiu	sp,sp,16
001dd314: dfbf0008  ld	ra,8(sp)
001dd318: 03e00008  jr	ra
001dd31c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dd2b8(void)`

```c
void FUN_001dd2b8(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if ((DAT_00352af1 == '\0') && (DAT_00352af0 != '\0')) {
    uVar1 = FUN_00106a18(0);
    uVar2 = FUN_00106a60(0);
    FUN_001dd320(uVar1,uVar2,1);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
