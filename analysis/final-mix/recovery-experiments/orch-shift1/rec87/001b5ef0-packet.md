# Target packet 001b5ef0

- Range: `001b5ef0`..`001b5f64`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b5ef0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102818` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`
- `001c8d80` registry: `_ZN2YS5MUTEX4lockEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`, `fm_primary_sixwordnext_recovered_001d7a50.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b5ef0: 27bdfff0  addiu	sp,sp,-16
001b5ef4: 3c0f0035  lui	t7,0x35
001b5ef8: ffb00000  sd	s0,0(sp)
001b5efc: 3c07001b  lui	a3,0x1b
001b5f00: ffbf0008  sd	ra,8(sp)
001b5f04: 24e75f68  addiu	a3,a3,24424   ; = D_001b5f68
001b5f08: 0080802d  move	s0,a0
001b5f0c: 24060002  li	a2,2
001b5f10: 8de41214  lw	a0,4628(t7)   ; = D_00351214
001b5f14: 24082000  li	t0,8192
001b5f18: 0c040a06  jal	0x102818
001b5f1c: 0000282d  move	a1,zero
001b5f20: 3c0f001b  lui	t7,0x1b
001b5f24: ac500004  sw	s0,4(v0)
001b5f28: 25ef5fe0  addiu	t7,t7,24544   ; = D_001b5fe0
001b5f2c: 3c040035  lui	a0,0x35
001b5f30: ac4f0030  sw	t7,48(v0)
001b5f34: 24050002  li	a1,2
001b5f38: 24841ec0  addiu	a0,a0,7872   ; = D_00351ec0
001b5f3c: 3c0f0035  lui	t7,0x35
001b5f40: 0c072360  jal	0x1c8d80
001b5f44: ade21180  sw	v0,4480(t7)   ; = D_00351180
001b5f48: 8e0f0108  lw	t7,264(s0)
001b5f4c: dfbf0008  ld	ra,8(sp)
001b5f50: 35ef0100  ori	t7,t7,0x100
001b5f54: ae0f0108  sw	t7,264(s0)
001b5f58: dfb00000  ld	s0,0(sp)
001b5f5c: 03e00008  jr	ra
001b5f60: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b5ef0(void)`

```c
void FUN_001b5ef0(int param_1)

{
  DAT_00351180 = FUN_00102818(DAT_00351214,0,2,0x1b5f68,0x2000);
  *(int *)(DAT_00351180 + 4) = param_1;
  *(code **)(DAT_00351180 + 0x30) = FUN_001b5fe0;
  FUN_001c8d80(0x351ec0,2);
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x100;
  return;
}
```

## Earlier attempts (newest first)

- none found
