# Target packet 001db5a8

- Range: `001db5a8`..`001db610`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001db5a8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002fd248` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_callbackfamily_recovered_001b8800.cpp`, `fm_primary_callbackfamily_recovered_001c0c38.cpp`, `fm_primary_callbackfamily_recovered_001c10f8.cpp`, `fm_primary_callbackfamily_recovered_001d22a8.cpp`, `fm_primary_callbackfamily_recovered_001d23e0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001db5a8: 27bdffe0  addiu	sp,sp,-32
001db5ac: 2407005c  li	a3,92
001db5b0: ffb10008  sd	s1,8(sp)
001db5b4: ffb00000  sd	s0,0(sp)
001db5b8: 3c1101d6  lui	s1,0x1d6
001db5bc: ffbf0010  sd	ra,16(sp)
001db5c0: 8e25baac  lw	a1,-17748(s1)   ; = D_01d5baac
001db5c4: 3c100032  lui	s0,0x32
001db5c8: 26101b28  addiu	s0,s0,6952   ; = D_00321b28
001db5cc: 8ca60004  lw	a2,4(a1)
001db5d0: 0200402d  move	t0,s0
001db5d4: 0c0bf492  jal	0x2fd248
001db5d8: 24a50008  addiu	a1,a1,8
001db5dc: 0200402d  move	t0,s0
001db5e0: 24040045  li	a0,69
001db5e4: 14400005  bnez	v0,0x1db5fc
001db5e8: 2407005c  li	a3,92
001db5ec: 8e2fbaac  lw	t7,-17748(s1)   ; = D_01d5baac
001db5f0: 8de60004  lw	a2,4(t7)
001db5f4: 0c0bf492  jal	0x2fd248
001db5f8: 25e50008  addiu	a1,t7,8
001db5fc: dfb00000  ld	s0,0(sp)
001db600: dfb10008  ld	s1,8(sp)
001db604: dfbf0010  ld	ra,16(sp)
001db608: 03e00008  jr	ra
001db60c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001db5a8(void)`

```c
void FUN_001db5a8(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = FUN_002fd248(param_1,DAT_01d5baac + 8,*(undefined4 *)(DAT_01d5baac + 4),0x5c,0x321b28);
  if (lVar1 == 0) {
    FUN_002fd248(0x45,DAT_01d5baac + 8,*(undefined4 *)(DAT_01d5baac + 4),0x5c,0x321b28);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
