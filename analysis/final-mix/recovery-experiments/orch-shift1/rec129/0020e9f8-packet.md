# Target packet 0020e9f8

- Range: `0020e9f8`..`0020ea44`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_0020e9f8`
- Registry names for this address: `_Z16wtarget_0020e9f8jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0020e9f8: 3c0d0037  lui	t5,0x37
0020e9fc: 3c0f0036  lui	t7,0x36
0020ea00: 25ad07c0  addiu	t5,t5,1984   ; = D_003707c0
0020ea04: 25ee9110  addiu	t6,t7,-28400   ; = D_00359110
0020ea08: c5a10000  lwc1	$f1,0(t5)
0020ea0c: 46016842  mul.s	$f1,$f13,$f1
0020ea10: 3c0d0037  lui	t5,0x37
0020ea14: 25ad07c4  addiu	t5,t5,1988   ; = D_003707c4
0020ea18: c5a00000  lwc1	$f0,0(t5)
0020ea1c: 460c6b41  sub.s	$f13,$f13,$f12
0020ea20: 00000000  nop
0020ea24: 00000000  nop
0020ea28: 460d0843  div.s	$f1,$f1,$f13
0020ea2c: 00000000  nop
0020ea30: 00000000  nop
0020ea34: 460d0003  div.s	$f0,$f0,$f13
0020ea38: e5c10004  swc1	$f1,4(t6)
0020ea3c: 03e00008  jr	ra
0020ea40: e5e09110  swc1	$f0,-28400(t7)   ; = D_00359110
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0020e9f8(void)`

```c
void FUN_0020e9f8(float param_1,float param_2)

{
  DAT_00359114 = (param_2 * DAT_003707c0) / (param_2 - param_1);
  DAT_00359110 = DAT_003707c4 / (param_2 - param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
