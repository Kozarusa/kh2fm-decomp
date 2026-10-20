# Target packet 001ad228

- Range: `001ad228`..`001ad280`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ad228`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001ac970` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ad228: 27bdfff0  addiu	sp,sp,-16
001ad22c: 00a0382d  move	a3,a1
001ad230: ffb00000  sd	s0,0(sp)
001ad234: 24050003  li	a1,3
001ad238: ffbf0008  sd	ra,8(sp)
001ad23c: 24060004  li	a2,4
001ad240: 0080802d  move	s0,a0
001ad244: 0000402d  move	t0,zero
001ad248: 24090100  li	t1,256
001ad24c: 240a0020  li	t2,32
001ad250: 0c06b25c  jal	0x1ac970
001ad254: 240b0003  li	t3,3
001ad258: 3c0f0035  lui	t7,0x35
001ad25c: ae000068  sw	zero,104(s0)
001ad260: 240e0002  li	t6,2
001ad264: dfbf0008  ld	ra,8(sp)
001ad268: 25ef0af0  addiu	t7,t7,2800   ; = D_00350af0
001ad26c: ae0e0064  sw	t6,100(s0)
001ad270: ae0f0000  sw	t7,0(s0)
001ad274: dfb00000  ld	s0,0(sp)
001ad278: 03e00008  jr	ra
001ad27c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ad228(void)`

```c
void FUN_001ad228(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  
  FUN_001ac970(param_1,3,4,param_2,0,0x100,0x20,3);
  puVar1 = (undefined4 *)param_1;
  puVar1[0x1a] = 0;
  puVar1[0x19] = 2;
  *puVar1 = &PTR_FUN_00350af0;
  return;
}
```

## Earlier attempts (newest first)

- none found
