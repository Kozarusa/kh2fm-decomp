# Target packet 002b27c8

- Range: `002b27c8`..`002b2840`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b27c8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0023f900` registry: `_ZNK2Tz7LayFile14getFileAddressEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcheu_recovered_00298f90.cpp`
- `0023fa08` registry: `Tz::LeadDataSetText(void*, unsigned int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_near_recovered_v2.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`
- `00292630` registry: `Tz::LoadDataIsFlushing()`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcher_recovered_00292630.cpp`
- `00293db8` registry: `_ZN2Tz6JMData10CacheAllocEiPKc`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcher_recovered_00293fc0.cpp`
- `00294000` registry: `_ZN2Tz6JmInfo7GetDataEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_calltransport_recovered_002956c0.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_orcher_recovered_00294208.cpp`, `fm_primary_orcheu_recovered_00295228.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b27c8: 27bdfff0  addiu	sp,sp,-16
002b27cc: ffb00000  sd	s0,0(sp)
002b27d0: ffbf0008  sd	ra,8(sp)
002b27d4: 3c100036  lui	s0,0x36
002b27d8: 0c08fe40  jal	0x23f900
002b27dc: 8e04f638  lw	a0,-2504(s0)   ; = D_0035f638
002b27e0: 0c0a498c  jal	0x292630
002b27e4: 00000000  nop
002b27e8: 14400011  bnez	v0,0x2b2830
002b27ec: 24040009  li	a0,9
002b27f0: 0c0a5000  jal	0x294000
002b27f4: 00000000  nop
002b27f8: 8e0ef638  lw	t6,-2504(s0)   ; = D_0035f638
002b27fc: 24040005  li	a0,5
002b2800: 81cf0034  lb	t7,52(t6)
002b2804: 000f7900  sll	t7,t7,0x4
002b2808: 004f2821  addu	a1,v0,t7
002b280c: 0c0a4f6e  jal	0x293db8
002b2810: 24a50016  addiu	a1,a1,22
002b2814: 8e04f638  lw	a0,-2504(s0)   ; = D_0035f638
002b2818: 0c08fe82  jal	0x23fa08
002b281c: 0040282d  move	a1,v0
002b2820: 8e0ef638  lw	t6,-2504(s0)   ; = D_0035f638
002b2824: 8dcf0034  lw	t7,52(t6)
002b2828: 35ef0200  ori	t7,t7,0x200
002b282c: adcf0034  sw	t7,52(t6)
002b2830: dfb00000  ld	s0,0(sp)
002b2834: dfbf0008  ld	ra,8(sp)
002b2838: 03e00008  jr	ra
002b283c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b27c8(void)`

```c
void FUN_002b27c8(void)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  
  FUN_0023f900(DAT_0035f638);
  lVar1 = FUN_00292630();
  if (lVar1 == 0) {
    iVar3 = FUN_00294000(9);
    uVar2 = FUN_00293db8(5,iVar3 + *(char *)(DAT_0035f638 + 0x34) * 0x10 + 0x16);
    FUN_0023fa08(DAT_0035f638,uVar2);
    *(uint *)(DAT_0035f638 + 0x34) = *(uint *)(DAT_0035f638 + 0x34) | 0x200;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
