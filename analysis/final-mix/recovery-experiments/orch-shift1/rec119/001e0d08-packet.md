# Target packet 001e0d08

- Range: `001e0d08`..`001e0d64`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e0d08`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e0d08: 3c0c0035  lui	t4,0x35
001e0d0c: 8c8f0020  lw	t7,32(a0)
001e0d10: 8d8d2bd0  lw	t5,11216(t4)   ; = D_00352bd0
001e0d14: 000f7980  sll	t7,t7,0x6
001e0d18: c4a00000  lwc1	$f0,0(a1)
001e0d1c: 8dae0dc4  lw	t6,3524(t5)
001e0d20: c4a10004  lwc1	$f1,4(a1)
001e0d24: 01cf7021  addu	t6,t6,t7
001e0d28: c4a20008  lwc1	$f2,8(a1)
001e0d2c: e5c00030  swc1	$f0,48(t6)
001e0d30: 8d8d2bd0  lw	t5,11216(t4)   ; = D_00352bd0
001e0d34: 8c8f0020  lw	t7,32(a0)
001e0d38: 8dae0dc4  lw	t6,3524(t5)
001e0d3c: 000f7980  sll	t7,t7,0x6
001e0d40: 01cf7021  addu	t6,t6,t7
001e0d44: e5c10034  swc1	$f1,52(t6)
001e0d48: 8d8d2bd0  lw	t5,11216(t4)   ; = D_00352bd0
001e0d4c: 8c8f0020  lw	t7,32(a0)
001e0d50: 8dae0dc4  lw	t6,3524(t5)
001e0d54: 000f7980  sll	t7,t7,0x6
001e0d58: 01cf7021  addu	t6,t6,t7
001e0d5c: 03e00008  jr	ra
001e0d60: e5c20038  swc1	$f2,56(t6)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e0d08(void)`

```c
void FUN_001e0d08(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *(undefined4 *)(*(int *)(DAT_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x30) =
       *param_2;
  *(undefined4 *)(*(int *)(DAT_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x34) = uVar1;
  *(undefined4 *)(*(int *)(DAT_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x38) = uVar2;
  return;
}
```

## Earlier attempts (newest first)

- 16 differing words, 92/92 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.cpp`)
