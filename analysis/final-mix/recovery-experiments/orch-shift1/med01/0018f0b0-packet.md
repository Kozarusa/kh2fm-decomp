# Target packet 0018f0b0

- Range: `0018f0b0`..`0018f100`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_0018f0b0`
- Registry names for this address: none
- Queue: state `leased`, queue `medium-register-and-branch`, attempts 3, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\eight-hour-20261011\\0018f0b0-medium-blocker.md", "sha256": "c362929600e607a63d15ac82b2b44e07374c914134856da03def0d4f4b7915d6", "hypothesis": "Focused source family still differs in native scheduling, register allocation or branch layout; see immutable probe census."}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0018f0b0: 340fffff  li	t7,0xffff
0018f0b4: 14af0010  bne	a1,t7,0x18f0f8
0018f0b8: 240f0001  li	t7,1
0018f0bc: 148f0007  bne	a0,t7,0x18f0dc
0018f0c0: 340fffff  li	t7,0xffff
0018f0c4: 3c0f0037  lui	t7,0x37
0018f0c8: 25efccd8  addiu	t7,t7,-13096   ; = D_0036ccd8
0018f0cc: c5e00000  lwc1	$f0,0(t7)
0018f0d0: 3c0f01c6  lui	t7,0x1c6
0018f0d4: e5e00cd0  swc1	$f0,3280(t7)   ; = D_01c60cd0
0018f0d8: 340fffff  li	t7,0xffff
0018f0dc: 14af0006  bne	a1,t7,0x18f0f8
0018f0e0: 240f0001  li	t7,1
0018f0e4: 148f0004  bne	a0,t7,0x18f0f8
0018f0e8: 3c0e01c6  lui	t6,0x1c6
0018f0ec: 25cf0cd8  addiu	t7,t6,3288   ; = D_01c60cd8
0018f0f0: adc00cd8  sw	zero,3288(t6)   ; = D_01c60cd8
0018f0f4: ade00004  sw	zero,4(t7)
0018f0f8: 03e00008  jr	ra
0018f0fc: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0018f0b0(void)`

```c
void FUN_0018f0b0(int param_1,long param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    DAT_01c60cd0 = DAT_0036ccd8;
    DAT_01c60cd8 = 0;
    DAT_01c60cdc = 0;
  }
  return;
}
```

## Earlier attempts (newest first)

- 20 differing words, 72/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018f0b0_medium_scalar_v1_1.verification.json`
- 17 differing words, 60/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018f0b0_medium_scalar_v1_0.verification.json`
- report: `analysis/final-mix/recovery-experiments/eight-hour-20261011/0018f0b0-medium-blocker.md`
