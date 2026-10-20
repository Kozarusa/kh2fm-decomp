# Target packet 001e0d68

- Range: `001e0d68`..`001e0dc4`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e0d68`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e0d68: 3c0c0035  lui	t4,0x35
001e0d6c: 8c8f0020  lw	t7,32(a0)
001e0d70: 8d8d2bd0  lw	t5,11216(t4)   ; = D_00352bd0
001e0d74: 000f7980  sll	t7,t7,0x6
001e0d78: c4a00000  lwc1	$f0,0(a1)
001e0d7c: 8dae0dc4  lw	t6,3524(t5)
001e0d80: c4a10004  lwc1	$f1,4(a1)
001e0d84: 01cf7021  addu	t6,t6,t7
001e0d88: c4a20008  lwc1	$f2,8(a1)
001e0d8c: e5c00020  swc1	$f0,32(t6)
001e0d90: 8d8d2bd0  lw	t5,11216(t4)   ; = D_00352bd0
001e0d94: 8c8f0020  lw	t7,32(a0)
001e0d98: 8dae0dc4  lw	t6,3524(t5)
001e0d9c: 000f7980  sll	t7,t7,0x6
001e0da0: 01cf7021  addu	t6,t6,t7
001e0da4: e5c10024  swc1	$f1,36(t6)
001e0da8: 8d8d2bd0  lw	t5,11216(t4)   ; = D_00352bd0
001e0dac: 8c8f0020  lw	t7,32(a0)
001e0db0: 8dae0dc4  lw	t6,3524(t5)
001e0db4: 000f7980  sll	t7,t7,0x6
001e0db8: 01cf7021  addu	t6,t6,t7
001e0dbc: 03e00008  jr	ra
001e0dc0: e5c20028  swc1	$f2,40(t6)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e0d68(void)`

```c
void FUN_001e0d68(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *(undefined4 *)(*(int *)(DAT_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x20) =
       *param_2;
  *(undefined4 *)(*(int *)(DAT_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x24) = uVar1;
  *(undefined4 *)(*(int *)(DAT_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x28) = uVar2;
  return;
}
```

## Earlier attempts (newest first)

- 16 differing words, 92/92 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.cpp`)
