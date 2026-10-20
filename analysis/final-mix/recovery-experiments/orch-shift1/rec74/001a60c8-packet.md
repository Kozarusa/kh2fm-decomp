# Target packet 001a60c8

- Range: `001a60c8`..`001a6118`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a60c8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001a6658` registry: none
- `001bdff0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a60c8: 27bdffe0  addiu	sp,sp,-32
001a60cc: 3c0f0035  lui	t7,0x35
001a60d0: ffb00000  sd	s0,0(sp)
001a60d4: 25ef0800  addiu	t7,t7,2048   ; = D_00350800
001a60d8: ffb10008  sd	s1,8(sp)
001a60dc: ffbf0010  sd	ra,16(sp)
001a60e0: 0000802d  move	s0,zero
001a60e4: 25f10028  addiu	s1,t7,40
001a60e8: 0c069996  jal	0x1a6658
001a60ec: 0200202d  move	a0,s0
001a60f0: 26100001  addiu	s0,s0,1
001a60f4: ae220000  sw	v0,0(s1)
001a60f8: 2a0f0006  slti	t7,s0,6
001a60fc: 15e0fffa  bnez	t7,0x1a60e8
001a6100: 2631002c  addiu	s1,s1,44
001a6104: dfb00000  ld	s0,0(sp)
001a6108: dfb10008  ld	s1,8(sp)
001a610c: dfbf0010  ld	ra,16(sp)
001a6110: 0806f7fc  j	0x1bdff0
001a6114: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a60c8(void)`

```c
void FUN_001a60c8(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  puVar3 = &DAT_00350828;
  do {
    uVar1 = FUN_001a6658(iVar2);
    iVar2 = iVar2 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 0xb;
  } while (iVar2 < 6);
  FUN_001bdff0();
  return;
}
```

## Earlier attempts (newest first)

- none found
