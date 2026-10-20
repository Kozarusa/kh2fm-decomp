# Target packet 002aa8e0

- Range: `002aa8e0`..`002aa960`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_002aa8e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002a9d68` registry: `_ZN2Tz9JmNewInfo7GetSramEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_threeword_recovered_002a01c8.cpp`, `fm_primary_threeword_recovered_002a6368.cpp`, `fm_primary_threeword_recovered_002a7f20.cpp`, `fm_primary_threeword_recovered_002a92a0.cpp`
- `002aa5b8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_threeword_recovered_002a01c8.cpp`, `fm_primary_threeword_recovered_002a6368.cpp`, `fm_primary_threeword_recovered_002a7f20.cpp`, `fm_primary_threeword_recovered_002a92a0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002aa8e0: 27bdffe0  addiu	sp,sp,-32
002aa8e4: ffb10008  sd	s1,8(sp)
002aa8e8: ffb20010  sd	s2,16(sp)
002aa8ec: ffb00000  sd	s0,0(sp)
002aa8f0: 0080882d  move	s1,a0
002aa8f4: ffbf0018  sd	ra,24(sp)
002aa8f8: 0c0aa75a  jal	0x2a9d68
002aa8fc: 00a0902d  move	s2,a1
002aa900: 0040802d  move	s0,v0
002aa904: 0220202d  move	a0,s1
002aa908: 0240282d  move	a1,s2
002aa90c: 0c0aa96e  jal	0x2aa5b8
002aa910: 00118880  sll	s1,s1,0x2
002aa914: 02118021  addu	s0,s0,s1
002aa918: 00027942  srl	t7,v0,0x5
002aa91c: 26100044  addiu	s0,s0,68
002aa920: 000f7880  sll	t7,t7,0x2
002aa924: 3042001f  andi	v0,v0,0x1f
002aa928: 01f06021  addu	t4,t7,s0
002aa92c: 8d8e0000  lw	t6,0(t4)
002aa930: 240f0001  li	t7,1
002aa934: 004f7804  sllv	t7,t7,v0
002aa938: 01cf6825  or	t5,t6,t7
002aa93c: 01cf7024  and	t6,t6,t7
002aa940: 51c00001  beqzl	t6,0x2aa948
002aa944: ad8d0000  sw	t5,0(t4)
002aa948: dfb00000  ld	s0,0(sp)
002aa94c: dfb10008  ld	s1,8(sp)
002aa950: dfb20010  ld	s2,16(sp)
002aa954: dfbf0018  ld	ra,24(sp)
002aa958: 03e00008  jr	ra
002aa95c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002aa8e0(void)`

```c
void FUN_002aa8e0(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  iVar2 = FUN_002a9d68();
  uVar3 = FUN_002aa5b8(param_1,param_2);
  puVar4 = (uint *)((uVar3 >> 5) * 4 + iVar2 + (int)param_1 * 4 + 0x44);
  uVar1 = *puVar4;
  uVar3 = 1 << (uVar3 & 0x1f);
  if ((uVar1 & uVar3) == 0) {
    *puVar4 = uVar1 | uVar3;
  }
  return;
}
```

## Earlier attempts (newest first)

- 21 differing words, 128/128 bytes: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_11_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_11_0.cpp`)
