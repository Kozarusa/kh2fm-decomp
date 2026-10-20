# Target packet 001e0de8

- Range: `001e0de8`..`001e0e3c`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e0de8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e0cc8` registry: `func_001e0cc8`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001e0ce8` registry: `func_001e0ce8`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e0de8: 27bdfff0  addiu	sp,sp,-16
001e0dec: ffb00000  sd	s0,0(sp)
001e0df0: ffbf0008  sd	ra,8(sp)
001e0df4: 0c078332  jal	0x1e0cc8
001e0df8: 0080802d  move	s0,a0
001e0dfc: 52020004  beql	s0,v0,0x1e0e10
001e0e00: ae00000c  sw	zero,12(s0)
001e0e04: 78480000  lq	t0,0(v0)
001e0e08: 7e080000  sq	t0,0(s0)
001e0e0c: ae00000c  sw	zero,12(s0)
001e0e10: 0200202d  move	a0,s0
001e0e14: 0c07833a  jal	0x1e0ce8
001e0e18: 26100010  addiu	s0,s0,16
001e0e1c: 52020004  beql	s0,v0,0x1e0e30
001e0e20: dfb00000  ld	s0,0(sp)
001e0e24: 78480000  lq	t0,0(v0)
001e0e28: 7e080000  sq	t0,0(s0)
001e0e2c: dfb00000  ld	s0,0(sp)
001e0e30: dfbf0008  ld	ra,8(sp)
001e0e34: 03e00008  jr	ra
001e0e38: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e0de8(void)`

```c
void FUN_001e0de8(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  lVar2 = FUN_001e0cc8();
  puVar1 = (undefined4 *)lVar2;
  puVar6 = (undefined4 *)param_1;
  if (param_1 == lVar2) {
    puVar6[3] = 0;
  }
  else {
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    *puVar6 = *puVar1;
    puVar6[1] = uVar3;
    puVar6[2] = uVar4;
    puVar6[3] = uVar5;
    puVar6[3] = 0;
  }
  puVar1 = (undefined4 *)FUN_001e0ce8(param_1);
  if (puVar6 + 4 != puVar1) {
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    puVar6[4] = *puVar1;
    puVar6[5] = uVar3;
    puVar6[6] = uVar4;
    puVar6[7] = uVar5;
  }
  return;
}
```

## Earlier attempts (newest first)

- 25 differing words, 124/84 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_08_0.cpp`)
