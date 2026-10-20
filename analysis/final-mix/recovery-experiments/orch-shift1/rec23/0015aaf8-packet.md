# Target packet 0015aaf8

- Range: `0015aaf8`..`0015ab70`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015aaf8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00197920` registry: `_ZN2YS5EVENT6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`, `fm_primary_oneword_recovered_00253538.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015aaf8: 27bdfff0  addiu	sp,sp,-16
0015aafc: ffb00000  sd	s0,0(sp)
0015ab00: ffbf0008  sd	ra,8(sp)
0015ab04: 0c065e48  jal	0x197920
0015ab08: 0080802d  move	s0,a0
0015ab0c: 10400009  beqz	v0,0x15ab34
0015ab10: 0200202d  move	a0,s0
0015ab14: 8e0f0000  lw	t7,0(s0)
0015ab18: 8dee0014  lw	t6,20(t7)
0015ab1c: 01c0f809  jalr	t6
0015ab20: 00000000  nop
0015ab24: dfb00000  ld	s0,0(sp)
0015ab28: dfbf0008  ld	ra,8(sp)
0015ab2c: 03e00008  jr	ra
0015ab30: 27bd0010  addiu	sp,sp,16
0015ab34: c601001c  lwc1	$f1,28(s0)
0015ab38: 44800000  mtc1	zero,$f0
0015ab3c: 46000836  c.le.s	$f1,$f0
0015ab40: 45000007  bc1f	0x15ab60
0015ab44: 3c0f0035  lui	t7,0x35
0015ab48: 8e0e0000  lw	t6,0(s0)
0015ab4c: 8dcf0014  lw	t7,20(t6)
0015ab50: 01e0f809  jalr	t7
0015ab54: 0200202d  move	a0,s0
0015ab58: c601001c  lwc1	$f1,28(s0)
0015ab5c: 3c0f0035  lui	t7,0x35
0015ab60: c5e09e14  lwc1	$f0,-25068(t7)   ; = D_00349e14
0015ab64: 46000801  sub.s	$f0,$f1,$f0
0015ab68: 1000ffee  b	0x15ab24
0015ab6c: e600001c  swc1	$f0,28(s0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015aaf8(void)`

```c
void FUN_0015aaf8(undefined8 param_1)

{
  long lVar1;
  int *piVar2;
  float fVar3;
  
  lVar1 = FUN_00197920();
  piVar2 = (int *)param_1;
  if (lVar1 == 0) {
    fVar3 = (float)piVar2[7];
    if (fVar3 <= 0.0) {
      (**(code **)(*piVar2 + 0x14))(param_1);
      fVar3 = (float)piVar2[7];
    }
    piVar2[7] = (int)(fVar3 - DAT_00349e14);
  }
  else {
    (**(code **)(*piVar2 + 0x14))(param_1);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
