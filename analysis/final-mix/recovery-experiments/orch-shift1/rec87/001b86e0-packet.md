# Target packet 001b86e0

- Range: `001b86e0`..`001b8718`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b86e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b86e0: 3c0c01d5  lui	t4,0x1d5
001b86e4: 3c0dcccc  lui	t5,0xcccc
001b86e8: 258c8cc8  addiu	t4,t4,-29496   ; = D_01d48cc8
001b86ec: 35adcccd  ori	t5,t5,0xcccd
001b86f0: 008c2023  subu	a0,a0,t4
001b86f4: 8d8f00c0  lw	t7,192(t4)
001b86f8: 00042083  sra	a0,a0,0x2
001b86fc: 008d2018  mult	a0,a0,t5
001b8700: 000f7080  sll	t6,t7,0x2
001b8704: 25ef0001  addiu	t7,t7,1
001b8708: 01cc7021  addu	t6,t6,t4
001b870c: ad8f00c0  sw	t7,192(t4)
001b8710: 03e00008  jr	ra
001b8714: adc400a0  sw	a0,160(t6)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b86e0(void)`

```c
void FUN_001b86e0(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_01d48d68 + DAT_01d48d88;
  DAT_01d48d88 = DAT_01d48d88 + 1;
  *piVar1 = (param_1 + -0x1d48cc8 >> 2) * -0x33333333;
  return;
}
```

## Earlier attempts (newest first)

- none found
