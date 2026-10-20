# Target packet 0015cc80

- Range: `0015cc80`..`0015ccec`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015cc80`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015cc80: c481000c  lwc1	$f1,12(a0)
0015cc84: 44800000  mtc1	zero,$f0
0015cc88: 46000832  c.eq.s	$f1,$f0
0015cc8c: 45000012  bc1f	0x15ccd8
0015cc90: 3c0f0037  lui	t7,0x37
0015cc94: c4810010  lwc1	$f1,16(a0)
0015cc98: 25efb3f8  addiu	t7,t7,-19464   ; = D_0036b3f8
0015cc9c: c5e00000  lwc1	$f0,0(t7)
0015cca0: 46000832  c.eq.s	$f1,$f0
0015cca4: 4500000c  bc1f	0x15ccd8
0015cca8: 3c0e00ff  lui	t6,0xff
0015ccac: 8c8f0000  lw	t7,0(a0)
0015ccb0: 35ceffff  ori	t6,t6,0xffff
0015ccb4: 3c0d0080  lui	t5,0x80
0015ccb8: 01ee7824  and	t7,t7,t6
0015ccbc: 35ad8080  ori	t5,t5,0x8080
0015ccc0: 55ed0006  bnel	t7,t5,0x15ccdc
0015ccc4: 240e0001  li	t6,1
0015ccc8: 3c0f0034  lui	t7,0x34
0015cccc: 24020001  li	v0,1
0015ccd0: 03e00008  jr	ra
0015ccd4: a1e00eb0  sb	zero,3760(t7)   ; = D_00340eb0
0015ccd8: 240e0001  li	t6,1
0015ccdc: 3c0f0034  lui	t7,0x34
0015cce0: a1ee0eb0  sb	t6,3760(t7)   ; = D_00340eb0
0015cce4: 03e00008  jr	ra
0015cce8: 0000102d  move	v0,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015cc80(void)`

```c
undefined4 FUN_0015cc80(uint *param_1)

{
  if ((((float)param_1[3] == 0.0) && ((float)param_1[4] == DAT_0036b3f8)) &&
     ((undefined *)(*param_1 & 0xffffff) == &DAT_00808080)) {
    DAT_00340eb0 = 0;
    return 1;
  }
  DAT_00340eb0 = 1;
  return 0;
}
```

## Earlier attempts (newest first)

- none found
