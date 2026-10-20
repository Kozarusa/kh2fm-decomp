# Target packet 001dddd0

- Range: `001dddd0`..`001dde3c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dddd0`
- Registry names for this address: `_Z16wtarget_001dddd0jjjj`
- Queue: state `leased`, queue `register-allocation`, attempts 3, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\nm10\\001dddd0-BLOCKED.md", "sha256": "e2b1faa1fc7b999170c1cd2e15d8aaa14e38cb4711202f31730ab594775597cc", "hypothesis": "bind only the copy to 15 after the object[1] store, leave a1+16 temp unbound"}`

## Callees

- `001dc010` registry: `_ZN3ryj11EFFECT_DATA3setEPv`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dddd0: 27bdfff0  addiu	sp,sp,-16
001dddd4: 24ae0010  addiu	t6,a1,16
001dddd8: ffb00000  sd	s0,0(sp)
001ddddc: 00a0782d  move	t7,a1
001ddde0: ac8e0004  sw	t6,4(a0)
001ddde4: 0080802d  move	s0,a0
001ddde8: ffbf0008  sd	ra,8(sp)
001dddec: ae050000  sw	a1,0(s0)
001dddf0: 24840008  addiu	a0,a0,8
001dddf4: 8ca5000c  lw	a1,12(a1)
001dddf8: 0c077004  jal	0x1dc010
001dddfc: 00af2821  addu	a1,a1,t7
001dde00: 3c0d01da  lui	t5,0x1da
001dde04: 25aee348  addiu	t6,t5,-7352   ; = D_01d9e348
001dde08: 8dcf0004  lw	t7,4(t6)
001dde0c: 55e00008  bnezl	t7,0x1dde30
001dde10: adf00014  sw	s0,20(t7)
001dde14: add00004  sw	s0,4(t6)
001dde18: adb0e348  sw	s0,-7352(t5)   ; = D_01d9e348
001dde1c: ae000014  sw	zero,20(s0)
001dde20: dfb00000  ld	s0,0(sp)
001dde24: dfbf0008  ld	ra,8(sp)
001dde28: 03e00008  jr	ra
001dde2c: 27bd0010  addiu	sp,sp,16
001dde30: ae000014  sw	zero,20(s0)
001dde34: 1000fffa  b	0x1dde20
001dde38: add00004  sw	s0,4(t6)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dddd0(void)`

```c
void FUN_001dddd0(int *param_1,int param_2)

{
  param_1[1] = param_2 + 0x10;
  *param_1 = param_2;
  FUN_001dc010(param_1 + 2,*(int *)(param_2 + 0xc) + param_2);
  if (DAT_01d9e34c == (int *)0x0) {
    DAT_01d9e348 = param_1;
    DAT_01d9e34c = param_1;
    param_1[5] = 0;
  }
  else {
    *(int **)((int)DAT_01d9e34c + 0x14) = param_1;
    param_1[5] = 0;
    DAT_01d9e34c = param_1;
  }
  return;
}
```

## Earlier attempts (newest first)

- 5 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm10/orch1_nm10_001dddd0_v4.verification.json`
- 10 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm10/orch1_nm10_001dddd0_v3.verification.json`
- 9 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm10/orch1_nm10_001dddd0_v2.verification.json`
- 5 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/nm10/orch1_nm10_001dddd0_v1.verification.json`
- 5 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec116/orch1_rec116_001dddd0_v6.verification.json`
- 9 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec116/orch1_rec116_001dddd0_v5.verification.json`
- 10 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec116/orch1_rec116_001dddd0_v4.verification.json`
- 5 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec116/orch1_rec116_001dddd0_v3.verification.json`
- 7 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec116/orch1_rec116_001dddd0_v2.verification.json`
- 25 differing words, 104/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec116/orch1_rec116_001dddd0_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/nm10/001dddd0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/nm10/001dddd0-packet.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec116/001dddd0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec116/001dddd0-packet.md`
