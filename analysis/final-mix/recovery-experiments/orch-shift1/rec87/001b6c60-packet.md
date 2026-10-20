# Target packet 001b6c60

- Range: `001b6c60`..`001b6ca8`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b6c60`
- Registry names for this address: `func_001b6c60`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001050d8` registry: `_ZN4AREA5AllocEj`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_callbackreturn_recovered_001050d8.cpp`
- `001b0330` registry: `_Z16u_call4_001b0330jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_queuealphaprime_recovered_001b01d8.cpp`, `fm_scalar_recovered_04.cpp`
- `001b6298` registry: `_Z16u_tail4_001b6298jjjj`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b6c60: 27bdfff0  addiu	sp,sp,-16
001b6c64: ffb00000  sd	s0,0(sp)
001b6c68: ffbf0008  sd	ra,8(sp)
001b6c6c: 0080802d  move	s0,a0
001b6c70: 0c06c0cc  jal	0x1b0330
001b6c74: 8c8409b8  lw	a0,2488(a0)
001b6c78: 3c0f0033  lui	t7,0x33
001b6c7c: 24040020  li	a0,32
001b6c80: 0c041436  jal	0x1050d8
001b6c84: a1e0f054  sb	zero,-4012(t7)   ; = D_0032f054
001b6c88: 0200282d  move	a1,s0
001b6c8c: dfbf0008  ld	ra,8(sp)
001b6c90: dfb00000  ld	s0,0(sp)
001b6c94: 0040202d  move	a0,v0
001b6c98: 0000302d  move	a2,zero
001b6c9c: 0000382d  move	a3,zero
001b6ca0: 0806d8a6  j	0x1b6298
001b6ca4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b6c60(void)`

```c
void FUN_001b6c60(undefined8 param_1)

{
  undefined8 uVar1;
  
  FUN_001b0330(*(undefined4 *)((int)param_1 + 0x9b8));
  DAT_0032f050._4_1_ = 0;
  uVar1 = FUN_001050d8(0x20);
  FUN_001b6298(uVar1,param_1,0,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
