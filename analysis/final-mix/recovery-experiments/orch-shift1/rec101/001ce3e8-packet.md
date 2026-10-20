# Target packet 001ce3e8

- Range: `001ce3e8`..`001ce454`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ce3e8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001980d0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_orchcn_recovered_001c2338.cpp`, `fm_primary_workerbacklog_recovered_001d9eb0.cpp`, `fm_primary_workerbacklog_recovered_001d9ef0.cpp`
- `001dba88` registry: `func_001dba88`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ce3e8: 27bdffe0  addiu	sp,sp,-32
001ce3ec: ffb10008  sd	s1,8(sp)
001ce3f0: ffb00000  sd	s0,0(sp)
001ce3f4: 00a0882d  move	s1,a1
001ce3f8: ffbf0010  sd	ra,16(sp)
001ce3fc: 00c0282d  move	a1,a2
001ce400: 0080802d  move	s0,a0
001ce404: 0c066034  jal	0x1980d0
001ce408: 24060004  li	a2,4
001ce40c: 3c0f0035  lui	t7,0x35
001ce410: ae1109f4  sw	s1,2548(s0)
001ce414: 25ef2140  addiu	t7,t7,8512   ; = D_00352140
001ce418: 0220202d  move	a0,s1
001ce41c: 0c076ea2  jal	0x1dba88
001ce420: ae0f0000  sw	t7,0(s0)
001ce424: 8e0d0588  lw	t5,1416(s0)
001ce428: 3c0e0080  lui	t6,0x80
001ce42c: 3c0f01d6  lui	t7,0x1d6
001ce430: dfb10008  ld	s1,8(sp)
001ce434: 01ae6825  or	t5,t5,t6
001ce438: dfbf0010  ld	ra,16(sp)
001ce43c: 25efb9e0  addiu	t7,t7,-17952   ; = D_01d5b9e0
001ce440: ae0d0588  sw	t5,1416(s0)
001ce444: ae0f09f8  sw	t7,2552(s0)
001ce448: dfb00000  ld	s0,0(sp)
001ce44c: 03e00008  jr	ra
001ce450: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ce3e8(void)`

```c
void FUN_001ce3e8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  
  FUN_001980d0(param_1,param_3,4);
  puVar1 = (undefined4 *)param_1;
  puVar1[0x27d] = (int)param_2;
  *puVar1 = &PTR_FUN_00352140;
  FUN_001dba88(param_2);
  puVar1[0x162] = puVar1[0x162] | 0x800000;
  puVar1[0x27e] = &DAT_01d5b9e0;
  return;
}
```

## Earlier attempts (newest first)

- none found
