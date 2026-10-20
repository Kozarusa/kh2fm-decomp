# Target packet 001ad098

- Range: `001ad098`..`001ad0f4`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ad098`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001ac970` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ad098: 27bdfff0  addiu	sp,sp,-16
001ad09c: 00a0382d  move	a3,a1
001ad0a0: ffb00000  sd	s0,0(sp)
001ad0a4: 00c0402d  move	t0,a2
001ad0a8: ffbf0008  sd	ra,8(sp)
001ad0ac: 24050003  li	a1,3
001ad0b0: 0080802d  move	s0,a0
001ad0b4: 24060005  li	a2,5
001ad0b8: 24090080  li	t1,128
001ad0bc: 240a0068  li	t2,104
001ad0c0: 0c06b25c  jal	0x1ac970
001ad0c4: 0000582d  move	t3,zero
001ad0c8: 3c0f0037  lui	t7,0x37
001ad0cc: dfbf0008  ld	ra,8(sp)
001ad0d0: 25efd79c  addiu	t7,t7,-10340   ; = D_0036d79c
001ad0d4: c5e00000  lwc1	$f0,0(t7)
001ad0d8: 3c0f0035  lui	t7,0x35
001ad0dc: e6000068  swc1	$f0,104(s0)
001ad0e0: 25ef0b70  addiu	t7,t7,2928   ; = D_00350b70
001ad0e4: ae0f0000  sw	t7,0(s0)
001ad0e8: dfb00000  ld	s0,0(sp)
001ad0ec: 03e00008  jr	ra
001ad0f0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ad098(void)`

```c
void FUN_001ad098(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001ac970(param_1,3,5,param_2,param_3,0x80,0x68,0);
  ((undefined4 *)param_1)[0x1a] = DAT_0036d79c;
  *(undefined4 *)param_1 = &PTR_FUN_00350b70;
  return;
}
```

## Earlier attempts (newest first)

- none found
