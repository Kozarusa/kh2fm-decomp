# Target packet 001ac8b0

- Range: `001ac8b0`..`001ac908`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ac8b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001aa668` registry: `func_001aa668`
- `001ac378` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ac8b0: 27bdfff0  addiu	sp,sp,-16
001ac8b4: 00a0382d  move	a3,a1
001ac8b8: ffb00000  sd	s0,0(sp)
001ac8bc: 24050004  li	a1,4
001ac8c0: ffbf0008  sd	ra,8(sp)
001ac8c4: 24060003  li	a2,3
001ac8c8: 0080802d  move	s0,a0
001ac8cc: 0000402d  move	t0,zero
001ac8d0: 24090100  li	t1,256
001ac8d4: 0c06b0de  jal	0x1ac378
001ac8d8: 240a016d  li	t2,365
001ac8dc: 3c0f0035  lui	t7,0x35
001ac8e0: dfbf0008  ld	ra,8(sp)
001ac8e4: 240e0004  li	t6,4
001ac8e8: 25ef0bf0  addiu	t7,t7,3056   ; = D_00350bf0
001ac8ec: ae0e0064  sw	t6,100(s0)
001ac8f0: 2604000c  addiu	a0,s0,12
001ac8f4: ae0f0000  sw	t7,0(s0)
001ac8f8: 0200282d  move	a1,s0
001ac8fc: dfb00000  ld	s0,0(sp)
001ac900: 0806a99a  j	0x1aa668
001ac904: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ac8b0(void)`

```c
void FUN_001ac8b0(undefined8 param_1,undefined8 param_2)

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
