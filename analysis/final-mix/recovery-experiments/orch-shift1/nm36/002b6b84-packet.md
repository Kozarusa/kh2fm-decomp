# Target packet 002b6b84

- Range: `002b6b84`..`002b6bc4`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b6b84`
- Registry names for this address: `func_002b6b84(void*)`
- Queue: state `accepted`, queue `general`, attempts 1, priority 2

## Callees

- `002b6708` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_queuekappaprime_recovered_002b6b84.cpp`, `fm_primary_queuekappaprime_recovered_002b7f84.cpp`, `fm_primary_queuelambdaprime_recovered_002b6bc4.cpp`, `fm_primary_queuelambdaprime_recovered_002b6c04.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b6b84: 27bdffe0  addiu	sp,sp,-32
002b6b88: ffbe0010  sd	s8,16(sp)
002b6b8c: ffbf0018  sd	ra,24(sp)
002b6b90: 03a0f02d  move	s8,sp
002b6b94: afc40000  sw	a0,0(s8)
002b6b98: 24040002  li	a0,2
002b6b9c: 24050008  li	a1,8
002b6ba0: 0c0ad9c2  jal	0x2b6708
002b6ba4: 8fc60000  lw	a2,0(s8)
002b6ba8: 0040782d  move	t7,v0
002b6bac: 01e0102d  move	v0,t7
002b6bb0: 03c0e82d  move	sp,s8
002b6bb4: dfbe0010  ld	s8,16(sp)
002b6bb8: dfbf0018  ld	ra,24(sp)
002b6bbc: 03e00008  jr	ra
002b6bc0: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b6b84(void)`

```c
undefined8 FUN_002b6b84(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_002b6708(2,8,param_1);
  return uVar1;
}
```

## Earlier attempts (newest first)

- 15 differing words, 40/64 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_11_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_11_0.cpp`)
- EXACT: `analysis/final-mix/recovery-experiments/fm_primary_queuekappaprime_recovered_002b6b84.verification.json`
- EXACT: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_v4_argument_constant_dependencies_1.verification.json`
- 2 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_v4_argument_constant_dependencies_0.verification.json`
- 2 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_v3_frame_ABI_primitives_3.verification.json`
- 3 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_v3_frame_ABI_primitives_2.verification.json`
- 2 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_v3_frame_ABI_primitives_1.verification.json`
- 3 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_v3_frame_ABI_primitives_0.verification.json`
- 11 differing words, 56/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_v2_zero_allocation_frame_3.verification.json`
- 11 differing words, 56/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_v2_zero_allocation_frame_2.verification.json`
- 11 differing words, 56/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_v2_zero_allocation_frame_1.verification.json`
- 13 differing words, 56/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_v2_zero_allocation_frame_0.verification.json`
- 13 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_frame_pointer_control_3.verification.json`
- 13 differing words, 56/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_frame_pointer_control_2.verification.json`
- 13 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_002b6b84_frame_pointer_control_1.verification.json`
