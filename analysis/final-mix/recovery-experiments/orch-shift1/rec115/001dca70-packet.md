# Target packet 001dca70

- Range: `001dca70`..`001dcae0`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dca70`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e7070` registry: `func_001e7070`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`
- `001e7088` registry: `func_001e7088`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dca70: 27bdfff0  addiu	sp,sp,-16
001dca74: 3c0e0004  lui	t6,0x4
001dca78: ffb00000  sd	s0,0(sp)
001dca7c: ffbf0008  sd	ra,8(sp)
001dca80: 0080802d  move	s0,a0
001dca84: 8c8f0008  lw	t7,8(a0)
001dca88: 01ee7824  and	t7,t7,t6
001dca8c: 11e00012  beqz	t7,0x1dcad8
001dca90: 0000202d  move	a0,zero
001dca94: 8e040030  lw	a0,48(s0)
001dca98: 8e050034  lw	a1,52(s0)
001dca9c: 0c079c1c  jal	0x1e7070
001dcaa0: 00000000  nop
001dcaa4: 8e0f0008  lw	t7,8(s0)
001dcaa8: 3c0e0008  lui	t6,0x8
001dcaac: 01ee7824  and	t7,t7,t6
001dcab0: 11e00007  beqz	t7,0x1dcad0
001dcab4: 0000202d  move	a0,zero
001dcab8: 8e050034  lw	a1,52(s0)
001dcabc: 8e040030  lw	a0,48(s0)
001dcac0: dfb00000  ld	s0,0(sp)
001dcac4: dfbf0008  ld	ra,8(sp)
001dcac8: 08079c22  j	0x1e7088
001dcacc: 27bd0010  addiu	sp,sp,16
001dcad0: 1000fffb  b	0x1dcac0
001dcad4: 0000282d  move	a1,zero
001dcad8: 1000fff0  b	0x1dca9c
001dcadc: 0000282d  move	a1,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dca70(void)`

```c
void FUN_001dca70(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0;
  if ((*(uint *)(param_1 + 8) & 0x40000) == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x30);
    uVar2 = *(undefined4 *)(param_1 + 0x34);
  }
  FUN_001e7070(uVar1,uVar2);
  uVar1 = 0;
  if ((*(uint *)(param_1 + 8) & 0x80000) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x34);
    uVar1 = *(undefined4 *)(param_1 + 0x30);
  }
  FUN_001e7088(uVar1,uVar2);
  return;
}
```

## Earlier attempts (newest first)

- 26 differing words, 112/112 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_1.cpp`)
