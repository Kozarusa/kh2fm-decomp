# Target packet 002b16d8

- Range: `002b16d8`..`002b1704`, **44 bytes = 11 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b16d8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b16d8: 3c0f0036  lui	t7,0x36
002b16dc: 0000102d  move	v0,zero
002b16e0: 8deef634  lw	t6,-2508(t7)   ; = D_0035f634
002b16e4: 8dcd5afc  lw	t5,23292(t6)
002b16e8: 240f007e  li	t7,126
002b16ec: 8dcc55fc  lw	t4,22012(t6)
002b16f0: 158f0002  bne	t4,t7,0x2b16fc
002b16f4: 39ad0081  xori	t5,t5,0x81
002b16f8: 2da20001  sltiu	v0,t5,1
002b16fc: 03e00008  jr	ra
002b1700: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b16d8(void)`

```c
bool FUN_002b16d8(void)

{
  return *(int *)(DAT_0035f634 + 0x55fc) == 0x7e && *(int *)(DAT_0035f634 + 0x5afc) == 0x81;
}
```

## Earlier attempts (newest first)

- 8 differing words, 44/44 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.cpp`)
