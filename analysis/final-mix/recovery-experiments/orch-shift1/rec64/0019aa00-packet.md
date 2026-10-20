# Target packet 0019aa00

- Range: `0019aa00`..`0019aa60`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019aa00`
- Registry names for this address: `func_0019aa00`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0019a9e0` registry: `func_0019a9e0`
  - accepted sources that already call it (copy their declaration): `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`, `fm_primary_sixword_recovered_0018f2a8.cpp`, `fm_primary_sixword_recovered_0018f2d0.cpp`
- `0019ab80` registry: `func_0019ab80`
  - accepted sources that already call it (copy their declaration): `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`, `fm_primary_sixword_recovered_0018f2a8.cpp`, `fm_primary_sixword_recovered_0018f2d0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019aa00: 27bdfff0  addiu	sp,sp,-16
0019aa04: ffb00000  sd	s0,0(sp)
0019aa08: ffbf0008  sd	ra,8(sp)
0019aa0c: 8c8f0004  lw	t7,4(a0)
0019aa10: 31ef0001  andi	t7,t7,0x1
0019aa14: 31ef00ff  andi	t7,t7,0xff
0019aa18: 15e0000d  bnez	t7,0x19aa50
0019aa1c: 0080802d  move	s0,a0
0019aa20: 8caf0588  lw	t7,1416(a1)
0019aa24: 31ef0800  andi	t7,t7,0x800
0019aa28: 51e0000a  beqzl	t7,0x19aa54
0019aa2c: dfb00000  ld	s0,0(sp)
0019aa30: 0c066a78  jal	0x19a9e0
0019aa34: 00000000  nop
0019aa38: 14400005  bnez	v0,0x19aa50
0019aa3c: 0200202d  move	a0,s0
0019aa40: dfb00000  ld	s0,0(sp)
0019aa44: dfbf0008  ld	ra,8(sp)
0019aa48: 08066ae0  j	0x19ab80
0019aa4c: 27bd0010  addiu	sp,sp,16
0019aa50: dfb00000  ld	s0,0(sp)
0019aa54: dfbf0008  ld	ra,8(sp)
0019aa58: 03e00008  jr	ra
0019aa5c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019aa00(void)`

```c
void FUN_0019aa00(undefined8 param_1,int param_2)

{
  long lVar1;
  
  if ((((*(uint *)((int)param_1 + 4) & 1) == 0) && ((*(uint *)(param_2 + 0x588) & 0x800) != 0)) &&
     (lVar1 = FUN_0019a9e0(), lVar1 == 0)) {
    FUN_0019ab80(param_1);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- 9 differing words, 96/96 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_parameters_04_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_parameters_04_0.cpp`)
