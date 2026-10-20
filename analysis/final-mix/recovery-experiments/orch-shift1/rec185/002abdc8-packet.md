# Target packet 002abdc8

- Range: `002abdc8`..`002abe28`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_002abdc8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002a9d68` registry: `_ZN2Tz9JmNewInfo7GetSramEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_orchey_recovered_002aab90.cpp`, `fm_primary_orchez_recovered_002aa450.cpp`, `fm_primary_threeword_recovered_002a01c8.cpp`, `fm_primary_threeword_recovered_002a6368.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002abdc8: 27bdfff0  addiu	sp,sp,-16
002abdcc: ffbf0000  sd	ra,0(sp)
002abdd0: 0c0aa75a  jal	0x2a9d68
002abdd4: 00000000  nop
002abdd8: 24420140  addiu	v0,v0,320
002abddc: 0000582d  move	t3,zero
002abde0: 24090001  li	t1,1
002abde4: 000b7942  srl	t7,t3,0x5
002abde8: 316e001f  andi	t6,t3,0x1f
002abdec: 000f7880  sll	t7,t7,0x2
002abdf0: 01c97004  sllv	t6,t1,t6
002abdf4: 01e25021  addu	t2,t7,v0
002abdf8: 256b0001  addiu	t3,t3,1
002abdfc: 8d4f0000  lw	t7,0(t2)
002abe00: 01ee6825  or	t5,t7,t6
002abe04: 01ee7824  and	t7,t7,t6
002abe08: 15e00002  bnez	t7,0x2abe14
002abe0c: 296c0004  slti	t4,t3,4
002abe10: ad4d0000  sw	t5,0(t2)
002abe14: 1580fff4  bnez	t4,0x2abde8
002abe18: 000b7942  srl	t7,t3,0x5
002abe1c: dfbf0000  ld	ra,0(sp)
002abe20: 03e00008  jr	ra
002abe24: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002abdc8(void)`

```c
void FUN_002abdc8(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = FUN_002a9d68();
  uVar3 = 0;
  uVar5 = 0;
  do {
    uVar4 = 1 << (uVar3 & 0x1f);
    puVar2 = (uint *)(uVar5 * 4 + iVar1 + 0x140);
    uVar3 = uVar3 + 1;
    uVar5 = *puVar2;
    if ((uVar5 & uVar4) == 0) {
      *puVar2 = uVar5 | uVar4;
    }
    uVar5 = uVar3 >> 5;
  } while ((int)uVar3 < 4);
  return;
}
```

## Earlier attempts (newest first)

- 15 differing words, 96/96 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_11_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_11_0.cpp`)
