# Target packet 002a1c68

- Range: `002a1c68`..`002a1cd4`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_002a1c68`
- Registry names for this address: `func_002a1c68`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0023f900` registry: `_ZNK2Tz7LayFile14getFileAddressEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcheu_recovered_00298f90.cpp`
- `0023fad0` registry: `func_0023fad0`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`, `fm_primary_oneword_recovered_00253538.cpp`
- `00292630` registry: `Tz::LoadDataIsFlushing()`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcher_recovered_00292630.cpp`
- `00293d80` registry: `_ZN2Tz6JMData5ClearEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcheu_recovered_00298f90.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002a1c68: 27bdfff0  addiu	sp,sp,-16
002a1c6c: ffb00000  sd	s0,0(sp)
002a1c70: ffbf0008  sd	ra,8(sp)
002a1c74: 0c0a498c  jal	0x292630
002a1c78: 00000000  nop
002a1c7c: 14400012  bnez	v0,0x2a1cc8
002a1c80: dfb00000  ld	s0,0(sp)
002a1c84: 3c0f0036  lui	t7,0x36
002a1c88: 91eef5e0  lbu	t6,-2592(t7)   ; = D_0035f5e0
002a1c8c: 11c00007  beqz	t6,0x2a1cac
002a1c90: 3c100036  lui	s0,0x36
002a1c94: 0c08fe40  jal	0x23f900
002a1c98: 8e04f5dc  lw	a0,-2596(s0)   ; = D_0035f5dc
002a1c9c: 10400003  beqz	v0,0x2a1cac
002a1ca0: 00000000  nop
002a1ca4: 0c08feb4  jal	0x23fad0
002a1ca8: 8e04f5dc  lw	a0,-2596(s0)   ; = D_0035f5dc
002a1cac: 0c0a4f60  jal	0x293d80
002a1cb0: 240413ed  li	a0,5101
002a1cb4: 3c0f0036  lui	t7,0x36
002a1cb8: 3c0e0036  lui	t6,0x36
002a1cbc: a1e0f5e0  sb	zero,-2592(t7)   ; = D_0035f5e0
002a1cc0: a1c0f5e1  sb	zero,-2591(t6)   ; = D_0035f5e1
002a1cc4: dfb00000  ld	s0,0(sp)
002a1cc8: dfbf0008  ld	ra,8(sp)
002a1ccc: 03e00008  jr	ra
002a1cd0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002a1c68(void)`

```c
void FUN_002a1c68(void)

{
  long lVar1;
  
  lVar1 = FUN_00292630();
  if (lVar1 == 0) {
    if ((DAT_0035f5e0 != '\0') && (lVar1 = FUN_0023f900(DAT_0035f5dc), lVar1 != 0)) {
      FUN_0023fad0(DAT_0035f5dc);
    }
    FUN_00293d80(0x13ed);
    DAT_0035f5e0 = '\0';
    DAT_0035f5e1 = 0;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
