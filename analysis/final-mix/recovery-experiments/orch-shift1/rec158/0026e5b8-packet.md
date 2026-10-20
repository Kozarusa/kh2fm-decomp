# Target packet 0026e5b8

- Range: `0026e5b8`..`0026e638`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0026e5b8`
- Registry names for this address: `Tz::PauseTaskIsDone(...)`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001039f8` registry: `func_001039f8`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`
- `0026e638` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_threeword_recovered_0026dcb8.cpp`, `fm_primary_threeword_recovered_0028e710.cpp`
- `0026e8a0` registry: `_ZN2Tz8Selector7ControlEP4TASK`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_threeword_recovered_0026dcb8.cpp`, `fm_primary_threeword_recovered_0028e710.cpp`
- `00287bc0` registry: `_ZN2Tz8MenuBase7GetModeEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`
- `00287db0` registry: `Tz::CmItem::isPadHelpVisible()`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0026e5b8: 27bdffe0  addiu	sp,sp,-32
0026e5bc: ffb10008  sd	s1,8(sp)
0026e5c0: ffb00000  sd	s0,0(sp)
0026e5c4: ffbf0010  sd	ra,16(sp)
0026e5c8: 0c0a1ef0  jal	0x287bc0
0026e5cc: 0080882d  move	s1,a0
0026e5d0: 0c0a1f6c  jal	0x287db0
0026e5d4: 0040802d  move	s0,v0
0026e5d8: 10400009  beqz	v0,0x26e600
0026e5dc: 00000000  nop
0026e5e0: 0c040e7e  jal	0x1039f8
0026e5e4: 00000000  nop
0026e5e8: 24020001  li	v0,1
0026e5ec: dfb00000  ld	s0,0(sp)
0026e5f0: dfb10008  ld	s1,8(sp)
0026e5f4: dfbf0010  ld	ra,16(sp)
0026e5f8: 03e00008  jr	ra
0026e5fc: 27bd0020  addiu	sp,sp,32
0026e600: 12000009  beqz	s0,0x26e628
0026e604: 240f0001  li	t7,1
0026e608: 120f0003  beq	s0,t7,0x26e618
0026e60c: 00000000  nop
0026e610: 1000fff6  b	0x26e5ec
0026e614: 0000102d  move	v0,zero
0026e618: 0c09ba28  jal	0x26e8a0
0026e61c: 00000000  nop
0026e620: 1000fff2  b	0x26e5ec
0026e624: 0000102d  move	v0,zero
0026e628: 0c09b98e  jal	0x26e638
0026e62c: 0220202d  move	a0,s1
0026e630: 1000ffee  b	0x26e5ec
0026e634: 0000102d  move	v0,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0026e5b8(void)`

```c
undefined4 FUN_0026e5b8(undefined8 param_1)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = FUN_00287bc0();
  lVar3 = FUN_00287db0();
  if (lVar3 == 0) {
    if (lVar2 == 0) {
      FUN_0026e638(param_1);
      uVar1 = 0;
    }
    else if (lVar2 == 1) {
      FUN_0026e8a0();
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    FUN_001039f8();
    uVar1 = 1;
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- 21 differing words, 128/128 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_10_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_10_1.cpp`)
