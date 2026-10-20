# Target packet 001dc4e8

- Range: `001dc4e8`..`001dc540`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dc4e8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001dc018` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_storeorder_recovered_00281f90.cpp`, `fm_primary_width_recovered_02.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dc4e8: 27bdffe0  addiu	sp,sp,-32
001dc4ec: 00c0782d  move	t7,a2
001dc4f0: ffb10008  sd	s1,8(sp)
001dc4f4: 24860014  addiu	a2,a0,20
001dc4f8: ffb00000  sd	s0,0(sp)
001dc4fc: 00e0882d  move	s1,a3
001dc500: ffbf0010  sd	ra,16(sp)
001dc504: 24870018  addiu	a3,a0,24
001dc508: 0080802d  move	s0,a0
001dc50c: 00a0202d  move	a0,a1
001dc510: 0c077006  jal	0x1dc018
001dc514: 01e0282d  move	a1,t7
001dc518: 10400003  beqz	v0,0x1dc528
001dc51c: 0000782d  move	t7,zero
001dc520: ae110010  sw	s1,16(s0)
001dc524: 240f0001  li	t7,1
001dc528: dfb00000  ld	s0,0(sp)
001dc52c: 01e0102d  move	v0,t7
001dc530: dfb10008  ld	s1,8(sp)
001dc534: dfbf0010  ld	ra,16(sp)
001dc538: 03e00008  jr	ra
001dc53c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dc4e8(void)`

```c
bool FUN_001dc4e8(int param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = FUN_001dc018(param_2,param_3,param_1 + 0x14,param_1 + 0x18);
  if (lVar1 != 0) {
    *(undefined4 *)(param_1 + 0x10) = param_4;
  }
  return lVar1 != 0;
}
```

## Earlier attempts (newest first)

- 9 differing words, 84/88 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_01_all.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_01_all.cpp`)
