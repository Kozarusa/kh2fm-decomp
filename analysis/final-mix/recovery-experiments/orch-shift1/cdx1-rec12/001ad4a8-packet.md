# Target packet 001ad4a8

- Range: `001ad4a8`..`001ad520`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ad4a8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001aa388` registry: `_Z16wtarget_001aa388jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchcd_recovered_001ad430.cpp`
- `001ac078` registry: `_Z16wtarget_001ac078jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchcd_recovered_001ad430.cpp`
- `001ac970` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_orchcd_recovered_001ad1d0.cpp`, `fm_primary_orchcd_recovered_001ad228.cpp`, `fm_primary_orchcd_recovered_001ad430.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ad4a8: 27bdfff0  addiu	sp,sp,-16
001ad4ac: 00a0382d  move	a3,a1
001ad4b0: ffb00000  sd	s0,0(sp)
001ad4b4: 0000402d  move	t0,zero
001ad4b8: ffbf0008  sd	ra,8(sp)
001ad4bc: 24090100  li	t1,256
001ad4c0: 0080802d  move	s0,a0
001ad4c4: 240a0150  li	t2,336
001ad4c8: 0000582d  move	t3,zero
001ad4cc: 24050003  li	a1,3
001ad4d0: 0c06b25c  jal	0x1ac970
001ad4d4: 24060005  li	a2,5
001ad4d8: 3c0f0035  lui	t7,0x35
001ad4dc: ae000068  sw	zero,104(s0)
001ad4e0: 240e0003  li	t6,3
001ad4e4: 25ef0b30  addiu	t7,t7,2864   ; = D_00350b30
001ad4e8: ae0e0064  sw	t6,100(s0)
001ad4ec: 260404ac  addiu	a0,s0,1196
001ad4f0: ae0f0000  sw	t7,0(s0)
001ad4f4: 24050001  li	a1,1
001ad4f8: 24060001  li	a2,1
001ad4fc: 0c06b01e  jal	0x1ac078
001ad500: 0000382d  move	a3,zero
001ad504: 2610000c  addiu	s0,s0,12
001ad508: 8e05000c  lw	a1,12(s0)
001ad50c: 0200202d  move	a0,s0
001ad510: dfbf0008  ld	ra,8(sp)
001ad514: dfb00000  ld	s0,0(sp)
001ad518: 0806a8e2  j	0x1aa388
001ad51c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ad4a8(void)`

```c
void FUN_001ad4a8(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  
  FUN_001ac970(param_1,3,5,param_2,0,0x100,0x150,0);
  puVar1 = (undefined4 *)param_1;
  puVar1[0x1a] = 0;
  puVar1[0x19] = 3;
  *puVar1 = &PTR_FUN_00350b30;
  FUN_001ac078(puVar1 + 299,1,1,0);
  FUN_001aa388(puVar1 + 3,puVar1[6]);
  return;
}
```

## Earlier attempts (newest first)

- none found
