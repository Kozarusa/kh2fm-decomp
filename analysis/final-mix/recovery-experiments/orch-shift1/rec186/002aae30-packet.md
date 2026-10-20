# Target packet 002aae30

- Range: `002aae30`..`002aae84`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_002aae30`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002a9d68` registry: `_ZN2Tz9JmNewInfo7GetSramEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_orchey_recovered_002aab90.cpp`, `fm_primary_orchez_recovered_002aa450.cpp`, `fm_primary_threeword_recovered_002a01c8.cpp`, `fm_primary_threeword_recovered_002a6368.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002aae30: 27bdfff0  addiu	sp,sp,-16
002aae34: ffb00000  sd	s0,0(sp)
002aae38: ffbf0008  sd	ra,8(sp)
002aae3c: 0c0aa75a  jal	0x2a9d68
002aae40: 0080802d  move	s0,a0
002aae44: 00107942  srl	t7,s0,0x5
002aae48: 24420094  addiu	v0,v0,148
002aae4c: 000f7880  sll	t7,t7,0x2
002aae50: 3210001f  andi	s0,s0,0x1f
002aae54: 01e26021  addu	t4,t7,v0
002aae58: 8d8e0000  lw	t6,0(t4)
002aae5c: 240f0001  li	t7,1
002aae60: 020f7804  sllv	t7,t7,s0
002aae64: 01cf6825  or	t5,t6,t7
002aae68: 01cf7024  and	t6,t6,t7
002aae6c: 51c00001  beqzl	t6,0x2aae74
002aae70: ad8d0000  sw	t5,0(t4)
002aae74: dfb00000  ld	s0,0(sp)
002aae78: dfbf0008  ld	ra,8(sp)
002aae7c: 03e00008  jr	ra
002aae80: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002aae30(void)`

```c
void FUN_002aae30(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  iVar2 = FUN_002a9d68();
  puVar3 = (uint *)((param_1 >> 5) * 4 + iVar2 + 0x94);
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
