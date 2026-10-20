# Target packet 001bbc30

- Range: `001bbc30`..`001bbcac`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bbc30`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001af2e8` registry: `func_001af2e8`
- `001af360` registry: `func_001af360`
  - accepted sources that already call it (copy their declaration): `fm_scalar_recovered_04.cpp`
- `001bb468` registry: `_ZN2YS7MISSION3EndEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twowordfresh_recovered_001b3330.cpp`, `fm_scalar_extra_recovered_01.cpp`, `fm_scalar_extra_recovered_04.cpp`, `fm_scalar_recovered_01.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bbc30: 27bdfff0  addiu	sp,sp,-16
001bbc34: 3c0f01d5  lui	t7,0x1d5
001bbc38: ffb00000  sd	s0,0(sp)
001bbc3c: ffbf0008  sd	ra,8(sp)
001bbc40: 8dee9320  lw	t6,-27872(t7)   ; = D_01d49320
001bbc44: 8dcd0008  lw	t5,8(t6)
001bbc48: 0c06ed1a  jal	0x1bb468
001bbc4c: 91b00008  lbu	s0,8(t5)
001bbc50: 0000202d  move	a0,zero
001bbc54: 240f001e  li	t7,30
001bbc58: 120f000b  beq	s0,t7,0x1bbc88
001bbc5c: 2a0e001f  slti	t6,s0,31
001bbc60: 11c0000d  beqz	t6,0x1bbc98
001bbc64: 240f0002  li	t7,2
001bbc68: 120f0008  beq	s0,t7,0x1bbc8c
001bbc6c: dfb00000  ld	s0,0(sp)
001bbc70: 0c06bcba  jal	0x1af2e8
001bbc74: 00000000  nop
001bbc78: dfb00000  ld	s0,0(sp)
001bbc7c: dfbf0008  ld	ra,8(sp)
001bbc80: 03e00008  jr	ra
001bbc84: 27bd0010  addiu	sp,sp,16
001bbc88: dfb00000  ld	s0,0(sp)
001bbc8c: dfbf0008  ld	ra,8(sp)
001bbc90: 0806bcd8  j	0x1af360
001bbc94: 27bd0010  addiu	sp,sp,16
001bbc98: 240f0023  li	t7,35
001bbc9c: 160ffff4  bne	s0,t7,0x1bbc70
001bbca0: dfb00000  ld	s0,0(sp)
001bbca4: 1000fffa  b	0x1bbc90
001bbca8: dfbf0008  ld	ra,8(sp)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bbc30(void)`

```c
void FUN_001bbc30(void)

{
  byte bVar1;
  
  bVar1 = *(byte *)(*(int *)(DAT_01d49320 + 8) + 8);
  FUN_001bb468();
  if (bVar1 != 0x1e) {
    if (bVar1 < 0x1f) {
      if (bVar1 != 2) {
LAB_001bbc70:
        FUN_001af2e8();
        return;
      }
    }
    else if (bVar1 != 0x23) goto LAB_001bbc70;
  }
  FUN_001af360(0);
  return;
}
```

## Earlier attempts (newest first)

- none found
