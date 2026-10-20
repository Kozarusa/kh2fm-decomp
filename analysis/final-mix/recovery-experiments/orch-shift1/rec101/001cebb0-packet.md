# Target packet 001cebb0

- Range: `001cebb0`..`001cec08`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001cebb0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102c18` registry: `_ZN5FIELD10CreateTaskEiiPFvP4TASKE`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_more_recovered.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`
- `001050d8` registry: `_ZN4AREA5AllocEj`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_callbackreturn_recovered_001050d8.cpp`
- `001ce8b8` registry: `func_001ce8b8`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001cebb0: 27bdfff0  addiu	sp,sp,-16
001cebb4: ffbf0008  sd	ra,8(sp)
001cebb8: ffb00000  sd	s0,0(sp)
001cebbc: 0c041436  jal	0x1050d8
001cebc0: 2404003c  li	a0,60
001cebc4: 0040802d  move	s0,v0
001cebc8: 0c073a2e  jal	0x1ce8b8
001cebcc: 0040202d  move	a0,v0
001cebd0: 3c0f0035  lui	t7,0x35
001cebd4: 3c06001d  lui	a2,0x1d
001cebd8: adf021d0  sw	s0,8656(t7)   ; = D_003521d0
001cebdc: 24040001  li	a0,1
001cebe0: 24c6ec08  addiu	a2,a2,-5112   ; = D_001cec08
001cebe4: 0c040b06  jal	0x102c18
001cebe8: 240536b1  li	a1,14001
001cebec: 3c0f001d  lui	t7,0x1d
001cebf0: dfb00000  ld	s0,0(sp)
001cebf4: 25efec28  addiu	t7,t7,-5080   ; = D_001cec28
001cebf8: dfbf0008  ld	ra,8(sp)
001cebfc: ac4f0030  sw	t7,48(v0)
001cec00: 03e00008  jr	ra
001cec04: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001cebb0(void)`

```c
void FUN_001cebb0(void)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_001050d8(0x3c);
  FUN_001ce8b8(uVar2);
  DAT_003521d0 = (int)uVar2;
  iVar1 = FUN_00102c18(1,0x36b1,0x1cec08);
  *(undefined1 **)(iVar1 + 0x30) = &LAB_001cec28;
  return;
}
```

## Earlier attempts (newest first)

- none found
