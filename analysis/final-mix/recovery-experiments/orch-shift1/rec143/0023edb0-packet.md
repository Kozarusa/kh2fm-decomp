# Target packet 0023edb0

- Range: `0023edb0`..`0023ede4`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_0023edb0`
- Registry names for this address: `func_0023edb0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0023edb0: 3c0d0036  lui	t5,0x36
0023edb4: 8daeeb88  lw	t6,-5240(t5)   ; = D_0035eb88
0023edb8: 51c40006  beql	t6,a0,0x23edd4
0023edbc: 3c0e0036  lui	t6,0x36
0023edc0: 11c00002  beqz	t6,0x23edcc
0023edc4: 3c0f0036  lui	t7,0x36
0023edc8: adeeeb8c  sw	t6,-5236(t7)   ; = D_0035eb8c
0023edcc: 03e00008  jr	ra
0023edd0: ada4eb88  sw	a0,-5240(t5)   ; = D_0035eb88
0023edd4: 91cfeb84  lbu	t7,-5244(t6)   ; = D_0035eb84
0023edd8: 25ef0001  addiu	t7,t7,1
0023eddc: 03e00008  jr	ra
0023ede0: a1cfeb84  sb	t7,-5244(t6)   ; = D_0035eb84
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0023edb0(void)`

```c
void FUN_0023edb0(int param_1)

{
  if (DAT_0035eb88 == param_1) {
    DAT_0035eb84 = DAT_0035eb84 + '\x01';
    return;
  }
  if (DAT_0035eb88 != 0) {
    DAT_0035eb8c = DAT_0035eb88;
  }
  DAT_0035eb88 = param_1;
  return;
}
```

## Earlier attempts (newest first)

- 11 differing words, 56/52 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.cpp`)
