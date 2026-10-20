# Target packet 0017c0a0

- Range: `0017c0a0`..`0017c108`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_0017c0a0`
- Registry names for this address: none
- Queue: state `leased`, queue `aggregate-abi-layout`, attempts 4, priority 1
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\0017c0a0-REPORT.md", "sha256": "b2ea3da2df94879e7475ef355448312c55b6d7322f0fb984acbda64e377e78e7", "hypothesis": "v5_1 final stores already exact; initial a0/a2 setup remains. Native aggregate-return/value-call variant has104 bytes but frame80; inspect callee ABI and model local lifetimes/output-buffer reuse"}`

## Callees

- `0017c030` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_002e8c28.cpp`, `fm_primary_floatpacket_recovered_002e8c58.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`
- `0017c4c8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`
- `0017f488` registry: `func_0017f488(int,int,float,float)`
  - accepted sources that already call it (copy their declaration): `fm_primary_animation_recovered.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0017c0a0: 27bdffc0  addiu	sp,sp,-64
0017c0a4: 30c700ff  andi	a3,a2,0xff
0017c0a8: ffb00030  sd	s0,48(sp)
0017c0ac: 03a0202d  move	a0,sp
0017c0b0: ffbf0038  sd	ra,56(sp)
0017c0b4: 27a60020  addiu	a2,sp,32
0017c0b8: 0c05f00c  jal	0x17c030
0017c0bc: 00a0802d  move	s0,a1
0017c0c0: 27a50010  addiu	a1,sp,16
0017c0c4: 7ba80000  lq	t0,0(sp)
0017c0c8: 7ca80000  sq	t0,0(a1)
0017c0cc: 0c05f132  jal	0x17c4c8
0017c0d0: 0200202d  move	a0,s0
0017c0d4: 44806000  mtc1	zero,$f12
0017c0d8: 26040140  addiu	a0,s0,320
0017c0dc: 8fa50020  lw	a1,32(sp)
0017c0e0: 0c05fd22  jal	0x17f488
0017c0e4: 46006346  mov.s	$f13,$f12
0017c0e8: 240f0005  li	t7,5
0017c0ec: dfbf0038  ld	ra,56(sp)
0017c0f0: 240e0004  li	t6,4
0017c0f4: ae0f0104  sw	t7,260(s0)
0017c0f8: ae0e0100  sw	t6,256(s0)
0017c0fc: dfb00030  ld	s0,48(sp)
0017c100: 03e00008  jr	ra
0017c104: 27bd0040  addiu	sp,sp,64
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0017c0a0(void)`

```c
void FUN_0017c0a0(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 auStack_20 [4];
  
  FUN_0017c030(&uStack_40,param_2,auStack_20,param_3);
  uStack_30 = uStack_40;
  uStack_2c = uStack_3c;
  uStack_28 = uStack_38;
  uStack_24 = uStack_34;
  FUN_0017c4c8(param_2);
  iVar1 = (int)param_2;
  FUN_0017f488(0,0,iVar1 + 0x140,auStack_20[0]);
  *(undefined4 *)(iVar1 + 0x104) = 5;
  *(undefined4 *)(iVar1 + 0x100) = 4;
  return;
}
```

## Earlier attempts (newest first)

- 2 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_17ec437b_v2.verification.json`
- 2 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_17ec437b_v1.verification.json`
- 2 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_17ec437b_v0.verification.json`
- 15 differing words, 108/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v17.verification.json`
- 12 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v16.verification.json`
- 27 differing words, 116/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v15.verification.json`
- 24 differing words, 112/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v14.verification.json`
- 2 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v13.verification.json`
- 2 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v12.verification.json`
- 6 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v11.verification.json`
- 3 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v10.verification.json`
- 2 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v9.verification.json`
- 27 differing words, 116/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v8.verification.json`
- 36 differing words, 152/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v7.verification.json`
- 23 differing words, 112/104 bytes: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_0017c0a0_e7816918_v6.verification.json`
- report: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/0017c0a0-callee-notes.md`
- report: `analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/0017c0a0-REPORT.md`
