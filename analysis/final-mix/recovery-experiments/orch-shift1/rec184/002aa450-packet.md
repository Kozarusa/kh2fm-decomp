# Target packet 002aa450

- Range: `002aa450`..`002aa4a4`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_002aa450`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002a9d68` registry: `_ZN2Tz9JmNewInfo7GetSramEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_threeword_recovered_002a01c8.cpp`, `fm_primary_threeword_recovered_002a6368.cpp`, `fm_primary_threeword_recovered_002a7f20.cpp`, `fm_primary_threeword_recovered_002a92a0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002aa450: 27bdfff0  addiu	sp,sp,-16
002aa454: ffb00000  sd	s0,0(sp)
002aa458: ffbf0008  sd	ra,8(sp)
002aa45c: 0c0aa75a  jal	0x2a9d68
002aa460: 0080802d  move	s0,a0
002aa464: 00107942  srl	t7,s0,0x5
002aa468: 2442013c  addiu	v0,v0,316
002aa46c: 000f7880  sll	t7,t7,0x2
002aa470: 3210001f  andi	s0,s0,0x1f
002aa474: 01e26021  addu	t4,t7,v0
002aa478: 8d8e0000  lw	t6,0(t4)
002aa47c: 240f0001  li	t7,1
002aa480: 020f7804  sllv	t7,t7,s0
002aa484: 01cf6825  or	t5,t6,t7
002aa488: 01cf7024  and	t6,t6,t7
002aa48c: 51c00001  beqzl	t6,0x2aa494
002aa490: ad8d0000  sw	t5,0(t4)
002aa494: dfb00000  ld	s0,0(sp)
002aa498: dfbf0008  ld	ra,8(sp)
002aa49c: 03e00008  jr	ra
002aa4a0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002aa450(void)`

```c
void FUN_002aa450(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  iVar2 = FUN_002a9d68();
  puVar3 = (uint *)((param_1 >> 5) * 4 + iVar2 + 0x13c);
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
