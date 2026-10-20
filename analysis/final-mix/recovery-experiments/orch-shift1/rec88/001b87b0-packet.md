# Target packet 001b87b0

- Range: `001b87b0`..`001b87fc`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b87b0`
- Registry names for this address: `_Z16u_tail0_001b87b0v`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b8838` registry: none
- `001b8da0` registry: `func_001b8da0`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b87b0: 27bdfff0  addiu	sp,sp,-16
001b87b4: 3c0f0033  lui	t7,0x33
001b87b8: 25effb68  addiu	t7,t7,-1176   ; = D_0032fb68
001b87bc: ffbf0000  sd	ra,0(sp)
001b87c0: 240d0007  li	t5,7
001b87c4: 01e0702d  move	t6,t7
001b87c8: adc00000  sw	zero,0(t6)
001b87cc: 25adffff  addiu	t5,t5,-1
001b87d0: 00000000  nop
001b87d4: 00000000  nop
001b87d8: 00000000  nop
001b87dc: 05a1fffa  bgez	t5,0x1b87c8
001b87e0: 25ce0004  addiu	t6,t6,4
001b87e4: a1e0011f  sb	zero,287(t7)
001b87e8: 0c06e20e  jal	0x1b8838
001b87ec: 0000202d  move	a0,zero
001b87f0: dfbf0000  ld	ra,0(sp)
001b87f4: 0806e368  j	0x1b8da0
001b87f8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b87b0(void)`

```c
void FUN_001b87b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0032fb68;
  iVar1 = 7;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  DAT_0032fc87 = 0;
  FUN_001b8838(0);
  FUN_001b8da0();
  return;
}
```

## Earlier attempts (newest first)

- none found
