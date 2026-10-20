# Target packet 0017de70

- Range: `0017de70`..`0017debc`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_0017de70`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0017de70: 27bdfff0  addiu	sp,sp,-16
0017de74: 3c0f0035  lui	t7,0x35
0017de78: ffbf0000  sd	ra,0(sp)
0017de7c: 0000302d  move	a2,zero
0017de80: 0000382d  move	a3,zero
0017de84: 8c8e048c  lw	t6,1164(a0)
0017de88: 8ded2130  lw	t5,8496(t7)   ; = D_00352130
0017de8c: c5c00004  lwc1	$f0,4(t6)
0017de90: c5a10058  lwc1	$f1,88(t5)
0017de94: 46800020  cvt.s.w	$f0,$f0
0017de98: 8c8f0000  lw	t7,0(a0)
0017de9c: 8de20078  lw	v0,120(t7)
0017dea0: 46010002  mul.s	$f0,$f0,$f1
0017dea4: 46000064  cvt.w.s	$f1,$f0
0017dea8: 0040f809  jalr	v0
0017deac: 44050800  mfc1	a1,$f1
0017deb0: dfbf0000  ld	ra,0(sp)
0017deb4: 03e00008  jr	ra
0017deb8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0017de70(void)`

```c
void FUN_0017de70(int *param_1)

{
  (**(code **)(*param_1 + 0x78))
            (param_1,(int)((float)*(int *)(param_1[0x123] + 4) * *(float *)(DAT_00352130 + 0x58)),0,
             0);
  return;
}
```

## Earlier attempts (newest first)

- none found
