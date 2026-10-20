# Target packet 001b5af0

- Range: `001b5af0`..`001b5b20`, **48 bytes = 12 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b5af0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b5af0: 3c0f01d5  lui	t7,0x1d5
001b5af4: 8dee8cb0  lw	t6,-29520(t7)   ; = D_01d48cb0
001b5af8: 11c00005  beqz	t6,0x1b5b10
001b5afc: 00000000  nop
001b5b00: 8dcf0040  lw	t7,64(t6)
001b5b04: 31ef0004  andi	t7,t7,0x4
001b5b08: 51e00003  beqzl	t7,0x1b5b18
001b5b0c: 8dcf0000  lw	t7,0(t6)
001b5b10: 03e00008  jr	ra
001b5b14: 0000102d  move	v0,zero
001b5b18: 03e00008  jr	ra
001b5b1c: 95e20028  lhu	v0,40(t7)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b5af0(void)`

```c
undefined2 FUN_001b5af0(void)

{
  if ((DAT_01d48cb0 != (int *)0x0) && ((DAT_01d48cb0[0x10] & 4U) == 0)) {
    return *(undefined2 *)(*DAT_01d48cb0 + 0x28);
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 8 differing words, 52/48 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
