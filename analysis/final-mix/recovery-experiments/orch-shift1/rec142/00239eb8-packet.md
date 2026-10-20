# Target packet 00239eb8

- Range: `00239eb8`..`00239f14`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_00239eb8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00239eb8: 3c0f0037  lui	t7,0x37
00239ebc: e48c0134  swc1	$f12,308(a0)
00239ec0: 25ef14c0  addiu	t7,t7,5312   ; = D_003714c0
00239ec4: c5e10000  lwc1	$f1,0(t7)
00239ec8: 46016032  c.eq.s	$f12,$f1
00239ecc: 45000009  bc1f	0x239ef4
00239ed0: 0000682d  move	t5,zero
00239ed4: c4800138  lwc1	$f0,312(a0)
00239ed8: 46010032  c.eq.s	$f0,$f1
00239edc: 45020006  bc1fl	0x239ef8
00239ee0: 240d0001  li	t5,1
00239ee4: c480013c  lwc1	$f0,316(a0)
00239ee8: 46010032  c.eq.s	$f0,$f1
00239eec: 45030003  bc1tl	0x239efc
00239ef0: 8c8f00b8  lw	t7,184(a0)
00239ef4: 240d0001  li	t5,1
00239ef8: 8c8f00b8  lw	t7,184(a0)
00239efc: 240efffd  li	t6,-3
00239f00: 000d6840  sll	t5,t5,0x1
00239f04: 01ee7824  and	t7,t7,t6
00239f08: 01ed7825  or	t7,t7,t5
00239f0c: 03e00008  jr	ra
00239f10: ac8f00b8  sw	t7,184(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00239eb8(void)`

```c
void FUN_00239eb8(float param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  *(float *)(param_2 + 0x134) = param_1;
  iVar2 = 0;
  if (((param_1 == DAT_003714c0) && (*(float *)(param_2 + 0x138) == DAT_003714c0)) &&
     (*(float *)(param_2 + 0x13c) == DAT_003714c0)) {
    uVar1 = *(uint *)(param_2 + 0xb8);
  }
  else {
    iVar2 = 1;
    uVar1 = *(uint *)(param_2 + 0xb8);
  }
  *(uint *)(param_2 + 0xb8) = uVar1 & 0xfffffffd | iVar2 << 1;
  return;
}
```

## Earlier attempts (newest first)

- 23 differing words, 92/92 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.cpp`)
