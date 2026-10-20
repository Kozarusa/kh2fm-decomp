# Target packet 0028ce98

- Range: `0028ce98`..`0028cf10`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028ce98`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00138c10` registry: `_ZN2dk6Sprite6setNumEi`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028ce98: 27bdfff0  addiu	sp,sp,-16
0028ce9c: 3c0f0036  lui	t7,0x36
0028cea0: ffbf0000  sd	ra,0(sp)
0028cea4: 00046880  sll	t5,a0,0x2
0028cea8: 8deef408  lw	t6,-3064(t7)   ; = D_0035f408
0028ceac: 01ae7021  addu	t6,t5,t6
0028ceb0: 8dcf0000  lw	t7,0(t6)
0028ceb4: 11e50014  beq	t7,a1,0x28cf08
0028ceb8: dfbf0000  ld	ra,0(sp)
0028cebc: 14a0000d  bnez	a1,0x28cef4
0028cec0: adc50000  sw	a1,0(t6)
0028cec4: 3c0e0036  lui	t6,0x36
0028cec8: 8dcff400  lw	t7,-3072(t6)   ; = D_0035f400
0028cecc: 01af7821  addu	t7,t5,t7
0028ced0: 85e50000  lh	a1,0(t7)
0028ced4: 240f0198  li	t7,408
0028ced8: dfbf0000  ld	ra,0(sp)
0028cedc: 008f7818  mult	t7,a0,t7
0028cee0: 3c0e0036  lui	t6,0x36
0028cee4: 8dc4f3fc  lw	a0,-3076(t6)   ; = D_0035f3fc
0028cee8: 008f2021  addu	a0,a0,t7
0028ceec: 0804e304  j	0x138c10
0028cef0: 27bd0010  addiu	sp,sp,16
0028cef4: 3c0e0036  lui	t6,0x36
0028cef8: 8dcff400  lw	t7,-3072(t6)   ; = D_0035f400
0028cefc: 01af7821  addu	t7,t5,t7
0028cf00: 1000fff4  b	0x28ced4
0028cf04: 85e50002  lh	a1,2(t7)
0028cf08: 03e00008  jr	ra
0028cf0c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028ce98(void)`

```c
void FUN_0028ce98(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = param_1 * 4;
  if (*(int *)(iVar2 + DAT_0035f408) != param_2) {
    *(int *)(iVar2 + DAT_0035f408) = param_2;
    if (param_2 == 0) {
      uVar1 = *(undefined2 *)(iVar2 + DAT_0035f400);
    }
    else {
      uVar1 = *(undefined2 *)(iVar2 + DAT_0035f400 + 2);
    }
    FUN_00138c10(DAT_0035f3fc + param_1 * 0x198,uVar1);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
