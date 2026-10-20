# Target packet 001dc278

- Range: `001dc278`..`001dc2f4`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dc278`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dc278: 3c0f0035  lui	t7,0x35
001dc27c: ac80000c  sw	zero,12(a0)
001dc280: 25ef2b48  addiu	t7,t7,11080   ; = D_00352b48
001dc284: ac800010  sw	zero,16(a0)
001dc288: ac8f0000  sw	t7,0(a0)
001dc28c: 3c0d0035  lui	t5,0x35
001dc290: ac800014  sw	zero,20(a0)
001dc294: 25ae2ae0  addiu	t6,t5,10976   ; = D_00352ae0
001dc298: 3c0f0037  lui	t7,0x37
001dc29c: ac800018  sw	zero,24(a0)
001dc2a0: 25efe7e4  addiu	t7,t7,-6172   ; = D_0036e7e4
001dc2a4: ac80001c  sw	zero,28(a0)
001dc2a8: c5e00000  lwc1	$f0,0(t7)
001dc2ac: ac800024  sw	zero,36(a0)
001dc2b0: e4800020  swc1	$f0,32(a0)
001dc2b4: 8dcf0004  lw	t7,4(t6)
001dc2b8: 55e0000b  bnezl	t7,0x1dc2e8
001dc2bc: ade40028  sw	a0,40(t7)
001dc2c0: adc40004  sw	a0,4(t6)
001dc2c4: ada42ae0  sw	a0,10976(t5)   ; = D_00352ae0
001dc2c8: ac800028  sw	zero,40(a0)
001dc2cc: ac860004  sw	a2,4(a0)
001dc2d0: 3c0e0035  lui	t6,0x35
001dc2d4: ac850008  sw	a1,8(a0)
001dc2d8: 8dcf2ae8  lw	t7,10984(t6)   ; = D_00352ae8
001dc2dc: 25ef0001  addiu	t7,t7,1
001dc2e0: 03e00008  jr	ra
001dc2e4: adcf2ae8  sw	t7,10984(t6)   ; = D_00352ae8
001dc2e8: ac800028  sw	zero,40(a0)
001dc2ec: 1000fff7  b	0x1dc2cc
001dc2f0: adc40004  sw	a0,4(t6)   ; = D_00350004
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dc278(void)`

```c
void FUN_001dc278(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = &PTR_LAB_00352b48;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  uVar1 = DAT_0036e7e4;
  param_1[9] = 0;
  param_1[8] = uVar1;
  if (DAT_00352ae4 == (undefined4 *)0x0) {
    DAT_00352ae0 = param_1;
    DAT_00352ae4 = param_1;
    param_1[10] = 0;
  }
  else {
    *(undefined4 **)((int)DAT_00352ae4 + 0x28) = param_1;
    param_1[10] = 0;
    DAT_00352ae4 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = param_2;
  DAT_00352ae8 = DAT_00352ae8 + 1;
  return;
}
```

## Earlier attempts (newest first)

- none found
