# Target packet 0028ff68

- Range: `0028ff68`..`0028ffe8`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028ff68`
- Registry names for this address: `func_0028ff68`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028ff68: 27bdfff0  addiu	sp,sp,-16
0028ff6c: ffb00000  sd	s0,0(sp)
0028ff70: ffbf0008  sd	ra,8(sp)
0028ff74: 0080802d  move	s0,a0
0028ff78: 8c8f0000  lw	t7,0(a0)
0028ff7c: 11e0000a  beqz	t7,0x28ffa8
0028ff80: 01e0202d  move	a0,t7
0028ff84: 0c04e75e  jal	0x139d78
0028ff88: 00000000  nop
0028ff8c: 50400007  beqzl	v0,0x28ffac
0028ff90: 8e0f0004  lw	t7,4(s0)
0028ff94: 8e0f0000  lw	t7,0(s0)
0028ff98: 8dee0000  lw	t6,0(t7)
0028ff9c: 8dcd0014  lw	t5,20(t6)
0028ffa0: 01a0f809  jalr	t5
0028ffa4: 01e0202d  move	a0,t7
0028ffa8: 8e0f0004  lw	t7,4(s0)
0028ffac: 11e0000a  beqz	t7,0x28ffd8
0028ffb0: 01e0202d  move	a0,t7
0028ffb4: 0c04e75e  jal	0x139d78
0028ffb8: 00000000  nop
0028ffbc: 50400007  beqzl	v0,0x28ffdc
0028ffc0: dfb00000  ld	s0,0(sp)
0028ffc4: 8e0f0004  lw	t7,4(s0)
0028ffc8: 8dee0000  lw	t6,0(t7)
0028ffcc: 8dcd0014  lw	t5,20(t6)
0028ffd0: 01a0f809  jalr	t5
0028ffd4: 01e0202d  move	a0,t7
0028ffd8: dfb00000  ld	s0,0(sp)
0028ffdc: dfbf0008  ld	ra,8(sp)
0028ffe0: 03e00008  jr	ra
0028ffe4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028ff68(void)`

```c
void FUN_0028ff68(int *param_1)

{
  int iVar1;
  long lVar2;
  
  if (*param_1 != 0) {
    lVar2 = FUN_00139d78(*param_1);
    if (lVar2 == 0) {
      iVar1 = param_1[1];
      goto LAB_0028ffac;
    }
    (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1);
  }
  iVar1 = param_1[1];
LAB_0028ffac:
  if ((iVar1 != 0) && (lVar2 = FUN_00139d78(iVar1), lVar2 != 0)) {
    (**(code **)(*(int *)param_1[1] + 0x14))((int *)param_1[1]);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
