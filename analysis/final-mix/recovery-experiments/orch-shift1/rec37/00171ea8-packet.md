# Target packet 00171ea8

- Range: `00171ea8`..`00171f00`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_00171ea8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001ca148` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00171ea8: 27bdffe0  addiu	sp,sp,-32
00171eac: ffb00010  sd	s0,16(sp)
00171eb0: ffbf0018  sd	ra,24(sp)
00171eb4: 0080802d  move	s0,a0
00171eb8: 8c8e0000  lw	t6,0(a0)
00171ebc: 8e0f0004  lw	t7,4(s0)
00171ec0: 8dc50004  lw	a1,4(t6)
00171ec4: 03a0202d  move	a0,sp
00171ec8: 8de60004  lw	a2,4(t7)
00171ecc: 0c072852  jal	0x1ca148
00171ed0: c60c0008  lwc1	$f12,8(s0)
00171ed4: 3c0f01c6  lui	t7,0x1c6
00171ed8: 25eff480  addiu	t7,t7,-2944   ; = D_01c5f480
00171edc: 53af0004  beql	sp,t7,0x171ef0
00171ee0: ae0f0000  sw	t7,0(s0)
00171ee4: 7ba80000  lq	t0,0(sp)
00171ee8: 7de80000  sq	t0,0(t7)
00171eec: ae0f0000  sw	t7,0(s0)
00171ef0: dfbf0018  ld	ra,24(sp)
00171ef4: dfb00010  ld	s0,16(sp)
00171ef8: 03e00008  jr	ra
00171efc: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00171ea8(void)`

```c
void FUN_00171ea8(int *param_1)

{
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  FUN_001ca148(param_1[2],&uStack_20,*(undefined4 *)(*param_1 + 4),*(undefined4 *)(param_1[1] + 4));
  if ((undefined4 *)&stack0x00000000 == &DAT_01c5f4a0) {
    *param_1 = (int)&DAT_01c5f480;
  }
  else {
    DAT_01c5f480 = uStack_20;
    DAT_01c5f484 = uStack_1c;
    DAT_01c5f488 = uStack_18;
    DAT_01c5f48c = uStack_14;
    *param_1 = (int)&DAT_01c5f480;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
