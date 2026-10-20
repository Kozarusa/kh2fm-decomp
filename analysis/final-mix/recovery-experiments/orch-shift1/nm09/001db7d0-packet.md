# Target packet 001db7d0

- Range: `001db7d0`..`001db808`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001db7d0`
- Registry names for this address: none
- Queue: state `leased`, queue `register-allocation`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec112\\001db7d0-BLOCKED.md", "sha256": "ef10c3cc56e2fd191fcbb5e2b12e7faa7a63a8eae52960d52fdaf171f96905cc", "hypothesis": "Bind inner to t5 (asm \\) and try base-class vtable layout; original loads a1 before vtable loads and moves a0 in jalr delay slot"}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001db7d0: 27bdfff0  addiu	sp,sp,-16
001db7d4: 3c0f0035  lui	t7,0x35
001db7d8: ffbf0000  sd	ra,0(sp)
001db7dc: 25ef2a38  addiu	t7,t7,10808   ; = D_00352a38
001db7e0: ac8f0000  sw	t7,0(a0)
001db7e4: 8c8d0004  lw	t5,4(a0)
001db7e8: 8c85000c  lw	a1,12(a0)
001db7ec: 8daf0000  lw	t7,0(t5)
001db7f0: 8dee0004  lw	t6,4(t7)
001db7f4: 01c0f809  jalr	t6
001db7f8: 01a0202d  move	a0,t5
001db7fc: dfbf0000  ld	ra,0(sp)
001db800: 03e00008  jr	ra
001db804: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001db7d0(void)`

```c
void FUN_001db7d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00352a38;
  (**(code **)(*(int *)param_1[1] + 4))((int *)param_1[1],param_1[3]);
  return;
}
```

## Earlier attempts (newest first)

- 13 differing words, 60/56 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec112/orch1_rec112_001db7d0_v5.verification.json`
- 9 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec112/orch1_rec112_001db7d0_v4.verification.json`
- 13 differing words, 60/56 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec112/orch1_rec112_001db7d0_v3.verification.json`
- 9 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec112/orch1_rec112_001db7d0_v2.verification.json`
- 13 differing words, 60/56 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec112/orch1_rec112_001db7d0_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec112/001db7d0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec112/001db7d0-packet.md`
