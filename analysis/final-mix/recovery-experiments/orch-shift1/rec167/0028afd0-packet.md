# Target packet 0028afd0

- Range: `0028afd0`..`0028b038`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028afd0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00289b30` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_threeword_recovered_0026dcb8.cpp`
- `0028b1c0` registry: `func_0028b1c0`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_queuelambda_recovered_0028b1c0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028afd0: 27bdfff0  addiu	sp,sp,-16
0028afd4: 00a0782d  move	t7,a1
0028afd8: ffb00000  sd	s0,0(sp)
0028afdc: 00052c00  sll	a1,a1,0x10
0028afe0: ffbf0008  sd	ra,8(sp)
0028afe4: 00052c03  sra	a1,a1,0x10
0028afe8: a48f0012  sh	t7,18(a0)
0028afec: 0080802d  move	s0,a0
0028aff0: 848d0000  lh	t5,0(a0)
0028aff4: 908e0025  lbu	t6,37(a0)
0028aff8: 15c0000b  bnez	t6,0x28b028
0028affc: 00ad2821  addu	a1,a1,t5
0028b000: 0c0a2c70  jal	0x28b1c0
0028b004: 00000000  nop
0028b008: 0200202d  move	a0,s0
0028b00c: 26060012  addiu	a2,s0,18
0028b010: 10400005  beqz	v0,0x28b028
0028b014: 0200282d  move	a1,s0
0028b018: dfb00000  ld	s0,0(sp)
0028b01c: dfbf0008  ld	ra,8(sp)
0028b020: 080a26cc  j	0x289b30
0028b024: 27bd0010  addiu	sp,sp,16
0028b028: dfb00000  ld	s0,0(sp)
0028b02c: dfbf0008  ld	ra,8(sp)
0028b030: 03e00008  jr	ra
0028b034: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028afd0(void)`

```c
void FUN_0028afd0(undefined8 param_1,short param_2)

{
  long lVar1;
  short *psVar2;
  
  psVar2 = (short *)param_1;
  psVar2[9] = param_2;
  if (*(char *)((int)psVar2 + 0x25) == '\0') {
    lVar1 = FUN_0028b1c0(param_1,(int)param_2 + (int)*psVar2);
    if (lVar1 != 0) {
      FUN_00289b30(param_1,param_1,psVar2 + 9);
      return;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 13 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_parameters_10_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_parameters_10_0.cpp`)
