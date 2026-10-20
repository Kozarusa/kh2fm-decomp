# Target packet 00292eb0

- Range: `00292eb0`..`00292f14`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_00292eb0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00292f18` registry: none
- `00292fe8` registry: none
- `00293200` registry: `_ZN2Tz8UnitLoad9isReadingEv`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00292eb0: 27bdfff0  addiu	sp,sp,-16
00292eb4: ffbf0000  sd	ra,0(sp)
00292eb8: 0c0a4c80  jal	0x293200
00292ebc: 00000000  nop
00292ec0: 1440000c  bnez	v0,0x292ef4
00292ec4: 240fffff  li	t7,-1
00292ec8: 3c0f0036  lui	t7,0x36
00292ecc: 85eef4e0  lh	t6,-2848(t7)   ; = D_0035f4e0
00292ed0: 11c00008  beqz	t6,0x292ef4
00292ed4: 0000782d  move	t7,zero
00292ed8: 3c0f0036  lui	t7,0x36
00292edc: 8deef4c4  lw	t6,-2876(t7)   ; = D_0035f4c4
00292ee0: 15c00008  bnez	t6,0x292f04
00292ee4: 00000000  nop
00292ee8: 0c0a4bc6  jal	0x292f18
00292eec: 00000000  nop
00292ef0: 0040782d  move	t7,v0
00292ef4: dfbf0000  ld	ra,0(sp)
00292ef8: 01e0102d  move	v0,t7
00292efc: 03e00008  jr	ra
00292f00: 27bd0010  addiu	sp,sp,16
00292f04: 0c0a4bfa  jal	0x292fe8
00292f08: 00000000  nop
00292f0c: 1000fff9  b	0x292ef4
00292f10: 0040782d  move	t7,v0
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00292eb0(void)`

```c
undefined8 FUN_00292eb0(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_00293200();
  uVar2 = 0xffffffffffffffff;
  if ((lVar1 == 0) && (uVar2 = 0, DAT_0035f4e0 != 0)) {
    if (DAT_0035f4c4 == 0) {
      uVar2 = FUN_00292f18();
    }
    else {
      uVar2 = FUN_00292fe8();
    }
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- none found
