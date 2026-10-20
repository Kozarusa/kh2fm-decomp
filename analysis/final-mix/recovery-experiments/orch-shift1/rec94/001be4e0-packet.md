# Target packet 001be4e0

- Range: `001be4e0`..`001be53c`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001be4e0`
- Registry names for this address: `_Z16wtarget_001be4e0jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bc730` registry: `func_001bc730`
  - accepted sources that already call it (copy their declaration): `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`, `fm_scalar_recovered_04.cpp`
- `001bd5b0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`, `fm_scalar_extra_recovered_12.cpp`
- `001bd618` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001be4e0: 27bdfff0  addiu	sp,sp,-16
001be4e4: 240f0074  li	t7,116
001be4e8: ffb00000  sd	s0,0(sp)
001be4ec: ffbf0008  sd	ra,8(sp)
001be4f0: 0080802d  move	s0,a0
001be4f4: 00af2018  mult	a0,a1,t7
001be4f8: 8e0e08c0  lw	t6,2240(s0)
001be4fc: ae050aa4  sw	a1,2724(s0)
001be500: 8dcf0000  lw	t7,0(t6)
001be504: 02042021  addu	a0,s0,a0
001be508: 24840024  addiu	a0,a0,36
001be50c: 0c06f1cc  jal	0x1bc730
001be510: 8de5006c  lw	a1,108(t7)
001be514: 0200202d  move	a0,s0
001be518: 0c06f586  jal	0x1bd618
001be51c: 0000282d  move	a1,zero
001be520: 8e050aa4  lw	a1,2724(s0)
001be524: 0200202d  move	a0,s0
001be528: dfbf0008  ld	ra,8(sp)
001be52c: 0000302d  move	a2,zero
001be530: dfb00000  ld	s0,0(sp)
001be534: 0806f56c  j	0x1bd5b0
001be538: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001be4e0(void)`

```c
void FUN_001be4e0(undefined8 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(int *)(iVar1 + 0xaa4) = param_2;
  FUN_001bc730(iVar1 + param_2 * 0x74 + 0x24,*(undefined4 *)(**(int **)(iVar1 + 0x8c0) + 0x6c));
  FUN_001bd618(param_1,0);
  FUN_001bd5b0(param_1,*(undefined4 *)(iVar1 + 0xaa4),0);
  return;
}
```

## Earlier attempts (newest first)

- 23 differing words, 96/92 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_00_all.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_00_all.cpp`)
