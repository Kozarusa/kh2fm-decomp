# Target packet 0018bbf8

- Range: `0018bbf8`..`0018bc5c`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_0018bbf8`
- Registry names for this address: `_Z16ctarget_0018bbf8jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016c028` registry: `func_0016c028`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`
- `0018c480` registry: `func_0018c480`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_fourword_recovered_00174e10.cpp`, `fm_primary_oneword_recovered_0017dfc8.cpp`
- `0018c490` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_fourword_recovered_00174e10.cpp`, `fm_primary_oneword_recovered_0017dfc8.cpp`, `fm_primary_sixword_recovered_00174168.cpp`, `fm_primary_threeword_recovered_00177460.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0018bbf8: 27bdffe0  addiu	sp,sp,-32
0018bbfc: ffb00000  sd	s0,0(sp)
0018bc00: ffb10008  sd	s1,8(sp)
0018bc04: ffbf0010  sd	ra,16(sp)
0018bc08: 24900a40  addiu	s0,a0,2624
0018bc0c: 920f0030  lbu	t7,48(s0)
0018bc10: 15e0000d  bnez	t7,0x18bc48
0018bc14: 0000102d  move	v0,zero
0018bc18: 0c05b00a  jal	0x16c028
0018bc1c: 00000000  nop
0018bc20: 0040282d  move	a1,v0
0018bc24: 0c063124  jal	0x18c490
0018bc28: 0200202d  move	a0,s0
0018bc2c: 0040882d  move	s1,v0
0018bc30: 0200202d  move	a0,s0
0018bc34: 10400003  beqz	v0,0x18bc44
0018bc38: 24050001  li	a1,1
0018bc3c: 0c063120  jal	0x18c480
0018bc40: 00000000  nop
0018bc44: 0220102d  move	v0,s1
0018bc48: dfb00000  ld	s0,0(sp)
0018bc4c: dfb10008  ld	s1,8(sp)
0018bc50: dfbf0010  ld	ra,16(sp)
0018bc54: 03e00008  jr	ra
0018bc58: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0018bbf8(void)`

```c
long FUN_0018bbf8(int param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = 0;
  if (*(char *)(param_1 + 0xa70) == '\0') {
    uVar2 = FUN_0016c028();
    lVar1 = FUN_0018c490(param_1 + 0xa40,uVar2);
    if (lVar1 != 0) {
      FUN_0018c480(param_1 + 0xa40,1);
    }
  }
  return lVar1;
}
```

## Earlier attempts (newest first)

- 10 differing words, 100/100 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_03_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_03_0.cpp`)
