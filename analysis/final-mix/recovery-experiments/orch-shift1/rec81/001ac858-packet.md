# Target packet 001ac858

- Range: `001ac858`..`001ac8b0`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ac858`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001aa668` registry: `func_001aa668`
- `001ac378` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ac858: 27bdfff0  addiu	sp,sp,-16
001ac85c: 00a0382d  move	a3,a1
001ac860: ffb00000  sd	s0,0(sp)
001ac864: 24050004  li	a1,4
001ac868: ffbf0008  sd	ra,8(sp)
001ac86c: 24060003  li	a2,3
001ac870: 0080802d  move	s0,a0
001ac874: 0000402d  move	t0,zero
001ac878: 24090100  li	t1,256
001ac87c: 0c06b0de  jal	0x1ac378
001ac880: 240a016d  li	t2,365
001ac884: 3c0f0035  lui	t7,0x35
001ac888: dfbf0008  ld	ra,8(sp)
001ac88c: 240e0004  li	t6,4
001ac890: 25ef0bf0  addiu	t7,t7,3056   ; = D_00350bf0
001ac894: ae0e0064  sw	t6,100(s0)
001ac898: 2604000c  addiu	a0,s0,12
001ac89c: ae0f0000  sw	t7,0(s0)
001ac8a0: 0200282d  move	a1,s0
001ac8a4: dfb00000  ld	s0,0(sp)
001ac8a8: 0806a99a  j	0x1aa668
001ac8ac: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ac858(void)`

```c
void FUN_001ac858(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  
  FUN_001ac378(param_1,4,3,param_2,0,0x100,0x16d);
  puVar1 = (undefined4 *)param_1;
  puVar1[0x19] = 4;
  *puVar1 = &PTR_LAB_00350bf0;
  FUN_001aa668(puVar1 + 3,param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
