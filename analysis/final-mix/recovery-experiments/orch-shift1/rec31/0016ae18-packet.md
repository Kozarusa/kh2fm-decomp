# Target packet 0016ae18

- Range: `0016ae18`..`0016ae58`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016ae18`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016adc8` registry: `func_0016adc8`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_loadorder_recovered.cpp`, `fm_primary_packetnext_recovered.cpp`, `fm_primary_packetorder_recovered_00172368.cpp`
- `0016aeb8` registry: `_ZN2YS3OBJ7set_rotEf`
  - accepted sources that already call it (copy their declaration): `fm_fallback_small.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_loadorder_recovered.cpp`, `fm_primary_packetnext_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016ae18: 27bdffe0  addiu	sp,sp,-32
0016ae1c: 248f0890  addiu	t7,a0,2192
0016ae20: ffb00010  sd	s0,16(sp)
0016ae24: ffbf0018  sd	ra,24(sp)
0016ae28: 0080802d  move	s0,a0
0016ae2c: 79e80000  lq	t0,0(t7)
0016ae30: 7fa80000  sq	t0,0(sp)
0016ae34: 0c05ab72  jal	0x16adc8
0016ae38: 03a0282d  move	a1,sp
0016ae3c: c60c089c  lwc1	$f12,2204(s0)
0016ae40: 0c05abae  jal	0x16aeb8
0016ae44: 0200202d  move	a0,s0
0016ae48: dfb00010  ld	s0,16(sp)
0016ae4c: dfbf0018  ld	ra,24(sp)
0016ae50: 03e00008  jr	ra
0016ae54: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016ae18(void)`

```c
void FUN_0016ae18(undefined8 param_1)

{
  int iVar1;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = (int)param_1;
  uStack_20 = *(undefined4 *)(iVar1 + 0x890);
  uStack_1c = *(undefined4 *)(iVar1 + 0x894);
  uStack_18 = *(undefined4 *)(iVar1 + 0x898);
  uStack_14 = *(undefined4 *)(iVar1 + 0x89c);
  FUN_0016adc8(param_1,&uStack_20);
  FUN_0016aeb8(*(undefined4 *)(iVar1 + 0x89c),param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
