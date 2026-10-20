# Target packet 0028b9b0

- Range: `0028b9b0`..`0028ba20`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028b9b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0028dfe8` registry: `func_0028dfe8`
  - accepted sources that already call it (copy their declaration): `fm_fallback_helpers.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028b9b0: 27bdffe0  addiu	sp,sp,-32
0028b9b4: 3c0f0034  lui	t7,0x34
0028b9b8: ffbf0010  sd	ra,16(sp)
0028b9bc: 2405003c  li	a1,60
0028b9c0: ffb00000  sd	s0,0(sp)
0028b9c4: ffb10008  sd	s1,8(sp)
0028b9c8: 0080802d  move	s0,a0
0028b9cc: 8dee7f80  lw	t6,32640(t7)   ; = D_00347f80
0028b9d0: 8dc40014  lw	a0,20(t6)
0028b9d4: 8c8f0000  lw	t7,0(a0)
0028b9d8: 8de20000  lw	v0,0(t7)
0028b9dc: 0040f809  jalr	v0
0028b9e0: 0000302d  move	a2,zero
0028b9e4: 0040882d  move	s1,v0
0028b9e8: 0c0a37fa  jal	0x28dfe8
0028b9ec: 0040202d  move	a0,v0
0028b9f0: ae110000  sw	s1,0(s0)
0028b9f4: ae000030  sw	zero,48(s0)
0028b9f8: ae000004  sw	zero,4(s0)
0028b9fc: ae000020  sw	zero,32(s0)
0028ba00: ae000024  sw	zero,36(s0)
0028ba04: ae000028  sw	zero,40(s0)
0028ba08: ae00002c  sw	zero,44(s0)
0028ba0c: dfb10008  ld	s1,8(sp)
0028ba10: dfb00000  ld	s0,0(sp)
0028ba14: dfbf0010  ld	ra,16(sp)
0028ba18: 03e00008  jr	ra
0028ba1c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028b9b0(void)`

```c
void FUN_0028b9b0(undefined4 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)**(undefined4 **)(DAT_00347f80 + 0x14))
                    (*(undefined4 **)(DAT_00347f80 + 0x14),0x3c,0);
  FUN_0028dfe8(uVar1);
  *param_1 = (int)uVar1;
  param_1[0xc] = 0;
  param_1[1] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
