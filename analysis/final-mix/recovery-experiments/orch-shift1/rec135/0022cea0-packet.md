# Target packet 0022cea0

- Range: `0022cea0`..`0022cf18`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_0022cea0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001671e8` registry: `func_001671e8`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_oct7_flags_recovered.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `00167218` registry: `func_00167218`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`, `fm_primary_oneword_recovered_0022d1d8.cpp`
- `00227ca8` registry: `_ZN2sa5EVENT7get_intEPv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`, `fm_primary_oneword_recovered_0022d1d8.cpp`
- `002282f0` registry: `func_002282f0`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0022cea0: 27bdffe0  addiu	sp,sp,-32
0022cea4: ffb10008  sd	s1,8(sp)
0022cea8: ffb00000  sd	s0,0(sp)
0022ceac: ffbf0010  sd	ra,16(sp)
0022ceb0: 0080882d  move	s1,a0
0022ceb4: 0c08a0bc  jal	0x2282f0
0022ceb8: 84840004  lh	a0,4(a0)
0022cebc: 14400012  bnez	v0,0x22cf08
0022cec0: dfb00000  ld	s0,0(sp)
0022cec4: 922f0006  lbu	t7,6(s1)
0022cec8: 55e0000c  bnezl	t7,0x22cefc
0022cecc: dfb10008  ld	s1,8(sp)
0022ced0: 92300007  lbu	s0,7(s1)
0022ced4: 0c089f2a  jal	0x227ca8
0022ced8: 26240008  addiu	a0,s1,8
0022cedc: 2e100001  sltiu	s0,s0,1
0022cee0: 0200282d  move	a1,s0
0022cee4: dfb10008  ld	s1,8(sp)
0022cee8: dfb00000  ld	s0,0(sp)
0022ceec: 0040202d  move	a0,v0
0022cef0: dfbf0010  ld	ra,16(sp)
0022cef4: 08059c7a  j	0x1671e8
0022cef8: 27bd0020  addiu	sp,sp,32
0022cefc: dfbf0010  ld	ra,16(sp)
0022cf00: 08059c86  j	0x167218
0022cf04: 27bd0020  addiu	sp,sp,32
0022cf08: dfb10008  ld	s1,8(sp)
0022cf0c: dfbf0010  ld	ra,16(sp)
0022cf10: 03e00008  jr	ra
0022cf14: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0022cea0(void)`

```c
void FUN_0022cea0(int param_1)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = FUN_002282f0(*(undefined2 *)(param_1 + 4));
  if (lVar2 != 0) {
    return;
  }
  if (*(char *)(param_1 + 6) != '\0') {
    FUN_00167218();
    return;
  }
  cVar1 = *(char *)(param_1 + 7);
  uVar3 = FUN_00227ca8(param_1 + 8);
  FUN_001671e8(uVar3,cVar1 == '\0');
  return;
}
```

## Earlier attempts (newest first)

- 27 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_08_0.cpp`)
