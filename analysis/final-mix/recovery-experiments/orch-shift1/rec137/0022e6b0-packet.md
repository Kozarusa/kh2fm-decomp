# Target packet 0022e6b0

- Range: `0022e6b0`..`0022e724`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_0022e6b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001ba028` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0022e6b0: 27bdffe0  addiu	sp,sp,-32
0022e6b4: e7b40018  swc1	$f20,24(sp)
0022e6b8: ffb00000  sd	s0,0(sp)
0022e6bc: 46006506  mov.s	$f20,$f12
0022e6c0: ffb10008  sd	s1,8(sp)
0022e6c4: 0080802d  move	s0,a0
0022e6c8: ffbf0010  sd	ra,16(sp)
0022e6cc: 00a0882d  move	s1,a1
0022e6d0: 0c06e80a  jal	0x1ba028
0022e6d4: 00a0202d  move	a0,a1
0022e6d8: 240f0001  li	t7,1
0022e6dc: 120f000f  beq	s0,t7,0x22e71c
0022e6e0: 2a0e0002  slti	t6,s0,2
0022e6e4: 51c00009  beqzl	t6,0x22e70c
0022e6e8: 240f0002  li	t7,2
0022e6ec: 52000001  beqzl	s0,0x22e6f4
0022e6f0: e6340034  swc1	$f20,52(s1)
0022e6f4: dfb00000  ld	s0,0(sp)
0022e6f8: dfb10008  ld	s1,8(sp)
0022e6fc: dfbf0010  ld	ra,16(sp)
0022e700: c7b40018  lwc1	$f20,24(sp)
0022e704: 03e00008  jr	ra
0022e708: 27bd0020  addiu	sp,sp,32
0022e70c: 520ffff9  beql	s0,t7,0x22e6f4
0022e710: e6340030  swc1	$f20,48(s1)
0022e714: 1000fff8  b	0x22e6f8
0022e718: dfb00000  ld	s0,0(sp)
0022e71c: 1000fff5  b	0x22e6f4
0022e720: e6340038  swc1	$f20,56(s1)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0022e6b0(void)`

```c
void FUN_0022e6b0(undefined4 param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  
  FUN_001ba028(param_3);
  iVar1 = (int)param_3;
  if (param_2 == 1) {
    *(undefined4 *)(iVar1 + 0x38) = param_1;
  }
  else if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined4 *)(iVar1 + 0x34) = param_1;
    }
  }
  else if (param_2 == 2) {
    *(undefined4 *)(iVar1 + 0x30) = param_1;
  }
  return;
}
```

## Earlier attempts (newest first)

- 25 differing words, 120/116 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_09_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_09_0.cpp`)
