# Target packet 001dc418

- Range: `001dc418`..`001dc484`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dc418`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001dc4b8` registry: `func_001dc4b8`
  - accepted sources that already call it (copy their declaration): `fm_primary_workerbacklog_recovered_001dc4b8.cpp`
- `001e2c00` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`
- `001e6c00` registry: `func_001e6c00`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`
- `00321c50` registry: `func_00321c50`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dc418: 27bdfff0  addiu	sp,sp,-16
001dc41c: 3c0f0035  lui	t7,0x35
001dc420: ffb00000  sd	s0,0(sp)
001dc424: 25ef2b48  addiu	t7,t7,11080   ; = D_00352b48
001dc428: ffbf0008  sd	ra,8(sp)
001dc42c: ac8f0000  sw	t7,0(a0)
001dc430: 0080802d  move	s0,a0
001dc434: 8c8e001c  lw	t6,28(a0)
001dc438: 11c00005  beqz	t6,0x1dc450
001dc43c: 01c0202d  move	a0,t6
001dc440: 0c078b00  jal	0x1e2c00
001dc444: 00000000  nop
001dc448: 0c079b00  jal	0x1e6c00
001dc44c: 8e04001c  lw	a0,28(s0)
001dc450: 3c040035  lui	a0,0x35
001dc454: 0200282d  move	a1,s0
001dc458: 0c0c8714  jal	0x321c50
001dc45c: 24842ae0  addiu	a0,a0,10976   ; = D_00352ae0
001dc460: 3c0e0035  lui	t6,0x35
001dc464: dfbf0008  ld	ra,8(sp)
001dc468: 8dcf2ae8  lw	t7,10984(t6)   ; = D_00352ae8
001dc46c: 0200202d  move	a0,s0
001dc470: dfb00000  ld	s0,0(sp)
001dc474: 25efffff  addiu	t7,t7,-1
001dc478: adcf2ae8  sw	t7,10984(t6)   ; = D_00352ae8
001dc47c: 0807712e  j	0x1dc4b8
001dc480: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dc418(void)`

```c
void FUN_001dc418(undefined8 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  *puVar1 = &PTR_LAB_00352b48;
  if (puVar1[7] != 0) {
    FUN_001e2c00(puVar1[7]);
    FUN_001e6c00(puVar1[7]);
  }
  FUN_00321c50(0x352ae0,param_1);
  DAT_00352ae8 = DAT_00352ae8 + -1;
  FUN_001dc4b8(param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
