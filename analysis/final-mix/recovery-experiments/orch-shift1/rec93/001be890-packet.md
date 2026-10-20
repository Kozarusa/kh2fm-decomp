# Target packet 001be890

- Range: `001be890`..`001be900`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001be890`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bc778` registry: `_ZN2YS12COMMAND_MENU5clearEv`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`
- `001bc780` registry: none
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`
- `001bd570` registry: `_ZN2YS14PLAYER_COMMAND12get_overrideEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001be890: 27bdffe0  addiu	sp,sp,-32
001be894: ffb20010  sd	s2,16(sp)
001be898: ffb00000  sd	s0,0(sp)
001be89c: ffb10008  sd	s1,8(sp)
001be8a0: 0080902d  move	s2,a0
001be8a4: ffbf0018  sd	ra,24(sp)
001be8a8: 00a0202d  move	a0,a1
001be8ac: 00a0882d  move	s1,a1
001be8b0: 0c06f1de  jal	0x1bc778
001be8b4: 0000802d  move	s0,zero
001be8b8: 26050003  addiu	a1,s0,3
001be8bc: 0c06f55c  jal	0x1bd570
001be8c0: 0240202d  move	a0,s2
001be8c4: 26100001  addiu	s0,s0,1
001be8c8: 90470004  lbu	a3,4(v0)
001be8cc: 2446000c  addiu	a2,v0,12
001be8d0: 94450002  lhu	a1,2(v0)
001be8d4: 0c06f1e0  jal	0x1bc780
001be8d8: 0220202d  move	a0,s1
001be8dc: 2a0f0004  slti	t7,s0,4
001be8e0: 15e0fff6  bnez	t7,0x1be8bc
001be8e4: 26050003  addiu	a1,s0,3
001be8e8: dfb00000  ld	s0,0(sp)
001be8ec: dfb10008  ld	s1,8(sp)
001be8f0: dfb20010  ld	s2,16(sp)
001be8f4: dfbf0018  ld	ra,24(sp)
001be8f8: 03e00008  jr	ra
001be8fc: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001be890(void)`

```c
void FUN_001be890(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_001bc778(param_2);
  iVar1 = 3;
  iVar2 = 0;
  do {
    iVar1 = FUN_001bd570(param_1,iVar1);
    iVar3 = iVar2 + 1;
    FUN_001bc780(param_2,*(undefined2 *)(iVar1 + 2),iVar1 + 0xc,*(undefined1 *)(iVar1 + 4));
    iVar1 = iVar2 + 4;
    iVar2 = iVar3;
  } while (iVar3 < 4);
  return;
}
```

## Earlier attempts (newest first)

- 31 differing words, 128/112 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_06_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_06_0.cpp`)
