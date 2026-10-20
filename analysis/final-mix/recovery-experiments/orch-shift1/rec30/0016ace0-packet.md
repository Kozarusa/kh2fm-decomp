# Target packet 0016ace0

- Range: `0016ace0`..`0016ad38`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016ace0`
- Registry names for this address: `_ZN2YS3OBJ7set_posERKN2kn7FVectorE`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00193608` registry: none
- `001ba028` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016ace0: 27bdffe0  addiu	sp,sp,-32
0016ace4: ffb00000  sd	s0,0(sp)
0016ace8: ffb10008  sd	s1,8(sp)
0016acec: ffbf0010  sd	ra,16(sp)
0016acf0: 00a0802d  move	s0,a1
0016acf4: 0c06e80a  jal	0x1ba028
0016acf8: 0080882d  move	s1,a0
0016acfc: 262f0540  addiu	t7,s1,1344
0016ad00: 51f00004  beql	t7,s0,0x16ad14
0016ad04: 3c0f0037  lui	t7,0x37
0016ad08: 7a080000  lq	t0,0(s0)
0016ad0c: 7de80000  sq	t0,0(t7)   ; = D_00370000
0016ad10: 3c0f0037  lui	t7,0x37
0016ad14: dfb00000  ld	s0,0(sp)
0016ad18: 25efc1b4  addiu	t7,t7,-15948   ; = D_0036c1b4
0016ad1c: dfbf0010  ld	ra,16(sp)
0016ad20: c5e00000  lwc1	$f0,0(t7)
0016ad24: 0220202d  move	a0,s1
0016ad28: e620054c  swc1	$f0,1356(s1)
0016ad2c: dfb10008  ld	s1,8(sp)
0016ad30: 08064d82  j	0x193608
0016ad34: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016ace0(void)`

```c
void FUN_0016ace0(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  FUN_001ba028();
  iVar4 = (int)param_1;
  if ((undefined4 *)(iVar4 + 0x540) != param_2) {
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *(undefined4 *)(iVar4 + 0x540) = *param_2;
    *(undefined4 *)(iVar4 + 0x544) = uVar1;
    *(undefined4 *)(iVar4 + 0x548) = uVar2;
    *(undefined4 *)(iVar4 + 0x54c) = uVar3;
  }
  *(undefined4 *)(iVar4 + 0x54c) = DAT_0036c1b4;
  FUN_00193608(param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
