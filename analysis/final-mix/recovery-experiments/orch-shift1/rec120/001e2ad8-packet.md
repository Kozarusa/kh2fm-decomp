# Target packet 001e2ad8

- Range: `001e2ad8`..`001e2b4c`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e2ad8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002fdfc8` registry: `func_002fdfc8`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e2ad8: 27bdffe0  addiu	sp,sp,-32
001e2adc: 0080782d  move	t7,a0
001e2ae0: ffb10008  sd	s1,8(sp)
001e2ae4: 3c040037  lui	a0,0x37
001e2ae8: ffb00000  sd	s0,0(sp)
001e2aec: 2484e978  addiu	a0,a0,-5768   ; = D_0036e978
001e2af0: ffb20010  sd	s2,16(sp)
001e2af4: 00a0882d  move	s1,a1
001e2af8: ffbf0018  sd	ra,24(sp)
001e2afc: 01e0282d  move	a1,t7
001e2b00: 00e0902d  move	s2,a3
001e2b04: 0c0bf7f2  jal	0x2fdfc8
001e2b08: 00c0802d  move	s0,a2
001e2b0c: 3c040037  lui	a0,0x37
001e2b10: 0220282d  move	a1,s1
001e2b14: 0200302d  move	a2,s0
001e2b18: 0c0bf7f2  jal	0x2fdfc8
001e2b1c: 2484e998  addiu	a0,a0,-5736   ; = D_0036e998
001e2b20: 3c040037  lui	a0,0x37
001e2b24: 0240282d  move	a1,s2
001e2b28: 0c0bf7f2  jal	0x2fdfc8
001e2b2c: 2484e9b0  addiu	a0,a0,-5712   ; = D_0036e9b0
001e2b30: 0000000d  break
001e2b34: dfb00000  ld	s0,0(sp)
001e2b38: dfb10008  ld	s1,8(sp)
001e2b3c: dfb20010  ld	s2,16(sp)
001e2b40: dfbf0018  ld	ra,24(sp)
001e2b44: 03e00008  jr	ra
001e2b48: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e2ad8(void)`

```c
void FUN_001e2ad8(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_002fdfc8(0x36e978,param_1);
  FUN_002fdfc8(0x36e998,param_2,param_3);
  FUN_002fdfc8(0x36e9b0,param_4);
  trap(0);
  return;
}
```

## Earlier attempts (newest first)

- none found
