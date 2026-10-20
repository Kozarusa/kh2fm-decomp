# Target packet 0014d8d0

- Range: `0014d8d0`..`0014d910`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_0014d8d0`
- Registry names for this address: `func_0014d8d0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002f25a0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_002e8c28.cpp`, `fm_primary_floatpacket_recovered_002e8c58.cpp`, `fm_primary_globalcall_recovered_0020f118.cpp`, `fm_primary_globalcall_recovered_0020f150.cpp`, `fm_primary_oneword_recovered_002ef1b8.cpp`
- `002f3918` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_globalcall_recovered_0020f118.cpp`, `fm_primary_globalcall_recovered_0020f150.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`
- `003058a0` registry: `FlushCache`
  - accepted sources that already call it (copy their declaration): `fm_boundary_initializers.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0014d8d0: 27bdfff0  addiu	sp,sp,-16
0014d8d4: ffb00000  sd	s0,0(sp)
0014d8d8: ffbf0008  sd	ra,8(sp)
0014d8dc: 0080802d  move	s0,a0
0014d8e0: 0c0c1628  jal	0x3058a0
0014d8e4: 0000202d  move	a0,zero
0014d8e8: 0000202d  move	a0,zero
0014d8ec: 0c0bc968  jal	0x2f25a0
0014d8f0: 0000282d  move	a1,zero
0014d8f4: 0200282d  move	a1,s0
0014d8f8: dfbf0008  ld	ra,8(sp)
0014d8fc: 3c0f0035  lui	t7,0x35
0014d900: dfb00000  ld	s0,0(sp)
0014d904: 8de49ef8  lw	a0,-24840(t7)   ; = D_00349ef8
0014d908: 080bce46  j	0x2f3918
0014d90c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0014d8d0(void)`

```c
void FUN_0014d8d0(undefined8 param_1)

{
  FlushCache(0);
  FUN_002f25a0(0,0);
  FUN_002f3918(DAT_00349ef8,param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
