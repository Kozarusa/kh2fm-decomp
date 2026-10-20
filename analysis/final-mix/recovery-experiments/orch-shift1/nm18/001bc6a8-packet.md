# Target packet 001bc6a8

- Range: `001bc6a8`..`001bc6fc`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bc6a8`
- Registry names for this address: none
- Queue: state `leased`, queue `register-allocation`, attempts 3, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\nm07\\001bc6a8-BLOCKED.md", "sha256": "249d3655b9e5401537c53ecd8859fefae0e3247c3dd95065570813a66bfc7f42", "hypothesis": "Make flag a u8 param or pointer-based read with the byte store through a separate s0 copy; bound register and +r guards already failed"}`

## Callees

- `001bc2a8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twowordfresh_recovered_001b3330.cpp`, `fm_scalar_extra_recovered_04.cpp`, `fm_scalar_extra_recovered_12.cpp`, `fm_scalar_recovered_04.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bc6a8: 27bdffe0  addiu	sp,sp,-32
001bc6ac: ffb00000  sd	s0,0(sp)
001bc6b0: ffb10008  sd	s1,8(sp)
001bc6b4: ffbf0010  sd	ra,16(sp)
001bc6b8: 0080802d  move	s0,a0
001bc6bc: 00e0882d  move	s1,a3
001bc6c0: 94af0000  lhu	t7,0(a1)
001bc6c4: a48f0002  sh	t7,2(a0)
001bc6c8: a2080004  sb	t0,4(s0)
001bc6cc: 00a0202d  move	a0,a1
001bc6d0: 00c0282d  move	a1,a2
001bc6d4: 0c06f0aa  jal	0x1bc2a8
001bc6d8: 00e0302d  move	a2,a3
001bc6dc: ae110008  sw	s1,8(s0)
001bc6e0: a2020005  sb	v0,5(s0)
001bc6e4: a6000000  sh	zero,0(s0)
001bc6e8: dfb10008  ld	s1,8(sp)
001bc6ec: dfb00000  ld	s0,0(sp)
001bc6f0: dfbf0010  ld	ra,16(sp)
001bc6f4: 03e00008  jr	ra
001bc6f8: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bc6a8(void)`

```c
void FUN_001bc6a8(undefined2 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5)

{
  undefined1 uVar1;
  
  param_1[1] = *(undefined2 *)param_2;
  *(undefined1 *)(param_1 + 2) = param_5;
  uVar1 = FUN_001bc2a8(param_2,param_3,param_4);
  *(int *)(param_1 + 4) = (int)param_4;
  *(undefined1 *)((int)param_1 + 5) = uVar1;
  *param_1 = 0;
  return;
}
```

## Earlier attempts (newest first)

- 26 differing words, 108/84 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_04.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_04.cpp`)
- 2 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm07/orch1_nm07_001bc6a8_v4.verification.json`
- 2 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm07/orch1_nm07_001bc6a8_v3.verification.json`
- 4 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm07/orch1_nm07_001bc6a8_v2.verification.json`
- 1 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm07/orch1_nm07_001bc6a8_v1.verification.json`
- 1 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec91/orch1_rec91_001bc6a8_v8.verification.json`
- 1 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec91/orch1_rec91_001bc6a8_v7.verification.json`
- 4 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec91/orch1_rec91_001bc6a8_v6.verification.json`
- 1 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec91/orch1_rec91_001bc6a8_v5.verification.json`
- 2 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec91/orch1_rec91_001bc6a8_v4.verification.json`
- 2 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec91/orch1_rec91_001bc6a8_v3.verification.json`
- 2 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec91/orch1_rec91_001bc6a8_v2.verification.json`
- 21 differing words, 88/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec91/orch1_rec91_001bc6a8_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/nm07/001bc6a8-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/nm07/001bc6a8-packet.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec91/001bc6a8-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec91/001bc6a8-packet.md`
