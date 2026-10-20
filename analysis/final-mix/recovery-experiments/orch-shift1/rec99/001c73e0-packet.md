# Target packet 001c73e0

- Range: `001c73e0`..`001c741c`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c73e0`
- Registry names for this address: `_Z16u_call4_001c73e0jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c71f8` registry: none
- `001c7440` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c73e0: 27bdfff0  addiu	sp,sp,-16
001c73e4: 3c0f0037  lui	t7,0x37
001c73e8: 25efdfa8  addiu	t7,t7,-8280   ; = D_0036dfa8
001c73ec: ffb00000  sd	s0,0(sp)
001c73f0: ffbf0008  sd	ra,8(sp)
001c73f4: c5ec0000  lwc1	$f12,0(t7)
001c73f8: 0c071c7e  jal	0x1c71f8
001c73fc: 0080802d  move	s0,a0
001c7400: 0200202d  move	a0,s0
001c7404: 0c071d10  jal	0x1c7440
001c7408: 0000282d  move	a1,zero
001c740c: dfb00000  ld	s0,0(sp)
001c7410: dfbf0008  ld	ra,8(sp)
001c7414: 03e00008  jr	ra
001c7418: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c73e0(void)`

```c
void FUN_001c73e0(undefined8 param_1)

{
  FUN_001c71f8(DAT_0036dfa8);
  FUN_001c7440(param_1,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
