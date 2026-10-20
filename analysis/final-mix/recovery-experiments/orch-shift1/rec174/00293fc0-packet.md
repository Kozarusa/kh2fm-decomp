# Target packet 00293fc0

- Range: `00293fc0`..`00294000`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_00293fc0`
- Registry names for this address: `func_00293fc0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00290940` registry: `Tz::JmInfo::IsLoaded(unsigned int)`
- `00290960` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_twoword_recovered_0026ec70.cpp`, `fm_primary_twoword_recovered_00276410.cpp`, `fm_primary_twoword_recovered_002806c8.cpp`, `fm_scalar_extra_recovered_07.cpp`, `fm_scalar_recovered_07.cpp`
- `00293db8` registry: `_ZN2Tz6JMData10CacheAllocEiPKc`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00293fc0: 27bdfff0  addiu	sp,sp,-16
00293fc4: ffb00000  sd	s0,0(sp)
00293fc8: ffbf0008  sd	ra,8(sp)
00293fcc: 3c100036  lui	s0,0x36
00293fd0: 0c0a4250  jal	0x290940
00293fd4: 8e04f574  lw	a0,-2700(s0)   ; = D_0035f574
00293fd8: 0000202d  move	a0,zero
00293fdc: 0c0a4f6e  jal	0x293db8
00293fe0: 0000282d  move	a1,zero
00293fe4: 8e04f574  lw	a0,-2700(s0)   ; = D_0035f574
00293fe8: 0040282d  move	a1,v0
00293fec: dfbf0008  ld	ra,8(sp)
00293ff0: 2406002b  li	a2,43
00293ff4: dfb00000  ld	s0,0(sp)
00293ff8: 080a4258  j	0x290960
00293ffc: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00293fc0(void)`

```c
void FUN_00293fc0(void)

{
  undefined8 uVar1;
  
  FUN_00290940(DAT_0035f574);
  uVar1 = FUN_00293db8(0,0);
  FUN_00290960(DAT_0035f574,uVar1,0x2b);
  return;
}
```

## Earlier attempts (newest first)

- none found
