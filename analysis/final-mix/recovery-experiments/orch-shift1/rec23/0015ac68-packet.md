# Target packet 0015ac68

- Range: `0015ac68`..`0015acdc`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015ac68`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00138840` registry: `func_00138840(void*)`
- `00197920` registry: `_ZN2YS5EVENT6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`, `fm_primary_oneword_recovered_00253538.cpp`
- `001ad938` registry: `_ZN2YS22WINDOW_SYSTEM_TUTORIAL6IsOpenEv`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015ac68: 27bdfff0  addiu	sp,sp,-16
0015ac6c: ffb00000  sd	s0,0(sp)
0015ac70: ffbf0008  sd	ra,8(sp)
0015ac74: 0c065e48  jal	0x197920
0015ac78: 0080802d  move	s0,a0
0015ac7c: 5440000c  bnezl	v0,0x15acb0
0015ac80: 8e0e0000  lw	t6,0(s0)
0015ac84: 0c06b64e  jal	0x1ad938
0015ac88: 00000000  nop
0015ac8c: 54400008  bnezl	v0,0x15acb0
0015ac90: 8e0e0000  lw	t6,0(s0)
0015ac94: 3c0e0035  lui	t6,0x35
0015ac98: 8dcff240  lw	t7,-3520(t6)   ; = D_0034f240
0015ac9c: 31ef0001  andi	t7,t7,0x1
0015aca0: 31ef00ff  andi	t7,t7,0xff
0015aca4: 11e00009  beqz	t7,0x15accc
0015aca8: 0200202d  move	a0,s0
0015acac: 8e0e0000  lw	t6,0(s0)
0015acb0: 8dcf0014  lw	t7,20(t6)
0015acb4: 01e0f809  jalr	t7
0015acb8: 0200202d  move	a0,s0
0015acbc: dfb00000  ld	s0,0(sp)
0015acc0: dfbf0008  ld	ra,8(sp)
0015acc4: 03e00008  jr	ra
0015acc8: 27bd0010  addiu	sp,sp,16
0015accc: dfbf0008  ld	ra,8(sp)
0015acd0: dfb00000  ld	s0,0(sp)
0015acd4: 0804e210  j	0x138840
0015acd8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015ac68(void)`

```c
void FUN_0015ac68(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  
  lVar1 = FUN_00197920();
  piVar3 = (int *)param_1;
  if (lVar1 == 0) {
    lVar1 = FUN_001ad938();
    if (lVar1 == 0) {
      if ((DAT_0034f240 & 1) == 0) {
        FUN_00138840(param_1);
        return;
      }
      iVar2 = *piVar3;
    }
    else {
      iVar2 = *piVar3;
    }
  }
  else {
    iVar2 = *piVar3;
  }
  (**(code **)(iVar2 + 0x14))(param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
