# Target packet 001e29e0

- Range: `001e29e0`..`001e2a50`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e29e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102788` registry: `_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`
- `00102c80` registry: `_Z12getFieldModev`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_more_recovered.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`
- `001050d8` registry: `_ZN4AREA5AllocEj`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_callbackreturn_recovered_001050d8.cpp`
- `001e27c0` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e29e0: 27bdffe0  addiu	sp,sp,-32
001e29e4: ffb10008  sd	s1,8(sp)
001e29e8: ffbf0010  sd	ra,16(sp)
001e29ec: ffb00000  sd	s0,0(sp)
001e29f0: 0c040b20  jal	0x102c80
001e29f4: 0080882d  move	s1,a0
001e29f8: 8c440004  lw	a0,4(v0)
001e29fc: 3c07001e  lui	a3,0x1e
001e2a00: 24050001  li	a1,1
001e2a04: 24e72938  addiu	a3,a3,10552   ; = D_001e2938
001e2a08: 0c0409e2  jal	0x102788
001e2a0c: 24065014  li	a2,20500
001e2a10: 3c0f001e  lui	t7,0x1e
001e2a14: 24040e10  li	a0,3600
001e2a18: 25ef2998  addiu	t7,t7,10648   ; = D_001e2998
001e2a1c: 0c041436  jal	0x1050d8
001e2a20: ac4f0030  sw	t7,48(v0)
001e2a24: 0040802d  move	s0,v0
001e2a28: 0c0789f0  jal	0x1e27c0
001e2a2c: 0040202d  move	a0,v0
001e2a30: 3c0f0035  lui	t7,0x35
001e2a34: dfbf0010  ld	ra,16(sp)
001e2a38: adf02bd0  sw	s0,11216(t7)   ; = D_00352bd0
001e2a3c: ae110dd0  sw	s1,3536(s0)
001e2a40: dfb00000  ld	s0,0(sp)
001e2a44: dfb10008  ld	s1,8(sp)
001e2a48: 03e00008  jr	ra
001e2a4c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e29e0(void)`

```c
void FUN_001e29e0(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00102c80();
  iVar1 = FUN_00102788(*(undefined4 *)(iVar1 + 4),1,0x5014,0x1e2938);
  *(code **)(iVar1 + 0x30) = FUN_001e2998;
  uVar2 = FUN_001050d8(0xe10);
  FUN_001e27c0(uVar2);
  DAT_00352bd0 = (int)uVar2;
  *(undefined4 *)((int)uVar2 + 0xdd0) = param_1;
  return;
}
```

## Earlier attempts (newest first)

- none found
