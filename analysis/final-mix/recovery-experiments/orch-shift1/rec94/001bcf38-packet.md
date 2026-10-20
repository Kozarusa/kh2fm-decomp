# Target packet 001bcf38

- Range: `001bcf38`..`001bcf80`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bcf38`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bcf38: 8c840000  lw	a0,0(a0)
001bcf3c: 240f000a  li	t7,10
001bcf40: 108f0007  beq	a0,t7,0x1bcf60
001bcf44: 288e000b  slti	t6,a0,11
001bcf48: 11c00007  beqz	t6,0x1bcf68
001bcf4c: 240f0005  li	t7,5
001bcf50: 108f0003  beq	a0,t7,0x1bcf60
001bcf54: 00000000  nop
001bcf58: 03e00008  jr	ra
001bcf5c: 0000102d  move	v0,zero
001bcf60: 03e00008  jr	ra
001bcf64: 24020001  li	v0,1
001bcf68: 248ffff3  addiu	t7,a0,-13
001bcf6c: 2def0006  sltiu	t7,t7,6
001bcf70: 11e0fff9  beqz	t7,0x1bcf58
001bcf74: 00000000  nop
001bcf78: 1000fff9  b	0x1bcf60
001bcf7c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bcf38(void)`

```c
undefined4 FUN_001bcf38(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 10) {
    if (iVar1 < 0xb) {
      if (iVar1 != 5) {
        return 0;
      }
    }
    else if (5 < iVar1 - 0xdU) {
      return 0;
    }
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 14 differing words, 68/72 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_04.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_04.cpp`)
