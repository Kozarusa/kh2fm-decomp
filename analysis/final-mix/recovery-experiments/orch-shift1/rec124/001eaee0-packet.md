# Target packet 001eaee0

- Range: `001eaee0`..`001eaf4c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001eaee0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002f4000` registry: `func_002f4000`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_queuedelta_recovered_002f4000.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001eaee0: 27bdffe0  addiu	sp,sp,-32
001eaee4: 8cce000c  lw	t6,12(a2)
001eaee8: ffb00000  sd	s0,0(sp)
001eaeec: ffb10008  sd	s1,8(sp)
001eaef0: ffbf0010  sd	ra,16(sp)
001eaef4: 0080802d  move	s0,a0
001eaef8: 3c1101da  lui	s1,0x1da
001eaefc: 8dcf0000  lw	t7,0(t6)
001eaf00: 8e24e6e8  lw	a0,-6424(s1)   ; = D_01d9e6e8
001eaf04: 020f8021  addu	s0,s0,t7
001eaf08: 0c0bd000  jal	0x2f4000
001eaf0c: 24840010  addiu	a0,a0,16
001eaf10: c60000a0  lwc1	$f0,160(s0)
001eaf14: 260d00a0  addiu	t5,s0,160
001eaf18: 8e2fe6e8  lw	t7,-6424(s1)   ; = D_01d9e6e8
001eaf1c: dfb00000  ld	s0,0(sp)
001eaf20: e5e00040  swc1	$f0,64(t7)
001eaf24: dfbf0010  ld	ra,16(sp)
001eaf28: 8e2ee6e8  lw	t6,-6424(s1)   ; = D_01d9e6e8
001eaf2c: c5a00004  lwc1	$f0,4(t5)
001eaf30: e5c00044  swc1	$f0,68(t6)
001eaf34: 8e2fe6e8  lw	t7,-6424(s1)   ; = D_01d9e6e8
001eaf38: c5a00008  lwc1	$f0,8(t5)
001eaf3c: dfb10008  ld	s1,8(sp)
001eaf40: e5e00048  swc1	$f0,72(t7)
001eaf44: 03e00008  jr	ra
001eaf48: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001eaee0(void)`

```c
void FUN_001eaee0(int param_1,undefined8 param_2,int param_3)

{
  param_1 = param_1 + **(int **)(param_3 + 0xc);
  FUN_002f4000(DAT_01d9e6e8 + 0x10);
  *(undefined4 *)(DAT_01d9e6e8 + 0x40) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(DAT_01d9e6e8 + 0x44) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(DAT_01d9e6e8 + 0x48) = *(undefined4 *)(param_1 + 0xa8);
  return;
}
```

## Earlier attempts (newest first)

- none found
