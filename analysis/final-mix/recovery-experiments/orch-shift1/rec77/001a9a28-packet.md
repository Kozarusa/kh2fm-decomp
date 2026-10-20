# Target packet 001a9a28

- Range: `001a9a28`..`001a9a68`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a9a28`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a9a28: 2c8f0006  sltiu	t7,a0,6
001a9a2c: 11e0000c  beqz	t7,0x1a9a60
001a9a30: 3c0e0037  lui	t6,0x37
001a9a34: 00047880  sll	t7,a0,0x2
001a9a38: 25ced61c  addiu	t6,t6,-10724   ; = D_0036d61c
001a9a3c: 01ee7821  addu	t7,t7,t6
001a9a40: 8ded0000  lw	t5,0(t7)
001a9a44: 01a00008  jr	t5
001a9a48: 00000000  nop
001a9a4c: 8cae0000  lw	t6,0(a1)
001a9a50: 8ccf0000  lw	t7,0(a2)
001a9a54: 01ee7823  subu	t7,t7,t6
001a9a58: 03e00008  jr	ra
001a9a5c: accf0000  sw	t7,0(a2)
001a9a60: 03e00008  jr	ra
001a9a64: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a9a28(void)`

```c
void FUN_001a9a28(ulong param_1,uint *param_2,int *param_3,int *param_4)

{
  if (param_1 < 6) {
                    /* WARNING: Switch is manually overridden */
    switch((int)param_1) {
    case 1:
      *param_3 = *param_3 - *param_2;
      return;
    case 2:
      *param_3 = *param_3 - (*param_2 >> 1);
      return;
    case 3:
      *param_3 = *param_3 - (*param_2 >> 1);
      *param_4 = *param_4 - (param_2[1] >> 1);
      return;
    case 4:
      *param_3 = *param_3 - (*param_2 >> 1);
      *param_4 = *param_4 - param_2[1];
      return;
    case 5:
      *param_4 = *param_4 - param_2[1];
      return;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
