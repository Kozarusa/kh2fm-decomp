# Target packet 0027db58

- Range: `0027db58`..`0027dbd4`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_0027db58`
- Registry names for this address: `func_0027db58`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001039f8` registry: `func_001039f8`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`
- `00167f18` registry: `Tz::MenuCursor::GetInputState(...)`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`
- `00242618` registry: `_ZN2Tz9MenuSound6PlaySEEib`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_threeword_recovered_002a01c8.cpp`, `fm_primary_threeword_recovered_002a6368.cpp`, `fm_primary_threeword_recovered_002a7f20.cpp`, `fm_primary_threeword_recovered_002a92a0.cpp`
- `00287da0` registry: `_ZN2Tz8MenuBase7SetExitEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_orchef_recovered_00263e18.cpp`, `fm_primary_threeword_recovered_0026dcb8.cpp`
- `00287db0` registry: `Tz::CmItem::isPadHelpVisible()`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`
- `00290740` registry: `Tz::Selector::HelpGraDone(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_threeword_recovered_0026dcb8.cpp`, `fm_primary_threeword_recovered_0028e710.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0027db58: 27bdfff0  addiu	sp,sp,-16
0027db5c: ffb00000  sd	s0,0(sp)
0027db60: ffbf0008  sd	ra,8(sp)
0027db64: 0c059fc6  jal	0x167f18
0027db68: 0000202d  move	a0,zero
0027db6c: 0c0a1f6c  jal	0x287db0
0027db70: 0040802d  move	s0,v0
0027db74: 1040000d  beqz	v0,0x27dbac
0027db78: 3c0f0036  lui	t7,0x36
0027db7c: 0c0a41d0  jal	0x290740
0027db80: 8de4f238  lw	a0,-3528(t7)   ; = D_0035f238
0027db84: 14400004  bnez	v0,0x27db98
0027db88: 0000782d  move	t7,zero
0027db8c: 0c040e7e  jal	0x1039f8
0027db90: 00000000  nop
0027db94: 240f0001  li	t7,1
0027db98: dfb00000  ld	s0,0(sp)
0027db9c: 01e0102d  move	v0,t7
0027dba0: dfbf0008  ld	ra,8(sp)
0027dba4: 03e00008  jr	ra
0027dba8: 27bd0010  addiu	sp,sp,16
0027dbac: de0f0008  ld	t7,8(s0)
0027dbb0: 31ef000c  andi	t7,t7,0xc
0027dbb4: 11e00005  beqz	t7,0x27dbcc
0027dbb8: 24040009  li	a0,9
0027dbbc: 0c090986  jal	0x242618
0027dbc0: 24050001  li	a1,1
0027dbc4: 0c0a1f68  jal	0x287da0
0027dbc8: 00000000  nop
0027dbcc: 1000fff2  b	0x27db98
0027dbd0: 0000782d  move	t7,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0027db58(void)`

```c
undefined4 FUN_0027db58(void)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00167f18(0);
  lVar2 = FUN_00287db0();
  if (lVar2 == 0) {
    if ((*(ulong *)(iVar1 + 8) & 0xc) != 0) {
      FUN_00242618(9,1);
      FUN_00287da0();
    }
    uVar3 = 0;
  }
  else {
    lVar2 = FUN_00290740(DAT_0035f238);
    uVar3 = 0;
    if (lVar2 == 0) {
      FUN_001039f8();
      uVar3 = 1;
    }
  }
  return uVar3;
}
```

## Earlier attempts (newest first)

- none found
