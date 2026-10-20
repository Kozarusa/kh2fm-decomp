# Target packet 001dbc58

- Range: `001dbc58`..`001dbccc`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dbc58`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c1748` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fiveword_recovered_002e8c28.cpp`, `fm_primary_floatpacket_recovered_002e8c58.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dbc58: 27bdffe0  addiu	sp,sp,-32
001dbc5c: ffb20010  sd	s2,16(sp)
001dbc60: ffb00000  sd	s0,0(sp)
001dbc64: ffb10008  sd	s1,8(sp)
001dbc68: 00e0902d  move	s2,a3
001dbc6c: ffbf0018  sd	ra,24(sp)
001dbc70: 3c07001e  lui	a3,0x1e
001dbc74: 0080802d  move	s0,a0
001dbc78: 00c0882d  move	s1,a2
001dbc7c: 0c0705d2  jal	0x1c1748
001dbc80: 24e7bd38  addiu	a3,a3,-17096   ; = D_001dbd38
001dbc84: 260f0030  addiu	t7,s0,48
001dbc88: 7a280000  lq	t0,0(s1)
001dbc8c: 7de80000  sq	t0,0(t7)
001dbc90: 240fffff  li	t7,-1
001dbc94: ae12005c  sw	s2,92(s0)
001dbc98: a2000050  sb	zero,80(s0)
001dbc9c: a20f0016  sb	t7,22(s0)
001dbca0: a2000051  sb	zero,81(s0)
001dbca4: ae000054  sw	zero,84(s0)
001dbca8: ae000058  sw	zero,88(s0)
001dbcac: dfb10008  ld	s1,8(sp)
001dbcb0: 924f0000  lbu	t7,0(s2)
001dbcb4: dfbf0018  ld	ra,24(sp)
001dbcb8: a20f0014  sb	t7,20(s0)
001dbcbc: dfb20010  ld	s2,16(sp)
001dbcc0: dfb00000  ld	s0,0(sp)
001dbcc4: 03e00008  jr	ra
001dbcc8: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dbc58(void)`

```c
void FUN_001dbc58(int param_1,undefined8 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  FUN_001c1748();
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  *(undefined4 *)(param_1 + 0x30) = *param_3;
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  *(undefined4 *)(param_1 + 0x38) = uVar2;
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  *(undefined1 **)(param_1 + 0x5c) = param_4;
  *(undefined1 *)(param_1 + 0x50) = 0;
  *(undefined1 *)(param_1 + 0x16) = 0xff;
  *(undefined1 *)(param_1 + 0x51) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined1 *)(param_1 + 0x14) = *param_4;
  return;
}
```

## Earlier attempts (newest first)

- 30 differing words, 128/116 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.cpp`)
