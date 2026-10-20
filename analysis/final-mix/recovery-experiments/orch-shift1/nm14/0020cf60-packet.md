# Target packet 0020cf60

- Range: `0020cf60`..`0020cfb8`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_0020cf60`
- Registry names for this address: none
- Queue: state `leased`, queue `store-order`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec128\\0020cf60-BLOCKED.md", "sha256": "bd081d1365275c60a967498b6254e835d913e31079a7dec4eff4e221dcadc115", "hypothesis": "C10(d): barrier between argument-load locals, or alter callee declaration order"}`

## Callees

- `00223e98` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0020cf60: 27bdfff0  addiu	sp,sp,-16
0020cf64: 3c0f0035  lui	t7,0x35
0020cf68: ffbf0000  sd	ra,0(sp)
0020cf6c: 8dee4688  lw	t6,18056(t7)   ; = D_00354688
0020cf70: 11c0000e  beqz	t6,0x20cfac
0020cf74: 00a0682d  move	t5,a1
0020cf78: 3c0f0035  lui	t7,0x35
0020cf7c: 8dee468c  lw	t6,18060(t7)   ; = D_0035468c
0020cf80: 19c0000b  blez	t6,0x20cfb0
0020cf84: dfbf0000  ld	ra,0(sp)
0020cf88: 90a6001c  lbu	a2,28(a1)
0020cf8c: 91a7001d  lbu	a3,29(t5)
0020cf90: 8da80014  lw	t0,20(t5)
0020cf94: 24a50008  addiu	a1,a1,8
0020cf98: 8da40004  lw	a0,4(t5)
0020cf9c: c5ac000c  lwc1	$f12,12(t5)
0020cfa0: c5ad0010  lwc1	$f13,16(t5)
0020cfa4: 08088fa6  j	0x223e98
0020cfa8: 27bd0010  addiu	sp,sp,16
0020cfac: dfbf0000  ld	ra,0(sp)
0020cfb0: 03e00008  jr	ra
0020cfb4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0020cf60(void)`

```c
void FUN_0020cf60(undefined8 param_1,int param_2)

{
  if ((DAT_00354688 != 0) && (0 < DAT_0035468c)) {
    FUN_00223e98(*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),
                 *(undefined4 *)(param_2 + 4),param_2 + 8,*(undefined1 *)(param_2 + 0x1c),
                 *(undefined1 *)(param_2 + 0x1d),*(undefined4 *)(param_2 + 0x14));
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- 12 differing words, 92/88 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec128/orch1_rec128_0020cf60_v4.verification.json`
- 6 differing words, 88/88 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec128/orch1_rec128_0020cf60_v3.verification.json`
- 6 differing words, 88/88 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec128/orch1_rec128_0020cf60_v2.verification.json`
- 3 differing words, 88/88 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec128/orch1_rec128_0020cf60_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec128/0020cf60-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec128/0020cf60-packet.md`
