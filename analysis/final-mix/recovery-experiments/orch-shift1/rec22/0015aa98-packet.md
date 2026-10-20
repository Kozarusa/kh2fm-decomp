# Target packet 0015aa98

- Range: `0015aa98`..`0015aaf4`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015aa98`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001391c8` registry: `_ZN2dk5Obj2D6createEii`
  - accepted sources that already call it (copy their declaration): `fm_more_recovered.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015aa98: 27bdffd0  addiu	sp,sp,-48
0015aa9c: e7b40020  swc1	$f20,32(sp)
0015aaa0: ffb10008  sd	s1,8(sp)
0015aaa4: 46006506  mov.s	$f20,$f12
0015aaa8: ffb20010  sd	s2,16(sp)
0015aaac: ffb00000  sd	s0,0(sp)
0015aab0: 00c0882d  move	s1,a2
0015aab4: ffbf0018  sd	ra,24(sp)
0015aab8: 00a0902d  move	s2,a1
0015aabc: 0080802d  move	s0,a0
0015aac0: 24052af8  li	a1,11000
0015aac4: 0c04e472  jal	0x1391c8
0015aac8: 0000302d  move	a2,zero
0015aacc: ae110020  sw	s1,32(s0)
0015aad0: ae120018  sw	s2,24(s0)
0015aad4: e614001c  swc1	$f20,28(s0)
0015aad8: dfb10008  ld	s1,8(sp)
0015aadc: dfb00000  ld	s0,0(sp)
0015aae0: dfb20010  ld	s2,16(sp)
0015aae4: dfbf0018  ld	ra,24(sp)
0015aae8: c7b40020  lwc1	$f20,32(sp)
0015aaec: 03e00008  jr	ra
0015aaf0: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015aa98(void)`

```c
void FUN_0015aa98(undefined4 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_001391c8(param_2,11000,0);
  iVar1 = (int)param_2;
  *(undefined4 *)(iVar1 + 0x20) = param_4;
  *(undefined4 *)(iVar1 + 0x18) = param_3;
  *(undefined4 *)(iVar1 + 0x1c) = param_1;
  return;
}
```

## Earlier attempts (newest first)

- none found
