# Target packet 002aab90

- Range: `002aab90`..`002aabe4`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_002aab90`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002a9d68` registry: `_ZN2Tz9JmNewInfo7GetSramEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_threeword_recovered_002a01c8.cpp`, `fm_primary_threeword_recovered_002a6368.cpp`, `fm_primary_threeword_recovered_002a7f20.cpp`, `fm_primary_threeword_recovered_002a92a0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002aab90: 27bdfff0  addiu	sp,sp,-16
002aab94: ffb00000  sd	s0,0(sp)
002aab98: ffbf0008  sd	ra,8(sp)
002aab9c: 0c0aa75a  jal	0x2a9d68
002aaba0: 0080802d  move	s0,a0
002aaba4: 00107942  srl	t7,s0,0x5
002aaba8: 24420084  addiu	v0,v0,132
002aabac: 000f7880  sll	t7,t7,0x2
002aabb0: 3210001f  andi	s0,s0,0x1f
002aabb4: 01e26021  addu	t4,t7,v0
002aabb8: 8d8e0000  lw	t6,0(t4)
002aabbc: 240f0001  li	t7,1
002aabc0: 020f7804  sllv	t7,t7,s0
002aabc4: 01cf6825  or	t5,t6,t7
002aabc8: 01cf7024  and	t6,t6,t7
002aabcc: 51c00001  beqzl	t6,0x2aabd4
002aabd0: ad8d0000  sw	t5,0(t4)
002aabd4: dfb00000  ld	s0,0(sp)
002aabd8: dfbf0008  ld	ra,8(sp)
002aabdc: 03e00008  jr	ra
002aabe0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002aab90(void)`

```c
void FUN_002aab90(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  iVar2 = FUN_002a9d68();
  puVar3 = (uint *)((param_1 >> 5) * 4 + iVar2 + 0x84);
  uVar1 = *puVar3;
  uVar4 = 1 << (param_1 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}
```

## Earlier attempts (newest first)

- 13 differing words, 80/84 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_11_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_11_0.cpp`)
