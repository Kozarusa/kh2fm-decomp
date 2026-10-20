# Target packet 001a8f10

- Range: `001a8f10`..`001a8f64`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a8f10`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a8f10: 24020001  li	v0,1
001a8f14: 240f0002  li	t7,2
001a8f18: 108f0006  beq	a0,t7,0x1a8f34
001a8f1c: 288e0003  slti	t6,a0,3
001a8f20: 11c00008  beqz	t6,0x1a8f44
001a8f24: 240f0001  li	t7,1
001a8f28: 108f0004  beq	a0,t7,0x1a8f3c
001a8f2c: 00000000  nop
001a8f30: 24020003  li	v0,3
001a8f34: 03e00008  jr	ra
001a8f38: 00000000  nop
001a8f3c: 03e00008  jr	ra
001a8f40: 0000102d  move	v0,zero
001a8f44: 240f0003  li	t7,3
001a8f48: 108ffffa  beq	a0,t7,0x1a8f34
001a8f4c: 24020002  li	v0,2
001a8f50: 240f000e  li	t7,14
001a8f54: 548ffff7  bnel	a0,t7,0x1a8f34
001a8f58: 24020003  li	v0,3
001a8f5c: 1000fff7  b	0x1a8f3c
001a8f60: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a8f10(void)`

```c
undefined4 FUN_001a8f10(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 2) {
    if (param_1 < 3) {
      if (param_1 == 1) {
        return 0;
      }
      uVar1 = 3;
    }
    else {
      uVar1 = 2;
      if (param_1 != 3) {
        if (param_1 == 0xe) {
          return 0;
        }
        uVar1 = 3;
      }
    }
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- 18 differing words, 76/84 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_03.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_03.cpp`)
