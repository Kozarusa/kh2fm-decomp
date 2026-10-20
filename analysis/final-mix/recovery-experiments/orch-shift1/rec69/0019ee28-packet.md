# Target packet 0019ee28

- Range: `0019ee28`..`0019ee5c`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019ee28`
- Registry names for this address: `_Z16wtarget_0019ee28jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019ee28: 340fffff  li	t7,0xffff
0019ee2c: 14af0009  bne	a1,t7,0x19ee54
0019ee30: 240f0001  li	t7,1
0019ee34: 148f0007  bne	a0,t7,0x19ee54
0019ee38: 3c0e0035  lui	t6,0x35
0019ee3c: 44800000  mtc1	zero,$f0
0019ee40: 25cf0448  addiu	t7,t6,1096   ; = D_00350448
0019ee44: e5e00020  swc1	$f0,32(t7)
0019ee48: 3c0f0035  lui	t7,0x35
0019ee4c: adc00448  sw	zero,1096(t6)   ; = D_00350448
0019ee50: e5e00464  swc1	$f0,1124(t7)   ; = D_00350464
0019ee54: 03e00008  jr	ra
0019ee58: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019ee28(void)`

```c
void FUN_0019ee28(int param_1,long param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    DAT_00350468 = 0;
    DAT_00350448 = 0;
    DAT_00350464 = 0;
  }
  return;
}
```

## Earlier attempts (newest first)

- 10 differing words, 48/52 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
