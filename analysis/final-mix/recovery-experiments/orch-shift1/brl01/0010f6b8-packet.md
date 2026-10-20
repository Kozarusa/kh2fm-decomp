# Target packet 0010f6b8

- Range: `0010f6b8`..`0010f6f4`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_0010f6b8`
- Registry names for this address: none
- Queue: state `leased`, queue `branch-layout`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec03\\0010f6b8-BLOCKED.md", "sha256": "fca0ea38e9a0c709beb0dbfdc1120262ec56d4bc21b501f8bd77e68d36e5c7ba", "hypothesis": "Original keeps slt t6 + bnez with li v0,1 / move v0,zero and shared epilogue; try volatile only on data[0] read or a separate s32 compare variable with else arm"}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0010f6b8: 8c8e048c  lw	t6,1164(a0)
0010f6bc: 11c0000b  beqz	t6,0x10f6ec
0010f6c0: 0000102d  move	v0,zero
0010f6c4: c5c00004  lwc1	$f0,4(t6)
0010f6c8: 46800020  cvt.s.w	$f0,$f0
0010f6cc: 8dce0000  lw	t6,0(t6)
0010f6d0: 460c0002  mul.s	$f0,$f0,$f12
0010f6d4: 46000064  cvt.w.s	$f1,$f0
0010f6d8: 440f0800  mfc1	t7,$f1
0010f6dc: 01cf702a  slt	t6,t6,t7
0010f6e0: 15c00002  bnez	t6,0x10f6ec
0010f6e4: 24020001  li	v0,1
0010f6e8: 0000102d  move	v0,zero
0010f6ec: 03e00008  jr	ra
0010f6f0: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0010f6b8(void)`

```c
undefined4 FUN_0010f6b8(float param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_2 + 0x48c);
  uVar2 = 0;
  if ((piVar1 != (int *)0x0) && (uVar2 = 1, (int)((float)piVar1[1] * param_1) <= *piVar1)) {
    uVar2 = 0;
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- 7 differing words, 48/60 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec03/orch1_rec03_0010f6b8_v6.verification.json`
- 12 differing words, 52/60 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec03/orch1_rec03_0010f6b8_v5.verification.json`
- 7 differing words, 52/60 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec03/orch1_rec03_0010f6b8_v4.verification.json`
- 7 differing words, 48/60 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec03/orch1_rec03_0010f6b8_v3.verification.json`
- 7 differing words, 48/60 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec03/orch1_rec03_0010f6b8_v2.verification.json`
- 7 differing words, 48/60 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec03/orch1_rec03_0010f6b8_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec03/0010f6b8-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec03/0010f6b8-packet.md`
