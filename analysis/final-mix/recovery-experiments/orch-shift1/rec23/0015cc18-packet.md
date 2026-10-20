# Target packet 0015cc18

- Range: `0015cc18`..`0015cc4c`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015cc18`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015cc18: 3c0f004f  lui	t7,0x4f
0015cc1c: 00042080  sll	a0,a0,0x2
0015cc20: 25ef3704  addiu	t7,t7,14084   ; = D_004f3704
0015cc24: 30a500ff  andi	a1,a1,0xff
0015cc28: 008f2021  addu	a0,a0,t7
0015cc2c: 30c600ff  andi	a2,a2,0xff
0015cc30: 30e700ff  andi	a3,a3,0xff
0015cc34: a0850000  sb	a1,0(a0)
0015cc38: 310800ff  andi	t0,t0,0xff
0015cc3c: a0860001  sb	a2,1(a0)
0015cc40: a0880003  sb	t0,3(a0)
0015cc44: 03e00008  jr	ra
0015cc48: a0870002  sb	a3,2(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015cc18(void)`

```c
void FUN_0015cc18(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5)

{
  param_1 = param_1 * 4;
  *(undefined1 *)((int)&DAT_004f3700 + param_1 + 4) = param_2;
  *(undefined1 *)((int)&DAT_004f3700 + param_1 + 5) = param_3;
  *(undefined1 *)((int)&DAT_004f3700 + param_1 + 7) = param_5;
  *(undefined1 *)((int)&DAT_004f3700 + param_1 + 6) = param_4;
  return;
}
```

## Earlier attempts (newest first)

- none found
