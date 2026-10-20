# Target packet 001a74f8

- Range: `001a74f8`..`001a752c`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a74f8`
- Registry names for this address: `func_001a74f8`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0019c218` registry: `func_0019c218`
- `001b8e88` registry: `_Z16u_call4_001b8e88jjjj`
  - accepted sources that already call it (copy their declaration): `fm_fallback_small.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a74f8: 27bdfff0  addiu	sp,sp,-16
001a74fc: ffbf0000  sd	ra,0(sp)
001a7500: 0c06e3a2  jal	0x1b8e88
001a7504: 00000000  nop
001a7508: 3c0e01c7  lui	t6,0x1c7
001a750c: 0040282d  move	a1,v0
001a7510: 8dcfcb78  lw	t7,-13448(t6)   ; = D_01c6cb78
001a7514: ade009b0  sw	zero,2480(t7)
001a7518: 0c067086  jal	0x19c218
001a751c: 8dc4cb78  lw	a0,-13448(t6)   ; = D_01c6cb78
001a7520: dfbf0000  ld	ra,0(sp)
001a7524: 03e00008  jr	ra
001a7528: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a74f8(void)`

```c
void FUN_001a74f8(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_001b8e88();
  *(undefined4 *)(DAT_01c6cb78 + 0x9b0) = 0;
  FUN_0019c218(DAT_01c6cb78,uVar1);
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 48/52 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round13_001a74f8_v02.verification.json`
- 9 differing words, 44/52 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round13_001a74f8_v01.verification.json`
