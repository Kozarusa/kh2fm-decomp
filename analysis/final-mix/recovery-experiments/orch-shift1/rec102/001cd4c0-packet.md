# Target packet 001cd4c0

- Range: `001cd4c0`..`001cd520`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_001cd4c0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001bbf00` registry: `func_001bbf00`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchck_recovered_001bbf00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001cd4c0: 27bdfff0  addiu	sp,sp,-16
001cd4c4: ffbf0000  sd	ra,0(sp)
001cd4c8: 0c06efc0  jal	0x1bbf00
001cd4cc: 00000000  nop
001cd4d0: 1440000f  bnez	v0,0x1cd510
001cd4d4: 240f0001  li	t7,1
001cd4d8: 3c0f0033  lui	t7,0x33
001cd4dc: 25efbae0  addiu	t7,t7,-17696   ; = D_0032bae0
001cd4e0: 95ee0004  lhu	t6,4(t7)
001cd4e4: 2dce0033  sltiu	t6,t6,51
001cd4e8: 11c00008  beqz	t6,0x1cd50c
001cd4ec: 3c0f0035  lui	t7,0x35
001cd4f0: 91ee0378  lbu	t6,888(t7)   ; = D_00350378
001cd4f4: 15c00006  bnez	t6,0x1cd510
001cd4f8: 0000782d  move	t7,zero
001cd4fc: 0c06ed28  jal	0x1bb4a0
001cd500: 00000000  nop
001cd504: 10400002  beqz	v0,0x1cd510
001cd508: 240f0001  li	t7,1
001cd50c: 0000782d  move	t7,zero
001cd510: dfbf0000  ld	ra,0(sp)
001cd514: 01e0102d  move	v0,t7
001cd518: 03e00008  jr	ra
001cd51c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001cd4c0(void)`

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_001cd4c0(void)

{
  long lVar1;
  
  lVar1 = FUN_001bbf00();
  if (lVar1 != 0) {
    return 1;
  }
  if (_DAT_0032bae4 < 0x33) {
    if (DAT_00350378 != '\0') {
      return 0;
    }
    lVar1 = FUN_001bb4a0();
    if (lVar1 == 0) {
      return 1;
    }
  }
  return 0;
}
```

## Earlier attempts (newest first)

- none found
