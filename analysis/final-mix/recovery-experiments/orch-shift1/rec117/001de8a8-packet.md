# Target packet 001de8a8

- Range: `001de8a8`..`001de910`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001de8a8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102788` registry: `_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001de8a8: 27bdffe0  addiu	sp,sp,-32
001de8ac: ffb20010  sd	s2,16(sp)
001de8b0: ffb00000  sd	s0,0(sp)
001de8b4: ffb10008  sd	s1,8(sp)
001de8b8: 00e0902d  move	s2,a3
001de8bc: ffbf0018  sd	ra,24(sp)
001de8c0: 3c07001e  lui	a3,0x1e
001de8c4: 0080882d  move	s1,a0
001de8c8: 00a0802d  move	s0,a1
001de8cc: 0c0409e2  jal	0x102788
001de8d0: 24e7e690  addiu	a3,a3,-6512   ; = D_001de690
001de8d4: 3c07001e  lui	a3,0x1e
001de8d8: 0220202d  move	a0,s1
001de8dc: 0200282d  move	a1,s0
001de8e0: 0240302d  move	a2,s2
001de8e4: 0c0409e2  jal	0x102788
001de8e8: 24e7e6d0  addiu	a3,a3,-6448   ; = D_001de6d0
001de8ec: 3c0f001e  lui	t7,0x1e
001de8f0: dfb00000  ld	s0,0(sp)
001de8f4: 25efe710  addiu	t7,t7,-6384   ; = D_001de710
001de8f8: dfb10008  ld	s1,8(sp)
001de8fc: ac4f0030  sw	t7,48(v0)
001de900: dfb20010  ld	s2,16(sp)
001de904: dfbf0018  ld	ra,24(sp)
001de908: 03e00008  jr	ra
001de90c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001de8a8(void)`

```c
void FUN_001de8a8(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  FUN_00102788();
  iVar1 = FUN_00102788(param_1,param_2,param_4,0x1de6d0);
  *(code **)(iVar1 + 0x30) = FUN_001de710;
  return;
}
```

## Earlier attempts (newest first)

- none found
