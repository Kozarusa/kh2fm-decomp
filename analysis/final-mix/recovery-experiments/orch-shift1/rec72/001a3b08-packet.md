# Target packet 001a3b08

- Range: `001a3b08`..`001a3b44`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a3b08`
- Registry names for this address: `_ZN2YS6EFFECT6EnsureEv`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00170950` registry: `_ZN2YS10CACHE_BUFF4FreeEPv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_near_recovered_v2.cpp`, `fm_primary_orchbk_recovered_001922c8.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_storeorder_recovered_00281f90.cpp`
- `001dde40` registry: none
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001de450` registry: `func_001de450`
  - accepted sources that already call it (copy their declaration): `fm_primary_resume_recovered_01.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a3b08: 27bdfff0  addiu	sp,sp,-16
001a3b0c: ffb00000  sd	s0,0(sp)
001a3b10: ffbf0008  sd	ra,8(sp)
001a3b14: 3c1001c7  lui	s0,0x1c7
001a3b18: 2610cae0  addiu	s0,s0,-13600   ; = D_01c6cae0
001a3b1c: 0c077914  jal	0x1de450
001a3b20: 0200202d  move	a0,s0
001a3b24: 0c077790  jal	0x1dde40
001a3b28: 0200202d  move	a0,s0
001a3b2c: 3c0f01c7  lui	t7,0x1c7
001a3b30: dfb00000  ld	s0,0(sp)
001a3b34: 8de4cafc  lw	a0,-13572(t7)   ; = D_01c6cafc
001a3b38: dfbf0008  ld	ra,8(sp)
001a3b3c: 0805c254  j	0x170950
001a3b40: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a3b08(void)`

```c
void FUN_001a3b08(void)

{
  FUN_001de450(0x1c6cae0);
  FUN_001dde40(0x1c6cae0);
  FUN_00170950(DAT_01c6cafc);
  return;
}
```

## Earlier attempts (newest first)

- none found
