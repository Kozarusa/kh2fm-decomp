# Target packet 002b9b78

- Range: `002b9b78`..`002b9bd0`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b9b78`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002bc9a8` registry: `func_002bc9a8`
  - accepted sources that already call it (copy their declaration): `fm_primary_sixwordnext_recovered_002ba140.cpp`, `fm_primary_sixwordnext_recovered_002ba1b8.cpp`, `fm_primary_threewordnext_recovered_002bcbf0.cpp`, `fm_scalar_extra_recovered_08.cpp`, `fm_scalar_recovered_08.cpp`
- `002bce10` registry: `func_002bce10`
  - accepted sources that already call it (copy their declaration): `fm_primary_sixwordnext_recovered_002ba140.cpp`, `fm_primary_sixwordnext_recovered_002ba1b8.cpp`, `fm_primary_threewordnext_recovered_002bcbf0.cpp`, `fm_scalar_extra_recovered_08.cpp`, `fm_scalar_recovered_08.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b9b78: 27bdfff0  addiu	sp,sp,-16
002b9b7c: 0000302d  move	a2,zero
002b9b80: ffb00000  sd	s0,0(sp)
002b9b84: 24050002  li	a1,2
002b9b88: ffbf0008  sd	ra,8(sp)
002b9b8c: 3c1001e3  lui	s0,0x1e3
002b9b90: 2610a410  addiu	s0,s0,-23536   ; = D_01e2a410
002b9b94: 0c0af26a  jal	0x2bc9a8
002b9b98: 0200202d  move	a0,s0
002b9b9c: 0200202d  move	a0,s0
002b9ba0: 0c0af384  jal	0x2bce10
002b9ba4: 24050002  li	a1,2
002b9ba8: 0200202d  move	a0,s0
002b9bac: 24050003  li	a1,3
002b9bb0: 0c0af26a  jal	0x2bc9a8
002b9bb4: 240603e7  li	a2,999
002b9bb8: 0200202d  move	a0,s0
002b9bbc: dfbf0008  ld	ra,8(sp)
002b9bc0: dfb00000  ld	s0,0(sp)
002b9bc4: 24050003  li	a1,3
002b9bc8: 080af384  j	0x2bce10
002b9bcc: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b9b78(void)`

```c
void FUN_002b9b78(void)

{
  FUN_002bc9a8(0x1e2a410,2,0);
  FUN_002bce10(0x1e2a410,2);
  FUN_002bc9a8(0x1e2a410,3,999);
  FUN_002bce10(0x1e2a410,3);
  return;
}
```

## Earlier attempts (newest first)

- 17 differing words, 88/88 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_12_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_12_0.cpp`)
