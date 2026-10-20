# Target packet 0019bf00

- Range: `0019bf00`..`0019bf50`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019bf00`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0017a538` registry: `func_0017a538`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_oneword_recovered_001b72c0.cpp`, `fm_primary_orchbd_recovered_0017a538.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019bf00: 27bdfff0  addiu	sp,sp,-16
0019bf04: ffb00000  sd	s0,0(sp)
0019bf08: ffbf0008  sd	ra,8(sp)
0019bf0c: 8c8f0588  lw	t7,1416(a0)
0019bf10: 31ef0080  andi	t7,t7,0x80
0019bf14: 11e00005  beqz	t7,0x19bf2c
0019bf18: 0080802d  move	s0,a0
0019bf1c: 0c05e94e  jal	0x17a538
0019bf20: 00000000  nop
0019bf24: 14400005  bnez	v0,0x19bf3c
0019bf28: 24040001  li	a0,1
0019bf2c: 8e0f0108  lw	t7,264(s0)
0019bf30: 3c0e0010  lui	t6,0x10
0019bf34: 01ee7824  and	t7,t7,t6
0019bf38: 000f202b  sltu	a0,zero,t7
0019bf3c: dfb00000  ld	s0,0(sp)
0019bf40: 0080102d  move	v0,a0
0019bf44: dfbf0008  ld	ra,8(sp)
0019bf48: 03e00008  jr	ra
0019bf4c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019bf00(void)`

```c
bool FUN_0019bf00(int param_1)

{
  long lVar1;
  
  if (((*(uint *)(param_1 + 0x588) & 0x80) != 0) && (lVar1 = FUN_0017a538(), lVar1 != 0)) {
    return true;
  }
  return (*(uint *)(param_1 + 0x108) & 0x100000) != 0;
}
```

## Earlier attempts (newest first)

- none found
