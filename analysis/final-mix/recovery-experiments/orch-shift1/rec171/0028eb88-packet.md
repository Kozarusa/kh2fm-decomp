# Target packet 0028eb88

- Range: `0028eb88`..`0028ebf0`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028eb88`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028eb88: 27bdffe0  addiu	sp,sp,-32
0028eb8c: e7b5001c  swc1	$f21,28(sp)
0028eb90: e7b40018  swc1	$f20,24(sp)
0028eb94: 46006d46  mov.s	$f21,$f13
0028eb98: ffb00000  sd	s0,0(sp)
0028eb9c: 46006506  mov.s	$f20,$f12
0028eba0: ffb10008  sd	s1,8(sp)
0028eba4: ffbf0010  sd	ra,16(sp)
0028eba8: 00a0802d  move	s0,a1
0028ebac: 0c04e75e  jal	0x139d78
0028ebb0: 0080882d  move	s1,a0
0028ebb4: 240e017c  li	t6,380
0028ebb8: 8e2f0038  lw	t7,56(s1)
0028ebbc: 020e8018  mult	s0,s0,t6
0028ebc0: dfbf0010  ld	ra,16(sp)
0028ebc4: 020f7821  addu	t7,s0,t7
0028ebc8: e5f40170  swc1	$f20,368(t7)
0028ebcc: 8e2e0038  lw	t6,56(s1)
0028ebd0: c7b40018  lwc1	$f20,24(sp)
0028ebd4: 020e8021  addu	s0,s0,t6
0028ebd8: dfb10008  ld	s1,8(sp)
0028ebdc: e6150174  swc1	$f21,372(s0)
0028ebe0: dfb00000  ld	s0,0(sp)
0028ebe4: c7b5001c  lwc1	$f21,28(sp)
0028ebe8: 03e00008  jr	ra
0028ebec: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028eb88(void)`

```c
void FUN_0028eb88(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  FUN_00139d78();
  *(undefined4 *)(param_4 * 0x17c + *(int *)(param_3 + 0x38) + 0x170) = param_1;
  *(undefined4 *)(param_4 * 0x17c + *(int *)(param_3 + 0x38) + 0x174) = param_2;
  return;
}
```

## Earlier attempts (newest first)

- 16 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_10_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_10_0.cpp`)
