# Target packet 001d9c68

- Range: `001d9c68`..`001d9c9c`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d9c68`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d9c68: 0000682d  move	t5,zero
001d9c6c: 240c0001  li	t4,1
001d9c70: 008d7021  addu	t6,a0,t5
001d9c74: 0000102d  move	v0,zero
001d9c78: 91cf0000  lbu	t7,0(t6)
001d9c7c: 25ad0001  addiu	t5,t5,1
001d9c80: 15ec0004  bne	t7,t4,0x1d9c94
001d9c84: 29ae0005  slti	t6,t5,5
001d9c88: 15c0fffb  bnez	t6,0x1d9c78
001d9c8c: 008d7021  addu	t6,a0,t5
001d9c90: 24020001  li	v0,1
001d9c94: 03e00008  jr	ra
001d9c98: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d9c68(void)`

```c
undefined4 FUN_001d9c68(char *param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = param_1;
  do {
    iVar1 = iVar1 + 1;
    if (*pcVar2 != '\x01') {
      return 0;
    }
    pcVar2 = param_1 + iVar1;
  } while (iVar1 < 5);
  return 1;
}
```

## Earlier attempts (newest first)

- 13 differing words, 56/52 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_05.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_05.cpp`)
