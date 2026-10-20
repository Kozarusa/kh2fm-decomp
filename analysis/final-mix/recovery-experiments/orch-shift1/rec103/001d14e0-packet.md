# Target packet 001d14e0

- Range: `001d14e0`..`001d153c`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d14e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00177dc8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_orchcp_recovered_001ced10.cpp`, `fm_primary_orchcp_recovered_001ced68.cpp`
- `001befd8` registry: `func_001befd8`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchcl_recovered_001befd8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d14e0: 27bdfff0  addiu	sp,sp,-16
001d14e4: 00e0402d  move	t0,a3
001d14e8: ffb00000  sd	s0,0(sp)
001d14ec: 00c0382d  move	a3,a2
001d14f0: ffbf0008  sd	ra,8(sp)
001d14f4: 24060008  li	a2,8
001d14f8: 0c05df72  jal	0x177dc8
001d14fc: 0080802d  move	s0,a0
001d1500: 8e0d0588  lw	t5,1416(s0)
001d1504: 3c0e0400  lui	t6,0x400
001d1508: 3c0f0035  lui	t7,0x35
001d150c: 8e040b44  lw	a0,2884(s0)
001d1510: 01ae6825  or	t5,t5,t6
001d1514: dfbf0008  ld	ra,8(sp)
001d1518: 25ef24b8  addiu	t7,t7,9400   ; = D_003524b8
001d151c: ae0d0588  sw	t5,1416(s0)
001d1520: ae0f0000  sw	t7,0(s0)
001d1524: 3c050037  lui	a1,0x37
001d1528: 24a5e3a8  addiu	a1,a1,-7256   ; = D_0036e3a8
001d152c: 24060002  li	a2,2
001d1530: dfb00000  ld	s0,0(sp)
001d1534: 0806fbf6  j	0x1befd8
001d1538: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d14e0(void)`

```c
void FUN_001d14e0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  
  FUN_00177dc8(param_1,param_2,8,param_3,param_4);
  puVar1 = (undefined4 *)param_1;
  puVar1[0x162] = puVar1[0x162] | 0x4000000;
  *puVar1 = &PTR_LAB_003524b8;
  FUN_001befd8(puVar1[0x2d1],0x36e3a8,2);
  return;
}
```

## Earlier attempts (newest first)

- none found
