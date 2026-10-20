# Target packet 001da420

- Range: `001da420`..`001da458`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001da420`
- Registry names for this address: `_Z16wtarget_001da420jjjj`
- Queue: state `leased`, queue `branch-layout`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec110\\001da420-BLOCKED.md", "sha256": "22e554b2dc2ba4f6026d68514901a2c3809e5e36b1c7665f9de791a38e64cd64", "hypothesis": "original loop uses bnez on t7 with move v0,t7 in the delay slot, not bnezl; try volatile reload of entry[1] or for(;;) with explicit break"}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001da420: 8c8f0000  lw	t7,0(a0)
001da424: 25ee001c  addiu	t6,t7,28
001da428: 8dc20004  lw	v0,4(t6)
001da42c: 50400008  beqzl	v0,0x1da450
001da430: 0000102d  move	v0,zero
001da434: 8dcf0000  lw	t7,0(t6)
001da438: 11e50005  beq	t7,a1,0x1da450
001da43c: 25ce0008  addiu	t6,t6,8
001da440: 8dcf0004  lw	t7,4(t6)
001da444: 15e0fffb  bnez	t7,0x1da434
001da448: 01e0102d  move	v0,t7
001da44c: 0000102d  move	v0,zero
001da450: 03e00008  jr	ra
001da454: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001da420(void)`

```c
int FUN_001da420(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(*param_1 + 0x20);
  piVar2 = (int *)(*param_1 + 0x1c);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (*piVar2 == param_2) break;
    iVar1 = piVar2[3];
    piVar2 = piVar2 + 2;
  }
  return iVar1;
}
```

## Earlier attempts (newest first)

- 11 differing words, 52/56 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_05.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_05.cpp`)
- 3 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec110/orch1_rec110_001da420_v4.verification.json`
- 6 differing words, 64/56 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec110/orch1_rec110_001da420_v3.verification.json`
- 3 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec110/orch1_rec110_001da420_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec110/001da420-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec110/001da420-packet.md`
