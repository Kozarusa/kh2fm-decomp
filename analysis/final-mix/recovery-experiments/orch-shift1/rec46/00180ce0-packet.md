# Target packet 00180ce0

- Range: `00180ce0`..`00180d40`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_00180ce0`
- Registry names for this address: `func_00180ce0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00180c38` registry: `_ZN2YS5VOICE4stopEv`
- `00180ef0` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00180ce0: 27bdfff0  addiu	sp,sp,-16
00180ce4: ffb00000  sd	s0,0(sp)
00180ce8: ffbf0008  sd	ra,8(sp)
00180cec: 8c8e0148  lw	t6,328(a0)
00180cf0: 11c00005  beqz	t6,0x180d08
00180cf4: 0080802d  move	s0,a0
00180cf8: 8dcf0000  lw	t7,0(t6)
00180cfc: 25efffff  addiu	t7,t7,-1
00180d00: adcf0000  sw	t7,0(t6)
00180d04: ac800148  sw	zero,328(a0)
00180d08: 0c06030e  jal	0x180c38
00180d0c: 00000000  nop
00180d10: 0c0603bc  jal	0x180ef0
00180d14: 0200202d  move	a0,s0
00180d18: 8e0f0194  lw	t7,404(s0)
00180d1c: 51e00005  beqzl	t7,0x180d34
00180d20: dfb00000  ld	s0,0(sp)
00180d24: 01e0f809  jalr	t7
00180d28: 8e040008  lw	a0,8(s0)
00180d2c: ae000194  sw	zero,404(s0)
00180d30: dfb00000  ld	s0,0(sp)
00180d34: dfbf0008  ld	ra,8(sp)
00180d38: 03e00008  jr	ra
00180d3c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00180ce0(void)`

```c
void FUN_00180ce0(undefined8 param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  piVar1 = *(int **)(iVar2 + 0x148);
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + -1;
    *(undefined4 *)(iVar2 + 0x148) = 0;
  }
  FUN_00180c38();
  FUN_00180ef0(param_1);
  if (*(code **)(iVar2 + 0x194) != (code *)0x0) {
    (**(code **)(iVar2 + 0x194))(*(undefined4 *)(iVar2 + 8));
    *(undefined4 *)(iVar2 + 0x194) = 0;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
