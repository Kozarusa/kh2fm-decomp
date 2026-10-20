# Target packet 00258ce8

- Range: `00258ce8`..`00258d40`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_00258ce8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00258ce8: 1480000a  bnez	a0,0x258d14
00258cec: 3c0f0036  lui	t7,0x36
00258cf0: 3c0d0036  lui	t5,0x36
00258cf4: 240f9fcf  li	t7,-24625
00258cf8: a5aff0a8  sh	t7,-3928(t5)   ; = D_0035f0a8
00258cfc: 25acf0a8  addiu	t4,t5,-3928   ; = D_0035f0a8
00258d00: 240e9fd1  li	t6,-24623
00258d04: 240f9fd0  li	t7,-24624
00258d08: a58e0004  sh	t6,4(t4)
00258d0c: 03e00008  jr	ra
00258d10: a58f0002  sh	t7,2(t4)
00258d14: 240d0002  li	t5,2
00258d18: 25eef0a8  addiu	t6,t7,-3928
00258d1c: 948f0000  lhu	t7,0(a0)
00258d20: 25adffff  addiu	t5,t5,-1
00258d24: a5cf0000  sh	t7,0(t6)
00258d28: 24840002  addiu	a0,a0,2
00258d2c: 00000000  nop
00258d30: 05a1fffa  bgez	t5,0x258d1c
00258d34: 25ce0002  addiu	t6,t6,2
00258d38: 03e00008  jr	ra
00258d3c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00258ce8(void)`

```c
void FUN_00258ce8(undefined2 *param_1)

{
  int iVar1;
  undefined2 *puVar2;
  
  if (param_1 == (undefined2 *)0x0) {
    DAT_0035f0a8 = 0x9fcf;
    DAT_0035f0ac = 0x9fd1;
    DAT_0035f0aa = 0x9fd0;
    return;
  }
  iVar1 = 2;
  puVar2 = &DAT_0035f0a8;
  do {
    iVar1 = iVar1 + -1;
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 88/88 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.cpp`)
