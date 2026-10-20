# Target packet 001b6d88

- Range: `001b6d88`..`001b6dd0`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b6d88`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b6d88: 240f0003  li	t7,3
001b6d8c: 14af0009  bne	a1,t7,0x1b6db4
001b6d90: 240f0002  li	t7,2
001b6d94: 908f0000  lbu	t7,0(a0)
001b6d98: 25ee0001  addiu	t6,t7,1
001b6d9c: 31ef00ff  andi	t7,t7,0xff
001b6da0: 2def0003  sltiu	t7,t7,3
001b6da4: 55e00003  bnezl	t7,0x1b6db4
001b6da8: 240f0002  li	t7,2
001b6dac: 03e00008  jr	ra
001b6db0: a08e0000  sb	t6,0(a0)
001b6db4: 14af0004  bne	a1,t7,0x1b6dc8
001b6db8: a0850000  sb	a1,0(a0)
001b6dbc: 908f0003  lbu	t7,3(a0)
001b6dc0: 31ef00fe  andi	t7,t7,0xfe
001b6dc4: a08f0003  sb	t7,3(a0)
001b6dc8: 03e00008  jr	ra
001b6dcc: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b6d88(void)`

```c
void FUN_001b6d88(byte *param_1,long param_2)

{
  if ((param_2 == 3) && (2 < *param_1)) {
    *param_1 = *param_1 + 1;
    return;
  }
  *param_1 = (byte)param_2;
  if (param_2 == 2) {
    param_1[3] = param_1[3] & 0xfe;
  }
  return;
}
```

## Earlier attempts (newest first)

- 12 differing words, 76/72 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_04.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_04.cpp`)
