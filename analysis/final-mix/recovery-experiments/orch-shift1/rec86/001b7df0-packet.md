# Target packet 001b7df0

- Range: `001b7df0`..`001b7e68`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b7df0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0018a7d0` registry: `func_0018a7d0`
- `0019bb98` registry: none
- `001b7998` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b7df0: 27bdffd0  addiu	sp,sp,-48
001b7df4: ffb00010  sd	s0,16(sp)
001b7df8: ffb10018  sd	s1,24(sp)
001b7dfc: ffbf0020  sd	ra,32(sp)
001b7e00: 0080802d  move	s0,a0
001b7e04: 00a0882d  move	s1,a1
001b7e08: 0c066ee6  jal	0x19bb98
001b7e0c: 8c840004  lw	a0,4(a0)
001b7e10: 0200202d  move	a0,s0
001b7e14: 1440000f  bnez	v0,0x1b7e54
001b7e18: 0220282d  move	a1,s1
001b7e1c: 0c06de66  jal	0x1b7998
001b7e20: 00000000  nop
001b7e24: 03a0302d  move	a2,sp
001b7e28: 0040202d  move	a0,v0
001b7e2c: 10400009  beqz	v0,0x1b7e54
001b7e30: 0220282d  move	a1,s1
001b7e34: 0c0629f4  jal	0x18a7d0
001b7e38: 00000000  nop
001b7e3c: 8e0f0004  lw	t7,4(s0)
001b7e40: 25ef0870  addiu	t7,t7,2160
001b7e44: d9e10000  lqc2	vf1,0(t7)
001b7e48: dba20000  lqc2	vf2,0(sp)
001b7e4c: 4be2086c  vsub.wxyz	vf1,vf1,vf2
001b7e50: f9e10000  sqc2	vf1,0(t7)
001b7e54: dfb00010  ld	s0,16(sp)
001b7e58: dfb10018  ld	s1,24(sp)
001b7e5c: dfbf0020  ld	ra,32(sp)
001b7e60: 03e00008  jr	ra
001b7e64: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b7df0(void)`

```c
void FUN_001b7df0(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined1 (*pauVar2) [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auStack_30 [16];
  
  lVar1 = FUN_0019bb98(*(undefined4 *)((int)param_1 + 4));
  if ((lVar1 == 0) && (lVar1 = FUN_001b7998(param_1,param_2), lVar1 != 0)) {
    FUN_0018a7d0(lVar1,param_2,auStack_30);
    pauVar2 = (undefined1 (*) [16])(*(int *)((int)param_1 + 4) + 0x870);
    auVar3 = _lqc2(*pauVar2);
    auVar4 = _lqc2(auStack_30);
    auVar3 = _vsub(auVar3,auVar4);
    auVar3 = _sqc2(auVar3);
    *pauVar2 = auVar3;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
