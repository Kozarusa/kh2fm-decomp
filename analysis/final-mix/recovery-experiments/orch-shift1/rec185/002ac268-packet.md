# Target packet 002ac268

- Range: `002ac268`..`002ac2e8`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_002ac268`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002a9d68` registry: `_ZN2Tz9JmNewInfo7GetSramEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_orchey_recovered_002aab90.cpp`, `fm_primary_orchez_recovered_002aa450.cpp`, `fm_primary_threeword_recovered_002a01c8.cpp`, `fm_primary_threeword_recovered_002a6368.cpp`
- `002abf40` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_threeword_recovered_002a01c8.cpp`, `fm_primary_threeword_recovered_002a6368.cpp`, `fm_primary_threeword_recovered_002a7f20.cpp`, `fm_primary_threeword_recovered_002a92a0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002ac268: 27bdffe0  addiu	sp,sp,-32
002ac26c: ffb10008  sd	s1,8(sp)
002ac270: ffb20010  sd	s2,16(sp)
002ac274: ffb00000  sd	s0,0(sp)
002ac278: 0080882d  move	s1,a0
002ac27c: ffbf0018  sd	ra,24(sp)
002ac280: 0c0aa75a  jal	0x2a9d68
002ac284: 00a0902d  move	s2,a1
002ac288: 0040802d  move	s0,v0
002ac28c: 0220202d  move	a0,s1
002ac290: 0240282d  move	a1,s2
002ac294: 0c0aafd0  jal	0x2abf40
002ac298: 00118880  sll	s1,s1,0x2
002ac29c: 02118021  addu	s0,s0,s1
002ac2a0: 00027942  srl	t7,v0,0x5
002ac2a4: 261000ac  addiu	s0,s0,172
002ac2a8: 000f7880  sll	t7,t7,0x2
002ac2ac: 3042001f  andi	v0,v0,0x1f
002ac2b0: 01f06021  addu	t4,t7,s0
002ac2b4: 8d8e0000  lw	t6,0(t4)
002ac2b8: 240f0001  li	t7,1
002ac2bc: 004f7804  sllv	t7,t7,v0
002ac2c0: 01cf6825  or	t5,t6,t7
002ac2c4: 01cf7024  and	t6,t6,t7
002ac2c8: 51c00001  beqzl	t6,0x2ac2d0
002ac2cc: ad8d0000  sw	t5,0(t4)
002ac2d0: dfb00000  ld	s0,0(sp)
002ac2d4: dfb10008  ld	s1,8(sp)
002ac2d8: dfb20010  ld	s2,16(sp)
002ac2dc: dfbf0018  ld	ra,24(sp)
002ac2e0: 03e00008  jr	ra
002ac2e4: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002ac268(void)`

```c
void FUN_002ac268(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  iVar2 = FUN_002a9d68();
  uVar3 = FUN_002abf40(param_1,param_2);
  puVar4 = (uint *)((uVar3 >> 5) * 4 + iVar2 + (int)param_1 * 4 + 0xac);
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
