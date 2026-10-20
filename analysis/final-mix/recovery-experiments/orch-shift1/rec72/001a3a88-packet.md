# Target packet 001a3a88

- Range: `001a3a88`..`001a3b04`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a3a88`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00168b38` registry: `func_00168b38`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`
- `001708f8` registry: `_ZN2YS10CACHE_BUFF5AllocEPKci`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_orchaz_recovered_001708f8.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_storeorder_recovered_00281f90.cpp`, `fm_primary_twoword_recovered_0026ec70.cpp`
- `001dddd0` registry: `_Z16wtarget_001dddd0jjjj`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a3a88: 27bdfff0  addiu	sp,sp,-16
001a3a8c: 3c0f0035  lui	t7,0x35
001a3a90: ffbf0000  sd	ra,0(sp)
001a3a94: 2405ffff  li	a1,-1
001a3a98: 0c05c23e  jal	0x1708f8
001a3a9c: 8de40748  lw	a0,1864(t7)   ; = D_00350748
001a3aa0: 3c0f01c7  lui	t7,0x1c7
001a3aa4: 0040202d  move	a0,v0
001a3aa8: ade2cafc  sw	v0,-13572(t7)   ; = D_01c6cafc
001a3aac: 24050012  li	a1,18
001a3ab0: 0c05a2ce  jal	0x168b38
001a3ab4: 0000302d  move	a2,zero
001a3ab8: 8c450008  lw	a1,8(v0)
001a3abc: 3c0401c7  lui	a0,0x1c7
001a3ac0: 0c077774  jal	0x1dddd0
001a3ac4: 2484cae0  addiu	a0,a0,-13600   ; = D_01c6cae0
001a3ac8: 3c0f01c7  lui	t7,0x1c7
001a3acc: 240e0003  li	t6,3
001a3ad0: 25efcb00  addiu	t7,t7,-13568   ; = D_01c6cb00
001a3ad4: ade00000  sw	zero,0(t7)
001a3ad8: 25ceffff  addiu	t6,t6,-1
001a3adc: 00000000  nop
001a3ae0: 00000000  nop
001a3ae4: 00000000  nop
001a3ae8: 05c1fffa  bgez	t6,0x1a3ad4
001a3aec: 25ef0004  addiu	t7,t7,4
001a3af0: 3c0f01c7  lui	t7,0x1c7
001a3af4: dfbf0000  ld	ra,0(sp)
001a3af8: ade0cb10  sw	zero,-13552(t7)   ; = D_01c6cb10
001a3afc: 03e00008  jr	ra
001a3b00: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a3a88(void)`

```c
void FUN_001a3a88(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_001708f8(PTR_s_00effect_bar_00350748,0xffffffffffffffff);
  DAT_01c6cafc = (undefined4)uVar2;
  iVar1 = FUN_00168b38(uVar2,0x12,0);
  FUN_001dddd0(0x1c6cae0,*(undefined4 *)(iVar1 + 8));
  iVar1 = 3;
  puVar3 = &DAT_01c6cb00;
  do {
    *puVar3 = 0;
    iVar1 = iVar1 + -1;
    puVar3 = puVar3 + 1;
  } while (-1 < iVar1);
  DAT_01c6cb10 = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
