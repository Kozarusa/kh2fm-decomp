# Target packet 001d53e8

- Range: `001d53e8`..`001d544c`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d53e8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00168b88` registry: `func_00168b88`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`
- `001b1490` registry: `func_001b1490`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbk_recovered_00192320.cpp`, `fm_primary_orchce_recovered_001aeb80.cpp`, `fm_scalar_recovered_04.cpp`
- `001c10b8` registry: `func_001c10b8`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d53e8: 27bdfff0  addiu	sp,sp,-16
001d53ec: 3c0f0035  lui	t7,0x35
001d53f0: ffbf0000  sd	ra,0(sp)
001d53f4: 0c06c524  jal	0x1b1490
001d53f8: 8de4276c  lw	a0,10092(t7)   ; = D_0035276c
001d53fc: 3c0f0037  lui	t7,0x37
001d5400: 0040202d  move	a0,v0
001d5404: 81e6e598  lb	a2,-6760(t7)   ; = D_0036e598
001d5408: 25eee598  addiu	t6,t7,-6760   ; = D_0036e598
001d540c: 81cc0001  lb	t4,1(t6)
001d5410: 2405ffff  li	a1,-1
001d5414: 81cd0003  lb	t5,3(t6)
001d5418: 0000382d  move	a3,zero
001d541c: 81cf0002  lb	t7,2(t6)
001d5420: 000c6200  sll	t4,t4,0x8
001d5424: 000d6e00  sll	t5,t5,0x18
001d5428: 000f7c00  sll	t7,t7,0x10
001d542c: 00cd3025  or	a2,a2,t5
001d5430: 01ec7825  or	t7,t7,t4
001d5434: 0c05a2e2  jal	0x168b88
001d5438: 00cf3025  or	a2,a2,t7
001d543c: 8c440008  lw	a0,8(v0)
001d5440: dfbf0000  ld	ra,0(sp)
001d5444: 0807042e  j	0x1c10b8
001d5448: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d53e8(void)`

```c
void FUN_001d53e8(void)

{
  undefined8 uVar1;
  int iVar2;
  
  uVar1 = FUN_001b1490(PTR_s_14mission_bar_0035276c);
  iVar2 = FUN_00168b88(uVar1,0xffffffffffffffff,
                       (long)DAT_0036e598 | (long)((int)DAT_0036e59b << 0x18) |
                       (long)((int)DAT_0036e59a << 0x10 | (int)DAT_0036e599 << 8),0);
  FUN_001c10b8(*(undefined4 *)(iVar2 + 8));
  return;
}
```

## Earlier attempts (newest first)

- none found
