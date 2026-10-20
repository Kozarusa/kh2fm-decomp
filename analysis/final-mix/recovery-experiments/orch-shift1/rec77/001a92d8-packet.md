# Target packet 001a92d8

- Range: `001a92d8`..`001a9350`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a92d8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016e920` registry: `Tz::JmInfo::GetCharaData(unsigned int)`
  - accepted sources that already call it (copy their declaration): `fm_fallback_helpers.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`
- `00170e58` registry: `_ZN2YS10CACHE_BUFF4DumpEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_loadorder_recovered.cpp`
- `001a9218` registry: `func_001a9218`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`
- `001a9350` registry: `_ZN2YS7OBJDATA4freeEv`
  - accepted sources that already call it (copy their declaration): `fm_more_recovered.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`
- `001a9758` registry: `_ZN2YS7OBJDATA8CanAllocEjPKNS_8OBJENTRYE`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a92d8: 27bdffe0  addiu	sp,sp,-32
001a92dc: ffb00000  sd	s0,0(sp)
001a92e0: ffb10008  sd	s1,8(sp)
001a92e4: ffb20010  sd	s2,16(sp)
001a92e8: 00a0802d  move	s0,a1
001a92ec: ffbf0018  sd	ra,24(sp)
001a92f0: 0080882d  move	s1,a0
001a92f4: 0c06a4d4  jal	0x1a9350
001a92f8: 00c0902d  move	s2,a2
001a92fc: 16400004  bnez	s2,0x1a9310
001a9300: 0200202d  move	a0,s0
001a9304: 0c05ba48  jal	0x16e920
001a9308: 00000000  nop
001a930c: 0040902d  move	s2,v0
001a9310: 0200202d  move	a0,s0
001a9314: 0c06a5d6  jal	0x1a9758
001a9318: 0240282d  move	a1,s2
001a931c: 54400004  bnezl	v0,0x1a9330
001a9320: ae300004  sw	s0,4(s1)
001a9324: 0c05c396  jal	0x170e58
001a9328: 00000000  nop
001a932c: ae300004  sw	s0,4(s1)
001a9330: 0220202d  move	a0,s1
001a9334: ae320008  sw	s2,8(s1)
001a9338: dfb00000  ld	s0,0(sp)
001a933c: dfb10008  ld	s1,8(sp)
001a9340: dfb20010  ld	s2,16(sp)
001a9344: dfbf0018  ld	ra,24(sp)
001a9348: 0806a486  j	0x1a9218
001a934c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a92d8(void)`

```c
void FUN_001a92d8(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  
  FUN_001a9350();
  if (param_3 == 0) {
    param_3 = FUN_0016e920(param_2);
  }
  lVar1 = FUN_001a9758(param_2,param_3);
  iVar2 = (int)param_1;
  if (lVar1 == 0) {
    FUN_00170e58();
    *(int *)(iVar2 + 4) = (int)param_2;
  }
  else {
    *(int *)(iVar2 + 4) = (int)param_2;
  }
  *(int *)(iVar2 + 8) = (int)param_3;
  FUN_001a9218(param_1);
  return;
}
```

## Earlier attempts (newest first)

- 9 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.cpp`)
