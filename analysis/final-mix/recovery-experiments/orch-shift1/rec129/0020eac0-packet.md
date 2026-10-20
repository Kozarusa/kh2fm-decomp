# Target packet 0020eac0

- Range: `0020eac0`..`0020eaf0`, **48 bytes = 12 instructions**. This size is the acceptance size.
- Layout name: `FUN_0020eac0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0020eac0: 3c0d7000  lui	t5,0x7000
0020eac4: 3c0f0036  lui	t7,0x36
0020eac8: 3c0e0036  lui	t6,0x36
0020eacc: 35ad4000  ori	t5,t5,0x4000
0020ead0: 3c0c7000  lui	t4,0x7000
0020ead4: adcd9810  sw	t5,-26608(t6)   ; = D_00359810
0020ead8: adec9788  sw	t4,-26744(t7)   ; = D_00359788
0020eadc: 3c0e0036  lui	t6,0x36
0020eae0: 3c0f0036  lui	t7,0x36
0020eae4: adc09808  sw	zero,-26616(t6)   ; = D_00359808
0020eae8: 03e00008  jr	ra
0020eaec: ade09780  sw	zero,-26752(t7)   ; = D_00359780
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0020eac0(void)`

```c
void FUN_0020eac0(void)

{
  DAT_00359810 = 0x70004000;
  DAT_00359788 = 0x70000000;
  DAT_00359808 = 0;
  DAT_00359780 = 0;
  return;
}
```

## Earlier attempts (newest first)

- 10 differing words, 48/48 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.cpp`)
