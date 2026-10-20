# Target packet 001b3a90

- Range: `001b3a90`..`001b3b0c`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b3a90`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016a070` registry: `_ZN2YS3OBJ12get_part_numEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`
- `001b3b70` registry: `_ZN2YS7PIERROTC2EPKNS_8OBJENTRYEjRKN2kn7FVectorEf`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b3a90: 27bdfff0  addiu	sp,sp,-16
001b3a94: 00c0382d  move	a3,a2
001b3a98: ffb00000  sd	s0,0(sp)
001b3a9c: 24060002  li	a2,2
001b3aa0: ffbf0008  sd	ra,8(sp)
001b3aa4: 0c06cedc  jal	0x1b3b70
001b3aa8: 0080802d  move	s0,a0
001b3aac: 8e0d0588  lw	t5,1416(s0)
001b3ab0: 3c0f0001  lui	t7,0x1
001b3ab4: 8e0c0600  lw	t4,1536(s0)
001b3ab8: 240eff87  li	t6,-121
001b3abc: 01af6825  or	t5,t5,t7
001b3ac0: 0200202d  move	a0,s0
001b3ac4: 3c0f0035  lui	t7,0x35
001b3ac8: ae0d0588  sw	t5,1416(s0)
001b3acc: 25ef1078  addiu	t7,t7,4216   ; = D_00351078
001b3ad0: 018e6024  and	t4,t4,t6
001b3ad4: ae0f0000  sw	t7,0(s0)
001b3ad8: ae0c0600  sw	t4,1536(s0)
001b3adc: 240f0001  li	t7,1
001b3ae0: 0c05a81c  jal	0x16a070
001b3ae4: ae0f03b0  sw	t7,944(s0)
001b3ae8: 240f1390  li	t7,5008
001b3aec: 544f0004  bnel	v0,t7,0x1b3b00
001b3af0: dfb00000  ld	s0,0(sp)
001b3af4: 3c0f0035  lui	t7,0x35
001b3af8: adf01068  sw	s0,4200(t7)   ; = D_00351068
001b3afc: dfb00000  ld	s0,0(sp)
001b3b00: dfbf0008  ld	ra,8(sp)
001b3b04: 03e00008  jr	ra
001b3b08: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b3a90(void)`

```c
void FUN_001b3a90(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 *puVar2;
  
  FUN_001b3b70(param_1,param_2,2,param_3);
  puVar2 = (undefined4 *)param_1;
  puVar2[0x162] = puVar2[0x162] | 0x10000;
  *puVar2 = &PTR_LAB_00351078;
  puVar2[0x180] = puVar2[0x180] & 0xffffff87;
  puVar2[0xec] = 1;
  lVar1 = FUN_0016a070(param_1);
  if (lVar1 != 0x1390) {
    puVar2 = DAT_00351068;
  }
  DAT_00351068 = puVar2;
  return;
}
```

## Earlier attempts (newest first)

- none found
