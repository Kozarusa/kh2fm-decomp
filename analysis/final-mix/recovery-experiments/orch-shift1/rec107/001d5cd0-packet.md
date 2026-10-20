# Target packet 001d5cd0

- Range: `001d5cd0`..`001d5d1c`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d5cd0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d5b78` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`
- `001d6ec8` registry: `func_001d6ec8`
  - accepted sources that already call it (copy their declaration): `fm_primary_queuegamma_recovered_001d6ec8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d5cd0: 27bdfff0  addiu	sp,sp,-16
001d5cd4: ffbf0000  sd	ra,0(sp)
001d5cd8: 0c075bb2  jal	0x1d6ec8
001d5cdc: 00000000  nop
001d5ce0: 3c0e0033  lui	t6,0x33
001d5ce4: 0040782d  move	t7,v0
001d5ce8: 25cee020  addiu	t6,t6,-8160   ; = D_0032e020
001d5cec: 0000202d  move	a0,zero
001d5cf0: 91cd1036  lbu	t5,4150(t6)
001d5cf4: 01a0282d  move	a1,t5
001d5cf8: 01af682a  slt	t5,t5,t7
001d5cfc: 11a00004  beqz	t5,0x1d5d10
001d5d00: 0000102d  move	v0,zero
001d5d04: dfbf0000  ld	ra,0(sp)
001d5d08: 080756de  j	0x1d5b78
001d5d0c: 27bd0010  addiu	sp,sp,16
001d5d10: dfbf0000  ld	ra,0(sp)
001d5d14: 03e00008  jr	ra
001d5d18: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d5cd0(void)`

```c
undefined8 FUN_001d5cd0(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_001d6ec8();
  if ((long)(ulong)DAT_0032f050._6_1_ < lVar1) {
    uVar2 = FUN_001d5b78(0,(ulong)DAT_0032f050._6_1_);
    return uVar2;
  }
  return 0;
}
```

## Earlier attempts (newest first)

- none found
