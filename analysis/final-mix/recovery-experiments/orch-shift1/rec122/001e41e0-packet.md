# Target packet 001e41e0

- Range: `001e41e0`..`001e4248`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e41e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e3650` registry: `func_001e3650`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001e3660` registry: `_Z13func_001e3660ji`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001e3c98` registry: none
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001e3e48` registry: none
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001e4028` registry: none
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e41e0: 27bdfff0  addiu	sp,sp,-16
001e41e4: ffbf0008  sd	ra,8(sp)
001e41e8: ffb00000  sd	s0,0(sp)
001e41ec: 8c820088  lw	v0,136(a0)
001e41f0: 0080802d  move	s0,a0
001e41f4: 0c078d94  jal	0x1e3650
001e41f8: 0040202d  move	a0,v0
001e41fc: 0040202d  move	a0,v0
001e4200: 0c078d98  jal	0x1e3660
001e4204: 24050002  li	a1,2
001e4208: 8e05008c  lw	a1,140(s0)
001e420c: 0040202d  move	a0,v0
001e4210: 0c078f26  jal	0x1e3c98
001e4214: 24a500c0  addiu	a1,a1,192
001e4218: 8e05008c  lw	a1,140(s0)
001e421c: 0040202d  move	a0,v0
001e4220: 0c078f92  jal	0x1e3e48
001e4224: 24a500d0  addiu	a1,a1,208
001e4228: 8e05008c  lw	a1,140(s0)
001e422c: 0040202d  move	a0,v0
001e4230: 0c07900a  jal	0x1e4028
001e4234: 24a500e0  addiu	a1,a1,224
001e4238: dfb00000  ld	s0,0(sp)
001e423c: dfbf0008  ld	ra,8(sp)
001e4240: 03e00008  jr	ra
001e4244: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e41e0(void)`

```c
void FUN_001e41e0(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_001e3650(*(undefined4 *)(param_1 + 0x88));
  uVar1 = FUN_001e3660(uVar1,2);
  uVar1 = FUN_001e3c98(uVar1,*(int *)(param_1 + 0x8c) + 0xc0);
  uVar1 = FUN_001e3e48(uVar1,*(int *)(param_1 + 0x8c) + 0xd0);
  FUN_001e4028(uVar1,*(int *)(param_1 + 0x8c) + 0xe0);
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_08_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_08_1.cpp`)
