# Target packet 001e60b0

- Range: `001e60b0`..`001e6100`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e60b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e6000` registry: `func_001e6000`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e60b0: 27bdfff0  addiu	sp,sp,-16
001e60b4: 3c0f0035  lui	t7,0x35
001e60b8: ffb00000  sd	s0,0(sp)
001e60bc: ffbf0008  sd	ra,8(sp)
001e60c0: 25f04bf0  addiu	s0,t7,19440   ; = D_00354bf0
001e60c4: 8e0e0004  lw	t6,4(s0)
001e60c8: 05c2000a  bltzl	t6,0x1e60f4
001e60cc: dfb00000  ld	s0,0(sp)
001e60d0: 0c079800  jal	0x1e6000
001e60d4: 26040028  addiu	a0,s0,40
001e60d8: 26040038  addiu	a0,s0,56
001e60dc: 0c079800  jal	0x1e6000
001e60e0: 26100048  addiu	s0,s0,72
001e60e4: 8e0f0004  lw	t7,4(s0)
001e60e8: 05e1fff9  bgez	t7,0x1e60d0
001e60ec: 00000000  nop
001e60f0: dfb00000  ld	s0,0(sp)
001e60f4: dfbf0008  ld	ra,8(sp)
001e60f8: 03e00008  jr	ra
001e60fc: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e60b0(void)`

```c
void FUN_001e60b0(void)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = &DAT_00354bf0;
  iVar1 = DAT_00354bf4;
  while (-1 < iVar1) {
    FUN_001e6000(puVar2 + 0x28);
    FUN_001e6000(puVar2 + 0x38);
    iVar1 = *(int *)(puVar2 + 0x4c);
    puVar2 = puVar2 + 0x48;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
