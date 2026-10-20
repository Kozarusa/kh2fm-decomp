# Target packet 001d3f38

- Range: `001d3f38`..`001d3f7c`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d3f38`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d3f38: 948e0028  lhu	t6,40(a0)
001d3f3c: 240f0158  li	t7,344
001d3f40: 11cf0007  beq	t6,t7,0x1d3f60
001d3f44: 29cd0159  slti	t5,t6,345
001d3f48: 11a00007  beqz	t5,0x1d3f68
001d3f4c: 240f011a  li	t7,282
001d3f50: 11cf0003  beq	t6,t7,0x1d3f60
001d3f54: 00000000  nop
001d3f58: 03e00008  jr	ra
001d3f5c: 24020001  li	v0,1
001d3f60: 03e00008  jr	ra
001d3f64: 0000102d  move	v0,zero
001d3f68: 240f01e4  li	t7,484
001d3f6c: 15cffffa  bne	t6,t7,0x1d3f58
001d3f70: 00000000  nop
001d3f74: 1000fffa  b	0x1d3f60
001d3f78: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d3f38(void)`

```c
undefined4 FUN_001d3f38(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x28);
  if (uVar1 != 0x158) {
    if (uVar1 < 0x159) {
      if (uVar1 != 0x11a) {
        return 1;
      }
    }
    else if (uVar1 != 0x1e4) {
      return 1;
    }
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 13 differing words, 56/68 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_05.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_05.cpp`)
