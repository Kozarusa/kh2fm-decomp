# Target packet 001b7f30

- Range: `001b7f30`..`001b7f88`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b7f30`
- Registry names for this address: `func_001b7f30`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00170c00` registry: `_ZN2YS10CACHE_BUFF7FixFreeEPv`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_queuetheta_recovered_00103748.cpp`, `fm_primary_workerbacklog_recovered_001053c0.cpp`
- `001b7f88` registry: `func_001b7f88`
  - accepted sources that already call it (copy their declaration): `fm_primary_workerbacklog_recovered_001b7f88.cpp`, `fm_primary_workerbacklog_recovered_001b81e8.cpp`, `fm_scalar_extra_recovered_00.cpp`, `fm_scalar_recovered_00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b7f30: 27bdfff0  addiu	sp,sp,-16
001b7f34: ffb00000  sd	s0,0(sp)
001b7f38: ffbf0008  sd	ra,8(sp)
001b7f3c: 8c8f0000  lw	t7,0(a0)
001b7f40: 11e0000a  beqz	t7,0x1b7f6c
001b7f44: 0080802d  move	s0,a0
001b7f48: 3c0f0035  lui	t7,0x35
001b7f4c: 240e0001  li	t6,1
001b7f50: 91ed11c3  lbu	t5,4547(t7)   ; = D_003511c3
001b7f54: 55ae0006  bnel	t5,t6,0x1b7f70
001b7f58: ae000000  sw	zero,0(s0)
001b7f5c: 0c06dfe2  jal	0x1b7f88
001b7f60: 00000000  nop
001b7f64: 0c05c300  jal	0x170c00
001b7f68: 8e040000  lw	a0,0(s0)
001b7f6c: ae000000  sw	zero,0(s0)
001b7f70: ae000008  sw	zero,8(s0)
001b7f74: ae000004  sw	zero,4(s0)
001b7f78: dfbf0008  ld	ra,8(sp)
001b7f7c: dfb00000  ld	s0,0(sp)
001b7f80: 03e00008  jr	ra
001b7f84: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b7f30(void)`

```c
void FUN_001b7f30(int *param_1)

{
  if (*param_1 != 0) {
    if (DAT_003511c3 != '\x01') {
      *param_1 = 0;
      goto LAB_001b7f70;
    }
    FUN_001b7f88();
    FUN_00170c00(*param_1);
  }
  *param_1 = 0;
LAB_001b7f70:
  param_1[2] = 0;
  param_1[1] = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
