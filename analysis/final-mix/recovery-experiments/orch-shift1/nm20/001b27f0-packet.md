# Target packet 001b27f0

- Range: `001b27f0`..`001b2860`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b27f0`
- Registry names for this address: none
- Queue: state `leased`, queue `store-order`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec85\\001b27f0-BLOCKED.md", "sha256": "5fc2c9110eb57f8369a9e622396a46743432a03296f40068219f8c8d21ec0279", "hypothesis": "asm lq/sq copy pattern from 001b2780 on Frame struct, then store order 0x104 before 0x100"}`

## Callees

- `0017c030` registry: `func_0017c030`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_002e8c28.cpp`, `fm_primary_floatpacket_recovered_002e8c58.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`
- `0017f488` registry: `func_0017f488(int,int,float,float)`
  - accepted sources that already call it (copy their declaration): `fm_primary_animation_recovered.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`
- `001b6dd0` registry: `func_001b6dd0`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_loadorder_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b27f0: 27bdffc0  addiu	sp,sp,-64
001b27f4: 30c700ff  andi	a3,a2,0xff
001b27f8: ffb00030  sd	s0,48(sp)
001b27fc: 03a0202d  move	a0,sp
001b2800: ffbf0038  sd	ra,56(sp)
001b2804: 27a60020  addiu	a2,sp,32
001b2808: 0c05f00c  jal	0x17c030
001b280c: 00a0802d  move	s0,a1
001b2810: 27a50010  addiu	a1,sp,16
001b2814: 7ba80000  lq	t0,0(sp)
001b2818: 7ca80000  sq	t0,0(a1)
001b281c: 0c06db74  jal	0x1b6dd0
001b2820: 0200202d  move	a0,s0
001b2824: 44806000  mtc1	zero,$f12
001b2828: 240f0004  li	t7,4
001b282c: 8fa50020  lw	a1,32(sp)
001b2830: 26040140  addiu	a0,s0,320
001b2834: 46006346  mov.s	$f13,$f12
001b2838: 0c05fd22  jal	0x17f488
001b283c: a20f0514  sb	t7,1300(s0)
001b2840: 240f0005  li	t7,5
001b2844: dfbf0038  ld	ra,56(sp)
001b2848: 240e0004  li	t6,4
001b284c: ae0f0104  sw	t7,260(s0)
001b2850: ae0e0100  sw	t6,256(s0)
001b2854: dfb00030  ld	s0,48(sp)
001b2858: 03e00008  jr	ra
001b285c: 27bd0040  addiu	sp,sp,64
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b27f0(void)`

```c
void FUN_001b27f0(undefined8 param_1,undefined8 param_2,undefined1 param_3)

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
  FUN_001b6dd0(param_2);
  iVar1 = (int)param_2;
  *(undefined1 *)(iVar1 + 0x514) = 4;
  FUN_0017f488(0,0,iVar1 + 0x140,auStack_20[0]);
  *(undefined4 *)(iVar1 + 0x104) = 5;
  *(undefined4 *)(iVar1 + 0x100) = 4;
  return;
}
```

## Earlier attempts (newest first)

- 24 differing words, 112/112 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_06_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_06_0.cpp`)
- 12 differing words, 112/112 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec85/orch1_rec85_001b27f0_v4.verification.json`
- 12 differing words, 112/112 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec85/orch1_rec85_001b27f0_v3.verification.json`
- 12 differing words, 112/112 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec85/orch1_rec85_001b27f0_v2.verification.json`
- 12 differing words, 112/112 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec85/orch1_rec85_001b27f0_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec85/001b27f0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec85/001b27f0-packet.md`
