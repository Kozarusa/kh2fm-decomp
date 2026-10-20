# Target packet 001a67e0

- Range: `001a67e0`..`001a684c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a67e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00105110` registry: `_ZN4AREA4FreeEPv`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_orchbu_recovered_001a4060.cpp`
- `001a5d48` registry: `_ZN2YS5MAGICD1Ev`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a67e0: 27bdfff0  addiu	sp,sp,-16
001a67e4: ffb00000  sd	s0,0(sp)
001a67e8: ffbf0008  sd	ra,8(sp)
001a67ec: 1080000f  beqz	a0,0x1a682c
001a67f0: 0080802d  move	s0,a0
001a67f4: 3c0f01c7  lui	t7,0x1c7
001a67f8: 0000702d  move	t6,zero
001a67fc: 8dedcb20  lw	t5,-13536(t7)   ; = D_01c6cb20
001a6800: 11c00002  beqz	t6,0x1a680c
001a6804: 01a0782d  move	t7,t5
001a6808: 8dcf000c  lw	t7,12(t6)
001a680c: 15e0000b  bnez	t7,0x1a683c
001a6810: 01e0702d  move	t6,t7
001a6814: 52000006  beqzl	s0,0x1a6830
001a6818: dfb00000  ld	s0,0(sp)
001a681c: 0c069752  jal	0x1a5d48
001a6820: 0200202d  move	a0,s0
001a6824: 0c041444  jal	0x105110
001a6828: 0200202d  move	a0,s0
001a682c: dfb00000  ld	s0,0(sp)
001a6830: dfbf0008  ld	ra,8(sp)
001a6834: 03e00008  jr	ra
001a6838: 27bd0010  addiu	sp,sp,16
001a683c: 15f0fff0  bne	t7,s0,0x1a6800
001a6840: 00000000  nop
001a6844: 1000fff3  b	0x1a6814
001a6848: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a67e0(void)`

```c
void FUN_001a67e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 0;
    do {
      iVar1 = DAT_01c6cb20;
      if (iVar2 != 0) {
        iVar1 = *(int *)(iVar2 + 0xc);
      }
    } while ((iVar1 != 0) && (iVar2 = iVar1, iVar1 != param_1));
    if (param_1 != 0) {
      FUN_001a5d48(param_1);
      FUN_00105110(param_1);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
