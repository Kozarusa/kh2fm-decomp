# Target packet 0028c0a0

- Range: `0028c0a0`..`0028c11c`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028c0a0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00138d60` registry: `_ZN2dk13SpriteMessage6createEiPvPN2YI5IMAGEEiPKN2YS7MESSAGEEii`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`
- `00192048` registry: `_Z16u_tail4_00192048jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028c0a0: 27bdffe0  addiu	sp,sp,-32
0028c0a4: 00a0702d  move	t6,a1
0028c0a8: ffb00000  sd	s0,0(sp)
0028c0ac: 3c0f0036  lui	t7,0x36
0028c0b0: ffb10008  sd	s1,8(sp)
0028c0b4: 0120502d  move	t2,t1
0028c0b8: ffbf0010  sd	ra,16(sp)
0028c0bc: 0100802d  move	s0,t0
0028c0c0: 0080882d  move	s1,a0
0028c0c4: 01c0402d  move	t0,t6
0028c0c8: 8de5f3d4  lw	a1,-3116(t7)   ; = D_0035f3d4
0028c0cc: 0c04e358  jal	0x138d60
0028c0d0: 0000482d  move	t1,zero
0028c0d4: 8e2f000c  lw	t7,12(s1)
0028c0d8: 0200202d  move	a0,s0
0028c0dc: 35ef0008  ori	t7,t7,0x8
0028c0e0: 06000004  bltz	s0,0x28c0f4
0028c0e4: ae2f000c  sw	t7,12(s1)
0028c0e8: 0c064812  jal	0x192048
0028c0ec: 00000000  nop
0028c0f0: ae220198  sw	v0,408(s1)
0028c0f4: 3c0e80e5  lui	t6,0x80e5
0028c0f8: dfb00000  ld	s0,0(sp)
0028c0fc: 240f0001  li	t7,1
0028c100: dfbf0010  ld	ra,16(sp)
0028c104: 35cee5e5  ori	t6,t6,0xe5e5
0028c108: ae2f01ac  sw	t7,428(s1)
0028c10c: ae2e01a4  sw	t6,420(s1)
0028c110: dfb10008  ld	s1,8(sp)
0028c114: 03e00008  jr	ra
0028c118: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028c0a0(void)`

```c
void FUN_0028c0a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 long param_5,undefined8 param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00138d60(param_1,DAT_0035f3d4,param_3,param_4,param_2,0,param_6);
  iVar2 = (int)param_1;
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 8;
  if (-1 < param_5) {
    uVar1 = FUN_00192048(param_5);
    *(undefined4 *)(iVar2 + 0x198) = uVar1;
  }
  *(undefined4 *)(iVar2 + 0x1ac) = 1;
  *(undefined4 *)(iVar2 + 0x1a4) = 0x80e5e5e5;
  return;
}
```

## Earlier attempts (newest first)

- none found
