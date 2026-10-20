# Target packet 00172fb0

- Range: `00172fb0`..`00173004`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_00172fb0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00104f58` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_loadorder_recovered.cpp`, `fm_primary_packetnext_recovered.cpp`, `fm_primary_packetorder_recovered_00172368.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00172fb0: 27bdffe0  addiu	sp,sp,-32
00172fb4: 0080702d  move	t6,a0
00172fb8: ffbf0010  sd	ra,16(sp)
00172fbc: 340fffff  li	t7,0xffff
00172fc0: 0000302d  move	a2,zero
00172fc4: 0000382d  move	a3,zero
00172fc8: 908d0000  lbu	t5,0(a0)
00172fcc: 0000402d  move	t0,zero
00172fd0: 91cc0004  lbu	t4,4(t6)
00172fd4: 03a0202d  move	a0,sp
00172fd8: a7af0008  sh	t7,8(sp)
00172fdc: a3ad0001  sb	t5,1(sp)
00172fe0: a3ac0002  sb	t4,2(sp)
00172fe4: a3af0000  sb	t7,0(sp)
00172fe8: a7af0004  sh	t7,4(sp)
00172fec: a7af0006  sh	t7,6(sp)
00172ff0: 0c0413d6  jal	0x104f58
00172ff4: 8dc50008  lw	a1,8(t6)
00172ff8: dfbf0010  ld	ra,16(sp)
00172ffc: 03e00008  jr	ra
00173000: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00172fb0(void)`

```c
void FUN_00172fb0(undefined1 *param_1)

{
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  
  uStack_1f = *param_1;
  uStack_1e = param_1[4];
  uStack_18 = 0xffff;
  uStack_20 = 0xff;
  uStack_1c = 0xffff;
  uStack_1a = 0xffff;
  FUN_00104f58(&uStack_20,*(undefined4 *)(param_1 + 8),0,0,0);
  return;
}
```

## Earlier attempts (newest first)

- 18 differing words, 56/84 bytes: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_return_variants_v2_02_0.cpp`)
