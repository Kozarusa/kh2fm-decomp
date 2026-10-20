# Target packet 0011ecc8

- Range: `0011ecc8`..`0011ed48`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0011ecc8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0011ecc8: 27bdfff0  addiu	sp,sp,-16
0011eccc: 00a0702d  move	t6,a1
0011ecd0: ffbf0000  sd	ra,0(sp)
0011ecd4: 8c850124  lw	a1,292(a0)
0011ecd8: 10a00013  beqz	a1,0x11ed28
0011ecdc: dfbf0000  ld	ra,0(sp)
0011ece0: 8caf0000  lw	t7,0(a1)
0011ece4: 55ee0014  bnel	t7,t6,0x11ed38
0011ece8: 8ca5000c  lw	a1,12(a1)
0011ecec: 8cae0008  lw	t6,8(a1)
0011ecf0: 11c0000f  beqz	t6,0x11ed30
0011ecf4: 8caf000c  lw	t7,12(a1)
0011ecf8: adcf000c  sw	t7,12(t6)
0011ecfc: 8cae000c  lw	t6,12(a1)
0011ed00: 51c00004  beqzl	t6,0x11ed14
0011ed04: 8c840010  lw	a0,16(a0)
0011ed08: 8caf0008  lw	t7,8(a1)
0011ed0c: adcf0008  sw	t7,8(t6)
0011ed10: 8c840010  lw	a0,16(a0)
0011ed14: 8c8e0000  lw	t6,0(a0)
0011ed18: 8dcf0004  lw	t7,4(t6)
0011ed1c: 01e0f809  jalr	t7
0011ed20: 00000000  nop
0011ed24: dfbf0000  ld	ra,0(sp)
0011ed28: 03e00008  jr	ra
0011ed2c: 27bd0010  addiu	sp,sp,16
0011ed30: 1000fff2  b	0x11ecfc
0011ed34: ac8f0124  sw	t7,292(a0)
0011ed38: 54a0ffea  bnezl	a1,0x11ece4
0011ed3c: 8caf0000  lw	t7,0(a1)
0011ed40: 1000fff9  b	0x11ed28
0011ed44: dfbf0000  ld	ra,0(sp)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0011ecc8(void)`

```c
void FUN_0011ecc8(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x124);
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    while (iVar2 != param_2) {
      piVar1 = (int *)piVar1[3];
      if (piVar1 == (int *)0x0) {
        return;
      }
      iVar2 = *piVar1;
    }
    if (piVar1[2] == 0) {
      *(int *)(param_1 + 0x124) = piVar1[3];
    }
    else {
      *(int *)(piVar1[2] + 0xc) = piVar1[3];
    }
    if (piVar1[3] == 0) {
      piVar1 = *(int **)(param_1 + 0x10);
    }
    else {
      *(int *)(piVar1[3] + 8) = piVar1[2];
      piVar1 = *(int **)(param_1 + 0x10);
    }
    (**(code **)(*piVar1 + 4))();
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
