# Target packet 0019bad8

- Range: `0019bad8`..`0019bb18`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019bad8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c0cd8` registry: `_ZN2YS3OBJ9is_attachEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019bad8: 27bdfff0  addiu	sp,sp,-16
0019badc: ffbf0000  sd	ra,0(sp)
0019bae0: 8c8f07f8  lw	t7,2040(a0)
0019bae4: 31ef0001  andi	t7,t7,0x1
0019bae8: 11e00008  beqz	t7,0x19bb0c
0019baec: 0000102d  move	v0,zero
0019baf0: 8c8f0108  lw	t7,264(a0)
0019baf4: 31ef0001  andi	t7,t7,0x1
0019baf8: 15e00005  bnez	t7,0x19bb10
0019bafc: dfbf0000  ld	ra,0(sp)
0019bb00: 0c070336  jal	0x1c0cd8
0019bb04: 00000000  nop
0019bb08: 2c420001  sltiu	v0,v0,1
0019bb0c: dfbf0000  ld	ra,0(sp)
0019bb10: 03e00008  jr	ra
0019bb14: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019bad8(void)`

```c
bool FUN_0019bad8(int param_1)

{
  bool bVar1;
  long lVar2;
  
  bVar1 = false;
  if (((*(uint *)(param_1 + 0x7f8) & 1) != 0) && ((*(uint *)(param_1 + 0x108) & 1) == 0)) {
    lVar2 = FUN_001c0cd8();
    bVar1 = lVar2 == 0;
  }
  return bVar1;
}
```

## Earlier attempts (newest first)

- 13 differing words, 68/64 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_04_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_04_0.cpp`)
