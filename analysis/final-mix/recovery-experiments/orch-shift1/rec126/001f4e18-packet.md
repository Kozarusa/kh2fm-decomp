# Target packet 001f4e18

- Range: `001f4e18`..`001f4e78`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_001f4e18`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002223e0` registry: `func_002223e0`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001f4e18: 27bdffe0  addiu	sp,sp,-32
001f4e1c: 8caf000c  lw	t7,12(a1)
001f4e20: ffb00000  sd	s0,0(sp)
001f4e24: ffb10008  sd	s1,8(sp)
001f4e28: ffbf0010  sd	ra,16(sp)
001f4e2c: 8dee0000  lw	t6,0(t7)
001f4e30: 008e8021  addu	s0,a0,t6
001f4e34: 261100a0  addiu	s1,s0,160
001f4e38: 0220202d  move	a0,s1
001f4e3c: 0c0888f8  jal	0x2223e0
001f4e40: 261000b0  addiu	s0,s0,176
001f4e44: ae20006c  sw	zero,108(s1)
001f4e48: fe200070  sd	zero,112(s1)
001f4e4c: fe200078  sd	zero,120(s1)
001f4e50: fe200080  sd	zero,128(s1)
001f4e54: fe200088  sd	zero,136(s1)
001f4e58: dfbf0010  ld	ra,16(sp)
001f4e5c: ae00002c  sw	zero,44(s0)
001f4e60: ae00000c  sw	zero,12(s0)
001f4e64: ae000024  sw	zero,36(s0)
001f4e68: dfb10008  ld	s1,8(sp)
001f4e6c: dfb00000  ld	s0,0(sp)
001f4e70: 03e00008  jr	ra
001f4e74: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001f4e18(void)`

```c
void FUN_001f4e18(int param_1,int param_2)

{
  param_1 = param_1 + **(int **)(param_2 + 0xc);
  FUN_002223e0(param_1 + 0xa0);
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined8 *)(param_1 + 0x110) = 0;
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(param_1 + 0x120) = 0;
  *(undefined8 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  return;
}
```

## Earlier attempts (newest first)

- 24 differing words, 80/96 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.cpp`)
