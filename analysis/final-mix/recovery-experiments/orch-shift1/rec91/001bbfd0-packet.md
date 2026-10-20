# Target packet 001bbfd0

- Range: `001bbfd0`..`001bc00c`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bbfd0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001bbcb0` registry: `_ZN2YS7MISSION10GetCurrentEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bbfd0: 27bdfff0  addiu	sp,sp,-16
001bbfd4: ffbf0000  sd	ra,0(sp)
001bbfd8: 0c06ed28  jal	0x1bb4a0
001bbfdc: 00000000  nop
001bbfe0: 10400007  beqz	v0,0x1bc000
001bbfe4: 3c0f0037  lui	t7,0x37
001bbfe8: 0c06ef2c  jal	0x1bbcb0
001bbfec: 00000000  nop
001bbff0: c4400530  lwc1	$f0,1328(v0)
001bbff4: dfbf0000  ld	ra,0(sp)
001bbff8: 03e00008  jr	ra
001bbffc: 27bd0010  addiu	sp,sp,16
001bc000: 25efdc44  addiu	t7,t7,-9148   ; = D_0036dc44
001bc004: 1000fffb  b	0x1bbff4
001bc008: c5e00000  lwc1	$f0,0(t7)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bbfd0(void)`

```c
undefined4 FUN_001bbfd0(void)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  
  lVar1 = FUN_001bb4a0();
  uVar3 = DAT_0036dc44;
  if (lVar1 != 0) {
    iVar2 = FUN_001bbcb0();
    uVar3 = *(undefined4 *)(iVar2 + 0x530);
  }
  return uVar3;
}
```

## Earlier attempts (newest first)

- none found
