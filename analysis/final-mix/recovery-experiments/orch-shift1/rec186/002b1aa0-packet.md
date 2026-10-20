# Target packet 002b1aa0

- Range: `002b1aa0`..`002b1af0`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b1aa0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002b23e0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_fallback_helpers.cpp`, `fm_primary_predicatereg_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b1aa0: 27bdfff0  addiu	sp,sp,-16
002b1aa4: ffbf0000  sd	ra,0(sp)
002b1aa8: 0c0ac8f8  jal	0x2b23e0
002b1aac: 2404ffff  li	a0,-1
002b1ab0: 8c4d0000  lw	t5,0(v0)
002b1ab4: 3c0e1000  lui	t6,0x1000
002b1ab8: 3c0f0400  lui	t7,0x400
002b1abc: 01ae7024  and	t6,t5,t6
002b1ac0: 01af6824  and	t5,t5,t7
002b1ac4: 15a00004  bnez	t5,0x2b1ad8
002b1ac8: 240250d2  li	v0,20690
002b1acc: 11c00005  beqz	t6,0x2b1ae4
002b1ad0: 3c0f0037  lui	t7,0x37
002b1ad4: 8de24ca4  lw	v0,19620(t7)   ; = D_00374ca4
002b1ad8: dfbf0000  ld	ra,0(sp)
002b1adc: 03e00008  jr	ra
002b1ae0: 27bd0010  addiu	sp,sp,16
002b1ae4: 3c0f0037  lui	t7,0x37
002b1ae8: 1000fffb  b	0x2b1ad8
002b1aec: 8de24ca8  lw	v0,19624(t7)   ; = D_00374ca8
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b1aa0(void)`

```c
undefined4 FUN_002b1aa0(void)

{
  uint *puVar1;
  undefined4 uVar2;
  
  puVar1 = (uint *)FUN_002b23e0(0xffffffffffffffff);
  uVar2 = 0x50d2;
  if (((*puVar1 & 0x4000000) == 0) && (uVar2 = DAT_00374ca8, (*puVar1 & 0x10000000) != 0)) {
    uVar2 = DAT_00374ca4;
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- none found
