# Target packet 001a07b0

- Range: `001a07b0`..`001a0800`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a07b0`
- Registry names for this address: `func_001a07b0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0017aab8` registry: `func_0017aab8`
  - accepted sources that already call it (copy their declaration): `fm_primary_queuexiprime_recovered_0016bd10.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a07b0: 27bdffe0  addiu	sp,sp,-32
001a07b4: ffb10008  sd	s1,8(sp)
001a07b8: ffb00000  sd	s0,0(sp)
001a07bc: ffbf0010  sd	ra,16(sp)
001a07c0: 0080882d  move	s1,a0
001a07c4: 00c0802d  move	s0,a2
001a07c8: 0c05eaae  jal	0x17aab8
001a07cc: 24040005  li	a0,5
001a07d0: 8c4e0000  lw	t6,0(v0)
001a07d4: 0040282d  move	a1,v0
001a07d8: 0200302d  move	a2,s0
001a07dc: 8dcf001c  lw	t7,28(t6)
001a07e0: 01e0f809  jalr	t7
001a07e4: 0220202d  move	a0,s1
001a07e8: 0220102d  move	v0,s1
001a07ec: dfb00000  ld	s0,0(sp)
001a07f0: dfb10008  ld	s1,8(sp)
001a07f4: dfbf0010  ld	ra,16(sp)
001a07f8: 03e00008  jr	ra
001a07fc: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a07b0(void)`

```c
undefined8 FUN_001a07b0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_0017aab8(5);
  (**(code **)(*(int *)uVar1 + 0x1c))(param_1,uVar1,param_3);
  return param_1;
}
```

## Earlier attempts (newest first)

- none found
