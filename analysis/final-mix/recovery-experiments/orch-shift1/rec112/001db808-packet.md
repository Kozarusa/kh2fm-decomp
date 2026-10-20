# Target packet 001db808

- Range: `001db808`..`001db850`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_001db808`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00106420` registry: `Tz::LoadDataFree(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchac_recovered_00123c98.cpp`, `fm_primary_orchac_recovered_00315678.cpp`, `fm_primary_orchac_recovered_00315700.cpp`, `fm_primary_orchac_recovered_00316890.cpp`, `fm_primary_queuealphaprime_recovered_0011f5a0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001db808: 27bdfff0  addiu	sp,sp,-16
001db80c: 3c0f0035  lui	t7,0x35
001db810: ffb00000  sd	s0,0(sp)
001db814: 25ef2a38  addiu	t7,t7,10808   ; = D_00352a38
001db818: ffbf0008  sd	ra,8(sp)
001db81c: ac8f0000  sw	t7,0(a0)
001db820: 0080802d  move	s0,a0
001db824: 8c8d0004  lw	t5,4(a0)
001db828: 8c85000c  lw	a1,12(a0)
001db82c: 8daf0000  lw	t7,0(t5)
001db830: 8dee0004  lw	t6,4(t7)
001db834: 01c0f809  jalr	t6
001db838: 01a0202d  move	a0,t5
001db83c: 0200202d  move	a0,s0
001db840: dfbf0008  ld	ra,8(sp)
001db844: dfb00000  ld	s0,0(sp)
001db848: 08041908  j	0x106420
001db84c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001db808(void)`

```c
void FUN_001db808(undefined8 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  *puVar1 = &PTR_FUN_00352a38;
  (**(code **)(*(int *)puVar1[1] + 4))((int *)puVar1[1],puVar1[3]);
  FUN_00106420(param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
