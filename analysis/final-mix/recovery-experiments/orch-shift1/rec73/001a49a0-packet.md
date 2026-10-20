# Target packet 001a49a0

- Range: `001a49a0`..`001a49d8`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a49a0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a49a0: 248f00e0  addiu	t7,a0,224
001a49a4: 51e50004  beql	t7,a1,0x1a49b8
001a49a8: 248f00f0  addiu	t7,a0,240
001a49ac: 78a80000  lq	t0,0(a1)
001a49b0: 7de80000  sq	t0,0(t7)
001a49b4: 248f00f0  addiu	t7,a0,240
001a49b8: 51e60004  beql	t7,a2,0x1a49cc
001a49bc: 8c8f0004  lw	t7,4(a0)
001a49c0: 78c80000  lq	t0,0(a2)
001a49c4: 7de80000  sq	t0,0(t7)
001a49c8: 8c8f0004  lw	t7,4(a0)
001a49cc: 35ef0020  ori	t7,t7,0x20
001a49d0: 03e00008  jr	ra
001a49d4: ac8f0004  sw	t7,4(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a49a0(void)`

```c
void FUN_001a49a0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((undefined4 *)(param_1 + 0xe0) != param_2) {
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *(undefined4 *)(param_1 + 0xe0) = *param_2;
    *(undefined4 *)(param_1 + 0xe4) = uVar1;
    *(undefined4 *)(param_1 + 0xe8) = uVar2;
    *(undefined4 *)(param_1 + 0xec) = uVar3;
  }
  if ((undefined4 *)(param_1 + 0xf0) == param_3) {
    uVar4 = *(uint *)(param_1 + 4);
  }
  else {
    uVar1 = param_3[1];
    uVar2 = param_3[2];
    uVar3 = param_3[3];
    *(undefined4 *)(param_1 + 0xf0) = *param_3;
    *(undefined4 *)(param_1 + 0xf4) = uVar1;
    *(undefined4 *)(param_1 + 0xf8) = uVar2;
    *(undefined4 *)(param_1 + 0xfc) = uVar3;
    uVar4 = *(uint *)(param_1 + 4);
  }
  *(uint *)(param_1 + 4) = uVar4 | 0x20;
  return;
}
```

## Earlier attempts (newest first)

- 25 differing words, 104/56 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_03.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_03.cpp`)
