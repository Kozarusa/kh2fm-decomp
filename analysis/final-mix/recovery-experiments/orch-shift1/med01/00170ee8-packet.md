# Target packet 00170ee8

- Range: `00170ee8`..`00170f34`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_00170ee8`
- Registry names for this address: none
- Queue: state `leased`, queue `medium-register-and-branch`, attempts 3, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\eight-hour-20261011\\00170ee8-medium-blocker.md", "sha256": "a55d4864cd7a113b06c732993e00e59a9ab4ff55ba3ce8d1157eaa100467ea50", "hypothesis": "Focused source family still differs in native scheduling, register allocation or branch layout; see immutable probe census."}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00170ee8: 340fffff  li	t7,0xffff
00170eec: 14af000f  bne	a1,t7,0x170f2c
00170ef0: 240f0001  li	t7,1
00170ef4: 148f0006  bne	a0,t7,0x170f10
00170ef8: 340fffff  li	t7,0xffff
00170efc: 3c0e0035  lui	t6,0x35
00170f00: 25cfdca0  addiu	t7,t6,-9056   ; = D_0034dca0
00170f04: adc0dca0  sw	zero,-9056(t6)   ; = D_0034dca0
00170f08: ade00004  sw	zero,4(t7)
00170f0c: 340fffff  li	t7,0xffff
00170f10: 14af0006  bne	a1,t7,0x170f2c
00170f14: 240f0001  li	t7,1
00170f18: 148f0004  bne	a0,t7,0x170f2c
00170f1c: 3c0e0035  lui	t6,0x35
00170f20: 25cfdcb8  addiu	t7,t6,-9032   ; = D_0034dcb8
00170f24: adc0dcb8  sw	zero,-9032(t6)   ; = D_0034dcb8
00170f28: ade00004  sw	zero,4(t7)
00170f2c: 03e00008  jr	ra
00170f30: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00170ee8(void)`

```c
void FUN_00170ee8(int param_1,long param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    DAT_0034dca0 = 0;
    DAT_0034dca4 = 0;
    DAT_0034dcb8 = 0;
    DAT_0034dcbc = 0;
  }
  return;
}
```

## Earlier attempts (newest first)

- 19 differing words, 68/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_00170ee8_medium_scalar_v1_1.verification.json`
- 17 differing words, 56/76 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_00170ee8_medium_scalar_v1_0.verification.json`
- report: `analysis/final-mix/recovery-experiments/eight-hour-20261011/00170ee8-medium-blocker.md`
