# Target packet 001fbb20

- Range: `001fbb20`..`001fbb94`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_001fbb20`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001facf8` registry: `func_001facf8(void*)`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001fbb20: 27bdffe0  addiu	sp,sp,-32
001fbb24: ffb00000  sd	s0,0(sp)
001fbb28: ffb10008  sd	s1,8(sp)
001fbb2c: ffb20010  sd	s2,16(sp)
001fbb30: 0080802d  move	s0,a0
001fbb34: ffbf0018  sd	ra,24(sp)
001fbb38: 00a0882d  move	s1,a1
001fbb3c: 8cce000c  lw	t6,12(a2)
001fbb40: 8dcf0000  lw	t7,0(t6)
001fbb44: 008f7821  addu	t7,a0,t7
001fbb48: 0c07eb3e  jal	0x1facf8
001fbb4c: 25f200a0  addiu	s2,t7,160
001fbb50: 8e0e000c  lw	t6,12(s0)
001fbb54: 8e2f0000  lw	t7,0(s1)
001fbb58: 15ee0009  bne	t7,t6,0x1fbb80
001fbb5c: dfb00000  ld	s0,0(sp)
001fbb60: c620000c  lwc1	$f0,12(s1)
001fbb64: e6400020  swc1	$f0,32(s2)
001fbb68: 962f0010  lhu	t7,16(s1)
001fbb6c: 448f0000  mtc1	t7,$f0
001fbb70: 46800020  cvt.s.w	$f0,$f0
001fbb74: e6400028  swc1	$f0,40(s2)
001fbb78: 962f0012  lhu	t7,18(s1)
001fbb7c: a64f002c  sh	t7,44(s2)
001fbb80: dfb10008  ld	s1,8(sp)
001fbb84: dfb20010  ld	s2,16(sp)
001fbb88: dfbf0018  ld	ra,24(sp)
001fbb8c: 03e00008  jr	ra
001fbb90: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001fbb20(void)`

```c
void FUN_001fbb20(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_1 + **(int **)(param_3 + 0xc);
  FUN_001facf8();
  if (*param_2 == *(int *)(param_1 + 0xc)) {
    *(int *)(iVar1 + 0xc0) = param_2[3];
    *(float *)(iVar1 + 200) = (float)*(ushort *)(param_2 + 4);
    *(undefined2 *)(iVar1 + 0xcc) = *(undefined2 *)((int)param_2 + 0x12);
  }
  return;
}
```

## Earlier attempts (newest first)

- 20 differing words, 112/116 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.cpp`)
