# Target packet 0027aa10

- Range: `0027aa10`..`0027aa78`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_0027aa10`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `00257770` registry: `_ZN2Tz5CmTop13GetListBufferEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`
- `0027af58` registry: `func_0027af58`
- `00287bc0` registry: `_ZN2Tz8MenuBase7GetModeEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`
- `0028da70` registry: `Tz::Select::SetSequence(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0027aa10: 27bdfff0  addiu	sp,sp,-16
0027aa14: ffbf0008  sd	ra,8(sp)
0027aa18: ffb00000  sd	s0,0(sp)
0027aa1c: 0c095ddc  jal	0x257770
0027aa20: 00000000  nop
0027aa24: 0040202d  move	a0,v0
0027aa28: 0c04e75e  jal	0x139d78
0027aa2c: 0040802d  move	s0,v0
0027aa30: 0c0a1ef0  jal	0x287bc0
0027aa34: 00000000  nop
0027aa38: 240f0010  li	t7,16
0027aa3c: 104f0009  beq	v0,t7,0x27aa64
0027aa40: 240500e7  li	a1,231
0027aa44: 0c09ebd6  jal	0x27af58
0027aa48: 00000000  nop
0027aa4c: 240e0006  li	t6,6
0027aa50: 3c0f0037  lui	t7,0x37
0027aa54: 004e1018  mult	v0,v0,t6
0027aa58: 25ef3e30  addiu	t7,t7,15920   ; = D_00373e30
0027aa5c: 004f1021  addu	v0,v0,t7
0027aa60: 84450004  lh	a1,4(v0)
0027aa64: 0200202d  move	a0,s0
0027aa68: dfbf0008  ld	ra,8(sp)
0027aa6c: dfb00000  ld	s0,0(sp)
0027aa70: 080a369c  j	0x28da70
0027aa74: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0027aa10(void)`

```c
void FUN_0027aa10(void)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined2 uVar4;
  
  uVar2 = FUN_00257770();
  FUN_00139d78(uVar2);
  lVar3 = FUN_00287bc0();
  uVar4 = 0xe7;
  if (lVar3 != 0x10) {
    iVar1 = FUN_0027af58();
    uVar4 = *(undefined2 *)((int)&PTR_DAT_00373e34 + iVar1 * 6);
  }
  FUN_0028da70(uVar2,uVar4);
  return;
}
```

## Earlier attempts (newest first)

- none found
