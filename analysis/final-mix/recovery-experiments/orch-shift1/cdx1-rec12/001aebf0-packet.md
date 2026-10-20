# Target packet 001aebf0

- Range: `001aebf0`..`001aec40`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aebf0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aebf0: 908e0000  lbu	t6,0(a0)
001aebf4: 3c0f01c9  lui	t7,0x1c9
001aebf8: 25ef4040  addiu	t7,t7,16448   ; = D_01c94040
001aebfc: 908d0001  lbu	t5,1(a0)
001aec00: 000e7080  sll	t6,t6,0x2
001aec04: 01cf7021  addu	t6,t6,t7
001aec08: 8dce0000  lw	t6,0(t6)
001aec0c: 8dcf0000  lw	t7,0(t6)
001aec10: 01af782a  slt	t7,t5,t7
001aec14: 15e00004  bnez	t7,0x1aec28
001aec18: 240f0018  li	t7,24
001aec1c: 3c0f01c9  lui	t7,0x1c9
001aec20: 03e00008  jr	ra
001aec24: ade0408c  sw	zero,16524(t7)   ; = D_01c9408c
001aec28: 01af7818  mult	t7,t5,t7
001aec2c: 01cf7821  addu	t7,t6,t7
001aec30: 25ef0004  addiu	t7,t7,4
001aec34: 3c0e01c9  lui	t6,0x1c9
001aec38: 03e00008  jr	ra
001aec3c: adcf408c  sw	t7,16524(t6)   ; = D_01c9408c
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aebf0(void)`

```c
void FUN_001aebf0(byte *param_1)

{
  if (*(int *)(&DAT_01c94040)[*param_1] <= (int)(uint)param_1[1]) {
    DAT_01c9408c = (int *)0x0;
    return;
  }
  DAT_01c9408c = (int *)(&DAT_01c94040)[*param_1] + (uint)param_1[1] * 6 + 1;
  return;
}
```

## Earlier attempts (newest first)

- none found
