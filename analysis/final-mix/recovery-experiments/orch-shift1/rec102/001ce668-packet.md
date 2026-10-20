# Target packet 001ce668

- Range: `001ce668`..`001ce6c8`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ce668`
- Registry names for this address: `_Z16wtarget_001ce668jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ce668: 340fffff  li	t7,0xffff
001ce66c: 14af0014  bne	a1,t7,0x1ce6c0
001ce670: 240f0001  li	t7,1
001ce674: 148f0007  bne	a0,t7,0x1ce694
001ce678: 340fffff  li	t7,0xffff
001ce67c: 3c0f01d6  lui	t7,0x1d6
001ce680: 25eeb9e0  addiu	t6,t7,-17952   ; = D_01d5b9e0
001ce684: ade0b9e0  sw	zero,-17952(t7)   ; = D_01d5b9e0
001ce688: adc00008  sw	zero,8(t6)
001ce68c: adc00004  sw	zero,4(t6)
001ce690: 340fffff  li	t7,0xffff
001ce694: 14af000a  bne	a1,t7,0x1ce6c0
001ce698: 240f0001  li	t7,1
001ce69c: 148f0008  bne	a0,t7,0x1ce6c0
001ce6a0: 3c0d0037  lui	t5,0x37
001ce6a4: 3c0f01d6  lui	t7,0x1d6
001ce6a8: 25ade2ec  addiu	t5,t5,-7444   ; = D_0036e2ec
001ce6ac: ade0b9f0  sw	zero,-17936(t7)   ; = D_01d5b9f0
001ce6b0: c5a00000  lwc1	$f0,0(t5)
001ce6b4: 25eeb9f0  addiu	t6,t7,-17936   ; = D_01d5b9f0
001ce6b8: adc00004  sw	zero,4(t6)
001ce6bc: e5c00008  swc1	$f0,8(t6)
001ce6c0: 03e00008  jr	ra
001ce6c4: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ce668(void)`

```c
void FUN_001ce668(int param_1,long param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    DAT_01d5b9e0 = 0;
    DAT_01d5b9e8 = 0;
    DAT_01d5b9e4 = 0;
    DAT_01d5b9f0 = 0;
    DAT_01d5b9f4 = 0;
    DAT_01d5b9f8 = DAT_0036e2ec;
  }
  return;
}
```

## Earlier attempts (newest first)

- 21 differing words, 80/96 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
