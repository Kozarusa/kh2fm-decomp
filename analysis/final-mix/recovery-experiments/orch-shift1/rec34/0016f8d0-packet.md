# Target packet 0016f8d0

- Range: `0016f8d0`..`0016f930`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016f8d0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016f930` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016f8d0: 27bdfff0  addiu	sp,sp,-16
0016f8d4: ffb00000  sd	s0,0(sp)
0016f8d8: ffbf0008  sd	ra,8(sp)
0016f8dc: 0c05be4c  jal	0x16f930
0016f8e0: 0080802d  move	s0,a0
0016f8e4: 240f0960  li	t7,2400
0016f8e8: 144f0003  bne	v0,t7,0x16f8f8
0016f8ec: 0000202d  move	a0,zero
0016f8f0: 0c05be4c  jal	0x16f930
0016f8f4: 00000000  nop
0016f8f8: 240f096a  li	t7,2410
0016f8fc: 104f0009  beq	v0,t7,0x16f924
0016f900: 240f0974  li	t7,2420
0016f904: 104f0005  beq	v0,t7,0x16f91c
0016f908: 3c0f004f  lui	t7,0x4f
0016f90c: dfb00000  ld	s0,0(sp)
0016f910: dfbf0008  ld	ra,8(sp)
0016f914: 03e00008  jr	ra
0016f918: 27bd0010  addiu	sp,sp,16
0016f91c: 1000fffb  b	0x16f90c
0016f920: adf063ac  sw	s0,25516(t7)   ; = D_004f63ac
0016f924: 3c0f004f  lui	t7,0x4f
0016f928: 1000fff8  b	0x16f90c
0016f92c: adf063a8  sw	s0,25512(t7)   ; = D_004f63a8
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016f8d0(void)`

```c
void FUN_0016f8d0(undefined4 param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_0016f930();
  if (lVar2 == 0x960) {
    lVar2 = FUN_0016f930(0);
  }
  uVar1 = param_1;
  if ((lVar2 != 0x96a) && (uVar1 = DAT_004f63a8, lVar2 == 0x974)) {
    DAT_004f63ac = param_1;
  }
  DAT_004f63a8 = uVar1;
  return;
}
```

## Earlier attempts (newest first)

- none found
